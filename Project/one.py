import tkinter as tk
from tkinter import ttk, messagebox, filedialog
import json
from datetime import datetime, timedelta
import os

class ExpenseTrackerApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Quản lý Chi tiêu")
        self.root.geometry("1000x700")
        self.root.configure(bg='#f0f4f8')
        
        # Data
        self.expenses = []
        self.data_file = "chi_tieu.json"
        self.load_data()
        
        # Categories
        self.categories = ["Ăn uống", "Di chuyển", "Mua sắm", "Giải trí", 
                          "Học tập", "Sức khỏe", "Hóa đơn", "Khác"]
        
        self.category_colors = {
            "Ăn uống": "#FF6B35",
            "Di chuyển": "#4A90E2",
            "Mua sắm": "#EC4899",
            "Giải trí": "#8B5CF6",
            "Học tập": "#10B981",
            "Sức khỏe": "#EF4444",
            "Hóa đơn": "#F59E0B",
            "Khác": "#6B7280"
        }
        
        self.setup_ui()
        self.update_display()
    
    def setup_ui(self):
        # Main container
        main_frame = tk.Frame(self.root, bg='#f0f4f8')
        main_frame.pack(fill=tk.BOTH, expand=True, padx=20, pady=20)
        
        # Header
        header_frame = tk.Frame(main_frame, bg='white', relief=tk.RAISED, bd=2)
        header_frame.pack(fill=tk.X, pady=(0, 20))
        
        title_label = tk.Label(header_frame, text="💰 QUẢN LÝ CHI TIÊU", 
                               font=("Arial", 24, "bold"), bg='white', 
                               fg='#4F46E5', pady=15)
        title_label.pack()
        
        # Statistics Frame
        stats_frame = tk.Frame(main_frame, bg='#f0f4f8')
        stats_frame.pack(fill=tk.X, pady=(0, 20))
        
        self.week_card = self.create_stat_card(stats_frame, "Tuần này", "0k", "#10B981")
        self.week_card.pack(side=tk.LEFT, fill=tk.BOTH, expand=True, padx=5)
        
        self.month_card = self.create_stat_card(stats_frame, "Tháng này", "0k", "#8B5CF6")
        self.month_card.pack(side=tk.LEFT, fill=tk.BOTH, expand=True, padx=5)
        
        self.total_card = self.create_stat_card(stats_frame, "Tổng cộng", "0k", "#F59E0B")
        self.total_card.pack(side=tk.LEFT, fill=tk.BOTH, expand=True, padx=5)
        
        # Input Frame
        input_frame = tk.LabelFrame(main_frame, text="Thêm chi tiêu mới", 
                                   font=("Arial", 12, "bold"), bg='white',
                                   fg='#4F46E5', relief=tk.RAISED, bd=2, pady=10)
        input_frame.pack(fill=tk.X, pady=(0, 20))
        
        # Amount
        tk.Label(input_frame, text="Số tiền (nghìn đồng):", 
                font=("Arial", 10), bg='white').grid(row=0, column=0, padx=10, pady=5, sticky='w')
        self.amount_entry = tk.Entry(input_frame, font=("Arial", 11), width=20)
        self.amount_entry.grid(row=0, column=1, padx=10, pady=5)
        
        # Purpose
        tk.Label(input_frame, text="Mục đích:", 
                font=("Arial", 10), bg='white').grid(row=0, column=2, padx=10, pady=5, sticky='w')
        self.purpose_entry = tk.Entry(input_frame, font=("Arial", 11), width=30)
        self.purpose_entry.grid(row=0, column=3, padx=10, pady=5)
        
        # Category
        tk.Label(input_frame, text="Danh mục:", 
                font=("Arial", 10), bg='white').grid(row=0, column=4, padx=10, pady=5, sticky='w')
        self.category_var = tk.StringVar(value=self.categories[0])
        self.category_combo = ttk.Combobox(input_frame, textvariable=self.category_var,
                                          values=self.categories, state='readonly',
                                          font=("Arial", 11), width=18)
        self.category_combo.grid(row=0, column=5, padx=10, pady=5)
        
        # Add Button
        add_btn = tk.Button(input_frame, text="➕ Thêm chi tiêu", 
                           command=self.add_expense,
                           bg='#4F46E5', fg='white', font=("Arial", 11, "bold"),
                           relief=tk.RAISED, bd=0, padx=20, pady=8,
                           cursor='hand2')
        add_btn.grid(row=0, column=6, padx=10, pady=5)
        
        # Bind Enter key
        self.root.bind('<Return>', lambda e: self.add_expense())
        
        # Action Buttons Frame
        action_frame = tk.Frame(main_frame, bg='#f0f4f8')
        action_frame.pack(fill=tk.X, pady=(0, 20))
        
        btn_style = {"font": ("Arial", 10, "bold"), "relief": tk.RAISED, 
                    "bd": 0, "padx": 15, "pady": 8, "cursor": "hand2"}
        
        tk.Button(action_frame, text="📊 Thống kê", command=self.show_statistics,
                 bg='#EC4899', fg='white', **btn_style).pack(side=tk.LEFT, padx=5)
        
        tk.Button(action_frame, text="💾 Xuất file", command=self.export_data,
                 bg='#10B981', fg='white', **btn_style).pack(side=tk.LEFT, padx=5)
        
        tk.Button(action_frame, text="📂 Nhập file", command=self.import_data,
                 bg='#3B82F6', fg='white', **btn_style).pack(side=tk.LEFT, padx=5)
        
        tk.Button(action_frame, text="🗑️ Xóa tất cả", command=self.clear_all,
                 bg='#EF4444', fg='white', **btn_style).pack(side=tk.LEFT, padx=5)
        
        # Filter Frame
        filter_frame = tk.Frame(main_frame, bg='#f0f4f8')
        filter_frame.pack(fill=tk.X, pady=(0, 10))
        
        self.view_mode = tk.StringVar(value="all")
        
        tk.Radiobutton(filter_frame, text="Tất cả", variable=self.view_mode,
                      value="all", command=self.update_display,
                      font=("Arial", 10, "bold"), bg='#f0f4f8',
                      selectcolor='#4F46E5', cursor='hand2').pack(side=tk.LEFT, padx=10)
        
        tk.Radiobutton(filter_frame, text="Tuần này", variable=self.view_mode,
                      value="week", command=self.update_display,
                      font=("Arial", 10, "bold"), bg='#f0f4f8',
                      selectcolor='#4F46E5', cursor='hand2').pack(side=tk.LEFT, padx=10)
        
        tk.Radiobutton(filter_frame, text="Tháng này", variable=self.view_mode,
                      value="month", command=self.update_display,
                      font=("Arial", 10, "bold"), bg='#f0f4f8',
                      selectcolor='#4F46E5', cursor='hand2').pack(side=tk.LEFT, padx=10)
        
        # Search
        tk.Label(filter_frame, text="🔍 Tìm kiếm:", 
                font=("Arial", 10), bg='#f0f4f8').pack(side=tk.LEFT, padx=(30, 5))
        self.search_var = tk.StringVar()
        self.search_var.trace('w', lambda *args: self.update_display())
        search_entry = tk.Entry(filter_frame, textvariable=self.search_var,
                               font=("Arial", 10), width=30)
        search_entry.pack(side=tk.LEFT, padx=5)
        
        # Expense List Frame
        list_frame = tk.Frame(main_frame, bg='white', relief=tk.RAISED, bd=2)
        list_frame.pack(fill=tk.BOTH, expand=True)
        
        # Scrollbar
        scrollbar = tk.Scrollbar(list_frame)
        scrollbar.pack(side=tk.RIGHT, fill=tk.Y)
        
        # Canvas for scrollable content
        self.canvas = tk.Canvas(list_frame, bg='white', 
                               yscrollcommand=scrollbar.set, highlightthickness=0)
        self.canvas.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)
        scrollbar.config(command=self.canvas.yview)
        
        # Frame inside canvas
        self.expense_frame = tk.Frame(self.canvas, bg='white')
        self.canvas_window = self.canvas.create_window((0, 0), window=self.expense_frame, 
                                                       anchor='nw', width=950)
        
        self.expense_frame.bind('<Configure>', 
                               lambda e: self.canvas.configure(scrollregion=self.canvas.bbox('all')))
        
        # Mouse wheel scrolling
        self.canvas.bind_all("<MouseWheel>", self._on_mousewheel)
    
    def _on_mousewheel(self, event):
        self.canvas.yview_scroll(int(-1*(event.delta/120)), "units")
    
    def create_stat_card(self, parent, title, value, color):
        card = tk.Frame(parent, bg=color, relief=tk.RAISED, bd=2)
        
        tk.Label(card, text=title, font=("Arial", 11), 
                bg=color, fg='white').pack(pady=(15, 5))
        
        value_label = tk.Label(card, text=value, font=("Arial", 20, "bold"),
                              bg=color, fg='white')
        value_label.pack(pady=(0, 5))
        
        count_label = tk.Label(card, text="0 giao dịch", font=("Arial", 9),
                              bg=color, fg='white')
        count_label.pack(pady=(0, 15))
        
        card.value_label = value_label
        card.count_label = count_label
        
        return card
    
    def add_expense(self):
        amount = self.amount_entry.get().strip()
        purpose = self.purpose_entry.get().strip()
        category = self.category_var.get()
        
        if not amount or not purpose:
            messagebox.showwarning("Cảnh báo", "Vui lòng nhập đầy đủ thông tin!")
            return
        
        try:
            amount_float = float(amount)
            if amount_float <= 0:
                messagebox.showwarning("Cảnh báo", "Số tiền phải lớn hơn 0!")
                return
        except ValueError:
            messagebox.showwarning("Cảnh báo", "Số tiền không hợp lệ!")
            return
        
        expense = {
            'id': datetime.now().timestamp(),
            'amount': amount_float,
            'purpose': purpose,
            'category': category,
            'timestamp': datetime.now().isoformat()
        }
        
        self.expenses.insert(0, expense)
        self.save_data()
        
        self.amount_entry.delete(0, tk.END)
        self.purpose_entry.delete(0, tk.END)
        self.amount_entry.focus()
        
        self.update_display()
    
    def delete_expense(self, expense_id):
        if messagebox.askyesno("Xác nhận", "Bạn có chắc muốn xóa chi tiêu này?"):
            self.expenses = [e for e in self.expenses if e['id'] != expense_id]
            self.save_data()
            self.update_display()
    
    def update_display(self):
        # Clear current display
        for widget in self.expense_frame.winfo_children():
            widget.destroy()
        
        # Filter expenses
        filtered = self.filter_expenses()
        
        # Update statistics
        self.update_statistics(filtered)
        
        # Display expenses
        if not filtered:
            empty_label = tk.Label(self.expense_frame, 
                                  text="📊 Chưa có chi tiêu nào\n\nHãy thêm chi tiêu đầu tiên của bạn!",
                                  font=("Arial", 14), fg='#9CA3AF', bg='white', pady=50)
            empty_label.pack()
        else:
            for expense in filtered:
                self.create_expense_item(expense)
    
    def filter_expenses(self):
        filtered = self.expenses.copy()
        
        # Filter by view mode
        mode = self.view_mode.get()
        if mode == 'week':
            week_ago = datetime.now() - timedelta(days=7)
            filtered = [e for e in filtered 
                       if datetime.fromisoformat(e['timestamp']) >= week_ago]
        elif mode == 'month':
            month_start = datetime.now().replace(day=1, hour=0, minute=0, second=0, microsecond=0)
            filtered = [e for e in filtered 
                       if datetime.fromisoformat(e['timestamp']) >= month_start]
        
        # Filter by search
        search = self.search_var.get().lower()
        if search:
            filtered = [e for e in filtered 
                       if search in e['purpose'].lower() or search in e['category'].lower()]
        
        return filtered
    
    def create_expense_item(self, expense):
        item_frame = tk.Frame(self.expense_frame, bg='#F9FAFB', 
                             relief=tk.RAISED, bd=1)
        item_frame.pack(fill=tk.X, padx=10, pady=5)
        
        # Left side - info
        left_frame = tk.Frame(item_frame, bg='#F9FAFB')
        left_frame.pack(side=tk.LEFT, fill=tk.BOTH, expand=True, padx=15, pady=10)
        
        # Category badge
        color = self.category_colors.get(expense['category'], '#6B7280')
        category_label = tk.Label(left_frame, text=expense['category'],
                                  bg=color, fg='white', font=("Arial", 9, "bold"),
                                  padx=10, pady=2)
        category_label.pack(anchor='w')
        
        # Purpose
        tk.Label(left_frame, text=expense['purpose'], 
                font=("Arial", 12, "bold"), bg='#F9FAFB',
                fg='#1F2937').pack(anchor='w', pady=(5, 0))
        
        # Timestamp
        time_str = self.format_relative_time(expense['timestamp'])
        tk.Label(left_frame, text=f"📅 {time_str}", 
                font=("Arial", 9), bg='#F9FAFB',
                fg='#6B7280').pack(anchor='w')
        
        # Right side - amount and actions
        right_frame = tk.Frame(item_frame, bg='#F9FAFB')
        right_frame.pack(side=tk.RIGHT, padx=15, pady=10)
        
        tk.Label(right_frame, text=f"{self.format_currency(expense['amount'])}",
                font=("Arial", 16, "bold"), bg='#F9FAFB',
                fg='#4F46E5').pack()
        
        # Delete button
        delete_btn = tk.Button(right_frame, text="🗑️", 
                              command=lambda: self.delete_expense(expense['id']),
                              bg='#EF4444', fg='white', font=("Arial", 10),
                              relief=tk.RAISED, bd=0, padx=10, pady=2,
                              cursor='hand2')
        delete_btn.pack(pady=(5, 0))
    
    def update_statistics(self, filtered_expenses):
        now = datetime.now()
        week_ago = now - timedelta(days=7)
        month_start = now.replace(day=1, hour=0, minute=0, second=0, microsecond=0)
        
        week_expenses = [e for e in self.expenses 
                        if datetime.fromisoformat(e['timestamp']) >= week_ago]
        month_expenses = [e for e in self.expenses 
                         if datetime.fromisoformat(e['timestamp']) >= month_start]
        
        week_total = sum(e['amount'] for e in week_expenses)
        month_total = sum(e['amount'] for e in month_expenses)
        all_total = sum(e['amount'] for e in self.expenses)
        
        self.week_card.value_label.config(text=self.format_currency(week_total))
        self.week_card.count_label.config(text=f"{len(week_expenses)} giao dịch")
        
        self.month_card.value_label.config(text=self.format_currency(month_total))
        self.month_card.count_label.config(text=f"{len(month_expenses)} giao dịch")
        
        self.total_card.value_label.config(text=self.format_currency(all_total))
        self.total_card.count_label.config(text=f"{len(self.expenses)} giao dịch")
    
    def format_currency(self, amount):
        return f"{int(amount):,}k".replace(',', '.')
    
    def format_relative_time(self, timestamp):
        dt = datetime.fromisoformat(timestamp)
        now = datetime.now()
        diff = now - dt
        
        if diff.total_seconds() < 60:
            return "Vừa xong"
        elif diff.total_seconds() < 3600:
            return f"{int(diff.total_seconds() / 60)} phút trước"
        elif diff.total_seconds() < 86400:
            return f"{int(diff.total_seconds() / 3600)} giờ trước"
        elif diff.days < 7:
            return f"{diff.days} ngày trước"
        else:
            return dt.strftime("%d/%m/%Y %H:%M")
    
    def show_statistics(self):
        if not self.expenses:
            messagebox.showinfo("Thống kê", "Chưa có dữ liệu để thống kê!")
            return
        
        # Calculate category totals
        category_totals = {}
        total = sum(e['amount'] for e in self.expenses)
        
        for exp in self.expenses:
            cat = exp['category']
            category_totals[cat] = category_totals.get(cat, 0) + exp['amount']
        
        # Create statistics window
        stats_win = tk.Toplevel(self.root)
        stats_win.title("Thống kê chi tiêu")
        stats_win.geometry("500x400")
        stats_win.configure(bg='white')
        
        tk.Label(stats_win, text="📊 THỐNG KÊ THEO DANH MỤC", 
                font=("Arial", 16, "bold"), bg='white',
                fg='#4F46E5', pady=20).pack()
        
        for cat, amount in sorted(category_totals.items(), key=lambda x: x[1], reverse=True):
            frame = tk.Frame(stats_win, bg='white')
            frame.pack(fill=tk.X, padx=30, pady=5)
            
            color = self.category_colors.get(cat, '#6B7280')
            
            tk.Label(frame, text=cat, font=("Arial", 11, "bold"),
                    bg='white', width=12, anchor='w').pack(side=tk.LEFT)
            
            tk.Label(frame, text=self.format_currency(amount),
                    font=("Arial", 11, "bold"), fg=color,
                    bg='white', width=15, anchor='e').pack(side=tk.RIGHT)
            
            percentage = (amount / total * 100) if total > 0 else 0
            tk.Label(frame, text=f"{percentage:.1f}%",
                    font=("Arial", 10), fg='#6B7280',
                    bg='white', width=8, anchor='e').pack(side=tk.RIGHT)
    
    def export_data(self):
        filename = filedialog.asksaveasfilename(
            defaultextension=".json",
            filetypes=[("JSON files", "*.json"), ("All files", "*.*")],
            initialfile=f"chi-tieu-{datetime.now().strftime('%Y%m%d')}.json"
        )
        if filename:
            try:
                with open(filename, 'w', encoding='utf-8') as f:
                    json.dump(self.expenses, f, ensure_ascii=False, indent=2)
                messagebox.showinfo("Thành công", "Đã xuất dữ liệu thành công!")
            except Exception as e:
                messagebox.showerror("Lỗi", f"Không thể xuất file: {str(e)}")
    
    def import_data(self):
        filename = filedialog.askopenfilename(
            filetypes=[("JSON files", "*.json"), ("All files", "*.*")]
        )
        if filename:
            try:
                with open(filename, 'r', encoding='utf-8') as f:
                    imported = json.load(f)
                if not isinstance(imported, list):
                    raise ValueError("Dữ liệu không hợp lệ")
                self.expenses = imported
                self.save_data()
                self.update_display()
                messagebox.showinfo("Thành công", "Đã nhập dữ liệu thành công!")
            except Exception as e:
                messagebox.showerror("Lỗi", f"Không thể nhập file: {str(e)}")
    
    def clear_all(self):
        if messagebox.askyesno("Xác nhận", 
                              "Bạn có chắc muốn xóa TẤT CẢ dữ liệu?\nHành động này không thể hoàn tác!"):
            self.expenses = []
            self.save_data()
            self.update_display()
            messagebox.showinfo("Thành công", "Đã xóa toàn bộ dữ liệu!")
    
    def load_data(self):
        if os.path.exists(self.data_file):
            try:
                with open(self.data_file, 'r', encoding='utf-8') as f:
                    self.expenses = json.load(f)
            except:
                self.expenses = []
    
    def save_data(self):
        try:
            with open(self.data_file, 'w', encoding='utf-8') as f:
                json.dump(self.expenses, f, ensure_ascii=False, indent=2)
        except Exception as e:
            messagebox.showerror("Lỗi", f"Không thể lưu dữ liệu: {str(e)}")

if __name__ == "__main__":
    root = tk.Tk()
    app = ExpenseTrackerApp(root)
    root.mainloop()
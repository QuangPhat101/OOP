// #include <format>
// #include <iostream>
// #include <string>
// #include <vector>
// using std::cout;
// using std::string;
// using std::vector;

// class Post {
// protected:
//   string _author;
//   string _title;
//   string _content;

// public:
//   Post();
//   Post(std::string author, std::string title, std::string content)
//       : _author(author), _title(title), _content(content) {}
//   virtual string toString();
// };

// class Comment {
// protected:
//   std::string _commentAuthor;
//   std::string _commentcontent;

// public:
//   Comment();
//   Comment(std::string commentAuthor, std::string commentContent)
//       : _commentAuthor(commentAuthor), _commentcontent(commentContent) {}
//   string commentAuthor();
//   string commentContent();
// };

// class GraphPost : public Post {
// private:
//   int _likes;
//   vector<Comment *> _comments;

// public:
//   GraphPost(Post post, int likes, vector<Comment *> comments)
//       : Post(post), _likes(likes), _comments(comments) {}
//   string toString() override;
// };

// int main() {
//   auto author = "Jane";
//   auto title = "3 tips to learn English effectively";
//   string content =
//       "To learn English effectively, you can try these 3 tips.\n1. Practice
//       on " "a daily basis.\n2. Take time to understand difficult
//       paragraphs\n3. Try " "new things everyday";
//   Post p(author, title, content);
//   // std::cout << p.toString();
//   vector<Comment *> comments = {new Comment("Anna", "Great work."),
//                                 new Comment("Blash", "This helps me a lot!"),
//                                 new Comment("Jack", " Thanks for your
//                                 post.")};
//   GraphPost gp(p, 5, comments);
//   cout << gp.toString();
//   return 0;
// }

// Post::Post() {
//   // Do nothing
// }

// std::string Post::toString() {
//   return std::format("Author: {}\nTitle: {}\nContent:\n{}", _author, _title,
//                      _content);
// }

// Comment::Comment() {
//   // Do nothing
// }

// string Comment::commentAuthor() { return _commentAuthor; }
// string Comment::commentContent() { return _commentcontent; }
// string GraphPost::toString() {
//   std::string result =
//       std::format("{}\nLikes: {}\nComments: {}\n", Post::toString(), _likes,
//                   this->_comments.size());
//   for (const auto &comment : this->_comments) {
//     result += std::format("- {}: {}\n", comment->commentAuthor(),
//                           comment->commentContent());
//   }
//   return result;
// }
#include <format>
#include <iostream>
#include <vector>
using namespace std;

class Account {
protected:
  string _name;
  int _balance;

public:
  string name();
  int balance();

public:
  Account();
  Account(string name, int balance);

public:
  // Trả ra số tiền có thể rút
  int withdraw(int amount);
};

class MockAccountRepository {
public:
  vector<Account> getAll();
};

class App {
private:
  vector<Account> _accounts;

public:
  void loadAccounts();
  // Thực hiện rút tiền cho tất cả các tài khoản cùng một lượng tiền
  void withdraw(int amount);
};

int main() {
  App app;
  app.loadAccounts();

  int amount = 70000;
  app.withdraw(amount);
}

// --- ACCOUNT ---------------------------------
string Account::name() { return _name; }
int Account::balance() { return _balance; }
Account::Account() {
  _name = "";
  _balance = 0;
}
Account::Account(string name, int balance) : _name(name), _balance(balance) {
  // Do nothing
}

int Account::withdraw(int amount) {
  if (_balance >= amount) {
    _balance -= amount;
    return amount;
  }
  return 0;
}

// --- MOCK ACCOUNT REPO ------------------------
vector<Account> MockAccountRepository::getAll() {
  return vector<Account>{
      Account("Alice", 60000),    Account("Bob", 100000),
      Account("Charlie", 100000), Account("David", 200000),
      Account("Eve", 300000),
  };
}

// --- APP --------------------------------------
void App::loadAccounts() {
  MockAccountRepository repo;
  _accounts = repo.getAll();
}

void App::withdraw(int amount) {
  for (auto &account : _accounts) {
    std::cout << format("{} has {}, can withdraw {} \n", account.name(),
                        account.balance(), account.withdraw(amount));
  }
}
#include <iostream>
#include <vector>
#include <string>
#include <expected>
#include <regex>
#include <format>
#include "Exercise3/utils.h"
using std::cout, std::cin, std::ostream;
using std::expected, std::unexpected;
using std::string;
using std::vector;
using std::format;
using std::regex, std::regex_match, std::smatch;

struct Student
{
    string id;
    string fullname;
    float gpa;
};
ostream &operator<<(ostream &os, const Student &sv);
void executeExercise02();

int main()
{
    salute("Bài tập 02: Chương trình tìm sinh viên có điểm trung bình lớn nhất\n");
    executeExercise02();
    bye();
    return 0;
}

ostream &operator<<(ostream &os, const Student &sv)
{
    os << sv.id << " - " << sv.fullname << " - " << sv.gpa;
    return os;
}

void executeExercise02()
{
    auto parseOneStudent = [](const string &prompt) -> expected<Student, string> {
        cout << prompt;
        string line;
        getline(cin, line);

        if (line.empty())
            return unexpected("Empty input data");

        static const regex pattern(R"(^\s*([^-]+?)\s*-\s*(.+?)\s*-\s*([0-9]+(?:\.[0-9]+)?)\s*$)");
        smatch m;
        if (!regex_match(line, m, pattern))
            return unexpected("Invalid format data, expected: ID - Full Name - GPA");

        string id = m[1].str();
        string name = m[2].str();
        string gpaStr = m[3].str();

        float gpa = 0.0f;
        try {
            gpa = std::stof(gpaStr);
        } catch (...) {
            return unexpected("Invalid GPA format");
        }

        if (gpa < 0.0f || gpa > 10.0f)
            return unexpected("Invalid GPA value, expected range: 0.0 - 10.0");

        auto trim = [](string &s) {
            size_t a = s.find_first_not_of(" \t\r\n");
            size_t b = s.find_last_not_of(" \t\r\n");
            if (a == string::npos) { s.clear(); return; }
            s = s.substr(a, b - a + 1);
        };
        trim(id);
        trim(name);

        return Student{id, name, gpa};
    };

    executeExerciseGeneric<Student>(
        [](const vector<Student> &students)
        {
            cout << "\n Danh sách sinh viên:\n";
            for (const auto &s : students)
                cout << s << "\n";

            const Student *best = &students[0];
            for (const auto &s : students)
                if (s.gpa > best->gpa)
                    best = &s;

            cout << "\n Sinh viên có GPA cao nhất (nếu trùng lấy người đầu tiên):\n"
                 << *best << "\n";
        },

        [&](string prompt) -> expected<Student, string> {
            return parseOneStudent("Nhập sinh viên theo định dạng ID - Họ tên - GPA: ");
        }
    );
}
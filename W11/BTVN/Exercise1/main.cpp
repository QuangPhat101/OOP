#include "IdeaProject.h"
#include "MVPProject.h"
#include "Project.h"
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

int main() {
  const double IDEA_COST = 2200.0;
  const double MVP_RUN_COST = 930.0;
  const double MVP_MKT_COST = 500.0;
  vector<Project *> projects;

  regex mvpRegex(R"(^Mvp:\s*([^,]+),\s*RunMonths=(\d+),\s*Marketing=(\d+))");
  regex ideaRegex(R"(^Idea:\s*([^,]+),\s*DevMonths=(\d+))");
  smatch matches; // Biến lưu kết quả khớp

  ifstream file("MayProposals.txt");
  string line;

  if (!file.is_open()) {
    cerr << "Khong the mo file!" << endl;
    return 1;
  }

  while (getline(file, line)) {
    // Kiểm tra xem dòng đó là Idea hay MVP

    // CASE 1: IDEA
    if (regex_search(line, matches, ideaRegex)) {
      // matches[1] là Tên, matches[2] là Số tháng Dev
      string name = matches[1];
      int devMonths = stoi(matches[2]); // Chuyển string sang int

      // Tạo đối tượng và Inject giá tiền IDEA_COST
      projects.push_back(new IdeaProject(name, devMonths, IDEA_COST));
    }
    // CASE 2: MVP
    else if (regex_search(line, matches, mvpRegex)) {
      // matches[1] là Tên, matches[2] là RunMonths, matches[3] là Marketing
      string name = matches[1];
      int runMonths = stoi(matches[2]);
      int mktMonths = stoi(matches[3]);

      // Tạo đối tượng và Inject giá tiền Run & Mkt
      projects.push_back(new MVPProject(name, runMonths, mktMonths,
                                        MVP_RUN_COST, MVP_MKT_COST));
    }
  }
  file.close();
  cout << "Kế hoạch tài trợ dự án startup nội bộ công ty AlphaTech \nTháng: "
          "05/2025\n\n";
  cout << format("{0:<8} | {1:<21} | {2:<24} | {3:<47} | {4:<20}", "STT",
                 "Loại dự án", "Tên dự án", "Thông tin", "Kinh phí");
  cout << "\n------------------------------------------------------------------"
          "------------------------------------------------\n";
  double Total = 0;
  for (int i = 0; i < projects.size(); i++) {
    cout << format("{0:<8} | {1}\n", i + 1, projects[i]->toString());
    Total += projects[i]->calculateSponsor();
  }
  cout << format("\nTổng kinh phí tài trợ: ${}\n", Total);
  for (auto &project : projects) {
    delete project;
  }
  return 0;
}
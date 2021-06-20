#include "University.h"

int Teacher::currentFreeId = 0;
int Subject::currentFreeId = 0;

string names[] = {"Anton",
                  "Oleg",
                  "Dima",
                  "Artem",
                  "Nikita",
                  "Alexandr",
                  "Vasia",
                  "Ashot",
                  "Jenia",
                  "Denis"
};

Teacher::Teacher() {
  _id = currentFreeId++;
  _name = "";
  _subjectIds.clear();
}

Teacher::Teacher(const string &name) {
  _id = currentFreeId++;
  _name = name;
}

Teacher::Teacher(const string &name, const vector<int> &subjectIds) {
  _id = currentFreeId++;
  _name = name;
  for (auto i : subjectIds)
    _subjectIds.push_back(i);
}

string Teacher::getName() {
  return _name;
}

void Teacher::setName(string name) {
  _name = name;
}

vector<Teacher> Teacher::generatingCompanies(int count) {
  int id;
  string name;
  vector<Teacher> result;
  for (int i = 0; i < count; i++) {
    name = names[i];
    Teacher teacher(name);
    result.push_back(teacher);
  }
  return result;
}

Subject::Subject() {
  _id = currentFreeId++;
  _name = "";
  _companyId = -1;
}

Subject::Subject(const string &name, int teacherId) {
  _id = currentFreeId++;
  _name = name;
  _companyId = teacherId;
}


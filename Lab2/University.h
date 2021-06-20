#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Teacher {
  int _id;
  string _name;
  vector<int> _subjectIds;
  static int currentFreeId;

 public:
  Teacher();
  Teacher(const string &name);
  Teacher(const string &name, const vector<int> &subjectIds);

  string getName();
  void setName(string name);
  static vector<Teacher> generatingCompanies(int count);

};

class Subject {
  int _id;
  string _name;
  int _companyId;
  static int currentFreeId;

 public:
  Subject();
  Subject(const string &name, int teacherId);
};

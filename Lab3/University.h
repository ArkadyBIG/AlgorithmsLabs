#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;

struct Subject {
  Subject() {
    name = "";
    date = 0;
      hours = 0;
  }
  string name;
  size_t date;
  size_t hours;
};

struct Teacher {
  Teacher() {
    name = "";
    subjects.resize(0);
  }
  string name;
  vector<Subject> subjects;
};

bool operator<(const Subject &a, const Subject &b) {
  if (a.hours < b.hours) return true;
  return false;
}

bool operator>(const Subject &a, const Subject &b) {
  if (a.hours > b.hours) return true;
  return false;
}

bool operator<=(const Subject &a, const Subject &b) {
  if (a.hours <= b.hours) return true;
  return false;
}

bool operator>=(const Subject &a, const Subject &b) {
  if (a.hours >= b.hours) return true;
  return false;
}

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student {
private:
  string name;
  float grd;
public:
  Student(const string& n = "", float g = 0);
  friend void sort(vector < Student >& v);
  void show() const;
};
Student::Student(const string& n, float g) { name = n, grd = g; }
void Student::show() const { cout << "N:" << name << " G:" << grd << '\n'; }
void sort(vector < Student >& v) {
  int i, j, size;
  Student tmp;
  size = v.size();
  for (i = 0; i < size - 1; i++) {
    for (j = i + 1; j < size; j++) {
      if (v[i].grd > v[j].grd) {
        tmp = v[i];
        v[i] = v[j];
        v[j] = tmp;
      }
    }
  }
}

int main() {
  int i;
  float grd;
  string name;
  vector <Student> st;
  while (1) {
    cout << "\nName : "; getline(cin, name);
    cout << " Grade : "; cin >> grd;
    if (grd == -1) break;

    Student tmp(name, grd);
    st.push_back(tmp);
    cin.get();
  }
  sort(st);
  for (i = 0; i < st.size(); i++) st[i].show();
  return 0;
}

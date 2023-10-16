#ifndef _E_H_
#define _E_H_

#include <string>
#include <vector>

using namespace std;

class People {
private:
  string name, job, id;
  int age;
public:
  People() {}
  People(string name, int age, string job, string id) {}

  string getName() const { return name; }
  int getAge() const { return age; }
  string getJob() const { return job; }
  string getId() const { return id; }

  void display() const {}
};

class Family {
private:
  string nameF, status, add;
  vector<People> p;
public:
  Family() {}
  Family(string nameF, string status, string add, vector<People> p) {}

  string getNameF() const { return nameF; }
  string getStatus() const { return status; }
  string getAdd() const { return add; }
  vector<People>& getP() { return p; }

  void display() const {}

  static vector<Family> getPoorHousehold(vector<Family> fa) {}
  static vector <Family> findFamilySurname(vector<Family> fa, string surname) {}
};

class Group {
private:
  string nameGr;
  vector<Family> f;
public:
  Group() {}
  Group(string nameGr, vector<Family> f) {}

  string getNameGr() const { return nameGr; }
  vector<Family> getF() const { return f; }
  int getNumberFammily() const { return f.size(); }

  static double avgAgeGroup(Group v) {}
  static vector<People> getPeopleHaveNotJob(Group g) {}
};
#endif

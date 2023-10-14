#ifndef _STUDENT_H
#define _STUDENT_H

#include <string>
class Student {
private:
  int student_id;
  double grade;
  std::string name;
public:
  void setStudentId(int);
  void setGrade(double);
  void setName(const std::string);

  int getStudentId() const;
  double getGrade() const;
  std::string getName() const;
};

#endif
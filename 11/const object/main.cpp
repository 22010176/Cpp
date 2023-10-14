#include <iostream>

class Student {
private:
  int student_id;
  // double grade;
  mutable double grade;

public:
  Student(int id) { student_id = id; }
  void setGrade(double grd) const { grade = grd; }
  int getStudentId() const { return student_id; }
  double getGrade() const { return grade; }
};

int main() {
  const Student s(10);
  // s.getGrade(9.0); // Wrong
  s.setGrade(9.0);
  std::cout << "Student_id: " << s.getGrade() << std::endl;
  std::cout << "Grade: " << s.getGrade() << std::endl;
  return 0;
}
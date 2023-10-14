#include <iostream>
#include <string>
#include "Student.h"

// g++ main.cpp Student.cpp -o main; ./main

int main() {
  Student s;

  s.setStudentId(1);
  s.setGrade(9.0);
  s.setName("Kate Moss");

  std::cout << " Infomation of student: " << std::endl;
  std::cout << "Student_id: " << s.getStudentId() << std::endl;
  std::cout << "Name: " << s.getName() << std::endl;
  std::cout << "Grade: " << s.getGrade() << std::endl;
}
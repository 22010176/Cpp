#include "Student.h"
#include <string>

void Student::setStudentId(int id) { student_id = id; }
void Student::setGrade(double grd) { grade = grd; }
void Student::setName(const std::string n) { name = n; }

int Student::getStudentId() const { return student_id; }
double Student::getGrade() const { return grade; }
std::string Student::getName() const { return name; }
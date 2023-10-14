#include <iostream>
#include <vector>

using namespace std;

class Company {
public:
  class Department {
  private:
    string depart_name;
    vector<string> employee_names;
  public:
    Department() {}
    void setName(const string& d_name) { depart_name = d_name; }
    string getName() const { return depart_name; }
    void addEmployee(const string& e_name) { employee_names.push_back(e_name); }
    void show() const;
  };

  Company(const string& c_name) : company_name(c_name) {}
  void createDepartment(const string&);
  void addEmployee(const string&, const string&);
  void show() const;

private:
  string company_name;
  vector<Department> department_objects;
};

void Company::createDepartment(const string& d_name) {
  Department department;
  department.setName(d_name);
  department_objects.push_back(department);
}

void Company::addEmployee(const string& d_name, const string& e_name) {
  for (Department& department : department_objects) {
    if (department.getName() != d_name) continue;
    department.addEmployee(e_name);
    return;
  }
}

void Company::show() const {
  cout << "Compary: " << company_name << endl;
  for (const Department& department : department_objects) {
    department.show();
    cout << endl;
  }
}

void Company::Department::show() const {
  cout << "Deparment: " << depart_name << endl;
  cout << "Employees: " << endl;
  for (const string& e_name : employee_names) cout << " - " << e_name << endl;
}

int main() {
  Company cmp("Coca-Cola");

  cmp.createDepartment("HR");
  cmp.addEmployee("HR", "Alice");
  cmp.addEmployee("HR", "Alex");

  cmp.createDepartment("Engineering");
  cmp.addEmployee("Engineering", "Jonh");
  cmp.addEmployee("Engineering", "David");
  cmp.addEmployee("Engineering", "Tony");

  cmp.createDepartment("Sales");
  cmp.addEmployee("Sales", "Lara");
  cmp.addEmployee("Sales", "Kate");
  cmp.show();

  return 0;
}
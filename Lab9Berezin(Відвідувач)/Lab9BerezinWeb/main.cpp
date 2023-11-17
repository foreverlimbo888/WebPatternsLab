#include <iostream>
#include <vector>
#include <string>

// Оголошення класу Співробітник
class Employee;

// Оголошення класу Департамент
class Department {
public:
    Department(const std::vector<Employee>& employees);

    // Додайте методи, які можуть бути потрібні для реалізації патерну Відвідувач

private:
    std::vector<Employee> employees;
};

// Оголошення класу Компанія
class Company {
public:
    Company(const std::vector<Department>& departments);

    // Додайте методи, які можуть бути потрібні для реалізації патерну Відвідувач

private:
    std::vector<Department> departments;
};

// Оголошення класу Співробітник
class Employee {
public:
    Employee(const std::string& position, double salary);

    // Додайте методи, які можуть бути потрібні для реалізації патерну Відвідувач

private:
    std::string position;
    double salary;
};

// Оголошення інтерфейсу відвідувача
class Visitor {
public:
    virtual void visit(Employee& employee) = 0;
    virtual void visit(Department& department) = 0;
    virtual void visit(Company& company) = 0;
};

// Реалізація класу ЗарплатнийВідомістьВідвідувач, який реалізує логіку отримання зарплатної відомості
class SalaryReportVisitor : public Visitor {
public:
        // Реалізуйте методи відвідувача
};

// Клієнтський код, який використовує патерн Відвідувач
int main() {
    // Створення об'єктів компанії, департаментів та співробітників
    // ...

    // Створення екземпляра ЗарплатнийВідомістьВідвідувач
    SalaryReportVisitor salaryVisitor;

    // Виклик методів відвідувача для отримання зарплатної відомості
    // ...

    return 0;
}

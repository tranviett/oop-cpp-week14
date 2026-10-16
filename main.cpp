
#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string id, name;

public:
    Employee(string id = "", string name = "") {
        this->id = id;
        this->name = name;
    }

    string getId() { return id; }
    void setId(string id) { this->id = id; }

    string getName() { return name; }
    void setName(string name) { this->name = name; }

    virtual void display() {
        cout << id << " - " << name << endl;
    }

    virtual double calculateSalary(int m, int y) = 0;
    virtual ~Employee() {}
};

class HourlyEmployee : public Employee {
private:
    double hours, salaryPerHours;
    int month, year;

public:
    HourlyEmployee(string id, string name, double h,
                   double s, int m, int y)
        : Employee(id, name), hours(h), salaryPerHours(s),
          month(m), year(y) {}

    double getHours() { return hours; }
    void setHours(double h) { hours = h; }

    double getSalaryPerHours() { return salaryPerHours; }
    void setSalaryPerHours(double s) { salaryPerHours = s; }

    int getMonth() { return month; }
    void setMonth(int m) { month = m; }

    int getYear() { return year; }
    void setYear(int y) { year = y; }

    double calculateSalary(int m, int y) override {
        return (month == m && year == y) ? hours * salaryPerHours : 0;
    }

    void display() override {
        Employee::display();
        cout << "Salary: " << calculateSalary(month, year) << endl;
    }
};

class MonthlyEmployee : public Employee {
private:
    double salary;
    int month, year;

public:
    MonthlyEmployee(string id, string name, double s, int m, int y)
        : Employee(id, name), salary(s), month(m), year(y) {}

    double getSalary() { return salary; }
    void setSalary(double s) { salary = s; }

    int getMonth() { return month; }
    void setMonth(int m) { month = m; }

    int getYear() { return year; }
    void setYear(int y) { year = y; }

    double calculateSalary(int m, int y) override {
        return (month == m && year == y) ? salary : 0;
    }

    void display() override {
        Employee::display();
        cout << "Salary: " << calculateSalary(month, year) << endl;
    }
};

class DailyEmployee : public Employee {
private:
    int numberOfDays, month, year;
    double salaryPerDay;

public:
    DailyEmployee(string id, string name, int d, double s, int m, int y)
        : Employee(id, name), numberOfDays(d), salaryPerDay(s),
          month(m), year(y) {}

    int getNumberOfDays() { return numberOfDays; }
    void setNumberOfDays(int d) { numberOfDays = d; }

    double getSalaryPerDay() { return salaryPerDay; }
    void setSalaryPerDay(double s) { salaryPerDay = s; }

    int getMonth() { return month; }
    void setMonth(int m) { month = m; }

    int getYear() { return year; }
    void setYear(int y) { year = y; }

    double calculateSalary(int m, int y) override {
        return (month == m && year == y) ? numberOfDays * salaryPerDay : 0;
    }

    void display() override {
        Employee::display();
        cout << "Salary: " << calculateSalary(month, year) << endl;
    }
};

int main() {
    HourlyEmployee a("E01", "An", 160, 50000, 10, 2026);
    MonthlyEmployee b("E02", "Binh", 12000000, 10, 2026);
    DailyEmployee c("E03", "Cuong", 22, 300000, 10, 2026);

    a.display();
    b.display();
    c.display();

    cout << "Salary October 2026: "
         << a.calculateSalary(10, 2026) + b.calculateSalary(10, 2026)
         + c.calculateSalary(10, 2026) << endl;

    return 0;
}


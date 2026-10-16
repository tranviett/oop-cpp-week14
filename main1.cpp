
#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class Employee {
private:
    string cccd, phone, address;

public:
    Employee() : cccd(""), phone(""), address("") {}

    Employee(string c, string p, string a)
        : cccd(c), phone(p), address(a) {}

    virtual double calculateSalary(int month, int year) = 0;
    virtual double calculateYearlySalary(int year) = 0;

    virtual void displayInfo() {
        cout << "CCCD: " << cccd << endl;
        cout << "Phone: " << phone << endl;
        cout << "Address: " << address << endl;
    }

    virtual ~Employee() = default;
};

class HourlyEmployee : public Employee {
private:
    double salaryPerHour;
    int hours[MAX], month[MAX], year[MAX], count;

public:
    HourlyEmployee(string c, string p, string a, double s)
        : Employee(c, p, a), salaryPerHour(s), count(0) {}

    void addRecord(int h, int m, int y) {
        if (count < MAX) {
            hours[count] = h;
            month[count] = m;
            year[count] = y;
            count++;
        }
    }

    double calculateSalary(int m, int y) override {
        double total = 0;
        for (int i = 0; i < count; i++)
            if (month[i] == m && year[i] == y)
                total += hours[i] * salaryPerHour;
        return total;
    }

    double calculateYearlySalary(int y) override {
        double total = 0;
        for (int i = 0; i < count; i++)
            if (year[i] == y)
                total += hours[i] * salaryPerHour;
        return total;
    }
};

class MonthlyEmployee : public Employee {
private:
    double monthlySalary;
    int month[MAX], year[MAX], count;

public:
    MonthlyEmployee(string c, string p, string a, double s)
        : Employee(c, p, a), monthlySalary(s), count(0) {}

    void addRecord(int m, int y) {
        if (count < MAX) {
            month[count] = m;
            year[count] = y;
            count++;
        }
    }

    double calculateSalary(int m, int y) override {
        double total = 0;
        for (int i = 0; i < count; i++)
            if (month[i] == m && year[i] == y)
                total += monthlySalary;
        return total;
    }

    double calculateYearlySalary(int y) override {
        double total = 0;
        for (int i = 0; i < count; i++)
            if (year[i] == y)
                total += monthlySalary;
        return total;
    }
};

class DailyEmployee : public Employee {
private:
    double salaryPerDay;
    int days[MAX], month[MAX], year[MAX], count;

public:
    DailyEmployee(string c, string p, string a, double s)
        : Employee(c, p, a), salaryPerDay(s), count(0) {}

    void addRecord(int d, int m, int y) {
        if (count < MAX) {
            days[count] = d;
            month[count] = m;
            year[count] = y;
            count++;
        }
    }

    double calculateSalary(int m, int y) override {
        double total = 0;
        for (int i = 0; i < count; i++)
            if (month[i] == m && year[i] == y)
                total += days[i] * salaryPerDay;
        return total;
    }

    double calculateYearlySalary(int y) override {
        double total = 0;
        for (int i = 0; i < count; i++)
            if (year[i] == y)
                total += days[i] * salaryPerDay;
        return total;
    }
};

int main() {
    HourlyEmployee h("001", "0901", "HCM", 50000);
    h.addRecord(26, 1, 2026);
    h.addRecord(24, 2, 2026);
    h.addRecord(30, 12, 2026);

    MonthlyEmployee m("002", "0902", "Dong Nai", 15000000);
    m.addRecord(1, 2026);
    m.addRecord(2, 2026);
    m.addRecord(12, 2026);

    DailyEmployee d("003", "0903", "Ha Noi", 400000);
    d.addRecord(26, 1, 2026);
    d.addRecord(24, 2, 2026);
    d.addRecord(30, 12, 2026);

    Employee* employees[] = {&h, &m, &d};

    cout << "=== SALARY MONTH 1/2026 ===" << endl;
    for (Employee* e : employees)
        cout << e->calculateSalary(1, 2026) << endl;

    cout << "\n=== YEARLY SALARY 2026 ===" << endl;
    for (Employee* e : employees)
        cout << e->calculateYearlySalary(2026) << endl;

    return 0;
}

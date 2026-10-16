
#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class Employee {
private:
    string id, phone, address;

public:
    Employee(string i = "", string p = "", string a = "") {
        id = i;
        phone = p;
        address = a;
    }

    string getId() { return id; }
    void setId(string i) { id = i; }

    string getPhone() { return phone; }
    void setPhone(string p) { phone = p; }

    string getAddress() { return address; }
    void setAddress(string a) { address = a; }

    virtual void displayInfo() {
        cout << "ID: " << id << "\nPhone: " << phone
             << "\nAddress: " << address << endl;
    }

    virtual double calculateSalary(int m, int y) = 0;
    virtual double calculateYearlySalary(int y) = 0;
    virtual ~Employee() {}
};

class HourlyEmployee : public Employee {
private:
    double rate;
    int month[MAX], year[MAX], hour[MAX], n;

public:
    HourlyEmployee(string i, string p, string a, double r)
        : Employee(i, p, a) {
        rate = r;
        n = 0;
    }

    double getRate() { return rate; }
    void setRate(double r) { rate = r; }

    void addRecord(int m, int y, int h) {
        if (n < MAX) {
            month[n] = m;
            year[n] = y;
            hour[n] = h;
            n++;
        }
    }

    double calculateSalary(int m, int y) override {
        double sum = 0;
        for (int i = 0; i < n; i++)
            if (month[i] == m && year[i] == y)
                sum += hour[i] * rate;
        return sum;
    }

    double calculateYearlySalary(int y) override {
        double sum = 0;
        for (int i = 0; i < n; i++)
            if (year[i] == y)
                sum += hour[i] * rate;
        return sum;
    }
};

class MonthlyEmployee : public Employee {
private:
    double salary;
    int month[MAX], year[MAX], n;

public:
    MonthlyEmployee(string i, string p, string a, double s)
        : Employee(i, p, a) {
        salary = s;
        n = 0;
    }

    double getSalary() { return salary; }
    void setSalary(double s) { salary = s; }

    void addRecord(int m, int y) {
        if (n < MAX) {
            month[n] = m;
            year[n] = y;
            n++;
        }
    }

    double calculateSalary(int m, int y) override {
        double sum = 0;
        for (int i = 0; i < n; i++)
            if (month[i] == m && year[i] == y)
                sum += salary;
        return sum;
    }

    double calculateYearlySalary(int y) override {
        double sum = 0;
        for (int i = 0; i < n; i++)
            if (year[i] == y)
                sum += salary;
        return sum;
    }
};

class DailyEmployee : public Employee {
private:
    double rate;
    int month[MAX], year[MAX], day[MAX], n;

public:
    DailyEmployee(string i, string p, string a, double r)
        : Employee(i, p, a) {
        rate = r;
        n = 0;
    }

    double getRate() { return rate; }
    void setRate(double r) { rate = r; }

    void addRecord(int m, int y, int d) {
        if (n < MAX) {
            month[n] = m;
            year[n] = y;
            day[n] = d;
            n++;
        }
    }

    double calculateSalary(int m, int y) override {
        double sum = 0;
        for (int i = 0; i < n; i++)
            if (month[i] == m && year[i] == y)
                sum += day[i] * rate;
        return sum;
    }

    double calculateYearlySalary(int y) override {
        double sum = 0;
        for (int i = 0; i < n; i++)
            if (year[i] == y)
                sum += day[i] * rate;
        return sum;
    }
};

int main() {
    HourlyEmployee e1("NV01", "091234", "HCM", 50000);
    e1.addRecord(10, 2026, 160);
    e1.addRecord(11, 2026, 150);

    MonthlyEmployee e2("NV02", "092345", "Dong Nai", 15000000);
    e2.addRecord(10, 2026);
    e2.addRecord(11, 2026);

    DailyEmployee e3("NV03", "093456", "Ha Noi", 400000);
    e3.addRecord(10, 2026, 22);
    e3.addRecord(11, 2026, 25);

    Employee* list[] = {&e1, &e2, &e3};

    for (Employee* e : list) {
        e->displayInfo();
        cout << "Salary in October: "
             << e->calculateSalary(10, 2026) << endl;
        cout << "Salary in 2026: "
             << e->calculateYearlySalary(2026) << endl;
        cout << "------------------" << endl;
    }

    return 0;
}

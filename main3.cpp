
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Vehicle {
private:
    string id, name;
    double price;

public:
    Vehicle() : id(""), name(""), price(0) {}

    Vehicle(string i, string n, double p)
        : id(i), name(n), price(p) {}

    string getId() { return id; }
    void setId(string i) { id = i; }

    string getName() { return name; }
    void setName(string n) { name = n; }

    double getPrice() { return price; }
    void setPrice(double p) { price = p; }

    virtual void displayInfo() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Daily price: " << price << endl;
    }

    virtual double calculateRentalFee(int days) = 0;

    virtual ~Vehicle() {}
};

class Car : public Vehicle {
public:
    Car() : Vehicle() {}

    Car(string i, string n, double p)
        : Vehicle(i, n, p) {}

    double calculateRentalFee(int days) override {
        double fee = getPrice() * days;
        if (days >= 7)
            fee *= 0.9;
        return fee;
    }

    void displayInfo() override {
        cout << "\n--- CAR ---" << endl;
        Vehicle::displayInfo();
    }
};

class Motorbike : public Vehicle {
public:
    Motorbike() : Vehicle() {}

    Motorbike(string i, string n, double p)
        : Vehicle(i, n, p) {}

    double calculateRentalFee(int days) override {
        double fee = getPrice() * days;
        if (days >= 5)
            fee *= 0.95;
        return fee;
    }

    void displayInfo() override {
        cout << "\n--- MOTORBIKE ---" << endl;
        Vehicle::displayInfo();
    }
};

class Truck : public Vehicle {
private:
    double transportFee;

public:
    Truck() : Vehicle(), transportFee(0) {}

    Truck(string i, string n, double p, double t)
        : Vehicle(i, n, p), transportFee(t) {}

    double getTransportFee() { return transportFee; }
    void setTransportFee(double t) { transportFee = t; }

    double calculateRentalFee(int days) override {
        return getPrice() * days + transportFee;
    }

    void displayInfo() override {
        cout << "\n--- TRUCK ---" << endl;
        Vehicle::displayInfo();
        cout << "Transport fee: " << transportFee << endl;
    }
};

int main() {
    vector<Vehicle*> vehicles;

    vehicles.push_back(new Car("C01", "Toyota", 800000));
    vehicles.push_back(new Motorbike("M01", "Honda", 150000));
    vehicles.push_back(new Truck("T01", "Isuzu", 1200000, 300000));

    int days;
    cout << "Enter rental days: ";
    cin >> days;

    if (days <= 0) {
        cout << "Invalid number of days!" << endl;
        for (Vehicle* v : vehicles)
            delete v;
        return 0;
    }

    double total = 0;
    double maxFee = -1;
    Vehicle* mostExpensive = nullptr;

    for (Vehicle* v : vehicles) {
        v->displayInfo();

        double fee = v->calculateRentalFee(days);
        cout << "Rental fee: " << fee << " VND" << endl;

        total += fee;

        if (fee > maxFee) {
            maxFee = fee;
            mostExpensive = v;
        }
    }

    cout << "\nTotal rental revenue: " << total << " VND" << endl;

    cout << "\nVehicle with highest rental fee:" << endl;
    if (mostExpensive != nullptr) {
        mostExpensive->displayInfo();
        cout << "Highest fee: " << maxFee << " VND" << endl;
    }

    for (Vehicle* v : vehicles)
        delete v;

    return 0;
}

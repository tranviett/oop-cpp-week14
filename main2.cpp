#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class Drinks {
private:
    string name;
    double price;
    int quantity;
    string date;

public:
    Drinks(string n = "", double p = 0, int q = 0, string d = "")
        : name(n), price(p), quantity(q), date(d) {}

    string getDate() { return date; }
    double getRevenue() { return price * quantity; }

    virtual void display() {
        cout << name << " | " << date
             << " | Revenue: " << getRevenue() << endl;
    }

    virtual ~Drinks() {}
};

class Coffee : public Drinks {
public:
    Coffee(string n, double p, int q, string d)
        : Drinks(n, p, q, d) {}
};

class Tea : public Drinks {
public:
    Tea(string n, double p, int q, string d)
        : Drinks(n, p, q, d) {}
};

class Smoothies : public Drinks {
public:
    Smoothies(string n, double p, int q, string d)
        : Drinks(n, p, q, d) {}
};

class Juices : public Drinks {
public:
    Juices(string n, double p, int q, string d)
        : Drinks(n, p, q, d) {}
};

class Foods {
private:
    string name;
    double price;
    int quantity;
    string date;

public:
    Foods(string n = "", double p = 0, int q = 0, string d = "")
        : name(n), price(p), quantity(q), date(d) {}

    string getDate() { return date; }
    double getRevenue() { return price
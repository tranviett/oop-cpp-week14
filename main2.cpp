
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
    double getRevenue() { return price * quantity; }

    virtual void display() {
        cout << name << " | " << date
             << " | Revenue: " << getRevenue() << endl;
    }

    virtual ~Foods() {}
};

class Cake : public Foods {
public:
    Cake(string n, double p, int q, string d)
        : Foods(n, p, q, d) {}
};

class Breads : public Foods {
public:
    Breads(string n, double p, int q, string d)
        : Foods(n, p, q, d) {}
};

int main() {
    Coffee c("Coffee", 30000, 10, "16/10/2026");
    Tea t("Tea", 25000, 8, "16/10/2026");
    Smoothies s("Smoothies", 40000, 5, "16/10/2026");
    Juices j("Juices", 35000, 6, "16/10/2026");

    Cake ca("Cake", 20000, 12, "16/10/2026");
    Breads b("Breads", 15000, 15, "16/10/2026");

    string targetDate;
    cout << "Enter date (dd/mm/yyyy): ";
    cin >> targetDate;

    Drinks* drinks[] = {&c, &t, &s, &j};
    Foods* foods[] = {&ca, &b};

    double drinkRevenue = 0;
    double foodRevenue = 0;

    for (Drinks* d : drinks) {
        if (d->getDate() == targetDate)
            drinkRevenue += d->getRevenue();
    }

    for (Foods* f : foods) {
        if (f->getDate() == targetDate)
            foodRevenue += f->getRevenue();
    }

    cout << "\nDate: " << targetDate << endl;
    cout << "Drinks: " << drinkRevenue << " VND" << endl;
    cout << "Foods: " << foodRevenue << " VND" << endl;

    return 0;
}

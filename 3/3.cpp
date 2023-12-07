#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Mechanic {
public:
    Mechanic() : level(0) {}
    Mechanic(int level) : level(level) {}
    Mechanic(const Mechanic& other) : level(other.level) {}
    ~Mechanic() {}
    int getLevel() const { return level; }
private:
    int level;
};

class Person {
public:
    Person() {}
    Person(const string& name) : name(name) {}
    Person(const Person& other) : name(other.name) {}
    ~Person() {}
    const string& getName() const { return name; }
private:
    string name;
};

class Driver : public Person {
public:
    Driver() : salary(0), experience(0), mechanic(0) {}
    Driver(const string& name, int salary, int experience, int mechanicLevel)
        : Person(name), salary(salary), experience(experience), mechanic(mechanicLevel) {}
    Driver(const Driver& other)
        : Person(other), salary(other.salary), experience(other.experience), mechanic(other.mechanic) {}
    ~Driver() {}
    int getSalary() const { return salary; }
    int getExperience() const { return experience; }
    const Mechanic& getMechanic() const { return mechanic; }
    void setSalary(int newSalary) { salary = newSalary; }
    void setExperience(int newExperience) { experience = newExperience; }
private:
    int salary;
    int experience;
    Mechanic mechanic;
};

class Truck {
public:
    Truck() {}
    Truck(const string& name, const Driver& driver) : name(name), driver(driver) {}
    ~Truck() {}
    const string& getName() const { return name; }
    const Driver& getDriver() const { return driver; }
private:
    string name;
    Driver driver;
};

class LogisticsCompany {
public:
    LogisticsCompany() : name(""), trucks() {}
    LogisticsCompany(const string& name, int numTrucks) : name(name) {
        for (int i = 0; i < numTrucks; i++) {
            string truckName = "" + to_string(i + 1);
            Driver driver("" + to_string(i + 1), 1000, 1, i + 1);
            Truck truck(truckName, driver);
            trucks.push_back(truck);
        }
    }
    LogisticsCompany(const LogisticsCompany& other) : name(other.name), trucks(other.trucks) {}
    ~LogisticsCompany() {}
    const string& getName() const { return name; }
    const vector<Truck>& getTrucks() const { return trucks; }
private:
    string name;
    vector<Truck> trucks;
};

int main() {
    setlocale(LC_ALL, "RUS");
    LogisticsCompany company("        ", 3);
    const vector<Truck>& trucks = company.getTrucks();
    for (const Truck& truck : trucks) {
        const Driver& driver = truck.getDriver();
        cout << "Грузовик " << truck.getName() << " под управлением " << driver.getName() << " водителя" << endl;
        cout << "Водитель " << driver.getName() << " имеет зарплату равную " << driver.getSalary() << " и опыт вождения равный " << driver.getExperience() << " лет " << endl;
        cout << "Водитель " << driver.getName() << " имеет уровень знания механики равный " << driver.getMechanic().getLevel() << endl;
    }
    return 0;
}


struct st {
string name;
float zarlata;
int mehenik;

};


class LogisticsCompany {
private:
    vector <st> Moy;
public:
//3 rjycnhernjhf b ltcnhernjh




};

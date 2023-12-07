#include <iostream>
#include <string>
#include <vector>

class Tariff {
public:
    std::string name;
    double pricePerKm;

    Tariff() : pricePerKm(0.0) {}  // Конструктор по умолчанию

    Tariff(std::string name, double pricePerKm) : name(name), pricePerKm(pricePerKm) {}

    ~Tariff() {}  // Деструктор

    double getPricePerKm() const {
        return pricePerKm;
    }

    void setPricePerKm(double price) {
        pricePerKm = price;
    }
};

class Car {
public:
    std::string brand;
    std::string model;
    int year;
    std::vector<Driver*> drivers;  // Ассоциация

    Car() : year(0) {}  // Конструктор по умолчанию

    Car(std::string brand, std::string model, int year) : brand(brand), model(model), year(year) {}

    ~Car() {}  // Деструктор

    void addDriver(Driver* driver) {
        drivers.push_back(driver);
    }

    void removeDriver(Driver* driver) {
        // Реализация удаления водителя из вектора
    }

    void listDrivers() {
        for (Driver* driver : drivers) {
            std::cout << driver->name << " " << driver->age << std::endl;
        }
    }
};

class Driver {
public:
    std::string name;
    int age;
    Car* car;  // Зависимость

    Driver() : age(0), car(nullptr) {}  // Конструктор по умолчанию

    Driver(std::string name, int age) : name(name), age(age), car(nullptr) {}

    ~Driver() {}  // Деструктор

    void setCar(Car* car) {
        this->car = car;
    }

    void removeCar() {
        car = nullptr;
    }

    void drive() {
        if (car != nullptr) {
            std::cout << "Driving " << car->brand << " " << car->model << std::endl;
        }
    }
};

class Order {
public:
    Customer* customer;
    Tariff* tariff;
    double distance;
    double price;

    Order() : distance(0.0), price(0.0) {}  // Конструктор по умолчанию

    Order(Customer* customer, Tariff* tariff, double distance) : customer(customer), tariff(tariff), distance(distance), price(0.0) {}

    ~Order() {}  // Деструктор

    void calculatePrice() {
        price = distance * tariff->getPricePerKm();
    }
};

class Customer {
public:
    std::string name;
    std::vector<Order*> orders;  // Композиция

    Customer() {}  // Конструктор по умолчанию

    Customer(std::string name) : name(name) {}

    ~Customer() {}  // Деструктор

    void addOrder(Order* order) {
        orders.push_back(order);
    }

    void removeOrder(Order* order) {
        // Реализация удаления заказа из вектора
    }

    void listOrders() {
        for (Order* order : orders) {
            std::cout << order->customer->name << " " << order->tariff->name << " " << order->distance << " " << order->price << std::endl;
        }
    }
};

class TaxiPark {
public:
    std::vector<Car*> cars;
    std::vector<Driver*> drivers;
    std::vector<Order*> orders;
    std::vector<Customer*> customers;

    void addCar(Car* car) {
        cars.push_back(car);
    }

    void addDriver(Driver* driver) {
        drivers.push_back(driver);
    }

    void addOrder(Order* order) {
        orders.push_back(order);
    }

    void addCustomer(Customer* customer) {
        customers.push_back(customer);
    }
};

int main() {
    Tariff tariff1("Standard", 1.0);
    Tariff tariff2("Premium", 1.5);

    Car car1("Toyota", "Camry", 2020);
    Car car2("Honda", "Civic", 2018);

    Driver driver1("John", 30);
    Driver driver2("Alice", 25);

    driver1.setCar(&car1);
    driver2.setCar(&car2);

    Customer customer1("Bob");
    Customer customer2("Eve");

    Order order1(&customer1, &tariff1, 10.0);
    Order order2(&customer2, &tariff2, 20.0);

    customer1.addOrder(&order1);
    customer2.addOrder(&order2);

    TaxiPark taxiPark;
    taxiPark.addCar(&car1);
    taxiPark.addCar(&car2);
    taxiPark.addDriver(&driver1);
    taxiPark.addDriver(&driver2);
    taxiPark.addCustomer(&customer1);
    taxiPark.addCustomer(&customer2);
    taxiPark.addOrder(&order1);
    taxiPark.addOrder(&order2);

    customer1.listOrders();
    driver1.drive();

    return 0;
}
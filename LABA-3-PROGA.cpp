
#include <iostream>
#include <string>

class Company {
private:
    std::string name;
public:
    Company(const std::string& companyName) : name(companyName) {}
    std::string getName() const {
        return name;
    }
};

class Employee {
private:
    std::string name;
    bool married;
    int numberOfChildren;
public:
    Employee(const std::string& employeeName, bool isMarried, int children) : name(employeeName), married(isMarried), numberOfChildren(children) {}
    std::string getName() const {
        return name;
    }
    bool isMarried() const {
        return married;
    }
    int getNumberOfChildren() const {
        return numberOfChildren;
    }
};

class Vehicle {
private:
    std::string type;
    std::string registrasionNumber;
    int year;
public:
    Vehicle(const std::string& vehicleType, int vehicleYear) : type(vehicleType), year(vehicleYear) {}
    std::string getType() const {
        return type;
    }
    int getYear() const {
        return year;
    }
};

class Truck : public Vehicle {
private:
    std::string cargoType;
    int mass;
    int capacity;
public:
    Truck(const std::string& truckType, int truckYear, const std::string& truckCargoType, int truckCapacity)
        : Vehicle(truckType, truckYear), cargoType(truckCargoType), capacity(truckCapacity) {}

    std::string getCargoType() const {
        return cargoType;
    }
    int getCapacity() const {
        return capacity;
    }
};

class Car : public Vehicle {
private:
    std::string color;
    std::string model;
    std::string transmission;
public:
    Car(const std::string& carType, int carYear, const std::string& carColor, const std::string& carModel)
        : Vehicle(carType, carYear), color(carColor), model(carModel) {}

    std::string getColor() const {
        return color;
    }
    std::string getModel() const {
        return model;
    }
};

int main() {
    Company company("MyCompany");
    Employee employee("Egor Tyrin", false, 12);
    Vehicle vehicle("Car", 1812);
    Truck truck("Truck", 862, "Cargo", 5000);
    Car car("Car", 2004, "Pink", "Horse");

    std::cout << "Company name: " << company.getName() << std::endl;
    std::cout << "Employee name: " << employee.getName() << std::endl;
    std::cout << "Employee married: " << (employee.isMarried() ? "Yes" : "No") << std::endl;
    std::cout << "Number of children: " << employee.getNumberOfChildren() << std::endl;
    std::cout << "Vehicle type: " << vehicle.getType() << std::endl;
    std::cout << "Vehicle year: " << vehicle.getYear() << std::endl;
    std::cout << "Truck type: " << truck.getType() << std::endl;
    std::cout << "Truck year: " << truck.getYear() << std::endl;
    std::cout << "Truck cargo type: " << truck.getCargoType() << std::endl;
    std::cout << "Truck capacity: " << truck.getCapacity() << std::endl;
    std::cout << "Car type: " << car.getType() << std::endl;
    std::cout << "Car year: " << car.getYear() << std::endl;
    std::cout << "Car color: " << car.getColor() << std::endl;
    std::cout << "Car model: " << car.getModel() << std::endl;

    return 0;
}
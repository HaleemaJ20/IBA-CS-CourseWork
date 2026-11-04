#include <iostream>
#include <vector>
using namespace std;

class Vehicle {
protected:
    string vehicleID;
    string brand;
    string model;
    double baseRatePerDay;
    bool isRented;

public:
    Vehicle(string id, string b, string m, double rate)
        : vehicleID(id), brand(b), model(m),
          baseRatePerDay(rate), isRented(false) {}

    virtual double calculateRentalCost(int days) = 0;
    virtual string getVehicleType() = 0;
    virtual bool requiresSpecialLicense() = 0;

    virtual void displayDetails() {
        cout << "ID: " << vehicleID
             << " | Brand: " << brand
             << " | Model: " << model
             << " | Rate/Day: $" << baseRatePerDay
             << " | Available: " << (isRented ? "No" : "Yes")
             << endl;
    }

    void rentVehicle() { isRented = true; }
    void returnVehicle() { isRented = false; }
    bool isAvailable() { return !isRented; }

    virtual ~Vehicle() {}
};

class Car : public Vehicle {
private:
    int numberOfSeats;
    bool hasSunroof;
    string fuelType;

public:
    Car(string id, string b, string m, double rate,
        int seats, bool sunroof, string fuel)
        : Vehicle(id, b, m, rate),
          numberOfSeats(seats),
          hasSunroof(sunroof),
          fuelType(fuel) {}

    double calculateRentalCost(int days) override {
        double cost = baseRatePerDay * days;

        if (hasSunroof)
            cost += cost * 0.20;

        if (fuelType == "Electric")
            cost += 10 * days;

        return cost;
    }

    void displayDetails() override {
        Vehicle::displayDetails();
        cout << "Type: Car | Seats: " << numberOfSeats
             << " | Sunroof: " << (hasSunroof ? "Yes" : "No")
             << " | Fuel: " << fuelType << endl;
    }

    string getVehicleType() override { return "Car"; }
    bool requiresSpecialLicense() override { return false; }
};

class Bike : public Vehicle {
private:
    int engineCC;
    string bikeType;

public:
    Bike(string id, string b, string m, double rate,
         int cc, string type)
        : Vehicle(id, b, m, rate),
          engineCC(cc), bikeType(type) {}

    double calculateRentalCost(int days) override {
        double cost = baseRatePerDay * days;

        if (days > 7)
            cost *= 0.5;

        if (bikeType == "Sport")
            cost += 5 * days;

        return cost;
    }

    void displayDetails() override {
        Vehicle::displayDetails();
        cout << "Type: Bike | Engine: " << engineCC
             << "cc | Category: " << bikeType << endl;
    }

    string getVehicleType() override { return "Bike"; }

    bool requiresSpecialLicense() override {
        return engineCC > 500;
    }
};

class Truck : public Vehicle {
private:
    double cargoCapacity;
    int numberOfAxles;

public:
    Truck(string id, string b, string m, double rate,
          double capacity, int axles)
        : Vehicle(id, b, m, rate),
          cargoCapacity(capacity),
          numberOfAxles(axles) {}

    double calculateRentalCost(int days) override {
        double cost = baseRatePerDay * days;
        cost += 20 * cargoCapacity * days;

        if (numberOfAxles > 2)
            cost += 50;

        return cost;
    }

    void displayDetails() override {
        Vehicle::displayDetails();
        cout << "Type: Truck | Capacity: " << cargoCapacity
             << " tons | Axles: " << numberOfAxles << endl;
    }

    string getVehicleType() override { return "Truck"; }
    bool requiresSpecialLicense() override { return true; }
};

class RentalManager {
private:
    vector<Vehicle*> fleet;

public:
    void addVehicle(Vehicle* v) {
        fleet.push_back(v);
    }

    void displayAvailableVehicles() {
        for (auto v : fleet)
            if (v->isAvailable())
                v->displayDetails();
    }

    void displayVehiclesByType(string type) {
        for (auto v : fleet)
            if (v->getVehicleType() == type)
                v->displayDetails();
    }

    double calculateTotalRevenue(int days) {
        double total = 0;
        for (auto v : fleet)
            total += v->calculateRentalCost(days);
        return total;
    }

    int countVehiclesRequiringLicense() {
        int count = 0;
        for (auto v : fleet)
            if (v->requiresSpecialLicense())
                count++;
        return count;
    }

    vector<Vehicle*>& getFleet() { return fleet; }

    ~RentalManager() {
        for (auto v : fleet)
            delete v;
    }
};

int main() {
    RentalManager manager;

    manager.addVehicle(new Car("C1","Toyota","Corolla",50,5,true,"Petrol"));
    manager.addVehicle(new Bike("B1","Yamaha","R1",40,1000,"Sport"));
    manager.addVehicle(new Truck("T1","Volvo","X200",100,5,4));

    cout << "\n--- All Available Vehicles ---\n";
    manager.displayAvailableVehicles();

    manager.getFleet()[0]->rentVehicle(); 
    manager.getFleet()[1]->rentVehicle(); 

    cout << "\n--- Available After Renting Car and Bike ---\n";
    manager.displayAvailableVehicles();

    cout << "\n--- Total Potential Revenue (1 day) --- $"
         << manager.calculateTotalRevenue(1) << endl;

    cout << "\nVehicles requiring special license: "
         << manager.countVehiclesRequiringLicense() << endl;

    manager.getFleet()[0]->returnVehicle(); 

    cout << "\n--- Available After Returning Car ---\n";
    manager.displayAvailableVehicles();

    return 0;
}

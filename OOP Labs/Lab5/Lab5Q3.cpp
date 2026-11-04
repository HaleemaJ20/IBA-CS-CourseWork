#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string make;
    string model;
    int year;

private:
    string registrationNumber;

public:
    Vehicle(string mk, string mdl, int yr, string regNum)
        : make(mk), model(mdl), year(yr), registrationNumber(regNum)
    {
        cout << "Vehicle constructor called" << endl;
    }

    void displayVehicleInfo() const {
        cout << "Make: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
        cout << "Registration: " << registrationNumber << endl;
    }

    string getRegistration() const {
        return registrationNumber;
    }

    int getAge() const {
        return 2026 - year;
    }
};

//DERIVED CLASS: CAR

class Car : public Vehicle {
private:
    int numberOfDoors;
    string fuelType;

public:
    Car(string mk, string mdl, int yr, string regNum,
        int doors, string fuel)
        : Vehicle(mk, mdl, yr, regNum),
          numberOfDoors(doors),
          fuelType(fuel)
    {
        cout << "Car constructor called" << endl;
    }

    void displayCarInfo() const {
        displayVehicleInfo();
        cout << "Number of Doors: " << numberOfDoors << endl;
        cout << "Fuel Type: " << fuelType << endl;
    }

    void displayVehicleInfo() const {
        Vehicle::displayVehicleInfo();
        cout << "Number of Doors: " << numberOfDoors << endl;
        cout << "Fuel Type: " << fuelType << endl;
    }

    string getFuelType() const {
        return fuelType;
    }
};

//DERIVED CLASS: BIKE

class Bike : public Vehicle {
private:
    string bikeType;
    int engineCC;

public:
    Bike(string mk, string mdl, int yr, string regNum,
         string type, int cc)
        : Vehicle(mk, mdl, yr, regNum),
          bikeType(type),
          engineCC(cc)
    {
        cout << "Bike constructor called" << endl;
    }

    void displayBikeInfo() const {
        displayVehicleInfo();
        cout << "Engine CC: " << engineCC << endl;
    }

    void displayVehicleInfo() const {
        Vehicle::displayVehicleInfo();
        cout << "Bike Type: " << bikeType << endl;
        cout << "Engine CC: " << engineCC << endl;
    }

    string getBikeType() const {
        return bikeType;
    }
};

//PART B: COMPILER ERROR DEMONSTRATION 

/*
* PART B: COMPILER ERROR DEMONSTRATION
*
* class BrokenCar : public Vehicle {
* private:
*     int doors;
* public:
*     BrokenCar(int d) {
*         doors = d;
*     }
* };
*
* ERROR: no matching function for call to 'Vehicle::Vehicle()'
* REASON: Base class has no default constructor
* FIX: Use initializer list to call parameterized constructor
*/

int main() {

    Car car1("Toyota", "Corolla", 2020, "ABC-123", 4, "Petrol");
    Bike bike1("Honda", "CBR500R", 2022, "XYZ-789", "Sport", 500);
    Car car2("Tesla", "Model 3", 2023, "EV-001", 4, "Electric");

    cout << "\n--- Car 1 Information ---\n" << endl;
    car1.displayCarInfo();

    cout << "\n--- Bike 1 Information ---\n" << endl;
    bike1.displayBikeInfo();

    cout << "\n--- Overridden displayVehicleInfo() ---\n" << endl;
    car1.displayVehicleInfo();
    cout << endl;
    bike1.displayVehicleInfo();

    cout << "\n--- Base Class Methods ---\n" << endl;
    cout << "Car Registration: " << car1.getRegistration() << endl;
    cout << "Car Age: " << car1.getAge() << " years" << endl;

    cout << "Bike Registration: " << bike1.getRegistration() << endl;
    cout << "Bike Age: " << bike1.getAge() << " years" << endl;

    cout << "\n--- Derived Class Specific Methods ---\n" << endl;
    cout << "Car 1 Fuel: " << car1.getFuelType() << endl;
    cout << "Car 2 Fuel: " << car2.getFuelType() << endl;
    cout << "Bike 1 Type: " << bike1.getBikeType() << endl;

    cout << "\n--- Creating More Vehicles ---\n" << endl;
    Car car3("Honda", "Civic", 2019, "HND-456", 4, "Hybrid");
    Bike bike2("Suzuki", "GSX-R1000", 2024, "SPD-111", "Sport", 1000);

    cout << "\nCar 3: " << car3.getRegistration()
         << " (" << car3.getFuelType() << ")" << endl;

    cout << "Bike 2: " << bike2.getRegistration()
         << " (" << bike2.getBikeType() << ")" << endl;

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

class BookingException : public exception {
protected:
    string message;
    string bookingRef;

public:
    BookingException(string ref, string msg) {
        bookingRef = ref;
        message = msg;
    }

    const char* what() const noexcept {
        return message.c_str();
    }

    string getBookingRef() {
        return bookingRef;
    }
};

class FlightFullException : public BookingException {
    string flightNumber;

public:
    FlightFullException(string ref, string flight)
        : BookingException(ref, "Flight " + flight + " is full. Booking ref: " + ref) {
        flightNumber = flight;
    }

    string getFlightNumber() {
        return flightNumber;
    }
};

class InvalidPassengerException : public BookingException {
    string reason;

public:
    InvalidPassengerException(string ref, string r)
        : BookingException(ref, "Invalid passenger details for booking " + ref + ": " + r) {
        reason = r;
    }

    string getReason() {
        return reason;
    }
};

class LuggageOverweightException : public BookingException {
    double actualWeight;
    double allowedWeight;

public:
    LuggageOverweightException(string ref, double actual, double allowed)
        : BookingException(ref, "Luggage overweight for booking " + ref +
                               ". Actual: " + to_string(actual) +
                               "kg, Allowed: " + to_string(allowed) + "kg") {
        actualWeight = actual;
        allowedWeight = allowed;
    }

    double getExcessWeight() {
        return actualWeight - allowedWeight;
    }
};

class FlightBookingSystem {
    string flightNumber;
    int totalSeats;
    int bookedSeats;
    double luggageLimit;

public:
    FlightBookingSystem(string f, int seats, double limit) {
        flightNumber = f;
        totalSeats = seats;
        bookedSeats = 0;
        luggageLimit = limit;
    }

    void validatePassenger(string ref, string name, int age) {
        if (name == "")
            throw InvalidPassengerException(ref, "Name cannot be empty");

        if (age < 0 || age > 120)
            throw InvalidPassengerException(ref, "Invalid age");
    }

    void checkSeatAvailability(string ref) {
        if (bookedSeats >= totalSeats)
            throw FlightFullException(ref, flightNumber);
    }

    void checkLuggage(string ref, double weight) {
        if (weight > luggageLimit)
            throw LuggageOverweightException(ref, weight, luggageLimit);
    }

    void bookFlight(string ref, string name, int age, double luggageWeight) {
        try {
            validatePassenger(ref, name, age);
            checkSeatAvailability(ref);
            checkLuggage(ref, luggageWeight);

            bookedSeats++;
            cout << "Booking " << ref << " confirmed on flight " << flightNumber << endl;
        }
        catch (BookingException& e) {
            cout << "BookingSystem: Failed booking " << ref << ": " << e.what() << endl;
            throw;
        }
    }
};

int main() {

    FlightBookingSystem system("PK101", 2, 20);

    try {
        system.bookFlight("B1", "Ali", 25, 15);
    }
    catch (BookingException& e) {}

    try {
        system.bookFlight("B2", "", 30, 10);
    }
    catch (InvalidPassengerException& e) {
        cout << "InvalidPassengerException: " << e.getReason() << endl;
    }
    catch (BookingException& e) {
        cout << e.what() << endl;
    }

    try {
        system.bookFlight("B3", "Sara", 28, 30);
    }
    catch (LuggageOverweightException& e) {
        cout << "Overweight luggage. Excess: " << e.getExcessWeight() << " kg" << endl;
    }
    catch (BookingException& e) {
        cout << e.what() << endl;
    }

    try {
        system.bookFlight("B4", "Ahmed", 40, 10);
    }
    catch (BookingException& e) {}

    try {
        system.bookFlight("B5", "Zara", 22, 10);
    }
    catch (FlightFullException& e) {
        cout << "FlightFullException on flight " << e.getFlightNumber() << endl;
    }
    catch (BookingException& e) {
        cout << e.what() << endl;
    }

    return 0;
}

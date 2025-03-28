#include <iostream>
using namespace std;

class SeatFullException {  
public:
    const char* message;
    SeatFullException(const char* msg) : message(msg) {}  
};

int main() {
    int totalSeats = 50;  
    int bookedSeats;      

    cout << "Welcome to the Seat Booking System.\n";
    cout << "Total available seats: " << totalSeats << endl;

    while (totalSeats > 0) {
        try {
            cout << "\nEnter the number of seats you want to book: ";
            cin >> bookedSeats;

            // Handle invalid input
            if (cin.fail() || bookedSeats <= 0) {
                cin.clear(); 
                cin.ignore(10000, '\n');
                cout << "Invalid input! Please enter a valid positive number.\n";
                continue;
            }

            // Check if requested seats exceed available seats
            if (bookedSeats > totalSeats) {
                throw SeatFullException("Not enough seats available! Try booking fewer seats.");
            }

            totalSeats -= bookedSeats;  
            cout << "Booking successful! Seats remaining: " << totalSeats << endl;

        } catch (SeatFullException &e) {
            cout << e.message << endl;
        }
    }

    cout << "\nAll seats are fully booked. No more seats available.\n";
    return 0;
}


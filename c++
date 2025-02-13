include <iostream>
#include <iomanip>
#include <vector>
#include <string> using namespace std;
// Constants
const int MAX_SEATS = 50;
// Structures
struct Passenger {
string name;
int age;
string address;
string contactNumber;
int trainNumber;
int seatNumber;
};
struct Train {
int number;
string name;
string source;
string destination;
int seatsAvailable;
};
// Global Variables
vector<Train> trains;
vector<Passenger> passengers;
// Function Prototypes
void displayMenu();
void addTrain();
void displayTrains();
void bookTicket();
void displayPassengers();
bool isValidTrainNumber(int);
bool isValidSeatNumber(int, int);
16
// Main Function
int main() {
int choice;
do {
displayMenu();
cin >> choice;
switch (choice) {
case 1:
addTrain();
break;
case 2:
displayTrains();
break;
case 3:
bookTicket();
break;
case 4:
displayPassengers();
break;
case 5:
cout << "Exiting program." << endl;
break;
default:
cout << "Invalid choice. Please try again." << endl;
}
} while (choice != 5);
return 0;
}
// Function Definitions
void displayMenu() {
cout << "Railway Reservation System" << endl;
cout << "1. Add train" << endl;
cout << "2. Display trains" << endl;
cout << "3. Book ticket" << endl;
cout << "4. Display passengers" << endl;
cout << "5. Exit" << endl;
cout << "Enter your choice: ";
}
void addTrain() {
Train train;
cout << "Enter train number: ";
17
cin >> train.number;
cout << "Enter train name: ";
cin.ignore();
getline(cin, train.name);
cout << "Enter source station: ";
getline(cin, train.source);
cout << "Enter destination station: ";
getline(cin, train.destination);
train.seatsAvailable = MAX_SEATS;
trains.push_back(train);
cout << "Train added successfully." << endl;
}
void displayTrains() {
if (trains.empty()) {
cout << "No trains available." << endl;
return;
}
cout << left << setw(10) << "Number"
<< left << setw(20) << "Name"
<< left << setw(20) << "Source"
<< left << setw(20) << "Destination"
<< left << setw(10) << "Seats"
<< endl;
for (int i = 0; i < trains.size(); i++) {
cout << left << setw(10) << trains[i].number
<< left << setw(20) << trains[i].name
<< left << setw(20) << trains[i].source
<< left << setw(20) << trains[i].destination
<< left << setw(10) << trains[i].seatsAvailable
<< endl;
}
}
void bookTicket() {
if (trains.empty()) {
cout << "No trains available to book tickets." << endl;
return;
}
Passenger passenger;
cout << "Enter passenger name: ";
cin.ignore();
getline(cin, passenger.name);
cout << "Enter passenger age: ";
18
cin >> passenger.age;
cout << "Enter passenger address: ";
cin.ignore();
getline(cin, passenger.address);
cout << "Enter passenger contact number: ";
getline(cin, passenger.contactNumber);
cout << "Enter train number: ";
cin >> passenger.trainNumber;
if (!isValidTrainNumber(passenger.trainNumber)) {
cout << "Invalid train number." << endl;
return;
}
cout << "Enter seat number: ";
cin >> passenger.seatNumber;
if (!isValidSeatNumber(passenger.trainNumber, passenger.seatNumber)) {
cout << "Invalid seat number." << endl;
return;
}
trains[passenger.trainNumber - 1].seatsAvailable--;
passengers.push_back(passenger);
cout << "Ticket booked successfully." << endl;
}
void displayPassengers() {
if (passengers.empty()) {
cout << "No passengers found." << endl;
return;
}
cout << left << setw(20) << "Name"
<< left << setw(10) << "Age"
<< left << setw(30) << "Address"
<< left << setw(20) << "Contact Number"
<< left << setw(10) << "Train"
<< left << setw(10) << "Seat"
<< endl;
for (int i = 0; i < passengers.size(); i++) {
cout << left << setw(20) << passengers[i].name
<< left << setw(10) << passengers[i].age
<< left << setw(30) << passengers[i].address
<< left << setw(20) << passengers[i].contactNumber
<< left << setw(10) << passengers[i].trainNumber
<< left << setw(10) << passengers[i].seatNumber
<< endl;
}
19
}
bool isValidTrainNumber(int trainNumber) {
if (trainNumber < 1 || trainNumber > trains.size()) {
return false;
}
return true;
}
bool isValidSeatNumber(int trainNumber, int seatNumber) {
if (seatNumber < 1 || seatNumber > MAX_SEATS) {
return false;
}
if (trains[trainNumber - 1].seatsAvailable < seatNumber) {
return false;
}
for (int i = 0; i < passengers.size(); i++) {
if (passengers[i].trainNumber == trainNumber && passengers[i].seatNumber ==
seatNumber) {
return false;
}
}
return true;
}

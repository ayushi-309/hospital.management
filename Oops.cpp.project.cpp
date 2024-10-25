#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// Base class for people
class Person {
public:
    string name, address, contact;

    Person(string name, string address, string contact) : name(name), address(address), contact(contact) {}

    virtual void displayInfo() = 0;
};

// Derived class for patients
class Patient : public Person {
public:
    int patientID;
    string medicalHistory;

    Patient(int patientID, string name, string address, string contact, string medicalHistory) :
        Person(name, address, contact), patientID(patientID), medicalHistory(medicalHistory) {}

    void displayInfo() override {
        cout << "Patient ID: " << patientID << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Contact: " << contact << endl;
        cout << "Medical History: " << medicalHistory << endl;
    }
};

// Derived class for doctors
class Doctor : public Person {
public:
    int doctorID;
    string specialization;

    Doctor(int doctorID, string name, string address, string contact, string specialization) :
        Person(name, address, contact), doctorID(doctorID), specialization(specialization) {}

    void displayInfo() override {
        cout << "Doctor ID: " << doctorID << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Contact: " << contact << endl;
        cout << "Specialization: " << specialization << endl;
    }
};

// Class for appointments
class Appointment {
public:
    int appointmentID;
    int patientID;
    int doctorID;
    string date;
    string time;

    Appointment(int appointmentID, int patientID, int doctorID, string date, string time) :
        appointmentID(appointmentID), patientID(patientID), doctorID(doctorID), date(date), time(time) {}
};

// Class for bills
class Bill {
public:
    int billID;
    int patientID;
    int appointmentID;
    double totalAmount;

    Bill(int billID, int patientID, int appointmentID, double totalAmount) :
        billID(billID), patientID(patientID), appointmentID(appointmentID), totalAmount(totalAmount) {}
};

// Class for inventory items
class InventoryItem {
public:
    int itemID;
    string itemName;
    int quantity;
    double price;

    InventoryItem(int itemID, string itemName, int quantity, double price) :
        itemID(itemID), itemName(itemName), quantity(quantity), price(price) {}
};

// Main function
int main() {
    // Create instances of patients, doctors, appointments, bills, and inventory items
    Patient patient1(1, "John Doe", "123 Main St", "555-1234", "Allergies: Peanuts");
    Doctor doctor1(1, "Dr. Smith", "456 Main St", "555-5678", "General Medicine");
    Appointment appointment1(1, 1, 1, "2023-12-25", "10:00 AM");
    Bill bill1(1, 1, 1, 200.0);
    InventoryItem item1(1, "Bandage", 100, 2.0);

    // Display information
    patient1.displayInfo();
    doctor1.displayInfo();
    cout << "Appointment ID: " << appointment1.appointmentID << endl;
    cout << "Bill ID: " << bill1.billID << endl;
    cout << "Total Amount: " << bill1.totalAmount << endl;
    cout << "Inventory Item ID: " << item1.itemID << endl;
    cout << "Item Name: " << item1.itemName << endl;
    cout << "Quantity: " << item1.quantity << endl;
    cout << "Price: " << item1.price << endl;

    // Save data to a file (optional)
    ofstream file("hospital_data.txt");
    file << "Patient Information:\n";
    file << patient1.patientID << "\n";
    file << patient1.name << "\n";
    file << patient1.address << "\n";
    file << patient1.contact << "\n";
    file << patient1.medicalHistory << "\n";
    // ... (save other data)
    file.close();

    return 0;
}

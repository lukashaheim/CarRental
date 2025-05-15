#include "functions/addCustomer.h"
#include <iostream>

using namespace std;

void addCustomer(SQLite::Database& db) {
    string name, phoneNumber, email;

    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter phone number: ";
    getline(cin, phoneNumber);
    cout << "Enter email: ";
    getline(cin, email);

    SQLite::Statement query(db, "INSERT INTO Customers (name, phone_number, email) VALUES (?, ?, ?)");
    query.bind(1, name);
    query.bind(2, phoneNumber);
    query.bind(3, email);
    query.exec();

    int id = static_cast<int>(db.getLastInsertRowid());
    cout << "Added customer: id: " << id
         << ", name: " << name
         << ", phone number: " << phoneNumber
         << ", email: " << email << "\n";
}
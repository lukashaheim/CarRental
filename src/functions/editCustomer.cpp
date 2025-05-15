#include "functions/editCustomer.h"
#include <iostream>

using namespace std;

void editCustomer(SQLite::Database& db) {
    int id;
    string name, phoneNumber, email;

    cout << "Enter customer id: ";
    cin >> id;

    SQLite::Statement checkQuery(db, "SELECT COUNT(*) FROM Customers WHERE id = ?");
    checkQuery.bind(1, id);
    checkQuery.executeStep();
    if (checkQuery.getColumn(0).getInt() == 0) {
        cout << "Customer not found\n";
        return;
    }

    cin.ignore();
    cout << "Enter new name: ";
    getline(cin, name);
    cout << "Enter new phone number: ";
    getline(cin, phoneNumber);
    cout << "Enter new email: ";
    getline(cin, email);

    SQLite::Statement query(db, "UPDATE Customers SET name = ?, phone_number = ?, email = ? WHERE id = ?");
    query.bind(1, name);
    query.bind(2, phoneNumber);
    query.bind(3, email);
    query.bind(4, id);
    query.exec();

    if (db.getChanges() > 0) {
        cout << "Customer was changed succesfully\n";
    } else {
        cout << "Customer was not found or not changed\n";
    }

}
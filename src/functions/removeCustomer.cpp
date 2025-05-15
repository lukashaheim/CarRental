#include "functions/removeCustomer.h"
#include <iostream>

using namespace std;

void removeCustomer(SQLite::Database& db) {
    int id;

    cout << "Enter customer id: ";
    cin >> id;

    SQLite::Statement query(db, "DELETE FROM Customers WHERE id = ?");
    query.bind(1, id);
    query.exec();

    if (db.getChanges() > 0) {
        cout << "Customer was deleted succesfully\n";
    } else {
        cout << "Customer was not found or not deleted\n";
    }
}
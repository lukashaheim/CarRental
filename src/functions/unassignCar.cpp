#include "functions/unassignCar.h"
#include <iostream>
#include <SQLiteCpp/SQLiteCpp.h>
using namespace std;

void unassignCar(SQLite::Database& db) {
    string carID, yn;
    cout << "Please enter the car ID you want to unassign: ";
    cin >> carID;

    SQLite::Statement nameQuery (
        db,
        "SELECT * FROM Rentals WHERE car_id = ?");
    nameQuery.bind(1, carID);

    string customerName;
    if (nameQuery.executeStep()) {
        customerName = nameQuery.getColumn(0).getString();
        cout << "That car is currently assigned to: " << customerName << endl;
    } else {
        cout << "No assignment found" << endl;
        return;
    }

    cout << "do you still want to unassign the var: (yes/no)";
    cin >> yn;

    if (yn != "yes") {
        cout << "Aborted.\n" << endl;
        return;
    }

    try {
        SQLite::Statement delQ(
            db, "DELETE FROM Rentals WHERE car_id = ?");
        delQ.bind(1, carID);
        delQ.exec();
        cout << "Car: " << carID << " has been unassigned from: " << customerName << endl;
    }
    catch (const exception& e) {
        cerr << "Failed to unassign car: " << e.what() << endl;
    }
}
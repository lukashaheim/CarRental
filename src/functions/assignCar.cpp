#include "../../include/functions/assignCar.h"
#include <iostream>
#include <SQLiteCpp/SQLiteCpp.h>

#include "functions/searchcar.h"
#include "functions/searchcustomer.h"
using namespace std;

void assignCar(SQLite::Database& db, string end_date, string start_date) {
    string carID, customerID, startDate, endDate;

    cout << "Enter Car ID or 0 to search: ";
    getline(cin, carID);

    if (carID == "0") {
        carID = searchCar(db);
    }

    {
        SQLite::Statement checkCars(db, "SELECT * FROM Cars WHERE id = ?");
        checkCars.bind(1, carID);
        if (!checkCars.executeStep() || checkCars.getColumn(0).getInt() == 0) {
            cerr << "Car does not exist" << endl;
            return;
        }
    }

    cout << "Enter customer ID or 0 to search: ";
    getline(cin, customerID);

    if (customerID == "0") {
        customerID = searchCustomer(db);
    }

    {
        SQLite::Statement CheckCustomers(db, "SELECT COUNT(*) FROM Customers WHERE id = ?");
        CheckCustomers.bind(1, customerID);
        if (!CheckCustomers.executeStep() || CheckCustomers.getColumn(0).getInt() == 0) {
            cerr << "Customer does not exist" << endl;
            return;
        }
    }

    cout << "Enter start date: " << endl;
    cin >> startDate;
    cout << "Enter end date: " << endl;
    cin >> endDate;

    SQLite::Statement query(db, "INSERT INTO Rentals (car_id, customer_id, start_date, end_date) VALUES (?, ?, ?, ?)");
    query.bind(1, carID);
    query.bind(2, customerID);
    query.bind(3, startDate);
    query.bind(4, endDate);
    query.exec();

    cout << "Car assigned" << endl;

}
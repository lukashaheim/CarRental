#include "functions/searchcustomer.h"
#include <iostream>
#include <SQLiteCpp/SQLiteCpp.h>
using namespace std;

int searchCustomer(SQLite::Database &db)  {
    int choice;
    string searchType;
    string searchString;

    cout << "Enter choice: \n"
    << "1. Name\n"
    << "2. Phone number\n"
    << "3. Email" << endl;
    cin >> choice;
    cin.ignore();

    switch (choice) {
        case 1:
            cout << "Enter name: ";
            searchType = "name";
            break;

        case 2:
            cout << "Enter phone number: ";
            searchType = "phone_number";
            break;

        case 3:
            cout << "Enter email: ";
            searchType = "email";
            break;
        default:
            cout << "No valid choice, Exiting...";
            return -1;
    }

    getline(cin, searchString);


    bool found = false;

    try {
        string query = "SELECT * FROM Customers WHERE " + searchType + " = ?";
        SQLite::Statement nameQuery (db, query);
        nameQuery.bind(1, searchString);

        while (nameQuery.executeStep()) {
            found = true;
            int CustomerID = nameQuery.getColumn(0);


            cout << "Customer ID: " << CustomerID << ", "
                 << "Name: " << nameQuery.getColumn(1) << ", "
                 << "Phone number: " << nameQuery.getColumn(2) << ", "
                 << "Email " << nameQuery.getColumn(3) << endl;


            char answer = ' ';

            while (answer != 'y' && answer != 'n') {
                cout << "Use this record? (y/n): ";
                cin >> answer;
                if (answer == 'y') {
                    return CustomerID;
                }
                if (answer == 'n') {
                    //it does nothing :)
                }
            }

        }

        if (!found) {
            cout << "No records found. Exiting...";
            return -1;
        }
        else {
            cout << "No more records. Exiting...";
            return -1;
        }
    }
    catch (const std::exception& e) {
        cerr << "Error: " << e.what() << endl;
        return -1;
    }
}

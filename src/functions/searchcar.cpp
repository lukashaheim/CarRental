#include "functions/searchcar.h"
#include <iostream>
#include <SQLiteCpp/SQLiteCpp.h>
using namespace std;


int searchCar(SQLite::Database &db) {
    int choice;
    string searchType;
    string searchString;

    cout << "Enter choice:\n"
    << "1. registration number \n"
    << "2. Brand \n"
    << "3. Model \n" << endl;
    cin >> choice;
    cin.ignore();

    switch (choice) {
        case 1:
            cout << "Enter registration number: ";
            searchType = "registration";
            break;

        case 2:
            cout << "Enter brand: ";
            searchType = "brand";
            break;

        case 3:
            cout << "Enter model: ";
            searchType = "model";
            break;
        default:
            cout << "No valid choice, Exiting...";
            return -1;
    }

    getline(cin, searchString);


    bool found = false;

    try {
        string query = "SELECT * FROM Cars WHERE " + searchType + " = ?";
        SQLite::Statement nameQuery (db, query);
        nameQuery.bind(1, searchString);

        while (nameQuery.executeStep()) {
            found = true;
            int carID = nameQuery.getColumn(0);

            cout << "Car ID: " << carID << ", "
                 << "Registration number: " << nameQuery.getColumn(1) << ", "
                 << "Brand: " << nameQuery.getColumn(2) << ", "
                 << "Model: " << nameQuery.getColumn(3) << endl;


            char answer = ' ';

            while (answer != 'y' && answer != 'n') {
                cout << "Use this record? (y/n): ";
                cin >> answer;
                if (answer == 'y') {
                    return carID;
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


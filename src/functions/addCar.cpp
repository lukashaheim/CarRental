#include "../../include/functions/addCar.h"
#include <iostream>
#include <SQLiteCpp/SQLiteCpp.h>
using namespace std;

void addCar(SQLite::Database& db) {
    string registration, brand, model;
    cout << "Enter registration number: ";
    getline(cin, registration);
    cout << "Enter brand: ";
    getline(cin, brand);
    cout << "Enter model: ";
    getline(cin, model);

    SQLite::Statement query(db, "INSERT INTO Cars (registration, brand, model) VALUES (?, ?, ?)");
    query.bind(1, registration);
    query.bind(2, brand);
    query.bind(3, model);
    query.exec();

    cout << "Car added!\n";
}

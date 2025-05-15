#include "functions/editCar.h"
#include <iostream>
#include <string>

void editCar(SQLite::Database& db) {
    int id;
    std::string registration, brand, model;

    std::cout << "Enter car id: ";
    std::cin >> id;

    SQLite::Statement checkQuery(db, "SELECT COUNT(*) FROM Cars WHERE id = ?");
    checkQuery.bind(1, id);
    checkQuery.executeStep();
    if (checkQuery.getColumn(0).getInt() == 0) {
        std::cout << "Car not found\n";
        return;
    }

    std::cin.ignore();
    std::cout << "Enter new registration number: ";
    std::getline(std::cin, registration);
    std::cout << "Enter new brand: ";
    std::getline(std::cin, brand);
    std::cout << "Enter new model: ";
    std::getline(std::cin, model);

    SQLite::Statement query(db, "UPDATE Cars SET registration = ?, brand = ?, model = ? WHERE id = ?");
    query.bind(1, registration);
    query.bind(2, brand);
    query.bind(3, model);
    query.bind(4, id);
    query.exec();

    if (db.getChanges() > 0) {
        std::cout << "Car was changed successfully\n";
    } else {
        std::cout << "Car was not found or not changed\n";
    }
}

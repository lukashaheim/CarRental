#include "functions/removeCar.h"
#include <iostream>

void removeCar(SQLite::Database& db) {
    int id;
    std::cout << "Enter car id: ";
    std::cin >> id;

    SQLite::Statement query(db, "DELETE FROM Cars WHERE id = ?");
    query.bind(1, id);
    query.exec();

    if (db.getChanges() > 0) {
        std::cout << "Car was deleted succesfully\n";
    } else {
        std::cout << "Car was not found or not deleted\n";
    }
}

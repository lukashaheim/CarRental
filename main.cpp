#include <iostream>
#include <string>
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

    int id = static_cast<int>(db.getLastInsertRowid());
    cout << "Added car: id: " << id
         << ", registration: " << registration
         << ", brand: " << brand
         << ", model: " << model << "\n";
}

int main() {
    try {
        SQLite::Database db("../CarRentalNew.sqlite", SQLite::OPEN_READWRITE);
        addCar(db);
    } catch (const std::exception& e) {
        cerr << "Database error: " << e.what() << endl;
        return 1;
    }

    return 0;
}

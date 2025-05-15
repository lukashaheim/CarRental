#include <iostream>
#include <string>
#include <SQLiteCpp/SQLiteCpp.h>

using namespace std;

void showMenu() {
    cout << "\nMenu:\n"
         << "1. Add cars\n"
         << "2. Edit cars\n"
         << "3. Remove cars\n"
         << "4. Add customer\n"
         << "5. Edit customer\n"
         << "6. Remove customer\n"
         << "7. Exit\n"
         << "Choice: ";
}

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

void editCar(SQLite::Database& db) {
    int id;
    string registration, brand, model;

    cout << "Enter car id: ";
    cin >> id;

    SQLite::Statement checkQuery(db, "SELECT COUNT(*) FROM Cars WHERE id = ?");
    checkQuery.bind(1, id);
    checkQuery.executeStep();
    if (checkQuery.getColumn(0).getInt() == 0) {
        cout << "Car not found\n";
        return;
    }

    cin.ignore();
    cout << "Enter new registration number: ";
    getline(cin, registration);
    cout << "Enter new brand: ";
    getline(cin, brand);
    cout << "Enter new model: ";
    getline(cin, model);

    SQLite::Statement query(db, "UPDATE Cars SET registration = ?, brand = ?, model = ? WHERE id = ?");
    query.bind(1, registration);
    query.bind(2, brand);
    query.bind(3, model);
    query.bind(4, id);
    query.exec();

    if (db.getChanges() > 0) {
        cout << "Car was changed succesfully\n";
    } else {
        cout << "Car was not found or not changed\n";
    }

}

void removeCar(SQLite::Database& db) {
    int id;

    cout << "Enter car id: ";
    cin >> id;

    SQLite::Statement query(db, "DELETE FROM Cars WHERE id = ?");
    query.bind(1, id);
    query.exec();

    if (db.getChanges() > 0) {
        cout << "Car was deleted succesfully\n";
    } else {
        cout << "Car was not found or not deleted\n";
    }
}

void addCustomer(SQLite::Database& db) {
    string name, phoneNumber, email;

    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter phone number: ";
    getline(cin, phoneNumber);
    cout << "Enter email: ";
    getline(cin, email);

    SQLite::Statement query(db, "INSERT INTO Customers (name, phone_number, email) VALUES (?, ?, ?)");
    query.bind(1, name);
    query.bind(2, phoneNumber);
    query.bind(3, email);
    query.exec();

    int id = static_cast<int>(db.getLastInsertRowid());
    cout << "Added customer: id: " << id
         << ", name: " << name
         << ", phone number: " << phoneNumber
         << ", email: " << email << "\n";
}

int main() {
    try {
        SQLite::Database db("../CarRental.sqlite", SQLite::OPEN_READWRITE);


        int choice;
        while (true) {
            showMenu();
            cin >> choice;
            cin.ignore();

            switch (choice) {
                case 1: addCar(db);
                    break;
                case 2: editCar(db);
                    break;
                case 3: removeCar(db);
                    break;
                case 4: addCustomer(db);
                    break;
                case 7:
                    cout << "Bye!\n";
                    return 0;
                default:
                    cout << "Invalid choice\n";
            }
        }
    } catch (const std::exception& e) {
        cerr << "Database error: " << e.what() << endl;
        return 1;
    }


    return 0;
}

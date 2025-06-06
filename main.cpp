#include <iostream>
#include <string>
#include <SQLiteCpp/SQLiteCpp.h>
#include "include/models/Car.h"
#include "functions/addCar.h"
#include "functions/editCar.h"
#include "functions/removeCar.h"
#include "functions/addCustomer.h"
#include "functions/editCustomer.h"
#include "functions/removeCustomer.h"


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
                case 5: editCustomer(db);
                    break;
                case 6: removeCustomer(db);
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

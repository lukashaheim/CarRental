#ifndef EDITCAR_H
#define EDITCAR_H

#include <SQLiteCpp/SQLiteCpp.h>

void editCar(SQLite::Database& db);
bool editCar_check(SQLite::Database& db, int id);
bool editCar_change(SQLite::Database& db, int id, std::string registration, std::string brand, std::string model);

#endif //EDITCAR_H

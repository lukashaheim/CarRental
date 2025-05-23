#ifndef ASSIGNCAR_H
#define ASSIGNCAR_H

#pragma once
#include <SQLiteCpp/SQLiteCpp.h>

void assignCar(SQLite::Database& db, std::string end_date, std::string start_date);

#endif

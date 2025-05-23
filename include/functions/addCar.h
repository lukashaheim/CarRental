#ifndef ADDCAR_H
#define ADDCAR_H

#pragma once
#include <SQLiteCpp/SQLiteCpp.h>
#include <string>

void addCar(SQLite::Database& db, const std::string& registration, const std::string& brand, const std::string& model);


#endif

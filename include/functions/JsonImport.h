#ifndef JSONIMPORT_H
#define JSONIMPORT_H

#include <SQLiteCpp/SQLiteCpp.h>

void JsonImport(SQLite::Database& db, const std::string& filename);

#endif

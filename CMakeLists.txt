cmake_minimum_required(VERSION 3.30)
project(CarRental)

set(CMAKE_CXX_STANDARD 17)

add_library(sqlite3 sqlite3/sqlite3.c)
target_include_directories(sqlite3 PUBLIC sqlite3)

add_library(sqlitecpp
        sqlitecpp/src/Backup.cpp
        sqlitecpp/src/Column.cpp
        sqlitecpp/src/Database.cpp
        sqlitecpp/src/Exception.cpp
        sqlitecpp/src/Savepoint.cpp
        sqlitecpp/src/Statement.cpp
        sqlitecpp/src/Transaction.cpp
)

target_include_directories(sqlitecpp PUBLIC sqlitecpp/include)
target_link_libraries(sqlitecpp sqlite3)

add_executable(CarRental main.cpp)
target_link_libraries(CarRental sqlite3 sqlitecpp)



cmake_minimum_required(VERSION 3.30)
project(CarRental)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED IMPORTED_TARGET gtkmm-4.0)

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

add_executable(CarRental
        main.cpp
        src/models/Car.cpp
        src/functions/addCar.cpp
        include/functions/editCar.h
        src/functions/editCar.cpp
        src/functions/removeCar.cpp
        include/functions/removeCar.h
        include/functions/addCustomer.h
        include/functions/editCustomer.h
        include/functions/removeCustomer.h
        src/functions/addCustomer.cpp
        src/functions/editCustomer.cpp
        src/functions/removeCustomer.cpp
        src/views/main_menu.cpp
        src/views/main_menu.h
        src/views/car/car_menu.cpp
        src/views/car/car_menu.h
        src/views/car/add_car_page.cpp
        src/views/car/add_car_page.h
        src/views/car/edit_car_page.cpp
        src/views/car/edit_car_page.h
)

target_include_directories(CarRental PRIVATE include)
target_link_libraries(CarRental sqlite3 sqlitecpp PkgConfig::GTKMM)



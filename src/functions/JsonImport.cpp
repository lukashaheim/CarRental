#include <iostream>
#include <fstream>
#include <sstream>
#include <SQLiteCpp/SQLiteCpp.h>
#include "functions/JsonImport.h"
#include "rapidjson/document.h"

void JsonImport(SQLite::Database& db, const std::string& filename) {
    std::ifstream file(filename);

    //Hvis filen ikke åpnes, så returneres det en melding som sier at filen ikke kunne åpnes
    if (!file.is_open())
    {
        std::cout << "Failed to open file" << std::endl;
        return;
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();

    std::string jsonStr = buffer.str();

    //parser dokumentet, om parsen skulle feile, så returneres det en melding som sier at det feilet
    rapidjson::Document doc;
    if (doc.Parse(jsonStr.c_str()).HasParseError())
    {
        std::cerr << "Error parsing JSON" << std::endl;
        return;
    }

        //Først sjekker om dokumentet har "cars", deretter sjekker den om det er et array
        //Hvis det er et array, så går det gjennom alle elementene i arrayet og legger det til i databasen
        if (doc.HasMember("cars") && doc["cars"].IsArray()) {
            for (const rapidjson::Value& car : doc["cars"].GetArray()) {

                    //sql spørring
                    SQLite::Statement query(db,
                    "UPDATE Cars SET registration = ?, brand = ?, model = ?, available = ? WHERE id = ?");

                if (car.HasMember("registration") && car["registration"].IsString()) {
                    query.bind(1, car["registration"].GetString());
                }
                if (car.HasMember("brand") && car["brand"].IsString()) {
                    query.bind(2, car["brand"].GetString());
                }
                if (car.HasMember("model") && car["model"].IsString()) {
                    query.bind(3, car["model"].GetString());
                }
                if (car.HasMember("available") && car["available"].IsInt()) {
                    query.bind(4, car["available"].GetInt());
                }
                if (car.HasMember("id") && car["id"].IsInt()) {
                    query.bind(5, car["id"].GetInt());
                }
                    query.exec();
                }
            }

        //Først sjekker om dokumentet har "customer", deretter sjekker den om det er et array
        //Hvis det er et array, så går det gjennom alle elementene i arrayet og legger det til i databasen
        if (doc.HasMember("customers") && doc["customers"].IsArray()) {
            for (const rapidjson::Value& customer : doc["customers"].GetArray()) {

                //sql spørring
                    SQLite::Statement query2(db,
                    "UPDATE Customers SET name = ?, phone_number = ?, email = ? WHERE id = ?");

                if (customer.HasMember("name") && customer["name"].IsString()) {
                    query2.bind(1, customer["name"].GetString());
                }
                if (customer.HasMember("phone_number") && customer["phone_number"].IsString()) {
                    query2.bind(2, customer["phone_number"].GetString());
                }
                if (customer.HasMember("email") && customer["email"].IsString()) {
                    query2.bind(3, customer["email"].GetString());
                }
                if (customer.HasMember("id") && customer["id"].IsInt()) {
                    query2.bind(4, customer["id"].GetInt());
                }
                    query2.exec();
                }
            }
        //Først sjekker om dokumentet har "rentals", deretter sjekker den om det er et array
        //Hvis det er et array, så går det gjennom alle elementene i arrayet og legger det til i databasen
        if (doc.HasMember("rentals") && doc["rentals"].IsArray()) {
            for (const rapidjson::Value& rental : doc["rentals"].GetArray()) {

                //sql spørring
                SQLite::Statement query3(db,
                "UPDATE Rentals SET customer_id = ?, car_id = ?, start_date = ?, end_date = ? WHERE id = ?");

                if (rental.HasMember("customer_id") && rental["customer_id"].IsInt()) {
                    query3.bind(1, rental["customer_id"].GetInt());
                }
                if (rental.HasMember("car_id") && rental["car_id"].IsInt()) {
                    query3.bind(2, rental["car_id"].GetInt());
                }
                if (rental.HasMember("start_date") && rental["start_date"].IsString()) {
                    query3.bind(3, rental["start_date"].GetString());
                }
                if (rental.HasMember("end_date") && rental["end_date"].IsString()) {
                    query3.bind(4, rental["end_date"].GetString());
                }
                if (rental.HasMember("id") && rental["id"].IsInt()) {
                    query3.bind(5, rental["id"].GetInt());
                }
                query3.exec();
            }
        }
    std::cout << "Json file imported successfully" << std::endl;
}


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

    //En løkke som leser igjennom hvert element i arrayet
    for (rapidjson::SizeType i = 0; i < doc.Size(); i++) {
        const auto& userfile = doc[i];

        //Hvis Json filen har disse verdiene, legger den det til i databasen
        if (userfile.HasMember("carid") && userfile.HasMember("registration") && userfile.HasMember("brand") && userfile.HasMember("model") && userfile.HasMember("available") &&
            userfile.HasMember("customersid") && userfile.HasMember("name") && userfile.HasMember("phone_number") && userfile.HasMember("email") &&
            userfile.HasMember("rentalsid") && userfile.HasMember("start_date") && userfile.HasMember("end_date")) {
            std::cout << "Importing file" << std::endl;

            //SQL spørringer som legger inn informasjonen i databasen i de ulike tabellene
            SQLite::Statement query(db,
            "UPDATE Cars SET car_id = ?, registration = ?, brand = ?, model = ?, available = ? WHERE id = ?");
            query.bind(1, userfile["carid"].GetInt());
            query.bind(2, userfile["registration"].GetString());
            query.bind(3, userfile["brand"].GetString());
            query.bind(4, userfile["model"].GetString());
            query.bind(5, userfile["available"].GetBool());
            query.exec();

            SQLite::Statement query2(db,
            "UPDATE Customers SET customer_id = ?, name = ?, phone_number = ?, email = ? WHERE id = ?");
            query2.bind(1, userfile["customerid"].GetInt());
            query2.bind(2, userfile["name"].GetString());
            query2.bind(3, userfile["phone_number"].GetString());
            query2.bind(4, userfile["email"].GetString());
            query2.exec();

            SQLite::Statement query3(db,
            "UPDATE Rentals SET rental_id = ?, car_id = ?, customer_id = ?, rental_date = ?, return_date = ? WHERE id = ?");
            query3.bind(1, userfile["rentalid"].GetInt());
            query3.bind(2, userfile["carid"].GetInt());
            query3.bind(3, userfile["customerid"].GetInt());
            query3.bind(4, userfile["start_date"].GetString());
            query3.bind(5, userfile["end_date"].GetString());
            query3.exec();
        }
    }
}

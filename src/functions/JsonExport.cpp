#include <iostream>
#include <fstream>
#include <sstream>
#include <SQLiteCpp/SQLiteCpp.h>
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"
#include "functions/JsonExport.h"

void JsonExport(SQLite::Database& db) {
    rapidjson::Document doc;
    //Lager et object i JSON filen
    doc.SetObject();

    //Lager array for cars, customers, rentals i JSON Filen
    rapidjson::Value cars(rapidjson::kArrayType);
    rapidjson::Value customers(rapidjson::kArrayType);
    rapidjson::Value rentals(rapidjson::kArrayType);

    //Lager en statement for å hente alle data fra databasen
    SQLite::Statement query(db, "SELECT * FROM Cars");
    SQLite::Statement query2(db, "SELECT * FROM Customers");
    SQLite::Statement query3(db, "SELECT * FROM Rentals");

    while (query.executeStep()) {
        rapidjson::Value car(rapidjson::kObjectType);
        car.AddMember("id", query.getColumn("id").getInt(), doc.GetAllocator());

        rapidjson::Value registration(query.getColumn("registration").getText(), doc.GetAllocator());;
        car.AddMember("registration", registration, doc.GetAllocator());
        rapidjson::Value brand(query.getColumn("brand").getText(), doc.GetAllocator());
        car.AddMember("brand", brand, doc.GetAllocator());
        rapidjson::Value model(query.getColumn("model").getText(), doc.GetAllocator());
        car.AddMember("model", model, doc.GetAllocator());
        rapidjson::Value available(query.getColumn("available").getInt());
        car.AddMember("available", available, doc.GetAllocator());

        cars.PushBack(car, doc.GetAllocator());
    }
    doc.AddMember("cars", cars, doc.GetAllocator());

    while (query2.executeStep()) {
        rapidjson::Value customer(rapidjson::kObjectType);
        customer.AddMember("id", query2.getColumn("id").getInt(), doc.GetAllocator());

        rapidjson::Value name(query2.getColumn("name").getText(), doc.GetAllocator());
        customer.AddMember("name", name, doc.GetAllocator());
        rapidjson::Value phone_number(query2.getColumn("phone_number").getInt());
        customer.AddMember("phone_number", phone_number, doc.GetAllocator());
        rapidjson::Value email(query2.getColumn("email").getText(), doc.GetAllocator());
        customer.AddMember("email", email, doc.GetAllocator());

        customers.PushBack(customer, doc.GetAllocator());
    }
    doc.AddMember("customers", customers, doc.GetAllocator());

    while (query3.executeStep()) {
        rapidjson::Value rental(rapidjson::kObjectType);
        rental.AddMember("id", query3.getColumn("id").getInt(), doc.GetAllocator());

        rapidjson::Value customerid(query3.getColumn("customer_id").getInt());
        rental.AddMember("customer_id", customerid, doc.GetAllocator());
        rapidjson::Value carid(query3.getColumn("car_id").getInt());
        rental.AddMember("car_id", carid, doc.GetAllocator());
        rapidjson::Value start_date(query3.getColumn("start_date").getText(), doc.GetAllocator());
        rental.AddMember("start_date", start_date, doc.GetAllocator());
        rapidjson::Value end_date(query3.getColumn("end_date").getText(), doc.GetAllocator());
        rental.AddMember("end_date", end_date, doc.GetAllocator());


        rentals.PushBack(rental, doc.GetAllocator());
    }
    doc.AddMember("rentals", rentals, doc.GetAllocator());

    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    doc.Accept(writer);

    std::ofstream file("backup.json");
    std::cout << "backup file created" << std::endl;
    file << buffer.GetString();
    file.close();
}
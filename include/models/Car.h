#pragma once
#include <string>

class Car {
public:
	Car(int id, const std::string& registration, const std::string& brand, const std::string& model);

	int get_id() const;

	std::string getRegistration() const;
	std::string getBrand() const;
	std::string getModel() const;

	void setRegistration(const std::string& r);
	void setBrand(const std::string& b);
	void setModel(const std::string& m);

private:
	int id;
	std::string registration;
	std::string brand;
	std::string model;
};

#include "models/Car.h"


Car::Car(int id, const std::string& registration, const std::string& brand, const std::string& model)
	: id(id), registration(registration), brand(brand), model(model) {}

int Car::get_id() const {
	return id;
}

std::string Car::getRegistration() const {
	return registration;
}

std::string Car::getBrand() const {
	return brand;
}

std::string Car::getModel() const {
	return model;
}

void Car::setRegistration(const std::string& r) {
	registration = r;
}

void Car::setBrand(const std::string& b) {
	brand = b;
}

void Car::setModel(const std::string& m) {
	model = m;
}

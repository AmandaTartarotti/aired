
#include <utility>

#include "../header/Airline.h"

Airline::Airline(string code, string name, string callSign, string country) {
    this->code = std::move(code);
    this->name = std::move(name);
    this->callSign = std::move(callSign);
    this->country = std::move(country);
}

string Airline::getCode() {
    return code;
}

string Airline::getName() {
    return name;
}

string Airline::getCallSign() {
    return callSign;
}

string Airline::getCountry() {
    return country;
}


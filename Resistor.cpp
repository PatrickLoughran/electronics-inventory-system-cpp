#include "Resistor.h"
#include <iostream>
using namespace std;

/**
 * @brief Creates a resistor using both shared and resistor-specific fields.
 */
Resistor::Resistor(string name, string manufacturer, int quantity,
                   double resistance, double tolerance, double powerRating, double pitch)
    : Component(name, manufacturer, quantity) {
    this->resistance = resistance;
    this->tolerance = tolerance;
    this->powerRating = powerRating;
    this->pitch = pitch;
}

/** @brief Gets the resistance value. @return Resistance in ohms. */
double Resistor::getResistance() const {
    return resistance;
}

/** @brief Gets the resistor tolerance. @return Tolerance percentage. */
double Resistor::getTolerance() const {
    return tolerance;
}

/** @brief Gets the power rating. @return Power rating in watts. */
double Resistor::getPowerRating() const {
    return powerRating;
}

/** @brief Gets the resistor pin pitch. @return Pitch in millimetres. */
double Resistor::getPitch() const {
    return pitch;
}

/**
 * @brief Displays formatted resistor information to the console.
 */
void Resistor::display() const {
    cout << "Type: Resistor" << endl;
    cout << "Name: " << name << endl;
    cout << "Manufacturer: " << manufacturer << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Resistance: " << resistance << " Ohms" << endl;
    cout << "Tolerance: " << tolerance << "%" << endl;
    cout << "Power Rating: " << powerRating << " W" << endl;
    cout << "Pitch: " << pitch << " mm" << endl;
}

/** @brief Gets the component type. @return "Resistor". */
string Resistor::getType() const {
    return "Resistor";
}

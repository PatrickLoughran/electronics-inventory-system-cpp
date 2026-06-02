#include "Capacitor.h"
#include <iostream>
using namespace std;

/**
 * @brief Creates a capacitor using shared and capacitor-specific fields.
 */
Capacitor::Capacitor(string name, string manufacturer, int quantity,
                     double capacitance, double tolerance, double voltageRating,
                     double pitch, string capacitorType)
    : Component(name, manufacturer, quantity) {
    this->capacitance = capacitance;
    this->tolerance = tolerance;
    this->voltageRating = voltageRating;
    this->pitch = pitch;
    this->capacitorType = capacitorType;
}

/** @brief Gets the capacitance. @return Capacitance in microfarads. */
double Capacitor::getCapacitance() const {
    return capacitance;
}

/** @brief Gets the capacitor tolerance. @return Tolerance percentage. */
double Capacitor::getTolerance() const {
    return tolerance;
}

/** @brief Gets the voltage rating. @return Voltage rating in volts. */
double Capacitor::getVoltageRating() const {
    return voltageRating;
}

/** @brief Gets the capacitor pin pitch. @return Pitch in millimetres. */
double Capacitor::getPitch() const {
    return pitch;
}

/** @brief Gets the capacitor type. @return Capacitor type text. */
string Capacitor::getCapacitorType() const {
    return capacitorType;
}

/**
 * @brief Displays formatted capacitor information to the console.
 */
void Capacitor::display() const {
    cout << "Type: Capacitor" << endl;
    cout << "Name: " << name << endl;
    cout << "Manufacturer: " << manufacturer << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Capacitance: " << capacitance << " uF" << endl;
    cout << "Tolerance: " << tolerance << "%" << endl;
    cout << "Voltage Rating: " << voltageRating << " V" << endl;
    cout << "Pitch: " << pitch << " mm" << endl;
    cout << "Capacitor Type: " << capacitorType << endl;
}

/** @brief Gets the component type. @return "Capacitor". */
string Capacitor::getType() const {
    return "Capacitor";
}

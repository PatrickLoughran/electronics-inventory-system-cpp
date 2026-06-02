#include "Inductor.h"
#include <iostream>
using namespace std;

/**
 * @brief Creates an inductor using shared and inductor-specific fields.
 */
Inductor::Inductor(string name, string manufacturer, int quantity,
                   double inductance, double tolerance, double currentRating,
                   double dcResistance, double pitch, string coreMaterial)
    : Component(name, manufacturer, quantity) {
    this->inductance = inductance;
    this->tolerance = tolerance;
    this->currentRating = currentRating;
    this->dcResistance = dcResistance;
    this->pitch = pitch;
    this->coreMaterial = coreMaterial;
}

/** @brief Gets the inductance. @return Inductance in millihenries. */
double Inductor::getInductance() const {
    return inductance;
}

/** @brief Gets the inductor tolerance. @return Tolerance percentage. */
double Inductor::getTolerance() const {
    return tolerance;
}

/** @brief Gets the current rating. @return Current rating in amps. */
double Inductor::getCurrentRating() const {
    return currentRating;
}

/** @brief Gets the DC resistance. @return DC resistance in ohms. */
double Inductor::getDcResistance() const {
    return dcResistance;
}

/** @brief Gets the inductor pin pitch. @return Pitch in millimetres. */
double Inductor::getPitch() const {
    return pitch;
}

/** @brief Gets the core material. @return Core material text. */
string Inductor::getCoreMaterial() const {
    return coreMaterial;
}

/**
 * @brief Displays formatted inductor information to the console.
 */
void Inductor::display() const {
    cout << "Type: Inductor" << endl;
    cout << "Name: " << name << endl;
    cout << "Manufacturer: " << manufacturer << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Inductance: " << inductance << " mH" << endl;
    cout << "Tolerance: " << tolerance << "%" << endl;
    cout << "Current Rating: " << currentRating << " A" << endl;
    cout << "DC Resistance: " << dcResistance << " Ohms" << endl;
    cout << "Pitch: " << pitch << " mm" << endl;
    cout << "Core Material: " << coreMaterial << endl;
}

/** @brief Gets the component type. @return "Inductor". */
string Inductor::getType() const {
    return "Inductor";
}

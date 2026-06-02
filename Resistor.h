#ifndef RESISTOR_H
#define RESISTOR_H

#include "Component.h"

/**
 * @class Resistor
 * @brief Represents a resistor component in the inventory.
 *
 * Stores resistor-specific details including resistance, tolerance, power
 * rating, and pin pitch.
 *
 * @author Patrick Bogan / Group contribution
 */
class Resistor : public Component {
private:
    double resistance;
    double tolerance;
    double powerRating;
    double pitch;

public:
    /**
     * @brief Creates a resistor object.
     * @param name Resistor name or label.
     * @param manufacturer Resistor manufacturer.
     * @param quantity Number of resistors in stock.
     * @param resistance Resistance value in ohms.
     * @param tolerance Tolerance percentage.
     * @param powerRating Power rating in watts.
     * @param pitch Pin pitch in millimetres.
     */
    Resistor(string name, string manufacturer, int quantity,
             double resistance, double tolerance, double powerRating, double pitch);

    /** @brief Gets the resistance value. @return Resistance in ohms. */
    double getResistance() const;

    /** @brief Gets the tolerance value. @return Tolerance percentage. */
    double getTolerance() const;

    /** @brief Gets the power rating. @return Power rating in watts. */
    double getPowerRating() const;

    /** @brief Gets the pin pitch. @return Pitch in millimetres. */
    double getPitch() const;

    /** @brief Displays all resistor details. */
    void display() const override;

    /** @brief Returns the component type. @return "Resistor". */
    string getType() const override;
};

#endif

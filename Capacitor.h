#ifndef CAPACITOR_H
#define CAPACITOR_H

#include "Component.h"

/**
 * @class Capacitor
 * @brief Represents a capacitor component in the inventory.
 *
 * Stores capacitor-specific information including capacitance, tolerance,
 * voltage rating, pin pitch, and capacitor type.
 *
 * @author Patrick Bogan / Group contribution
 */
class Capacitor : public Component {
private:
    double capacitance;
    double tolerance;
    double voltageRating;
    double pitch;
    string capacitorType;

public:
    /**
     * @brief Creates a capacitor object.
     * @param name Capacitor name or label.
     * @param manufacturer Capacitor manufacturer.
     * @param quantity Number of capacitors in stock.
     * @param capacitance Capacitance in microfarads.
     * @param tolerance Tolerance percentage.
     * @param voltageRating Voltage rating in volts.
     * @param pitch Pin pitch in millimetres.
     * @param capacitorType Capacitor type, e.g. electrolytic or ceramic.
     */
    Capacitor(string name, string manufacturer, int quantity,
              double capacitance, double tolerance, double voltageRating,
              double pitch, string capacitorType);

    /** @brief Gets the capacitance. @return Capacitance in microfarads. */
    double getCapacitance() const;

    /** @brief Gets the tolerance. @return Tolerance percentage. */
    double getTolerance() const;

    /** @brief Gets the voltage rating. @return Voltage rating in volts. */
    double getVoltageRating() const;

    /** @brief Gets the pin pitch. @return Pitch in millimetres. */
    double getPitch() const;

    /** @brief Gets the capacitor type. @return Capacitor type text. */
    string getCapacitorType() const;

    /** @brief Displays all capacitor details. */
    void display() const override;

    /** @brief Returns the component type. @return "Capacitor". */
    string getType() const override;
};

#endif

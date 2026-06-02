#ifndef INDUCTOR_H
#define INDUCTOR_H

#include "Component.h"

/**
 * @class Inductor
 * @brief Represents an inductor component in the inventory.
 *
 * Stores inductor-specific details including inductance, tolerance, current
 * rating, DC resistance, pitch, and core material.
 *
 * @author Oisin Clendenning
 */
class Inductor : public Component {
private:
    double inductance;
    double tolerance;
    double currentRating;
    double dcResistance;
    double pitch;
    string coreMaterial;

public:
    /**
     * @brief Creates an inductor object.
     * @param name Inductor name or label.
     * @param manufacturer Inductor manufacturer.
     * @param quantity Number of inductors in stock.
     * @param inductance Inductance in millihenries.
     * @param tolerance Tolerance percentage.
     * @param currentRating Current rating in amps.
     * @param dcResistance DC resistance in ohms.
     * @param pitch Pin pitch in millimetres.
     * @param coreMaterial Core material, e.g. ferrite.
     */
    Inductor(string name, string manufacturer, int quantity,
             double inductance, double tolerance, double currentRating,
             double dcResistance, double pitch, string coreMaterial);

    /** @brief Gets the inductance. @return Inductance in millihenries. */
    double getInductance() const;

    /** @brief Gets the tolerance. @return Tolerance percentage. */
    double getTolerance() const;

    /** @brief Gets the current rating. @return Current rating in amps. */
    double getCurrentRating() const;

    /** @brief Gets the DC resistance. @return DC resistance in ohms. */
    double getDcResistance() const;

    /** @brief Gets the pin pitch. @return Pitch in millimetres. */
    double getPitch() const;

    /** @brief Gets the core material. @return Core material text. */
    string getCoreMaterial() const;

    /** @brief Displays all inductor details. */
    void display() const override;

    /** @brief Returns the component type. @return "Inductor". */
    string getType() const override;
};

#endif

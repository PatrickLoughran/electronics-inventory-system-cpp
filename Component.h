#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
using namespace std;

/**
 * @class Component
 * @brief Abstract base class for all electronic components stored in the inventory.
 *
 * This class contains the shared fields used by every component type. Specific
 * components such as resistors, capacitors, and inductors inherit from this
 * class and implement their own display and type behaviour.
 *
 * @author Patrick Loughran
 */
class Component {
protected:
    string name;
    string manufacturer;
    int quantity;

public:
    /**
     * @brief Creates an empty component with default values.
     */
    Component();

    /**
     * @brief Creates a component with the shared component details.
     * @param name Component name or label.
     * @param manufacturer Component manufacturer.
     * @param quantity Number of components in stock.
     */
    Component(string name, string manufacturer, int quantity);

    /** @brief Gets the component name. @return Component name. */
    string getName() const;

    /** @brief Gets the component manufacturer. @return Manufacturer name. */
    string getManufacturer() const;

    /** @brief Gets the stock quantity. @return Quantity in stock. */
    int getQuantity() const;

    /** @brief Updates the component name. @param name New component name. */
    void setName(string name);

    /** @brief Updates the manufacturer. @param manufacturer New manufacturer. */
    void setManufacturer(string manufacturer);

    /** @brief Updates the quantity. @param quantity New quantity value. */
    void setQuantity(int quantity);

    /**
     * @brief Displays the component details to the console.
     *
     * This is pure virtual so each derived class must provide its own display
     * format for its specific component attributes.
     */
    virtual void display() const = 0;

    /**
     * @brief Returns the component type as text.
     * @return Type name such as "Resistor", "Capacitor", or "Inductor".
     */
    virtual string getType() const = 0;

    /**
     * @brief Virtual destructor for safe deletion through base-class pointers.
     */
    virtual ~Component();
};

#endif

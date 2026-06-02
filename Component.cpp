#include "Component.h"

/**
 * @brief Creates an empty component with default values.
 */
Component::Component() {
    name = "";
    manufacturer = "";
    quantity = 0;
}

/**
 * @brief Creates a component using the shared component fields.
 * @param name Component name or label.
 * @param manufacturer Component manufacturer.
 * @param quantity Number of components in stock.
 */
Component::Component(string name, string manufacturer, int quantity) {
    this->name = name;
    this->manufacturer = manufacturer;
    this->quantity = quantity;
}

/**
 * @brief Gets the component name.
 * @return Component name.
 */
string Component::getName() const {
    return name;
}

/**
 * @brief Gets the component manufacturer.
 * @return Manufacturer name.
 */
string Component::getManufacturer() const {
    return manufacturer;
}

/**
 * @brief Gets the component stock quantity.
 * @return Quantity in stock.
 */
int Component::getQuantity() const {
    return quantity;
}

/**
 * @brief Updates the component name.
 * @param name New component name.
 */
void Component::setName(string name) {
    this->name = name;
}

/**
 * @brief Updates the component manufacturer.
 * @param manufacturer New manufacturer.
 */
void Component::setManufacturer(string manufacturer) {
    this->manufacturer = manufacturer;
}

/**
 * @brief Updates the stock quantity.
 * @param quantity New stock quantity.
 */
void Component::setQuantity(int quantity) {
    this->quantity = quantity;
}

/**
 * @brief Virtual destructor.
 */
Component::~Component() {
}

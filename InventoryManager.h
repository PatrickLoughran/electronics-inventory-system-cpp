#ifndef INVENTORYMANAGER_H
#define INVENTORYMANAGER_H

#include <vector>
#include <memory>
#include <string>
#include "Component.h"
using namespace std;

/**
 * @class InventoryManager
 * @brief Stores and manages all electronic components in the system.
 *
 * The class uses polymorphism by storing shared pointers to the abstract
 * Component base class. This allows different component types to be managed
 * through one common interface.
 *
 * @author Patrick Loughran
 */
class InventoryManager {
private:
    vector<shared_ptr<Component>> components;

public:
    /**
     * @brief Adds a component to the inventory.
     * @param component Shared pointer to the component being added.
     */
    void addComponent(shared_ptr<Component> component);

    /**
     * @brief Removes the first component matching the supplied name.
     * @param name Name of the component to remove.
     * @return true if a component was removed, otherwise false.
     */
    bool removeComponentByName(const string& name);

    /**
     * @brief Displays every component currently stored in the inventory.
     */
    void displayAllComponents() const;

    /**
     * @brief Searches for components by name.
     * @param name Name or partial name to search for.
     */
    void searchByName(const string& name) const;

    /**
     * @brief Searches for components by type.
     * @param type Component type such as Resistor, Capacitor, or Inductor.
     */
    void searchByType(const string& type) const;

    /**
     * @brief Sorts all stored components by quantity in ascending order.
     */
    void sortByQuantity();

    /**
     * @brief Checks whether the inventory contains any components.
     * @return true if the inventory is empty, otherwise false.
     */
    bool isEmpty() const;

    /**
     * @brief Provides read-only access to all stored components.
     * @return Constant reference to the component vector.
     */
    const vector<shared_ptr<Component>>& getComponents() const;
};

#endif

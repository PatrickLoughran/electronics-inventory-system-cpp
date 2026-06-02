#include "InventoryManager.h"
#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;

/**
 * @brief Converts a string to lowercase to support case-insensitive searching.
 * @param text Text to convert.
 * @return Lowercase version of the input string.
 */
static string toLowerCase(string text) {
    transform(text.begin(), text.end(), text.begin(),
              [](unsigned char c) { return static_cast<char>(tolower(c)); });
    return text;
}

/**
 * @brief Adds a component to the inventory.
 * @param component Shared pointer to the component being added.
 */
void InventoryManager::addComponent(shared_ptr<Component> component) {
    components.push_back(component);
    cout << "Component added successfully.\n";
}

/**
 * @brief Removes the first component matching the supplied name.
 * @param name Name of the component to remove.
 * @return true if the component was found and removed.
 */
bool InventoryManager::removeComponentByName(const string& name) {
    string searchName = toLowerCase(name);

    for (auto it = components.begin(); it != components.end(); ++it) {
        if (toLowerCase((*it)->getName()) == searchName) {
            components.erase(it);
            cout << "Component removed successfully.\n";
            return true;
        }
    }

    cout << "Component not found.\n";
    return false;
}

/**
 * @brief Displays every component currently stored in the inventory.
 */
void InventoryManager::displayAllComponents() const {
    if (components.empty()) {
        cout << "Inventory is empty.\n";
        return;
    }

    cout << "\n--- Inventory ---\n";
    for (size_t i = 0; i < components.size(); i++) {
        cout << "\nComponent " << i + 1 << ":\n";
        components[i]->display();
        cout << endl;
    }
}

/**
 * @brief Searches for components by name or partial name.
 * @param name Name or partial name to search for.
 */
void InventoryManager::searchByName(const string& name) const {
    bool found = false;
    string searchName = toLowerCase(name);

    for (const auto& component : components) {
        if (toLowerCase(component->getName()).find(searchName) != string::npos) {
            cout << "\nComponent found:\n";
            component->display();
            cout << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No component found with that name.\n";
    }
}

/**
 * @brief Searches for components by component type.
 * @param type Component type such as Resistor, Capacitor, or Inductor.
 */
void InventoryManager::searchByType(const string& type) const {
    bool found = false;
    string searchType = toLowerCase(type);

    for (const auto& component : components) {
        if (toLowerCase(component->getType()) == searchType) {
            cout << "\nMatching component:\n";
            component->display();
            cout << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No components found for that type.\n";
    }
}

/**
 * @brief Sorts all components by quantity in ascending order.
 */
void InventoryManager::sortByQuantity() {
    sort(components.begin(), components.end(),
        [](const shared_ptr<Component>& a, const shared_ptr<Component>& b) {
            return a->getQuantity() < b->getQuantity();
        });

    cout << "Components sorted by quantity.\n";
}

/**
 * @brief Checks whether the inventory contains any components.
 * @return true if the inventory is empty, otherwise false.
 */
bool InventoryManager::isEmpty() const {
    return components.empty();
}

/**
 * @brief Provides read-only access to all stored components.
 * @return Constant reference to the component vector.
 */
const vector<shared_ptr<Component>>& InventoryManager::getComponents() const {
    return components;
}

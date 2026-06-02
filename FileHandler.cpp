#include "FileHandler.h"
#include "Resistor.h"
#include "Capacitor.h"
#include "Inductor.h"
#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

/**
 * @brief Writes a component's details into a CSV row.
 *
 * Dynamic casts are used so that component-specific fields can be exported
 * while still keeping the inventory stored polymorphically as Component
 * pointers.
 *
 * @param file Output file stream.
 * @param component Component to write.
 * @param number Row number for display in the CSV file.
 */
void FileHandler::writeComponentRow(ofstream& file, const shared_ptr<Component>& component, int number) const {
    file << number << ","
         << component->getType() << ","
         << component->getName() << ","
         << component->getManufacturer() << ","
         << component->getQuantity();

    if (const Resistor* resistor = dynamic_cast<const Resistor*>(component.get())) {
        file << "," << resistor->getResistance()
             << "," << resistor->getTolerance()
             << "," << resistor->getPowerRating()
             << "," << resistor->getPitch()
             << ",,,,";
    }
    else if (const Capacitor* capacitor = dynamic_cast<const Capacitor*>(component.get())) {
        file << ",,,,," 
             << capacitor->getCapacitance()
             << "," << capacitor->getTolerance()
             << "," << capacitor->getVoltageRating()
             << "," << capacitor->getPitch()
             << "," << capacitor->getCapacitorType()
             << ",,,,";
    }
    else if (const Inductor* inductor = dynamic_cast<const Inductor*>(component.get())) {
        file << ",,,,,,,,," 
             << inductor->getInductance()
             << "," << inductor->getTolerance()
             << "," << inductor->getCurrentRating()
             << "," << inductor->getDcResistance()
             << "," << inductor->getPitch()
             << "," << inductor->getCoreMaterial();
    }

    file << "\n";
}

/**
 * @brief Exports component data from the inventory into CSV files.
 *
 * The user can export all components, or choose a specific component type.
 * Each CSV file is overwritten to prevent old test data being repeated.
 *
 * @param manager InventoryManager containing the current components.
 */
void FileHandler::exportFile(const InventoryManager& manager) const {
    if (manager.isEmpty()) {
        cout << "No components available to export.\n";
        return;
    }

    int selection = 0;

    do {
        cout << "\n== CSV File Export Options ==\n";
        cout << "1. Export all components\n";
        cout << "2. Export resistors only\n";
        cout << "3. Export capacitors only\n";
        cout << "4. Export inductors only\n";
        cout << "5. Return to main menu\n";
        cout << "Enter choice: ";
        cin >> selection;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string fileName;
        string filterType;

        if (selection == 1) {
            fileName = "all_components.csv";
            filterType = "";
        }
        else if (selection == 2) {
            fileName = "resistors.csv";
            filterType = "Resistor";
        }
        else if (selection == 3) {
            fileName = "capacitors.csv";
            filterType = "Capacitor";
        }
        else if (selection == 4) {
            fileName = "inductors.csv";
            filterType = "Inductor";
        }
        else if (selection == 5) {
            cout << "Returning to main menu.\n";
            return;
        }
        else {
            cout << "Invalid option. Please try again.\n";
            continue;
        }

        ofstream file(fileName);

        if (!file.is_open()) {
            cout << "Error creating " << fileName << ".\n";
            return;
        }

        file << "List Number,Type,Name,Manufacturer,Quantity,"
             << "Resistance (Ohms),Resistor Tolerance (%),Power Rating (W),Resistor Pitch (mm),"
             << "Capacitance (uF),Capacitor Tolerance (%),Voltage Rating (V),Capacitor Pitch (mm),Capacitor Type,"
             << "Inductance (mH),Inductor Tolerance (%),Current Rating (A),DC Resistance (Ohms),Inductor Pitch (mm),Core Material\n";

        int count = 1;
        int exported = 0;

        for (const auto& component : manager.getComponents()) {
            if (filterType.empty() || component->getType() == filterType) {
                writeComponentRow(file, component, count++);
                exported++;
            }
        }

        file.close();

        cout << exported << " component(s) exported to " << fileName << ".\n";

    } while (selection != 5);
}

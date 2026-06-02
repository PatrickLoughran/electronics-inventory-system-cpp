#include <iostream>
#include <limits>
#include <memory>
#include "InventoryManager.h"
#include "Resistor.h"
#include "Capacitor.h"
#include "Inductor.h"
#include "FileHandler.h"

using namespace std;

/**
 * @brief Clears failed input and removes the rest of the current input line.
 */
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/**
 * @brief Reads a non-empty line of text from the user.
 * @param prompt Message shown to the user.
 * @return Non-empty user input.
 */
string readText(const string& prompt) {
    string value;

    do {
        cout << prompt;
        getline(cin, value);

        if (value.empty()) {
            cout << "Input cannot be empty. Please try again.\n";
        }
    } while (value.empty());

    return value;
}

/**
 * @brief Reads a positive integer from the user.
 * @param prompt Message shown to the user.
 * @return Positive integer entered by the user.
 */
int readPositiveInt(const string& prompt) {
    int value;

    while (true) {
        cout << prompt;
        cin >> value;

        if (!cin.fail() && value >= 0) {
            clearInput();
            return value;
        }

        cout << "Invalid input. Please enter a positive whole number.\n";
        clearInput();
    }
}

/**
 * @brief Reads a positive decimal number from the user.
 * @param prompt Message shown to the user.
 * @return Positive decimal value entered by the user.
 */
double readPositiveDouble(const string& prompt) {
    double value;

    while (true) {
        cout << prompt;
        cin >> value;

        if (!cin.fail() && value >= 0) {
            clearInput();
            return value;
        }

        cout << "Invalid input. Please enter a positive number.\n";
        clearInput();
    }
}

/**
 * @brief Displays the main application menu.
 */
void showMenu() {
    cout << "\n===== Electronics Inventory Menu =====\n";
    cout << "1. Add resistor\n";
    cout << "2. Add capacitor\n";
    cout << "3. Add inductor\n";
    cout << "4. Remove component by name\n";
    cout << "5. Display all components\n";
    cout << "6. Search component by name\n";
    cout << "7. Search component by type\n";
    cout << "8. Sort components by quantity\n";
    cout << "9. Export components to CSV\n";
    cout << "10. Load sample data\n";
    cout << "11. Exit\n";
    cout << "Enter choice: ";
}

/**
 * @brief Adds a resistor to the inventory using user input.
 * @param manager Inventory manager receiving the new resistor.
 */
void addResistor(InventoryManager& manager) {
    string name = readText("Enter resistor name: ");
    string manufacturer = readText("Enter manufacturer: ");
    int quantity = readPositiveInt("Enter quantity: ");
    double resistance = readPositiveDouble("Enter resistance (ohms): ");
    double tolerance = readPositiveDouble("Enter tolerance (%): ");
    double powerRating = readPositiveDouble("Enter power rating (W): ");
    double pitch = readPositiveDouble("Enter pitch (mm): ");

    manager.addComponent(make_shared<Resistor>(
        name, manufacturer, quantity, resistance, tolerance, powerRating, pitch
    ));
}

/**
 * @brief Adds a capacitor to the inventory using user input.
 * @param manager Inventory manager receiving the new capacitor.
 */
void addCapacitor(InventoryManager& manager) {
    string name = readText("Enter capacitor name: ");
    string manufacturer = readText("Enter manufacturer: ");
    int quantity = readPositiveInt("Enter quantity: ");
    double capacitance = readPositiveDouble("Enter capacitance (uF): ");
    double tolerance = readPositiveDouble("Enter tolerance (%): ");
    double voltageRating = readPositiveDouble("Enter voltage rating (V): ");
    double pitch = readPositiveDouble("Enter pitch (mm): ");
    string capacitorType = readText("Enter capacitor type: ");

    manager.addComponent(make_shared<Capacitor>(
        name, manufacturer, quantity, capacitance, tolerance,
        voltageRating, pitch, capacitorType
    ));
}

/**
 * @brief Adds an inductor to the inventory using user input.
 * @param manager Inventory manager receiving the new inductor.
 */
void addInductor(InventoryManager& manager) {
    string name = readText("Enter inductor name: ");
    string manufacturer = readText("Enter manufacturer: ");
    int quantity = readPositiveInt("Enter quantity: ");
    double inductance = readPositiveDouble("Enter inductance (mH): ");
    double tolerance = readPositiveDouble("Enter tolerance (%): ");
    double currentRating = readPositiveDouble("Enter current rating (A): ");
    double dcResistance = readPositiveDouble("Enter DC resistance (ohms): ");
    double pitch = readPositiveDouble("Enter pitch (mm): ");
    string coreMaterial = readText("Enter core material: ");

    manager.addComponent(make_shared<Inductor>(
        name, manufacturer, quantity, inductance, tolerance,
        currentRating, dcResistance, pitch, coreMaterial
    ));
}

/**
 * @brief Loads sample components to demonstrate and test the application.
 * @param manager Inventory manager receiving the sample components.
 */
void loadSampleData(InventoryManager& manager) {
    manager.addComponent(make_shared<Resistor>("2M", "Vishay", 10, 2000000, 5, 0.25, 10.16));
    manager.addComponent(make_shared<Resistor>("10K", "Yageo", 25, 10000, 1, 0.25, 7.62));
    manager.addComponent(make_shared<Capacitor>("100u", "Panasonic", 30, 100, 20, 25, 2.5, "Electrolytic"));
    manager.addComponent(make_shared<Capacitor>("0.1u", "Murata", 50, 0.1, 10, 50, 5.0, "Ceramic"));
    manager.addComponent(make_shared<Inductor>("10u", "Murata", 10, 0.01, 10, 1.5, 0.07, 3.0, "Ferrite"));

    cout << "Sample component data loaded.\n";
}

/**
 * @brief Entry point for the electronics inventory program.
 * @return 0 when the program exits successfully.
 */
int main() {
    InventoryManager manager;
    FileHandler fileHandler;
    int choice;

    do {
        showMenu();
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a number.\n";
            clearInput();
            continue;
        }

        clearInput();

        if (choice == 1) {
            addResistor(manager);
        }
        else if (choice == 2) {
            addCapacitor(manager);
        }
        else if (choice == 3) {
            addInductor(manager);
        }
        else if (choice == 4) {
            string name = readText("Enter component name to remove: ");
            manager.removeComponentByName(name);
        }
        else if (choice == 5) {
            manager.displayAllComponents();
        }
        else if (choice == 6) {
            string name = readText("Enter component name to search: ");
            manager.searchByName(name);
        }
        else if (choice == 7) {
            string type = readText("Enter component type (Resistor/Capacitor/Inductor): ");
            manager.searchByType(type);
        }
        else if (choice == 8) {
            manager.sortByQuantity();
        }
        else if (choice == 9) {
            fileHandler.exportFile(manager);
        }
        else if (choice == 10) {
            loadSampleData(manager);
        }
        else if (choice == 11) {
            cout << "Exiting program.\n";
        }
        else {
            cout << "Invalid option. Try again.\n";
        }

    } while (choice != 11);

    return 0;
}

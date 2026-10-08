Electronics Inventory System
============================

Project summary
---------------
This is a C++ object-oriented electronics inventory system. It stores different
component types including resistors, capacitors, and inductors. The system uses
inheritance and polymorphism through a shared Component base class.

Main features
-------------
- Add resistor, capacitor, and inductor components
- Display all components
- Search by component name
- Search by component type
- Remove components by name
- Sort components by quantity
- Export all components or selected component types to CSV files
- Load sample data for quick testing
- Input validation for numeric entries
- JavaDoc-style comments throughout the source files

File list
---------
Component.h / Component.cpp
    Abstract base class for all components.

Resistor.h / Resistor.cpp
    Derived class for resistor-specific data.

Capacitor.h / Capacitor.cpp
    Derived class for capacitor-specific data.

Inductor.h / Inductor.cpp
    Derived class for inductor-specific data.

InventoryManager.h / InventoryManager.cpp
    Stores, displays, searches, removes, and sorts components.

FileHandler.h / FileHandler.cpp
    Exports component data from InventoryManager to CSV files.

Main.cpp
    Contains the menu system and user interaction.

How to compile
--------------
Open a terminal in this folder and run:

g++ Main.cpp Component.cpp Resistor.cpp Capacitor.cpp Inductor.cpp InventoryManager.cpp FileHandler.cpp -o inventory

How to run
----------
In PowerShell on Windows:

.\inventory.exe

In MSYS2 / Git Bash / Linux-style terminal:

./inventory

Quick test steps
----------------
1. Run the program.
2. Choose option 10 to load sample data.
3. Choose option 5 to display all components.
4. Choose option 6 and search for 2M.
5. Choose option 7 and search for Inductor.
6. Choose option 8 to sort by quantity, then option 5 to display again.
7. Choose option 9 and export all components to CSV.
8. Open all_components.csv and check that component data has exported correctly.

CSV output files
----------------
Depending on the export option selected, the program can create:

all_components.csv
resistors.csv
capacitors.csv
inductors.csv

Notes
-----
The FileHandler exports data directly from InventoryManager so that the CSV
files match the components currently stored in the program.

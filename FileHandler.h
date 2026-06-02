#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>
#include "InventoryManager.h"
using namespace std;

/**
 * @class FileHandler
 * @brief Handles CSV export functionality for the inventory system.
 *
 * The class exports data from InventoryManager rather than storing its own
 * duplicate component lists. This keeps the file output consistent with the
 * components currently added through the main program.
 *
 * @author Patrick Bogan / Integration by group
 */
class FileHandler {
private:
    /**
     * @brief Writes a single component to a CSV output stream.
     * @param file Output file stream.
     * @param component Component to export.
     * @param number Row number for the CSV file.
     */
    void writeComponentRow(ofstream& file, const shared_ptr<Component>& component, int number) const;

public:
    /**
     * @brief Opens the export menu and exports selected component data to CSV.
     * @param manager InventoryManager containing the components to export.
     */
    void exportFile(const InventoryManager& manager) const;
};

#endif

/*
Developer: Amanda Dunn
Date: 02/22/2026
Purpose: Corner Grocer item-tracking program. Reads daily purchase records from
         CS210_Project_Three_Input_File.txt, counts item frequencies, creates a backup file (frequency.dat), 
         and provides a menu to search/print data.
*/


#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <limits>
#include <algorithm>
#include <cctype>


using namespace std;

class GroceryTracker {
public:
    //Constructor 
    // Initializes file names, loads data and writes backup file automatically
    GroceryTracker(const string& inputFileName, const string& backupFileName) {
        inputFile = inputFileName;
        backupFile = backupFileName;


        LoadItemsFromFile();   // Reads and counts items
        WriteBackupFile();    // Creates frequency.dat backup file

    }

    // Option 1: Returns the frequency of a specific item and is case-insensitive
    int GetItemFrequency(const string& item) const {
        string normalizedItem = ToLower(item);     // Converts search term to lowercase

        auto it = itemFrequency.find(normalizedItem);   // Search map
        if (it != itemFrequency.end()) {
            return it->second;                   // Returns count if found
        }
        return 0;       // Returns 0 if no item is found
    }

    // Prints a single formatted search result (used in menu option 1)
    void PrintSingleItem(const string& item) const {
        int freq = GetItemFrequency(item);
        

        // Format display name. Lowercase storage with capitalized output
        cout << Capitalize(ToLower(item)) << " " << freq << endl;
    }

    // Menu option 2: Print all items with their numeric frequency
    void PrintAllFrequencies() const {

        // Safety check in case file was not loaded
        if (itemFrequency.empty()) {
            cout << "No items loaded.\n";
            return;
        }

        // Loop through map and display formatted output
        for (const auto& pair : itemFrequency) {
            cout << Capitalize(pair.first) << " " << pair.second << endl;
        }
    }


    // Option 3: Print histogram using '*' 
    void PrintHistogram() const {
        if (itemFrequency.empty()) {
            cout << "No items loaded.\n";
            return;
        }

        for (const auto& pair : itemFrequency) {

            // Creates a string of '*' equal to frequency count
            cout << Capitalize(pair.first) << " " << string(pair.second, '*') << endl;
        }
    }


private:
    string inputFile;                    // Stores input file name
    string backupFile;                   // Stores backup file name
    map<string, int> itemFrequency;     // Key =  item name, Value =  frequency count

    // Converts a string to lowercase to make counting/searching case-insensitive
    string ToLower(const string& str) const {
        string lowerStr = str;
        transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(),
            [](unsigned char c) {
                return static_cast<char>(tolower(c));  
            });
        return lowerStr;
    }

    // Capitalizes only the first character for cleaner display
    string Capitalize(const string& str) const {
        if (str.empty()) return str;

        string result = str;
        result[0] = static_cast<char>(toupper(static_cast<unsigned char>(result[0])));
        return result;
    }


    // Reads input file and counts each item
    void LoadItemsFromFile() {
        ifstream inFS(inputFile);      // Opens input file

        if (!inFS.is_open()) {
            cout << "ERROR: Could not open input file: " << inputFile << endl;
            return;
        }

        string item;
        while (inFS >> item) {       // Read each word/item from file
            item = ToLower(item);    // Normalize to lowercase
            itemFrequency[item]++;   // Count frequency
        }

        inFS.close();         // Closes file after reading
    }

    // Writes item frequencies to backup file frequency.dat
    void WriteBackupFile() const {
        ofstream outFS(backupFile);    // Creates output file


        if (!outFS.is_open()) {
            cout << "ERROR: Could not create backup file: " << backupFile << endl;
            return;
        }

        // Write item and count to backup file
        for (const auto& pair : itemFrequency) {
            outFS << pair.first << " " << pair.second << endl;
        }

        outFS.close();      // Closes output file
    }

};

// Displays the menu options
void PrintMenu() {
    cout << "\n===== Corner Grocer Menu =====\n";
    cout << "1. Look up an item frequency\n";
    cout << "2. Print all item frequencies\n";
    cout << "3. Print histogram\n";
    cout << "4. Exit\n";
    cout << "Choose an option (1-4): ";
}

// Validates menu input to prevent crashing
int GetValidatedMenuChoice() {
    int choice;

    while (!(cin >> choice) || choice < 1 || choice > 4) {
        cout << "Invalid input. Please enter a number 1 - 4: ";
        cin.clear();                                            // Clear error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n');   // Discards bad input
    }

    return choice;
}

int main() {

    // Define file names
    const string inputFileName = "CS210_Project_Three_Input_File.txt";
    const string backupFileName = "frequency.dat";

    // Creates GroceryTracker object and automatically loads/writes backup file
    GroceryTracker tracker(inputFileName, backupFileName);

    int choice = 0;

    // Loop menu until user chooses exit
    do {
        PrintMenu();
        choice = GetValidatedMenuChoice();

        if (choice == 1) {
            cout << "Please enter the item you want to search for: ";
            string item;
            cin >> item;

            tracker.PrintSingleItem(item);   // Display formatted result
        }
        else if (choice == 2) {
            tracker.PrintAllFrequencies();

        }
        else if (choice == 3) {
            tracker.PrintHistogram();

        }
        // Choice 4 will exit

    } while (choice != 4);

    cout << "Goodbye!\n";

    return 0;
}





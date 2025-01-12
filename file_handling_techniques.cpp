#include <iostream>
#include <fstream>
#include <string>

using namespace std;


void writeToFile(const string& fileName) {
    ofstream file(fileName); 
    if (!file) {
        cout << "Error: Unable to open the file for writing!" << endl;
        return;
    }

    cout << "Enter the data you want to write to the file (end with an empty line):" << endl;
    string data;
    cin.ignore(); 
    while (true) {
        getline(cin, data);
        if (data.empty()) break; 
        file << data << endl;
    }

    file.close();
    cout << "Data successfully written to " << fileName << "." << endl;
}


void appendToFile(const string& fileName) {
    ofstream file(fileName, ios::app); 
    if (!file) {
        cout << "Error: Unable to open the file for appending!" << endl;
        return;
    }

    cout << "Enter the data you want to append to the file (end with an empty line):" << endl;
    string data;
    cin.ignore(); 
    while (true) {
        getline(cin, data);
        if (data.empty()) break; 
        file << data << endl;
    }

    file.close();
    cout << "Data successfully appended to " << fileName << "." << endl;
}


void readFromFile(const string& fileName) {
    ifstream file(fileName); 
    if (!file) {
        cout << "Error: Unable to open the file for reading!" << endl;
        return;
    }

    cout << "Contents of " << fileName << ":" << endl;
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

int main() {
    string fileName = "data.txt"; // Default file name
    int choice;

    do {
        cout << "\nFile Operations Menu:" << endl;
        cout << "1. Write to File" << endl;
        cout << "2. Append to File" << endl;
        cout << "3. Read from File" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                writeToFile(fileName);
                break;
            case 2:
                appendToFile(fileName);
                break;
            case 3:
                readFromFile(fileName);
                break;
            case 4:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please select a valid option." << endl;
        }
    } while (choice != 4);

    return 0;
}

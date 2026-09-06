#include <iostream>
#include <string>
#include <limits>

using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::numeric_limits;
using std::streamsize;
using std::string;

class Employee {
    public:
        string title;    
        string name;
        string surname;
        string age;
        string clockId;
        string position;
        string startDate;
        string department;
        string payRate;
        string ratePerHour;
        string hoursWorked;
        string totalPayGross;
        string medicalAidContribution;
        string payAsYouEarn;
        string uif;
        string totalPayAfterDeductionsAndTaxes;

};
class Department {
    public:
        string departmentName;
        int numberOfEmployees;
        int employeeCount;
        string departmentManager;
        string departmentStatus;
};
class Item {
    public:
        string name;
        string description;
        string category;
        string colour;
        string size;
        string price;
        string quantity;
        string total;
};
class StoreSecurity {
    public:
        string doors;
        string windows;
        string lights;
        string alarms;
        string dropSafe;
};
// Function to check the doors
void checkDoors() {
    cout << "Checking the doors...\n";
    string doors = "Open";
    if (doors == "Open") {
        cout << "The doors are open.\n";
    } else {
        cout << "The doors are closed.\n";
        return;
    }
}
// Function to check the windows
void checkWindows() {
    cout << "Checking the windows...\n";
    string windows = "Open";
    while (windows == "Closed") {
        cout << "The windows are open. Please check windows...\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        checkWindows();
    }
    cout << "The windows are closed.\n";
    }

// Function to check the lights
void checkLights() {
    cout << "Checking the lights...\n";
    string lights = "On";
    if (lights == "On") {
        cout << "The lights are on.\n";
    } else {
        cout << "The lights are off.\n";
        return;
    }
}
// Function to check the alarms
void checkAlarms() {
    cout << "Checking the alarms...\n";
    // If the alarms are on, the store should not be open
    string alarms = "On";
    while (alarms == "Off") {
        cerr << "The alarms are on, Please disable the alarms.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  
        checkAlarms();
    }
    cout << "The alarms are off.\n";
}
// Function to check the drop safe
void checkDropSafe() {
    cout << "Checking the drop safe...\n";
    string dropSafe = "Open";
    if (dropSafe == "Open") {
        cout << "The drop safe is open.\n";
    } else {
        cout << "The drop safe is closed.\n";
        return;
    }
}
// Function to view the store security
void viewStoreSecurity() {
    cout << "Viewing the store security...\n";
    StoreSecurity storeSecurity;
    cout << "Doors: " << storeSecurity.doors << endl;
    cout << "Windows: " << storeSecurity.windows << endl;
    cout << "Lights: " << storeSecurity.lights << endl;
    cout << "Alarms: " << storeSecurity.alarms << endl;
    cout << "Drop safe: " << storeSecurity.dropSafe << endl;
}
// Function to open the store
void openStore() {
    cout << "Running security checks...\n";
    checkDoors();
    checkWindows();
    checkLights();
    checkAlarms();
    checkDropSafe();
    cout << "The store is now open.\n";
}

// Main function
int main() {
    cout << "Welcome to the Manager's Desk\n";
    while (true) {
        cout << "1. Open The Store\n";
        cout << "2. View Store Security\n";
        cout << "3. View Store Status\n";
        cout << "4. Access Departments Information\n";
        cout << "5. Access Employees Information\n";
        cout << "6. Close The Store\n";
        cout << "0. Exit\n";
        cout << "Please select an option: ";
        int option;
        cin >> option;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        while (cin.fail() || option < 0 || option > 6) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Invalid input. Please try again.\n";
            cout << "1. Open The Store\n";
            cout << "2. View Store Security\n";
            cout << "3. View Store Status\n";
            cout << "4. Access Departments Information\n";
            cout << "5. Access Employees Information\n";
            cout << "6. Close The Store\n";
            cout << "0. Exit\n";
            cout << "Please select an option: ";
            cin >> option;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (option == 1) {
            openStore();
        } else if (option == 2) {
            viewStoreSecurity();
        } else if (option == 3) {
            // View store status
        } else if (option == 4) {
            // Access departments information
        } else if (option == 5) {
            // Access employees information
        } else if (option == 6) {
            // Close the store
        } else if (option == 0) {
            cout << "Closing the manager's desk... Goodbye!\n";
            exit(0);

        }
    }
    return 0;
}
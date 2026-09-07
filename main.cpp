#include <iostream>
#include <string>
#include <limits>

using std::cout;
using std::cerr;
using std::cin;
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
    private:
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
        string securityDoor = " ";
        string windows = " ";
        string lights = " ";
        string alarms = " ";
        string dropSafe = " ";
};
// Function to check the doors
void checkDoors(StoreSecurity &storeSecurity) {
    (void)storeSecurity;
    cout << "Checking the Security door...\n";
    string securityDoor = "Closed";
    cout << "The Security Door is " << securityDoor << ".\n";
    while (securityDoor == "Open") {
        cerr << "The Security Door is " << securityDoor << ", Please check it...";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        checkDoors(storeSecurity);
        break;
    } 
    return;
    }

// Function to check the windows
void checkWindows(StoreSecurity &storeSecurity) {
    cout << "Checking the windows...\n";
    string windows = "Closed";
    cout << "The windows are " << windows << "...\n";
    while (windows == "Open") {
        cerr << "The windows are " << windows << ", Please check them...";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        checkWindows(storeSecurity);
        break;
    }
    return;
    }

// Function to check the lights
void checkLights(StoreSecurity &storeSecurity) {
    (void)storeSecurity;
    cout << "Checking the lights...\n";
    string lights = "On";
    cout << "The lights are " << lights << "...\n";
    while (lights == "Off") {
        cerr << "The lights are " << lights << ", Please check them...";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        checkLights(storeSecurity);
        break;
    }
    return;
    }

// Function to check the alarms
void checkAlarms(StoreSecurity &storeSecurity) {
    cout << "Checking the alarm...\n";
    // If the alarms are on, the store should not be open
    string alarms = "Off";
    cout << "The alarm is " << alarms << "...\n";
    while (alarms == "On") {
        cerr << "The alarm is " << alarms << ", Please disable it...";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  
        checkAlarms(storeSecurity);
        break;
    }
    return;
}
// Function to check the drop safe
void checkDropSafe(StoreSecurity &storeSecurity) {
    cout << "Checking the drop safe...\n";
    string dropSafe = "Closed";
    cout << "The drop safe is " << dropSafe << "...\n";
    while (dropSafe == "Open") {
        cout << "The drop safe is " << dropSafe << ", Please check it...";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        checkDropSafe(storeSecurity);
        break;
    }
    return;        
}

// Function to view the store security
void viewStoreSecurity(StoreSecurity &storeSecurity) {
    cout << "Viewing the store security...\n";
    cout << "Doors: " << storeSecurity.securityDoor << "\n";
    cout << "Windows: " << storeSecurity.windows << "\n";
    cout << "Lights: " << storeSecurity.lights << "\n";
    cout << "Alarms: " << storeSecurity.alarms << "\n";
    cout << "Drop Safe: " << storeSecurity.dropSafe << "\n";
    
}
// Function to open the store
void openStore() {
    StoreSecurity storeSecurity;
    cout << "Running security checks...\n";
    checkDoors(storeSecurity);
    checkWindows(storeSecurity);
    checkLights(storeSecurity);
    checkAlarms(storeSecurity);
    checkDropSafe(storeSecurity);
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
            StoreSecurity storeSecurity;
            openStore();
        } else if (option == 2) {
            StoreSecurity storeSecurity;
            viewStoreSecurity(storeSecurity);
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
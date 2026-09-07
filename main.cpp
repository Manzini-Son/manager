#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <vector>
#include <ios>
#include <cctype>


using std::cout;
using std::cerr;
using std::cin;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::ios;
using std::vector;
using std::numeric_limits;
using std::streamsize;
using std::string;

class Employee {
    public:
        string title;    
        string firstName;
        string middleName;
        string lastName;
        string gender;
        string dateOfBirth;
        int age;
        string idNumber;
        string maritalStatus;
        string spouseFirstName;
        string spouseLastName;
        string spousePhoneNumber;
        string phoneNumber;
        string emailAddress;
        string houseNumber;
        string streetName;
        string town;
        string city;
        string postalCode;
        string province;
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
// Headers
bool isValidTitle (const string &title) {
    if (title == "Mr" || title == "Mrs" || title == "Miss" || title == "Ms" || title == "Dr" || title == "Prof") {
        return true;
    } else {
        return false;
    }
}
bool isValidName (const string &name) {
    if (!name.empty() && name.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ") == string::npos) {
        return true;
    } else {
        return false;
    }
}
bool isValidGender (const string &gender) {
    if (gender == "Male" || gender == "Female" || gender == "Other") {
        return true;
    } else {
        return false;
    }
}
bool isValidAge (const string &age) {
    if (age < "18" || age > "60") {
        return false;
    } else {
        return true;
    }
}
bool isValidDate (const string &date) {
    if (date.length() != 10 || date[2] != '/' || date[5] != '/' ||
        date.substr(0, 2).find_first_not_of("0123456789") != string::npos ||
        date.substr(3, 2).find_first_not_of("0123456789") != string::npos ||
        date.substr(6, 4).find_first_not_of("0123456789") != string::npos) {
        return false;
    } else {
        return true;
    }
}
bool isValidIdNumber (const string &idNumber) {
    if (idNumber.length() != 13 || idNumber.find_first_not_of("0123456789") != string::npos) {
        return false;
    } else {
        return true;
    }
}
bool isValidMaritalStatus (const string &maritalStatus) {
    if (maritalStatus == "Single" || maritalStatus == "Married" || maritalStatus == "Separated" || maritalStatus == "Divorced" || maritalStatus == "Widowed") {
        return true;
    } else {
        return false;
    }
}
bool isValidPhoneNumber (const string &phoneNumber) {
    if (phoneNumber.length() != 10 || phoneNumber.find_first_not_of("0123456789") != string::npos) {
        return false;
    } else {
        return true;
    }
}
bool isValidEmail (const string &email) {
    if (email.find("@") == string::npos || email.find(".") == string::npos) {
        return false;
    } else {
        return true;
    }
}
bool isValidPostalCode (const string &postalCode) {
    if (postalCode.length() < 4 || postalCode.length() > 6 || postalCode.find_first_not_of("0123456789") != string::npos) {
        return false;
    } else {
        return true;
    }
}
bool isValidProvince (const string &province) {
    return province == "Eastern cape" || province == "Free state" ||
           province == "Gauteng" || province == "Limpopo" ||
           province == "Mpumalanga" || province == "KwaZulu natal" ||
           province == "North west" || province == "Northern cape" ||
           province == "Western cape";
}
bool isValidClockId (const string &clockId) {
    if (clockId.length() != 6 || clockId.find_first_not_of("0123456789") != string::npos) {
        return false;
    } else {
        return true;
    }
}
// Prototypes of functions
void createEmployeeDataBaseFile();
void createSalesDataBaseFile();
void manageTheStore();
void checkSecurityDoor(StoreSecurity &storeSecurity);
void checkWindows(StoreSecurity &storeSecurity);
void checkLights(StoreSecurity &storeSecurity);
void checkAlarms(StoreSecurity &storeSecurity);
void checkDropSafe(StoreSecurity &storeSecurity);
void accessEmployeeInformation(Employee &employee);
//void saveSalesData();
//void viewSalesData();
//void updateSalesData();
//void deleteSalesData();
void createStockDataBaseFile();
void saveEmployeeData(Employee &employee);
void captureEmployeeData(Employee &employee);
void addEmployeeData(Employee &employee);
void viewEmployeeData(Employee &employee);
void updateEmployeeData(Employee &employee);
void deleteEmployeeData(Employee &employee);
void viewAllEmployeeData(Employee &employee);
//void stockUpStore();
string capitaliseFirstLetter (string word) {
    if (!word.empty()) {
        word[0] = static_cast<char>(toupper(static_cast<unsigned char>(word[0])));
    }
    return word;
}
// Function to create employee database file if it does not exist
void createEmployeeDataBaseFile() {
    ifstream existingFile("employeeDatabase.txt");
    if (!existingFile.good()) {
        ofstream employeeDatabaseFile("employeeDatabase.txt");
    }
}
// Function to create sales database file if it does not exist
void createSalesDataBaseFile() {
    ifstream existingFile("salesDatabase.txt");
    if (!existingFile.good()) {
        ofstream salesDatabaseFile("salesDatabase.txt");
    }
}
// Function to create stock database file if it does not exist
void createStockDataBaseFile() {
    ifstream existingFile("stockDatabase.txt");
    if (!existingFile.good()) {
        ofstream stockDatabaseFile("stockDatabase.txt");
    }
}
// Function to save employee data
void saveEmployeeData(Employee &employee) {
    cout << "Saving employee data...\n";
    ofstream outFile("employeeDatabase.txt", ios::app);
    if (!outFile) {
        cerr << "Error opening file\n";
        return;
    }
    outFile << "Title: " << employee.title << "\n";
    outFile << "First Name: " << employee.firstName << "\n";
    outFile << "Middle Name: " << employee.middleName << "\n";
    outFile << "Last Name: " << employee.lastName << "\n";
    outFile << "Gender: " << employee.gender << "\n";
    outFile << "Date of Birth: " << employee.dateOfBirth << "\n";
    outFile << "Age: " << employee.age << "\n";
    outFile << "ID Number: " << employee.idNumber << "\n";
    outFile << "Marital Status: " << employee.maritalStatus << "\n";
    if (employee.maritalStatus == "Married") {
        outFile << "Spouse First Name: " << employee.spouseFirstName << "\n";
        outFile << "Spouse Last Name: " << employee.spouseLastName << "\n";
        outFile << "Spouse Phone Number: " << employee.spousePhoneNumber << "\n";
    }
    outFile << "Phone Number: " << employee.phoneNumber << "\n";
    outFile << "Email Address: " << employee.emailAddress << "\n";
    outFile << "House Number: " << employee.houseNumber << "\n";
    outFile << "Street Name: " << employee.streetName << "\n";
    outFile << "Town: " << employee.town << "\n";
    outFile << "City: " << employee.city << "\n";
    outFile << "Postal Code: " << employee.postalCode << "\n";
    outFile << "Province: " << employee.province << "\n";
    outFile << "Clock ID: " << employee.clockId << "\n";
    outFile << "Position: " << employee.position << "\n";
    outFile << "Start Date: " << employee.startDate << "\n";
    outFile << "Department: " << employee.department << "\n";
    outFile << "--------------------------------------\n";
    outFile.close();
    cout << "Employee data saved successfully.\n";
}
// Function to access employee information
void accessEmployeeInformation(Employee &employee) {
    cout << "Accessing employee information...\n";
    cout << "-----------------------------------\n";
    cout << "1. View Employee Data\n";
    cout << "2. Add Employee Data\n";
    cout << "3. Update Employee Data\n";
    cout << "4. Remove Employee Data\n";
    cout << "5. View all Employee Data\n";
    cout << "0. Exit\n";
    cout << "Please select an option: ";
    int option;
    cin >> option;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (cin.fail() || option < 0 || option > 5) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "Invalid input. Please try again.\n";
        cout << "1. View Employee Data\n";
        cout << "2. Add Employee Data\n";
        cout << "3. Update Employee Data\n";
        cout << "4. Remove Employee Data\n";
        cout << "5. View all Employee Data\n";
        cout << "0. Exit\n";
        cout << "Please select an option: ";
        cin >> option;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    switch (option) {
        case 1:
            viewEmployeeData(employee);
            break;
        case 2:
            addEmployeeData(employee);
            break;
        case 3:
            updateEmployeeData(employee);
            break;
        case 4:
            deleteEmployeeData(employee);
            break;

        case 5:
            viewAllEmployeeData(employee);
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid option. Please try again.\n";
            break;
    }
}
// Function to view all employee data
void viewAllEmployeeData(Employee &) {
    cout << "Viewing all employee data...\n";
    ifstream inFile("employeeDatabase.txt");
    if (!inFile) {
        cerr << "Error opening file\n";
        return;
    }
    string line;
    while (getline(inFile, line)) {
        cout << line << "\n";
    }
    inFile.close();
}
// Function to remove employee data
void deleteEmployeeData(Employee &employee) {
    cout << "Removing employee data...\n";
    cout << "Enter clock ID to remove employee data: ";
    string clockId;
    getline(cin, clockId);
    while (!isValidClockId(clockId)) {
        cerr << "Invalid clock ID. Please enter a valid clock ID (6 digits).\n";
        cout << "Enter clock ID to remove employee data: ";
        getline(cin, clockId);
    }
    employee.clockId = clockId;
    ifstream inFile("employeeDatabase.txt");
    ofstream outFile("temp.txt");
    if (!inFile || !outFile) {
        cerr << "Error opening employee database\n";
        return;
    }
    string line;
    vector<string> record;
    bool removed = false;
    while (getline(inFile, line)) {
        if (line == "--------------------------------------") {
            bool matches = false;
            for (const string &recordLine : record) {
                if (recordLine == "Clock ID: " + clockId) {
                    matches = true;
                    break;
                }
            }
            if (!matches) {
                for (const string &recordLine : record) {
                    outFile << recordLine << "\n";
                }
                outFile << line << "\n";
            } else {
                removed = true;
            }
            record.clear();
        } else {
            record.push_back(line);
        }
    }
    for (const string &recordLine : record) {
        outFile << recordLine << "\n";
    }
    inFile.close();
    outFile.close();
    if (removed) {
        remove("employeeDatabase.txt");
        rename("temp.txt", "employeeDatabase.txt");
        cout << "Employee data removed successfully.\n";
    } else {
        remove("temp.txt");
        cout << "Employee data not found.\n";
    }
}
// Function to update employee data
void updateEmployeeData(Employee &employee) {
    cout << "Updating employee data...\n";
    cout << "Enter clock ID to update employee data: ";
    string clockId;
    getline(cin, clockId);
    while (!isValidClockId(clockId)) {
        cerr << "Invalid clock ID. Please enter a valid clock ID (6 digits).\n";
        cout << "Enter clock ID to update employee data: ";
        getline(cin, clockId);
    }
    employee.clockId = clockId;
    ifstream inFile("employeeDatabase.txt");
    ofstream outFile("temp.txt");
    if (!inFile || !outFile) {
        cerr << "Error opening employee database\n";
        return;
    }
    string line;
    vector<string> record;
    bool updated = false;
    while (getline(inFile, line)) {
        if (line == "--------------------------------------") {
            bool matches = false;
            for (const string &recordLine : record) {
                if (recordLine == "Clock ID: " + clockId) {
                    matches = true;
                    break;
                }
            }
            if (matches) {
                captureEmployeeData(employee);
                updated = true;
                outFile << "Clock ID: " << employee.clockId << "\n";
                outFile << "Title: " << employee.title << "\n";
                outFile << "First Name: " << employee.firstName << "\n";
                outFile << "Last Name: " << employee.lastName << "\n";
                outFile << "Gender: " << employee.gender << "\n";
                outFile << "Date of Birth: " << employee.dateOfBirth << "\n";
                outFile << "Age: " << employee.age << "\n";
                outFile << "ID Number: " << employee.idNumber << "\n";
                outFile << "Marital Status: " << employee.maritalStatus << "\n";
                if (employee.maritalStatus == "Married") {
                    outFile << "Spouse First Name: " << employee.spouseFirstName << "\n";
                    outFile << "Spouse Last Name: " << employee.spouseLastName << "\n";
                    outFile << "Spouse Phone Number: " << employee.spousePhoneNumber << "\n";
                }
                outFile << "Phone Number: " << employee.phoneNumber << "\n";
                outFile << "Email Address: " << employee.emailAddress << "\n";
                outFile << "House Number: " << employee.houseNumber << "\n";
                outFile << "Street Name: " << employee.streetName << "\n";
                outFile << "Town: " << employee.town << "\n";
                outFile << "City: " << employee.city << "\n";
                outFile << "Postal Code: " << employee.postalCode << "\n";
                outFile << "Province: " << employee.province << "\n";
                outFile << "Position: " << employee.position << "\n";
                outFile << "Start Date: " << employee.startDate << "\n";
                outFile << "Department: " << employee.department << "\n";
            } else {
                for (const string &recordLine : record) {
                    outFile << recordLine << "\n";
                }
            }
            outFile << line << "\n";
            record.clear();
        } else {
            record.push_back(line);
        }
    }
    for (const string &recordLine : record) {
        outFile << recordLine << "\n";
    }
    inFile.close();
    outFile.close();
    if (updated) {
        remove("employeeDatabase.txt");
        rename("temp.txt", "employeeDatabase.txt");
        cout << "Employee data updated successfully.\n";
    } else {
        remove("temp.txt");
        cout << "Employee data not found.\n";
    }
}
// Function to add employee data
void addEmployeeData(Employee &employee) {
    cout << "Adding employee data...\n";
    captureEmployeeData(employee);
}
// Function to capture employee data
void captureEmployeeData(Employee &employee) {
    cout << "Capturing employee data...\n";
    cout << "Title: ";
    getline(cin, employee.title);
    employee.title = capitaliseFirstLetter(employee.title);
    while (!isValidTitle(employee.title)) {
        cerr << "Invalid title. Please enter a valid title (Mr, Mrs, Miss, Ms, Dr or Prof).\n";
        cout << "Title: ";
        getline(cin, employee.title);
        employee.title = capitaliseFirstLetter(employee.title);
    }
    cout << "First Name: ";
    getline(cin, employee.firstName);
    employee.firstName = capitaliseFirstLetter(employee.firstName);
    while (!isValidName(employee.firstName)) {
        cerr << "Invalid first name. Please enter a valid name (no numbers or special characters).\n";
        cout << "First Name: ";
        getline(cin, employee.firstName);
        employee.firstName = capitaliseFirstLetter(employee.firstName);
    }
    cout << "Middle Name: ";
    getline(cin, employee.middleName);
    employee.middleName = capitaliseFirstLetter(employee.middleName);
    while (!isValidName(employee.middleName)) {
        if (employee.middleName.empty()) {
            break; // allow blank middle name
        }
        cerr << "Invalid middle name. Please enter a valid name (no numbers or special characters).\n";
        cout << "Middle Name: ";
        getline(cin, employee.middleName);
        employee.middleName = capitaliseFirstLetter(employee.middleName);
    }
    cout << "Last Name: ";
    getline(cin, employee.lastName);
    employee.lastName = capitaliseFirstLetter(employee.lastName);
    while (!isValidName(employee.lastName)) {
        cerr << "Invalid last name. Please enter a valid name (no numbers or special characters).\n";
        cout << "Last Name: ";
        getline(cin, employee.lastName);
        employee.lastName = capitaliseFirstLetter(employee.lastName);
    }
    cout << "Gender: ";
    getline(cin, employee.gender);
    employee.gender = capitaliseFirstLetter(employee.gender);
    while (!isValidGender(employee.gender)) {
        cerr << "Invalid gender. Please enter a valid gender (Male or Female).\n";
        cout << "Gender: ";
        getline(cin, employee.gender);
        employee.gender = capitaliseFirstLetter(employee.gender);
    }
    cout << "Date of Birth: ";
    getline(cin, employee.dateOfBirth);
    employee.dateOfBirth = capitaliseFirstLetter(employee.dateOfBirth);
    while (!isValidDate(employee.dateOfBirth)) {
        cerr << "Invalid date of birth. Please enter a valid date (dd/mm/yyyy).\n";
        cout << "Date of Birth: ";
        getline(cin, employee.dateOfBirth);
    }
    cout << "Age: ";
    cin >> employee.age;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (cin.fail() || employee.age < 18 || employee.age > 60) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "Invalid age. Please enter a valid age (18-60).\n";
        cout << "Age: ";
        cin >> employee.age;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "ID Number: ";
    getline(cin, employee.idNumber);
    while (!isValidIdNumber(employee.idNumber)) {
        cerr << "Invalid ID number. Please enter a valid ID number (13 digits).\n";
        cout << "ID Number: ";
        getline(cin, employee.idNumber);
    }
    cout << "Marital Status: ";
    getline(cin, employee.maritalStatus);
    employee.maritalStatus = capitaliseFirstLetter(employee.maritalStatus);
    while (!isValidMaritalStatus(employee.maritalStatus)) {
        cerr << "Invalid marital status. Please enter a valid marital status (Single, Married, Divorced, Widowed).\n";
        cout << "Marital Status: ";
        getline(cin, employee.maritalStatus);
        employee.maritalStatus = capitaliseFirstLetter(employee.maritalStatus);
    }
    if (employee.maritalStatus == "Married") {
        cout << "Spouse First Name: ";
        getline(cin, employee.spouseFirstName);
        employee.spouseFirstName = capitaliseFirstLetter(employee.spouseFirstName);
        while (!isValidName(employee.spouseFirstName)) {
            cerr << "Invalid spouse first name. Please enter a valid name (no numbers or special characters).\n";
            cout << "Spouse First Name: ";
            getline(cin, employee.spouseFirstName);
            employee.spouseFirstName = capitaliseFirstLetter(employee.spouseFirstName);
        }
        cout << "Spouse Last Name: ";
        getline(cin, employee.spouseLastName);
        employee.spouseLastName = capitaliseFirstLetter(employee.spouseLastName);
        while (!isValidName(employee.spouseLastName)) {
            cerr << "Invalid spouse last name. Please enter a valid name (no numbers or special characters).\n";
            cout << "Spouse Last Name: ";
            getline(cin, employee.spouseLastName);
            employee.spouseLastName = capitaliseFirstLetter(employee.spouseLastName);
        }
        cout << "Spouse Phone Number: ";
        getline(cin, employee.spousePhoneNumber);
        while (!isValidPhoneNumber(employee.spousePhoneNumber)) {
            if (employee.spousePhoneNumber.empty()) {
                break; // allow blank phone number
            }
            cerr << "Invalid spouse phone number. Please enter a valid phone number (10 digits).\n";
            cout << "Spouse Phone Number: ";
            getline(cin, employee.spousePhoneNumber);
        }
    }
    cout << "Phone Number: ";
    getline(cin, employee.phoneNumber);
    while (!isValidPhoneNumber(employee.phoneNumber)) {
        if (employee.phoneNumber.empty()) {
            break; // allow blank phone number
        }
        cerr << "Invalid phone number. Please enter a valid phone number (10 digits).\n";
        cout << "Phone Number: ";
        getline(cin, employee.phoneNumber);
    }
    cout << "Email Address: ";
    getline(cin, employee.emailAddress);
    while (!isValidEmail(employee.emailAddress)) {
        if (employee.emailAddress.empty()) {
            break; // allow blank email address
        }
        cerr << "Invalid email address. Please enter a valid email address.\n";
        cout << "Email Address: ";
        getline(cin, employee.emailAddress);
    }
    cout << "House Number: ";
    getline(cin, employee.houseNumber);
    while (employee.houseNumber.empty()) {
        cerr << "Invalid house number. Please enter a valid house number.\n";
        cout << "House Number: ";
        getline(cin, employee.houseNumber);
    }
    cout << "Street Name: ";
    getline(cin, employee.streetName);
    while (employee.streetName.empty()) {
        cerr << "Invalid street name. Please enter a valid street name.\n";
        cout << "Street Name: ";
        getline(cin, employee.streetName);
    }
    cout << "Town: ";
    getline(cin, employee.town);
    employee.town = capitaliseFirstLetter(employee.town);
    while (!isValidName(employee.town)) {
        cerr << "Invalid town. Please enter a valid town (no numbers or special characters).\n";
        cout << "Town: ";
        getline(cin, employee.town);
        employee.town = capitaliseFirstLetter(employee.town);
    }
    cout << "City: ";
    getline(cin, employee.city);
    employee.city = capitaliseFirstLetter(employee.city);
    while (!isValidName(employee.city)) {
        cerr << "Invalid city. Please enter a valid city (no numbers or special characters).\n";
        cout << "City: ";
        getline(cin, employee.city);
        employee.city = capitaliseFirstLetter(employee.city);
    }
    cout << "Postal Code: ";
    getline(cin, employee.postalCode);
    while (!isValidPostalCode(employee.postalCode)) {
        cerr << "Invalid postal code. Please enter a valid postal code (4-6 digits).\n";
        cout << "Postal Code: ";
        getline(cin, employee.postalCode);
    }
    cout << "Province: ";
    getline(cin, employee.province);
    employee.province = capitaliseFirstLetter(employee.province);
    while (!isValidProvince(employee.province)) {
        cerr << "Invalid province. Please enter a valid province (no numbers or special characters).\n";
        cout << "Province: ";
        getline(cin, employee.province);
        employee.province = capitaliseFirstLetter(employee.province);
    }
    cout << "Clock ID: ";
    getline(cin, employee.clockId);
    while (!isValidClockId(employee.clockId)) {
        cerr << "Invalid clock ID. Please enter a valid clock ID (6 digits).\n";
        cout << "Clock ID: ";
        getline(cin, employee.clockId);
    }
    cout << "Position: ";
    getline(cin, employee.position);
    employee.position = capitaliseFirstLetter(employee.position);
    while (!isValidName(employee.position)) {
        cerr << "Invalid position. Please enter a valid position (no numbers or special characters).\n";
        cout << "Position: ";
        getline(cin, employee.position);
        employee.position = capitaliseFirstLetter(employee.position);
    }
    cout << "Start Date: ";
    getline(cin, employee.startDate);
    while (!isValidDate(employee.startDate)) {
        cerr << "Invalid start date. Please enter a valid start date (dd/mm/yyyy).\n";
        cout << "Start Date: ";
        getline(cin, employee.startDate);
    }
    cout << "Department: ";
    getline(cin, employee.department);
    employee.department = capitaliseFirstLetter(employee.department);
    while (!isValidName(employee.department)) {
        cerr << "Invalid department. Please enter a valid department (no numbers or special characters).\n";
        cout << "Department: ";
        getline(cin, employee.department);
        employee.department = capitaliseFirstLetter(employee.department);
    }
    saveEmployeeData(employee);
}
// Function to view the employee data
void viewEmployeeData(Employee &employee) {
    cout << "Viewing the employee data...\n";
    cout << "Enter clock ID to view employee data: ";
    string clockId;
    getline(cin, clockId);
    while (!isValidClockId(clockId)) {
        cerr << "Invalid clock ID. Please enter a valid clock ID (6 digits).\n";
        cout << "Enter clock ID to view employee data: ";
        getline(cin, clockId);
    }
    employee.clockId = clockId;
    ifstream inFile("employeeDatabase.txt");
    if (!inFile.good()) {
        cerr << "Error opening file\n";
        return;
    }
    string line;
    bool found = false;
    vector<string> record;
    while (getline(inFile, line)) {
    if (line == "--------------------------------------") {
        // End of record. Check if it contains the target clock ID
        bool hasClockId = false;
        for (const auto &l : record) {
            if (l.find("Clock ID: " + clockId) != string::npos) {
                hasClockId = true;
                break;
            }
        }
        if (hasClockId) {
            cout << "Employee data found:\n";
            cout << "------------------------------------------------\n";
            for (const auto &l : record) {
                cout << l << "\n";
            }
            cout << "------------------------------------------------\n";
            found = true;
            break;
        }
        record.clear();
    } else {
        record.push_back(line);
    }
    }
    if (!found) {
        cout << "Employee data not found.\n";
    }
    inFile.close();
    } 
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
// Function to access employees information
void accessEmployeesInformation() {
    cout << "Accessing employees information...\n";
    cout << "-----------------------------------\n";
    Employee employee;
    cout << "1. View Employee Data\n";
    cout << "2. Add Employee Data\n";
    cout << "3. Update Employee Data\n";
    cout << "4. Remove Employee Data\n";
    cout << "5. View all Employee Data\n";
    cout << "0. Exit\n";
    cout << "Please select an option: ";
    int option;
    cin >> option;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (cin.fail() || option < 0 || option > 5) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "Invalid input. Please try again.\n";
        cout << "1. View Employee Data\n";
        cout << "2. Add Employee Data\n";
        cout << "3. Update Employee Data\n";
        cout << "4. Remove Employee Data\n";
        cout << "5. View all Employee Data\n";
        cout << "0. Exit\n";
        cout << "Please select an option: ";
        cin >> option;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    switch (option) {
        case 1:
            viewEmployeeData(employee);
            break;
        case 2:
            addEmployeeData(employee);
            break;
        case 3:
            updateEmployeeData(employee);
            break;
        case 4:
            deleteEmployeeData(employee);
            break;
        case 5:
            viewAllEmployeeData(employee);
            break;
        case 0:
            return;
    }
}

// Function to manage the store
void manageTheStore() {
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
            //accessDepartmentsInformation(employee);
        } else if (option == 5) {
            Employee employee;
            accessEmployeeInformation(employee);
        } else if (option == 6) {
            // Close the store
        } else if (option == 0) {
            cout << "Closing the manager's desk... Goodbye!\n";
            break;

        }
    }
    
}
int main() {
    createEmployeeDataBaseFile();
    createSalesDataBaseFile();
    createStockDataBaseFile();
    while (true) {
        cout << "Welcome to the Manager's Desk\n";
        cout << "1. Manage The Store\n";
        cout << "2. Manage Employees\n";
        cout << "3. Manage Security\n";
        cout << "0. Exit\n";
        cout << "Please select an option: ";
        int option;
        cin >> option;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        while (cin.fail() || option < 0 || option > 3) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Invalid input. Please try again.\n";
            cout << "1. Manage The Store\n";
            cout << "2. Manage Employees\n";
            cout << "3. Manage Security\n";
            cout << "0. Exit\n";
            cout << "Please select an option: ";
            cin >> option;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (option == 1) {
            manageTheStore();
        } else if (option == 2) {
            accessEmployeesInformation();
        } else if (option == 3) {
            // Manage security
        } else if (option == 0) {
            cout << "Closing the manager's desk... Goodbye!\n";
            break;
        }
    }
    return 0;
}
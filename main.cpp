#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <vector>
#include <ios>
#include <cctype>
#include <chrono>
#include <thread>

using namespace std::this_thread;
using namespace std::chrono;

std::string capitaliseFirstLetter (std::string word) {
    if (word.length() > 0) {
        word[0] = toupper(word[0]);
    }
    return word;
}

class Employee {
    public:
        std::string title;    
        std::string firstName;
        std::string middleName;
        std::string lastName;
        std::string gender;
        std::string dateOfBirth;
        int age;
        std::string idNumber;
        std::string maritalStatus;
        std::string spouseFirstName;
        std::string spouseLastName;
        std::string spousePhoneNumber;
        std::string phoneNumber;
        std::string emailAddress;
        std::string houseNumber;
        std::string streetName;
        std::string town;
        std::string city;
        std::string postalCode;
        std::string province;
        std::string clockId;
        std::string position;
        std::string startDate;
        std::string department;
    private:
        std::string payRate;
        std::string ratePerHour;
        std::string hoursWorked;
        std::string totalPayGross;
        std::string medicalAidContribution;
        std::string payAsYouEarn;
        std::string uif;
        std::string totalPayAfterDeductionsAndTaxes;

};
class Department {
    public:
        std::string departmentName;
        int numberOfEmployees;
        int employeeCount;
        std::string departmentManager;
        std::string departmentStatus;
};
class Item {
    public:
        std::string name;
        std::string description;
        std::string category;
        std::string colour;
        std::string size;
        std::string price;
        std::string quantity;
        std::string total;
};
class DataBase {
    public:
        std::string itemName;
        std::string itemCode;
        std::string itemDepartment;
        std::string itemDescription;
        std::string itemCategory;
        std::string itemColour;
        std::string itemSize;
        std::string itemPrice;
        std::string itemQuantity;
        std::string itemTotal;
};
class StoreSecurity {
    public:
        std::string securityDoor = " ";
        std::string windows = " ";
        std::string lights = " ";
        std::string alarms = " ";
        std::string dropSafe = " ";
};
// Helpers
bool isValidTitle (const std::string &title) {
    if (title == "Mr" || title == "Mrs" || title == "Miss" || title == "Ms" || title == "Dr" || title == "Prof") {
        return true;
    } else {
        return false;
    }
}
bool isValidName (const std::string &name) {
    if (!name.empty() && name.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ") == std::string::npos) {
        return true;
    } else {
        return false;
    }
}
bool isValidGender (const std::string &gender) {
    if (gender == "Male" || gender == "Female" || gender == "Other") {
        return true;
    } else {
        return false;
    }
}
bool isValidAge (const std::string &age) {
    if (age < "18" || age > "60") {
        return false;
    } else {
        return true;
    }
}
bool isValidDate (const std::string &date) {
    if (date.length() != 10 || date[2] != '/' || date[5] != '/' ||
        date.substr(0, 2).find_first_not_of("0123456789") != std::string::npos ||
        date.substr(3, 2).find_first_not_of("0123456789") != std::string::npos ||
        date.substr(6, 4).find_first_not_of("0123456789") != std::string::npos) {
        return false;
    } else {
        return true;
    }
}
bool isValidIdNumber (const std::string &idNumber) {
    if (idNumber.length() != 13 || idNumber.find_first_not_of("0123456789") != std::string::npos) {
        return false;
    } else {
        return true;
    }
}
bool isValidMaritalStatus (const std::string &maritalStatus) {
    if (maritalStatus == "Single" || maritalStatus == "Married" || maritalStatus == "Separated" || maritalStatus == "Divorced" || maritalStatus == "Widowed") {
        return true;
    } else {
        return false;
    }
}
bool isValidPhoneNumber (const std::string &phoneNumber) {
    if (phoneNumber.length() != 10 || phoneNumber.find_first_not_of("0123456789") != std::string::npos) {
        return false;
    } else {
        return true;
    }
}
bool isValidEmail (const std::string &email) {
    if (email.find("@") == std::string::npos || email.find(".") == std::string::npos) {
        return false;
    } else {
        return true;
    }
}
bool isValidPostalCode (const std::string &postalCode) {
    if (postalCode.length() < 4 || postalCode.length() > 6 || postalCode.find_first_not_of("0123456789") != std::string::npos) {
        return false;
    } else {
        return true;
    }
}
bool isValidProvince (const std::string &province) {
    return province == "Eastern cape" || province == "Free state" ||
           province == "Gauteng" || province == "Limpopo" ||
           province == "Mpumalanga" || province == "KwaZulu natal" ||
           province == "North west" || province == "Northern cape" ||
           province == "Western cape";
}
bool isValidClockId (const std::string &clockId) {
    if (clockId.length() != 6 || clockId.find_first_not_of("0123456789") != std::string::npos) {
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
void saveSalesData(Department &department, Item &item);
void captureSalesData();
void checkManagementDepartment(Department &department);
void checkSalesDepartment(Department &department);
void checkStockDepartment(Department &department);
void checkBakeryDepartment(Department &department);
void checkGroceryDepartment(Department &department);
void checkCleaningDepartment(Department &department);
void checkBeveragesDepartment(Department &department);
void checkFruitsAndVegetablesDepartment(Department &department);
void checkMeatAndSeafoodDepartment(Department &department);
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
void viewStoreStatus(Department &department, Employee &employee);
void stockUpStore(Item &item);

// Function to create employee database file if it does not exist
void createEmployeeDataBaseFile() {
    std::ifstream existingFile("employeeDatabase.txt");
    if (!existingFile.good()) {
        std::ofstream employeeDatabaseFile("employeeDatabase.txt");
    }
}
// Function to create sales database file if it does not exist
void createSalesDataBaseFile() {
    std::ifstream existingFile("salesDatabase.txt");
    if (!existingFile.good()) {
        std::ofstream salesDatabaseFile("salesDatabase.txt");
    }
}
// Function to create stock database file if it does not exist
void createStockDataBaseFile() {
    std::ifstream existingFile("stockDatabase.txt");
    if (!existingFile.good()) {
        std::ofstream stockDatabaseFile("stockDatabase.txt");
    }
}
// Function to save sales data to sales database file
void saveSalesData(Department &department, Item &item) {
    std::cout << "Saving sales data...\n";
    std::cout << "-----------------------------------\n";
    std::ofstream outFile("salesDatabase.txt", std::ios::app);
    if (!outFile) {
        std::cerr << "Error opening file\n";
        return;
    }
    outFile << "Department: " << department.departmentName << "\n";
    outFile << "Item: " << item.name << "\n";
    outFile << "Description: " << item.description << "\n";
    outFile << "Category: " << item.category << "\n";
    outFile << "Colour: " << item.colour << "\n";
    outFile << "Size: " << item.size << "\n";
    outFile << "Price: " << item.price << "\n";
    outFile << "Quantity: " << item.quantity << "\n";
    outFile << "Total: " << item.total << "\n";
    outFile << "-----------------------------------\n";
    outFile.close();
}
// Function to check management department
void checkManagementDepartment(Department &department) {
    std::cout << "\n";
    std::cout << "-----------------------------------\n";
    std::cout << "Checking management department...\n";
    std::cout << "-----------------------------------\n";
    department.departmentName = "Management";
    department.numberOfEmployees = 18;
    department.employeeCount = 18;
    department.departmentManager = "Andile Busakwe";
    std::cout << "Department: " << department.departmentName << "\n";
    std::cout << "Number of employees: " << department.numberOfEmployees << "\n";
    std::cout << "Employee count: " << department.employeeCount << "\n";
    std::cout << "Department manager: " << department.departmentManager << "\n";
    if (department.numberOfEmployees == department.employeeCount) {
        department.departmentStatus = "The team is full in " + department.departmentName + "\n";
    } else {
        department.departmentStatus = "There is a shortage of employees in " + department.departmentName;
    }
    std::cout << "Department status: " << department.departmentStatus << "\n";
    std::cout << "-----------------------------------\n";
}
// Function to check sales department
void checkSalesDepartment(Department &department) {
    std::cout << "\n";
    std::cout << "-----------------------------------\n";
    std::cout << "Checking sales department...\n";
    std::cout << "-----------------------------------\n";
    department.departmentName = "Sales";
    department.numberOfEmployees = 12;
    department.employeeCount = 10;
    department.departmentManager = "Mbulelo Mahlangu";
    std::cout << "Department: " << department.departmentName << "\n";
    std::cout << "Number of employees: " << department.numberOfEmployees << "\n";
    std::cout << "Employee count: " << department.employeeCount << "\n";
    std::cout << "Department manager: " << department.departmentManager << "\n";
    if (department.numberOfEmployees == department.employeeCount) {
        department.departmentStatus = "The team is full in " + department.departmentName + "\n";
    } else {
        department.departmentStatus = "There is a shortage of employees in " + department.departmentName;
    }
    std::cout << "Department status: " << department.departmentStatus << "\n";
    std::cout << "-----------------------------------\n";
}
// Function to check stock department
void checkStockDepartment(Department &department) {
    std::cout << "Checking stock department...\n";
    std::cout << "-----------------------------------\n";
    department.departmentName = "Stock";
    department.numberOfEmployees = 8;
    department.employeeCount = 8;
    department.departmentManager = "Andile Danse";
    std::cout << "Department: " << department.departmentName << "\n";
    std::cout << "Number of employees: " << department.numberOfEmployees << "\n";
    std::cout << "Employee count: " << department.employeeCount << "\n";
    std::cout << "Department manager: " << department.departmentManager << "\n";
    if (department.numberOfEmployees == department.employeeCount) {
        department.departmentStatus = "The team is full in " + department.departmentName + "\n";
    } else {
        department.departmentStatus = "There is a shortage of employees in " + department.departmentName;
    }
    std::cout << "Department status: " << department.departmentStatus << "\n";
    std::cout << "-----------------------------------\n";
}
// Function to check human resources department
void checkHumanResourcesDepartment(Department &department) {
    std::cout << "Checking human resources department...\n";
    std::cout << "-----------------------------------\n";
    department.departmentName = "Human Resources";
    department.numberOfEmployees = 6;
    department.employeeCount = 6;
    department.departmentManager = "Sindiswa Dlala";
    std::cout << "Department: " << department.departmentName << "\n";
    std::cout << "Number of employees: " << department.numberOfEmployees << "\n";
    std::cout << "Employee count: " << department.employeeCount << "\n";
    std::cout << "Department manager: " << department.departmentManager << "\n";
    if (department.numberOfEmployees == department.employeeCount) {
        department.departmentStatus = "The team is full in " + department.departmentName + "\n";
    } else {
        department.departmentStatus = "There is a shortage of employees in " + department.departmentName;
    }
    std::cout << "Department status: " << department.departmentStatus << "\n";
    std::cout << "-----------------------------------\n";
}
// Function to check bakery department
void checkBakeryDepartment(Department &department) {
    std::cout << "Checking bakery department...\n";
    std::cout << "-----------------------------------\n";
    department.departmentName = "Bakery";
    department.numberOfEmployees = 4;
    department.employeeCount = 4;
    department.departmentManager = "Andile Joseph";
    std::cout << "Department: " << department.departmentName << "\n";
    std::cout << "Number of employees: " << department.numberOfEmployees << "\n";
    std::cout << "Employee count: " << department.employeeCount << "\n";
    std::cout << "Department manager: " << department.departmentManager << "\n";
    if (department.numberOfEmployees == department.employeeCount) {
        department.departmentStatus = "The team is full in " + department.departmentName + "\n";
    } else {
        department.departmentStatus = "There is a shortage of employees in " + department.departmentName;
    }
    std::cout << "Department status: " << department.departmentStatus << "\n";
    std::cout << "-----------------------------------\n";
}
// Function to check security department
void checkSecurityDepartment(Department &department) {
    std::cout << "Checking security department...\n";
    std::cout << "-----------------------------------\n";
    department.departmentName = "Security";
    department.numberOfEmployees = 4;
    department.employeeCount = 4;
    department.departmentManager = "Andile Joseph";
    std::cout << "Department: " << department.departmentName << "\n";
    std::cout << "Number of employees: " << department.numberOfEmployees << "\n";
    std::cout << "Employee count: " << department.employeeCount << "\n";
    std::cout << "Department manager: " << department.departmentManager << "\n";
    if (department.numberOfEmployees == department.employeeCount) {
        department.departmentStatus = "The team is full in " + department.departmentName + "\n";
    } else {
        department.departmentStatus = "There is a shortage of employees in " + department.departmentName;
    }
    std::cout << "Department status: " << department.departmentStatus << "\n";
    std::cout << "-----------------------------------\n";
}
// Function to check grocery department
void checkGroceryDepartment(Department &department) {
    std::cout << "Checking grocery department...\n";
    std::cout << "-----------------------------------\n";
    department.departmentName = "Grocery";
    department.numberOfEmployees = 4;
    department.employeeCount = 4;
    department.departmentManager = "Andile Joseph";
    std::cout << "Department: " << department.departmentName << "\n";
    std::cout << "Number of employees: " << department.numberOfEmployees << "\n";
    std::cout << "Employee count: " << department.employeeCount << "\n";
    std::cout << "Department manager: " << department.departmentManager << "\n";
    if (department.numberOfEmployees == department.employeeCount) {
        department.departmentStatus = "The team is full in " + department.departmentName + "\n";
    } else {
        department.departmentStatus = "There is a shortage of employees in " + department.departmentName;
    }
    std::cout << "Department status: " << department.departmentStatus << "\n";
    std::cout << "-----------------------------------\n";
}
// Function to check cleaning department
void checkCleaningDepartment(Department &department) {
    std::cout << "Checking cleaning department...\n";
    std::cout << "-----------------------------------\n";
    department.departmentName = "Cleaning";
    department.numberOfEmployees = 4;
    department.employeeCount = 4;
    department.departmentManager = "Andile Joseph";
    std::cout << "Department: " << department.departmentName << "\n";
    std::cout << "Number of employees: " << department.numberOfEmployees << "\n";
    std::cout << "Employee count: " << department.employeeCount << "\n";
    std::cout << "Department manager: " << department.departmentManager << "\n";
    if (department.numberOfEmployees == department.employeeCount) {
        department.departmentStatus = "The team is full in " + department.departmentName + "\n";
    } else {
        department.departmentStatus = "There is a shortage of employees in " + department.departmentName;
    }
    std::cout << "Department status: " << department.departmentStatus << "\n";
    std::cout << "-----------------------------------\n";
}
// Function to check beverages department
void checkBeveragesDepartment(Department &department) {
    std::cout << "Checking beverages department...\n";
    std::cout << "-----------------------------------\n";
    department.departmentName = "Beverages";
    department.numberOfEmployees = 4;
    department.employeeCount = 4;
    department.departmentManager = "Andile Joseph";
    std::cout << "Department: " << department.departmentName << "\n";
    std::cout << "Number of employees: " << department.numberOfEmployees << "\n";
    std::cout << "Employee count: " << department.employeeCount << "\n";
    std::cout << "Department manager: " << department.departmentManager << "\n";
    if (department.numberOfEmployees == department.employeeCount) {
        department.departmentStatus = "The team is full in " + department.departmentName + "\n";
    } else {
        department.departmentStatus = "There is a shortage of employees in " + department.departmentName;
    }
    std::cout << "Department status: " << department.departmentStatus << "\n";
    std::cout << "-----------------------------------\n";
}
// Function to check fruits and vegetables department
void checkFruitsAndVegetablesDepartment(Department &department) {
    std::cout << "Checking fruits and vegetables department...\n";
    std::cout << "-----------------------------------\n";
    department.departmentName = "Fruits and Vegetables";
    department.numberOfEmployees = 4;
    department.employeeCount = 4;
    department.departmentManager = "Andile Joseph";
    std::cout << "Department: " << department.departmentName << "\n";
    std::cout << "Number of employees: " << department.numberOfEmployees << "\n";
    std::cout << "Employee count: " << department.employeeCount << "\n";
    std::cout << "Department manager: " << department.departmentManager << "\n";
    if (department.numberOfEmployees == department.employeeCount) {
        department.departmentStatus = "The team is full in " + department.departmentName + "\n";
    } else {
        department.departmentStatus = "There is a shortage of employees in " + department.departmentName;
    }
    std::cout << "Department status: " << department.departmentStatus << "\n";
    std::cout << "-----------------------------------\n";
}
// Function to check meat and seafood department
void checkMeatAndSeafoodDepartment(Department &department) {
    std::cout << "Checking meat and seafood department...\n";
    std::cout << "-----------------------------------\n";
    department.departmentName = "Meat and Seafood";
    department.numberOfEmployees = 4;
    department.employeeCount = 4;
    department.departmentManager = "Andile Joseph";
    std::cout << "Department: " << department.departmentName << "\n";
    std::cout << "Number of employees: " << department.numberOfEmployees << "\n";
    std::cout << "Employee count: " << department.employeeCount << "\n";
    std::cout << "Department manager: " << department.departmentManager << "\n";
    if (department.numberOfEmployees == department.employeeCount) {
        department.departmentStatus = "The team is full in " + department.departmentName + "\n";
    } else {
        department.departmentStatus = "There is a shortage of employees in " + department.departmentName;
    }
    std::cout << "Department status: " << department.departmentStatus << "\n";
    std::cout << "-----------------------------------\n";
}
// Function to stock up the store
void stockUpStore(Item &item) {
    // The items entered by the user will be added to the stock database
    std::cout << "Stocking up the store...\n";
    std::cout << "-----------------------------------\n";
    std::ofstream outFile("stockDatabase.txt", std::ios::app);
    if (!outFile) {
        std::cerr << "Error opening file\n";
        return;
    }
    std::cout << "Enter Item Name: ";
    std::getline(std::cin, item.name);
    item.name = capitaliseFirstLetter(item.name);
    while (item.name.empty()) {
        std::cout << "Item name cannot be empty. Please enter a valid item name: ";
        std::getline(std::cin, item.name);
        item.name = capitaliseFirstLetter(item.name);
    }
    std::ifstream stockFile("stockDatabase.txt");
    if (!stockFile) {
        std::cerr << "Unable to open stock database file.\n";
    }
    stockFile.close();
    

}
// Function to capture sales data
void captureSalesData() {
    Item item;
    std::cout << "Capturing sales data...\n";
    std::cout << "-----------------------------------\n";
    std::cout << "Enter Item Name: ";
    std::getline(std::cin, item.name);
    item.name = capitaliseFirstLetter(item.name);
    while (item.name.empty()) {
        std::cout << "Item name cannot be empty. Please enter a valid item name: ";
        std::getline(std::cin, item.name);
        item.name = capitaliseFirstLetter(item.name);
    }
    std::ifstream existingFile("salesDatabase.txt");
    // The program will deduct the quantity of the sold item from the stock database
    if (existingFile.is_open()) {
        std::string line;
        while (std::getline(existingFile, line)) {
            if (line.find("Item: " + item.name) != std::string::npos) {
                std::cout << "-----------------------------------\n";
                std::cout << "Item: " << item.name << "\n";
                std::cout << "Description: " << item.description << "\n";
                std::cout << "Category: " << item.category << "\n";
                std::cout << "Colour: " << item.colour << "\n";
                std::cout << "Size: " << item.size << "\n";
                std::cout << "Price: R" << item.price << "\n";
                std::cout << "Quantity: " << item.quantity << "\n";
                std::cout << "Total: R" << item.total << "\n";
                std::cout << "-----------------------------------\n";
                item.quantity = std::to_string(std::stoi(item.quantity) - 1);
                item.total = std::to_string(std::stod(item.total) - std::stod(item.price));
                break;
            }
        }
    }
}
// Function to save employee data
void saveEmployeeData(Employee &employee) {
    std::cout << "Saving employee data...\n";
    std::cout << "-----------------------------------\n";
    std::ofstream outFile("employeeDatabase.txt", std::ios::app);
    if (!outFile) {
        std::cerr << "Error opening file\n";
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
    std::cout << "Employee data saved successfully.\n";
}
// Function to access employee information
void accessEmployeeInformation(Employee &employee) {
    std::cout << "Accessing employee information...\n";
    std::cout << "-----------------------------------\n";
    std::cout << "1. View Employee Data\n";
    std::cout << "2. Add Employee Data\n";
    std::cout << "3. Update Employee Data\n";
    std::cout << "4. Remove Employee Data\n";
    std::cout << "5. View all Employee Data\n";
    std::cout << "0. Exit\n";
    std::cout << "Please select an option: ";
    int option;
    std::cin >> option;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (std::cin.fail() || option < 0 || option > 5) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cerr << "Invalid input. Please try again.\n";
        std::cout << "1. View Employee Data\n";
        std::cout << "2. Add Employee Data\n";
        std::cout << "3. Update Employee Data\n";
        std::cout << "4. Remove Employee Data\n";
        std::cout << "5. View all Employee Data\n";
        std::cout << "0. Exit\n";
        std::cout << "Please select an option: ";
        std::cin >> option;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid option. Please try again.\n";
            break;
    }
}
// Function to view all employee data
void viewAllEmployeeData(Employee &) {
    std::cout << "Viewing all employee data...\n";
    std::cout << "-----------------------------------\n";
    std::ifstream inFile("employeeDatabase.txt");
    if (!inFile) {
        std::cerr << "Error opening file\n";
        return;
    }
    std::string line;
    while (std::getline(inFile, line)) {
        std::cout << line << "\n";
    }
    inFile.close();
}
// Function to remove employee data
void deleteEmployeeData(Employee &employee) {
    std::cout << "Removing employee data...\n";
    std::cout << "-----------------------------------\n";
    std::cout << "Enter clock ID to remove employee data: ";
    std::string clockId;
    std::getline(std::cin, clockId);
    while (!isValidClockId(clockId)) {
        std::cerr << "Invalid clock ID. Please enter a valid clock ID (6 digits).\n";
        std::cout << "Enter clock ID to remove employee data: ";
        std::getline(std::cin, clockId);
    }
    employee.clockId = clockId;
    std::ifstream inFile("employeeDatabase.txt");
    std::ofstream outFile("temp.txt");
    if (!inFile || !outFile) {
        std::cerr << "Error opening employee database\n";
        return;
    }
    std::string line;
    std::vector<std::string> record;
    bool removed = false;
    while (std::getline(inFile, line)) {
        if (line == "--------------------------------------") {
            bool matches = false;
            for (const std::string &recordLine : record) {
                if (recordLine == "Clock ID: " + clockId) {
                    matches = true;
                    break;
                }
            }
            if (!matches) {
                for (const std::string &recordLine : record) {
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
    for (const std::string &recordLine : record) {
        outFile << recordLine << "\n";
    }
    inFile.close();
    outFile.close();
    if (removed) {
        remove("employeeDatabase.txt");
        rename("temp.txt", "employeeDatabase.txt");
        std::cout << "Employee data removed successfully.\n";
    } else {
        remove("temp.txt");
        std::cout << "Employee data not found.\n";
    }
}
// Function to update employee data
void updateEmployeeData(Employee &employee) {
    std::cout << "Updating employee data...\n";
    std::cout << "-----------------------------------\n";
    std::cout << "Enter clock ID to update employee data: ";
    std::string clockId;
    std::getline(std::cin, clockId);
    while (!isValidClockId(clockId)) {
        std::cerr << "Invalid clock ID. Please enter a valid clock ID (6 digits).\n";
        std::cout << "Enter clock ID to update employee data: ";
        std::getline(std::cin, clockId);
    }
    employee.clockId = clockId;
    std::ifstream inFile("employeeDatabase.txt");
    std::ofstream outFile("temp.txt");
    if (!inFile || !outFile) {
        std::cerr << "Error opening employee database\n";
        return;
    }
    std::string line;
    std::vector<std::string> record;
    bool updated = false;
    while (std::getline(inFile, line)) {
        if (line == "--------------------------------------") {
            bool matches = false;
            for (const std::string &recordLine : record) {
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
                for (const std::string &recordLine : record) {
                    outFile << recordLine << "\n";
                }
            }
            outFile << line << "\n";
            record.clear();
        } else {
            record.push_back(line);
        }
    }
    for (const std::string &recordLine : record) {
        outFile << recordLine << "\n";
    }
    inFile.close();
    outFile.close();
    if (updated) {
        remove("employeeDatabase.txt");
        rename("temp.txt", "employeeDatabase.txt");
        std::cout << "Employee data updated successfully.\n";
    } else {
        remove("temp.txt");
        std::cout << "Employee data not found.\n";
    }
}
// Function to add employee data
void addEmployeeData(Employee &employee) {
    captureEmployeeData(employee);
}
// Function to capture employee data
void captureEmployeeData(Employee &employee) {
    std::cout << "Capturing employee data...\n";
    std::cout << "Title: ";
    std::getline(std::cin, employee.title);
    employee.title = capitaliseFirstLetter(employee.title);
    while (!isValidTitle(employee.title)) {
        std::cerr << "Invalid title. Please enter a valid title (Mr, Mrs, Miss, Ms, Dr or Prof).\n";
        std::cout << "Title: ";
        std::getline(std::cin, employee.title);
        employee.title = capitaliseFirstLetter(employee.title);
    }
    std::cout << "First Name: ";
    std::getline(std::cin, employee.firstName);
    employee.firstName = capitaliseFirstLetter(employee.firstName);
    while (!isValidName(employee.firstName)) {
        std::cerr << "Invalid first name. Please enter a valid name (no numbers or special characters).\n";
        std::cout << "First Name: ";
        std::getline(std::cin, employee.firstName);
        employee.firstName = capitaliseFirstLetter(employee.firstName);
    }
    std::cout << "Middle Name: ";
    std::getline(std::cin, employee.middleName);
    employee.middleName = capitaliseFirstLetter(employee.middleName);
    while (!isValidName(employee.middleName)) {
        if (employee.middleName.empty()) {
            break; // allow blank middle name
        }
        std::cerr << "Invalid middle name. Please enter a valid name (no numbers or special characters).\n";
        std::cout << "Middle Name: ";
        std::getline(std::cin, employee.middleName);
        employee.middleName = capitaliseFirstLetter(employee.middleName);
    }
    std::cout << "Last Name: ";
    std::getline(std::cin, employee.lastName);
    employee.lastName = capitaliseFirstLetter(employee.lastName);
    while (!isValidName(employee.lastName)) {
        std::cerr << "Invalid last name. Please enter a valid name (no numbers or special characters).\n";
        std::cout << "Last Name: ";
        std::getline(std::cin, employee.lastName);
        employee.lastName = capitaliseFirstLetter(employee.lastName);
    }
    std::cout << "Gender: ";
    std::getline(std::cin, employee.gender);
    employee.gender = capitaliseFirstLetter(employee.gender);
    while (!isValidGender(employee.gender)) {
        std::cerr << "Invalid gender. Please enter a valid gender (Male or Female).\n";
        std::cout << "Gender: ";
        std::getline(std::cin, employee.gender);
        employee.gender = capitaliseFirstLetter(employee.gender);
    }
    std::cout << "Date of Birth: ";
    std::getline(std::cin, employee.dateOfBirth);
    employee.dateOfBirth = capitaliseFirstLetter(employee.dateOfBirth);
    while (!isValidDate(employee.dateOfBirth)) {
        std::cerr << "Invalid date of birth. Please enter a valid date (dd/mm/yyyy).\n";
        std::cout << "Date of Birth: ";
        std::getline(std::cin, employee.dateOfBirth);
    }
    std::cout << "Age: ";
    std::cin >> employee.age;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (std::cin.fail() || employee.age < 18 || employee.age > 60) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cerr << "Invalid age. Please enter a valid age (18-60).\n";
        std::cout << "Age: ";
        std::cin >> employee.age;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << "ID Number: ";
    std::getline(std::cin, employee.idNumber);
    while (!isValidIdNumber(employee.idNumber)) {
        std::cerr << "Invalid ID number. Please enter a valid ID number (13 digits).\n";
        std::cout << "ID Number: ";
        std::getline(std::cin, employee.idNumber);
    }
    std::cout << "Marital Status: ";
    std::getline(std::cin, employee.maritalStatus);
    employee.maritalStatus = capitaliseFirstLetter(employee.maritalStatus);
    while (!isValidMaritalStatus(employee.maritalStatus)) {
        std::cerr << "Invalid marital status. Please enter a valid marital status (Single, Married, Divorced, Widowed).\n";
        std::cout << "Marital Status: ";
        std::getline(std::cin, employee.maritalStatus);
        employee.maritalStatus = capitaliseFirstLetter(employee.maritalStatus);
    }
    if (employee.maritalStatus == "Married") {
        std::cout << "Spouse First Name: ";
        std::getline(std::cin, employee.spouseFirstName);
        employee.spouseFirstName = capitaliseFirstLetter(employee.spouseFirstName);
        while (!isValidName(employee.spouseFirstName)) {
            std::cerr << "Invalid spouse first name. Please enter a valid name (no numbers or special characters).\n";
            std::cout << "Spouse First Name: ";
            std::getline(std::cin, employee.spouseFirstName);
            employee.spouseFirstName = capitaliseFirstLetter(employee.spouseFirstName);
        }
        std::cout << "Spouse Last Name: ";
        std::getline(std::cin, employee.spouseLastName);
        employee.spouseLastName = capitaliseFirstLetter(employee.spouseLastName);
        while (!isValidName(employee.spouseLastName)) {
            std::cerr << "Invalid spouse last name. Please enter a valid name (no numbers or special characters).\n";
            std::cout << "Spouse Last Name: ";
            std::getline(std::cin, employee.spouseLastName);
            employee.spouseLastName = capitaliseFirstLetter(employee.spouseLastName);
        }
        std::cout << "Spouse Phone Number: ";
        std::getline(std::cin, employee.spousePhoneNumber);
        while (!isValidPhoneNumber(employee.spousePhoneNumber)) {
            if (employee.spousePhoneNumber.empty()) {
                break; // allow blank phone number
            }
            std::cerr << "Invalid spouse phone number. Please enter a valid phone number (10 digits).\n";
            std::cout << "Spouse Phone Number: ";
            std::getline(std::cin, employee.spousePhoneNumber);
        }
    }
    std::cout << "Phone Number: ";
    std::getline(std::cin, employee.phoneNumber);
    while (!isValidPhoneNumber(employee.phoneNumber)) {
        if (employee.phoneNumber.empty()) {
            break; // allow blank phone number
        }
        std::cerr << "Invalid phone number. Please enter a valid phone number (10 digits).\n";
        std::cout << "Phone Number: ";
        std::getline(std::cin, employee.phoneNumber);
    }
    std::cout << "Email Address: ";
    std::getline(std::cin, employee.emailAddress);
    while (!isValidEmail(employee.emailAddress)) {
        if (employee.emailAddress.empty()) {
            break; // allow blank email address
        }
        std::cerr << "Invalid email address. Please enter a valid email address.\n";
        std::cout << "Email Address: ";
        std::getline(std::cin, employee.emailAddress);
    }
    std::cout << "House Number: ";
    std::getline(std::cin, employee.houseNumber);
    while (employee.houseNumber.empty()) {
        std::cerr << "Invalid house number. Please enter a valid house number.\n";
        std::cout << "House Number: ";
        std::getline(std::cin, employee.houseNumber);
    }
    std::cout << "Street Name: ";
    std::getline(std::cin, employee.streetName);
    employee.streetName = capitaliseFirstLetter(employee.streetName);
    while (employee.streetName.empty()) {
        std::cerr << "Invalid street name. Please enter a valid street name.\n";
        std::cout << "Street Name: ";
        std::getline(std::cin, employee.streetName);
        employee.streetName = capitaliseFirstLetter(employee.streetName);
    }
    std::cout << "Town: ";
    std::getline(std::cin, employee.town);
    employee.town = capitaliseFirstLetter(employee.town);
    while (!isValidName(employee.town)) {
        std::cerr << "Invalid town. Please enter a valid town (no numbers or special characters).\n";
        std::cout << "Town: ";
        std::getline(std::cin, employee.town);
        employee.town = capitaliseFirstLetter(employee.town);
    }
    std::cout << "City: ";
    std::getline(std::cin, employee.city);
    employee.city = capitaliseFirstLetter(employee.city);
    while (!isValidName(employee.city)) {
        std::cerr << "Invalid city. Please enter a valid city (no numbers or special characters).\n";
        std::cout << "City: ";
        std::getline(std::cin, employee.city);
        employee.city = capitaliseFirstLetter(employee.city);
    }
    std::cout << "Postal Code: ";
    std::getline(std::cin, employee.postalCode);
    while (!isValidPostalCode(employee.postalCode)) {
        std::cerr << "Invalid postal code. Please enter a valid postal code (4-6 digits).\n";
        std::cout << "Postal Code: ";
        std::getline(std::cin, employee.postalCode);
    }
    std::cout << "Province: ";
    std::getline(std::cin, employee.province);
    employee.province = capitaliseFirstLetter(employee.province);
    while (!isValidProvince(employee.province)) {
        std::cerr << "Invalid province. Please enter a valid province (no numbers or special characters).\n";
        std::cout << "Province: ";
        std::getline(std::cin, employee.province);
        employee.province = capitaliseFirstLetter(employee.province);
    }
    std::cout << "Clock ID: ";
    std::getline(std::cin, employee.clockId);
    while (!isValidClockId(employee.clockId)) {
        std::cerr << "Invalid clock ID. Please enter a valid clock ID (6 digits).\n";
        std::cout << "Clock ID: ";
        std::getline(std::cin, employee.clockId);
    }
    std::cout << "Position: ";
    std::getline(std::cin, employee.position);
    employee.position = capitaliseFirstLetter(employee.position);
    while (!isValidName(employee.position)) {
        std::cerr << "Invalid position. Please enter a valid position (no numbers or special characters).\n";
        std::cout << "Position: ";
        std::getline(std::cin, employee.position);
        employee.position = capitaliseFirstLetter(employee.position);
    }
    std::cout << "Start Date: ";
    std::getline(std::cin, employee.startDate);
    while (!isValidDate(employee.startDate)) {
        std::cerr << "Invalid start date. Please enter a valid start date (dd/mm/yyyy).\n";
        std::cout << "Start Date: ";
        std::getline(std::cin, employee.startDate);
    }
    std::cout << "Department: ";
    std::getline(std::cin, employee.department);
    employee.department = capitaliseFirstLetter(employee.department);
    while (!isValidName(employee.department)) {
        std::cerr << "Invalid department. Please enter a valid department (no numbers or special characters).\n";
        std::cout << "Department: ";
        std::getline(std::cin, employee.department);
        employee.department = capitaliseFirstLetter(employee.department);
    }
    saveEmployeeData(employee);
}
// Function to view the employee data
void viewEmployeeData(Employee &employee) {
    std::cout << "Viewing an employee's data...\n";
    std::cout << "Enter clock ID to view employee data: ";
    std::string clockId;
    std::getline(std::cin, clockId);
    while (!isValidClockId(clockId)) {
        std::cerr << "Invalid clock ID. Please enter a valid clock ID (6 digits).\n";
        std::cout << "Enter clock ID to view employee data: ";
        std::getline(std::cin, clockId);
    }
    employee.clockId = clockId;
    std::ifstream inFile("employeeDatabase.txt");
    if (!inFile.good()) {
        std::cerr << "Error opening file\n";
        return;
    }
    std::string line;
    bool found = false;
    std::vector<std::string> record;
    while (std::getline(inFile, line)) {
    if (line == "--------------------------------------") {
        // End of record. Check if it contains the target clock ID
        bool hasClockId = false;
        for (const auto &l : record) {
            if (l.find("Clock ID: " + clockId) != std::string::npos) {
                hasClockId = true;
                break;
            }
        }
        if (hasClockId) {
            std::cout << "Employee data found:\n";
            std::cout << "------------------------------------------------\n";
            for (const auto &l : record) {
                std::cout << l << "\n";
            }
            std::cout << "------------------------------------------------\n";
            found = true;
            break;
        }
        record.clear();
    } else {
        record.push_back(line);
    }
    }
    if (!found) {
        std::cout << "Employee data not found.\n";
    }
    inFile.close();
}
// Function to check the doors
void checkDoors(StoreSecurity &storeSecurity) {
    (void)storeSecurity;
    std::cout << "Checking the Security door...\n";
    std::string securityDoor = "Closed";
    std::cout << "The Security Door is " << securityDoor << ".\n";
    return;
    }

// Function to check the windows
void checkWindows(StoreSecurity &storeSecurity) {
    (void)storeSecurity;
    std::cout << "Checking the windows...\n";
    std::string windows = "Closed";
    std::cout << "The windows are " << windows << "...\n";
    return;
    }

// Function to check the lights
void checkLights(StoreSecurity &storeSecurity) {
    (void)storeSecurity;
    std::cout << "Checking the lights...\n";
    std::string lights = "On";
    std::cout << "The lights are " << lights << "...\n";
    return;
    }

// Function to check the alarms
void checkAlarms(StoreSecurity &storeSecurity) {
    (void)storeSecurity;
    std::cout << "Checking the alarm...\n";
    std::string alarms = "Off";
    std::cout << "The alarm is " << alarms << "...\n";
    return;
}
// Function to check the drop safe
void checkDropSafe(StoreSecurity &storeSecurity) {
    (void)storeSecurity;
    std::cout << "Checking the drop safe...\n";
    std::string dropSafe = "Closed";
    std::cout << "The drop safe is " << dropSafe << "...\n";
    return;        
}

// Function to view the store security
void viewStoreSecurity(StoreSecurity &storeSecurity) {
    std::cout << "Viewing the store security status...\n";
    checkDoors(storeSecurity);
    checkWindows(storeSecurity);
    checkLights(storeSecurity);
    checkAlarms(storeSecurity);
    checkDropSafe(storeSecurity);
    std::cout << "This is the current store security status.\n";
}
// Function to open the store
void openStore() {
    StoreSecurity storeSecurity;
    std::cout << "Running security checks...\n";
    checkDoors(storeSecurity);
    checkWindows(storeSecurity);
    checkLights(storeSecurity);
    checkAlarms(storeSecurity);
    checkDropSafe(storeSecurity);
    std::cout << "The store is now open.\n";
}
// Function to view the store status
void viewStoreStatus(Department &department) {
    std::cout << "Viewing the store status...\n";
    checkBakeryDepartment(department);
    checkGroceryDepartment(department);
    checkSalesDepartment(department);
    checkSecurityDepartment(department);
    checkBeveragesDepartment(department);
    checkHumanResourcesDepartment(department);
    checkMeatAndSeafoodDepartment(department);
    std::cout << "The store is currently open.\n";
}
// Function to access employees information
void accessEmployeesInformation() {
    std::cout << "Accessing employees information...\n";
    std::cout << "-----------------------------------\n";
    Employee employee;
    std::cout << "1. View Employee Data\n";
    std::cout << "2. Add Employee Data\n";
    std::cout << "3. Update Employee Data\n";
    std::cout << "4. Remove Employee Data\n";
    std::cout << "5. View all Employee Data\n";
    std::cout << "0. Exit\n";
    std::cout << "Please select an option: ";
    int option;
    std::cin >> option;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (std::cin.fail() || option < 0 || option > 5) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cerr << "Invalid input. Please try again.\n";
        std::cout << "1. View Employee Data\n";
        std::cout << "2. Add Employee Data\n";
        std::cout << "3. Update Employee Data\n";
        std::cout << "4. Remove Employee Data\n";
        std::cout << "5. View all Employee Data\n";
        std::cout << "0. Exit\n";
        std::cout << "Please select an option: ";
        std::cin >> option;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
            break;
        default:
            break;
    }
}

// Function to manage the store
void manageTheStore() {
    std::cout << "Store Management\n";
    while (true) {
        std::cout << "1. Open The Store\n";
        std::cout << "2. View Store Security\n";
        std::cout << "3. View Store Status\n";
        std::cout << "4. Stock up the store\n";
        std::cout << "5. Access Departments Information\n";
        std::cout << "6. Access Employees Information\n";
        std::cout << "7. Close The Store\n";
        std::cout << "0. Exit\n";
        std::cout << "Please select an option: ";
        int option;
        std::cin >> option;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        while (std::cin.fail() || option < 0 || option > 7) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Invalid input. Please try again.\n";
            std::cout << "1. Open The Store\n";
            std::cout << "2. View Store Security\n";
            std::cout << "3. View Store Status\n";
            std::cout << "4. Stock up the store\n";
            std::cout << "5. Access Departments Information\n";
            std::cout << "6. Access Employees Information\n";
            std::cout << "7. Close The Store\n";
            std::cout << "0. Exit\n";
            std::cout << "Please select an option: ";
            std::cin >> option;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if (option == 1) {
            StoreSecurity storeSecurity;
            openStore();
            sleep_for(seconds(5));
            return;
        } else if (option == 2) {
            StoreSecurity storeSecurity;
            viewStoreSecurity(storeSecurity);
            sleep_for(seconds(5));
            return;
        } else if (option == 3) {
            Department department;
            Employee employee;
            viewStoreStatus(department);
            sleep_for(seconds(5));
            return;
        } else if (option == 4) {
            Item item;
            stockUpStore(item);
            return;
        } else if (option == 5) {
            Employee employee;
            accessEmployeeInformation(employee);
        } else if (option == 6) {
            // Close the store
        } else if (option == 0) {
            std::cout << "Closing the manager's desk... Goodbye!\n";
            break;

        }
    }
    
}
int main() {
    createEmployeeDataBaseFile();
    createSalesDataBaseFile();
    createStockDataBaseFile();
    std::cout << "Welcome to the Manager's Desk\n";
    while (true) {
        std::cout << "\n";
        std::cout << "--------------------------\n";
        std::cout << "What would you like to do?\n";
        std::cout << "--------------------------\n";
        std::cout << "\n";
        std::cout << "1. Manage The Store\n";
        std::cout << "2. Manage Employees\n";
        std::cout << "3. Manage Security\n";
        std::cout << "0. Exit\n";
        std::cout << "Please select an option: ";
        int option;
        std::cin >> option;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        while (std::cin.fail() || option < 0 || option > 3) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Invalid input. Please try again.\n";
            std::cout << "1. Manage The Store\n";
            std::cout << "2. Manage Employees\n";
            std::cout << "3. Manage Security\n";
            std::cout << "0. Exit\n";
            std::cout << "Please select an option: ";
            std::cin >> option;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if (option == 1) {
            manageTheStore();
        } else if (option == 2) {
            accessEmployeesInformation();
        } else if (option == 3) {
            // Manage security
        } else if (option == 0) {
            std::cout << "Closing the manager's desk... Goodbye!\n";
            sleep_for(seconds(2));
            exit(0);
        }
    }
    return 0;
}
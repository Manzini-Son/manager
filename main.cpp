#include <cctype>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <ios>
#include <iostream>
#include <limits>
#include <string>
#include <thread>
#include <vector>
#include <termios.h>



using namespace std::this_thread;
using namespace std::chrono;

std::string capitaliseFirstLetter(std::string word) {
  if (word.length() > 0) {
    word[0] = toupper(word[0]);
  }
  return word;
}

class ManagerApp {
  public:
  std::string supermarket;
  std::string hospital;
  std::string policeStation;
  std::string lawFirm;
  std::string carWash;
};
class SupermarketEmployee {
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
  std::string supermarketDepartment;
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
class SupermarketDepartment {
public:
  std::string supermarketDepartmentName; //eg Bakery, Butchery, Hardware, etc.
  std::string supermarketDepartmentManagerFirstName = " ";
  std::string supermarketDepartmentManagerLastName = " ";
  std::string supermarketDepartmentManagerClockId = " ";
  int numberOfRequiredEmployees;
  int employeesCurrentlyPresentCount;
  std::string supermarketDepartmentStatus;
};
class SupermarketItem {
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
class SupermarketDataBase {
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
class SupermarketSecurity {
public:
  std::string securityDoor = " ";
  std::string windows = " ";
  std::string lights = " ";
  std::string alarms = " ";
  std::string dropSafe = " ";
};

// Helpers
bool isValidTitle(const std::string &title) {
  if (title == "Mr" || title == "Mrs" || title == "Miss" || title == "Ms" || title == "Dr" || title == "Prof") {
    return true;
  } else {
    return false;
  }
}
bool isValidName(const std::string &name) {
  if (!name.empty() &&
      name.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ") == std::string::npos) {
    return true;
  } else {
    return false;
  }
}
bool isValidGender(const std::string &gender) {
  if (gender == "Male" || gender == "Female" || gender == "Other") {
    return true;
  } else {
    return false;
  }
}
bool isValidPin(const std::string &encryptPin) {
  if (encryptPin.length() < 4 || encryptPin.length() > 6) {
    return false;
  } else {
    return true;
  }
}
bool isValidAge(const std::string &age) {
  if (age < "18" || age > "60") {
    return false;
  } else {
    return true;
  }
}
bool isValidDate(const std::string &date) {
  if (date.length() != 10 || date[2] != '/' || date[5] != '/' ||
      date.substr(0, 2).find_first_not_of("0123456789") != std::string::npos ||
      date.substr(3, 2).find_first_not_of("0123456789") != std::string::npos ||
      date.substr(6, 4).find_first_not_of("0123456789") != std::string::npos) {
    return false;
  } else {
    return true;
  }
}
bool isValidIdNumber(const std::string &idNumber) {
  if (idNumber.length() != 13 || idNumber.find_first_not_of("0123456789") != std::string::npos) {
    return false;
  } else {
    return true;
  }
}
bool isValidMaritalStatus(const std::string &maritalStatus) {
  if (maritalStatus == "Single" || maritalStatus == "Married" || maritalStatus == "Separated" || maritalStatus == "Divorced" || maritalStatus == "Widowed") {
    return true;
  } else {
    return false;
  }
}
bool isValidPhoneNumber(const std::string &phoneNumber) {
  if (phoneNumber.length() != 10 || phoneNumber.find_first_not_of("0123456789") != std::string::npos) {
    return false;
  } else {
    return true;
  }
}
bool isValidEmail(const std::string &email) {
  if (email.find("@") == std::string::npos || email.find(".") == std::string::npos) {
    return false;
  } else {
    return true;
  }
}
bool isValidPostalCode(const std::string &postalCode) {
  if (postalCode.length() < 4 || postalCode.length() > 6 || postalCode.find_first_not_of("0123456789") != std::string::npos) {
    return false;
  } else {
    return true;
  }
}
bool isValidProvince(const std::string &province) {
  return province == "Eastern cape" || province == "Free state" ||
         province == "Gauteng" || province == "Limpopo" ||
         province == "Mpumalanga" || province == "KwaZulu natal" ||
         province == "North west" || province == "Northern cape" ||
         province == "Western cape";
}
bool isValidClockId(const std::string &clockId) {
  if (clockId.length() != 6 || clockId.find_first_not_of("0123456789") != std::string::npos) {
    return false;
  } else {
    return true;
  }
}
// Prototypes of login functions
std::string encryptPIN(const std::string &pin);
std::string decryptPIN(const std::string &encryptedPIN);
std::string getPIN();

// Prototypes of functions
void createEmployeeDataBaseFile();
bool hasManagerAccounts();
void createAccount();
bool loginUser(std::string &loggedInUser);
void manageManagerAccount(bool &canModify);
bool recoverManagerAccount(bool &canModify);
void createSalesDataBaseFile();
void showMenu(bool &canModify);
void manageTheSupermarkt(bool canModify);
void checkSecurityDoor(SupermarketSecurity &supermarketSecurity);
void checkWindows(SupermarketSecurity &supermaketSecurity);
void checkLights(SupermarketSecurity &supermarketSecurity);
void checkAlarms(SupermarketSecurity &supermarketSecurity);
void checkDropSafe(SupermarketSecurity &supermarketSecurity);
void accessSupermarketEmployeeInformation(SupermarketEmployee &supermarketEmployee, bool canModify);
void manageSecurity(SupermarketSecurity &supermarketSecurity, bool canModify);
void saveSalesData(SupermarketDepartment &supermarketDepartment, SupermarketItem &supermarketItem);
void captureSupermarketSalesData(SupermarketDepartment &supermarketDepartment, SupermarketItem &supermarketItem);
void checkManagementDepartment(SupermarketDepartment &supermarketDepartment);
const std::string RECORD_SEPARATOR = "--------------------------------------";
void checkSalesDepartment(SupermarketDepartment &supermarketDepartment);
void checkStockDepartment(SupermarketDepartment &supermarketDepartment);
void checkBakeryDepartment(SupermarketDepartment &supermarketDepartment);
void checkGroceryDepartment(SupermarketDepartment &supermarketDepartment);
void checkCleaningDepartment(SupermarketDepartment &supermarsupermarketDepartment);
void checkBeveragesDepartment(SupermarketDepartment &supermarketDepartment);
void checkFruitsAndVegetablesDepartment(SupermarketDepartment &supermarketDepartment);
void checkMeatAndSeafoodDepartment(SupermarketDepartment &supermarketDepartment);
// void viewSalesData();
// void updateSalesData();
// void deleteSalesData();
void checkSupermarketSecurity(SupermarketDepartment &supermarketDepartment);
void createStockDataBaseFile();
void saveSupermarketEmployeeData(SupermarketEmployee &supermarketEmployee);
void captureSupermarketEmployeeData(SupermarketEmployee &supermarketEmployee);
void addEmployeeData(SupermarketEmployee &supermarketEmployee);
void viewSupermarketEmployeeData(SupermarketEmployee &supermarketEmployee);
void viewSupermarketSecurity(SupermarketSecurity &supermarketSecurity);
void editSupermarketEmployeeInformation(SupermarketEmployee &supermarketEmployee);
void deleteEmployeeData(SupermarketEmployee &supermarketEmployee);
void viewAllEmployeeData(SupermarketEmployee &supermarketEmployee);
void viewStoreStatus(SupermarketDepartment &supermarketDepartment);
void stockUpStore(SupermarketItem &supermarketItem);

// Function to create employee database file if it does not exist
void createEmployeeDataBaseFile() {
  std::ifstream existingFile("supermarkeEmployeeDatabase.txt");
  if (!existingFile.good()) {
    std::ofstream supermarkeEmployeeDatabaseFile("supermarkeEmployeeDatabase.txt");
  }
}
bool hasManagerAccounts() {
  std::ifstream file("managerCredentials.txt");
  std::string idNumber, storedPin;
  return static_cast<bool>(file >> idNumber >> storedPin);
}

void createAccount() {
  std::string idNumber, pin;
  std::cout << "Create manager account\n";
  std::cout << "Enter your 13-digit ID Number: ";
  std::getline(std::cin, idNumber);
  while (!isValidIdNumber(idNumber)) {
    std::cerr << "Invalid ID Number.\nEnter your 13-digit ID Number: ";
    std::getline(std::cin, idNumber);
  }
  std::cout << "Create a 4-6 digit PIN: ";
  pin = getPIN();
  while (!isValidPin(pin) || pin.find_first_not_of("0123456789") != std::string::npos) {
    std::cerr << "PIN must contain 4-6 digits.\nCreate a 4-6 digit PIN: ";
    pin = getPIN();
  }
  std::ofstream file("managerCredentials.txt", std::ios::app);
  if (!file) {
    std::cerr << "Unable to save manager credentials.\n";
    return;
  }
  file << idNumber << " " << encryptPIN(pin) << "\n";
  std::cout << "Manager account created.\n";
}

// Function to login user
bool loginUser(std::string &loggedInUser) {
  std::string idNumber, pin;
  std::cout << "Enter your ID Number: ";
  std::getline(std::cin, idNumber);
  if (!isValidIdNumber(idNumber)) {
    std::cerr << "Invalid ID Number.\n";
    return false;
  }
  std::cout << "Enter your PIN: ";
  pin = getPIN();
  if (!isValidPin(pin)) {
    std::cerr << "Invalid pin.\n";
    return false;
  }
  std::ifstream file("managerCredentials.txt");
  if (!file.is_open()) {
    std::cerr << "Error opening file, for reading.\n";
    return false;
  }
  std::string storedIdNumber, storedPin;
  while (file >> storedIdNumber >> storedPin) {
    if (storedIdNumber == idNumber && decryptPIN(storedPin) == pin) {
      loggedInUser = idNumber;
      std::cout << "Login successful.\n";
      return true;
    }
  }
  std::cerr << "Invalid ID Number or Pin.\n";
  return false;
}

bool saveManagerCredentials(const std::string &idNumber, const std::string &pin) {
  std::ofstream file("managerCredentials.txt", std::ios::trunc);
  if (!file) {
    std::cerr << "Unable to update manager credentials.\n";
    return false;
  }
  file << idNumber << " " << encryptPIN(pin) << "\n";
  return static_cast<bool>(file);
}

void manageManagerAccount(bool &canModify) {
  std::cout << "Manager Account\n";
  std::cout << "1. Change manager credentials\n";
  std::cout << "2. Delete manager account\n";
  std::cout << "0. Return\n";
  std::cout << "Selection: ";
  std::string choice;
  std::getline(std::cin, choice);
  if (choice != "1" && choice != "2") {
    return;
  }

  std::string loggedInUser;
  if (!loginUser(loggedInUser)) {
    return;
  }
  if (choice == "2") {
    if (std::remove("managerCredentials.txt") == 0) {
      std::cout << "Manager account deleted. This session is now read-only.\n";
      canModify = false;
    } else {
      std::cerr << "Unable to delete manager credentials.\n";
    }
    return;
  }

  std::string newIdNumber, newPin;
  std::cout << "Enter the new 13-digit ID Number: ";
  std::getline(std::cin, newIdNumber);
  while (!isValidIdNumber(newIdNumber)) {
    std::cerr << "Invalid ID Number.\nEnter the new 13-digit ID Number: ";
    std::getline(std::cin, newIdNumber);
  }
  std::cout << "Enter a new 4-6 digit PIN: ";
  newPin = getPIN();
  while (!isValidPin(newPin) || newPin.find_first_not_of("0123456789") != std::string::npos) {
    std::cerr << "PIN must contain 4-6 digits.\nEnter a new 4-6 digit PIN: ";
    newPin = getPIN();
  }
  if (saveManagerCredentials(newIdNumber, newPin)) {
    std::cout << "Manager credentials updated.\n";
  }
}

bool recoverManagerAccount(bool &canModify) {
  std::cout << "Authenticate with your system password to remove manager credentials.\n";
  if (std::system("sudo -k && sudo -v") != 0) {
    std::cerr << "System authentication failed. Manager credentials were not changed.\n";
    return false;
  }
  if (std::remove("managerCredentials.txt") != 0) {
    std::cerr << "Unable to delete manager credentials.\n";
    return false;
  }
  canModify = false;
  std::cout << "Manager credentials removed. Employee and store data were not changed.\n";
  return true;
}

// Function to encrypt PIN
std::string encryptPIN(const std::string& pin) {
    std::string encryptedPIN = pin;
    for (char& c : encryptedPIN) {
        c += 2;
    }
    return encryptedPIN;
}
// Function to decrypt PIN
std::string decryptPIN(const std::string& encryptedPIN) {
    std::string decryptedPIN = encryptedPIN;
    for (char& c : decryptedPIN) {
        c -= 2;
    }
    return decryptedPIN;
}
// Function to get PIN without echoing
std::string getPIN() {
    termios oldt;
    tcgetattr(fileno(stdin), &oldt);
    termios newt = oldt;
    newt.c_lflag &= ~ECHO;
    tcsetattr(fileno(stdin), TCSANOW, &newt);
    std::string pin;
    std::cin >> pin;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    tcsetattr(fileno(stdin), TCSANOW, &oldt);
    std::cout << "\n";
    return pin;
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
void saveSalesData(SupermarketDepartment &supermarketDepartment, SupermarketItem &supermarketItem) {
  std::cout << "Saving sales data...\n";
  std::cout << "-----------------------------------\n";
  std::ofstream outFile("salesDatabase.txt", std::ios::app);
  if (!outFile) {
    std::cerr << "Error opening file\n";
    return;
  }
  outFile << "Department: " << supermarketDepartment.supermarketDepartmentName << "\n";
  outFile << "Item: " << supermarketItem.name << "\n";
  outFile << "Description: " << supermarketItem.description << "\n";
  outFile << "Category: " << supermarketItem.category << "\n";
  outFile << "Colour: " << supermarketItem.colour << "\n";
  outFile << "Size: " << supermarketItem.size << "\n";
  outFile << "Price: " << supermarketItem.price << "\n";
  outFile << "Quantity: " << supermarketItem.quantity << "\n";
  outFile << "Total: " << supermarketItem.total << "\n";
  outFile << "-----------------------------------\n";
  outFile.close();
}
// Function to check management supermarketDepartment
void checkManagementDepartment(SupermarketDepartment &supermarketDepartment) {
  std::cout << "\n";
  std::cout << "-----------------------------------\n";
  std::cout << "Checking management Department...\n";
  std::cout << "-----------------------------------\n";
  std::this_thread::sleep_for(std::chrono::seconds(3));
  supermarketDepartment.supermarketDepartmentName = "Management";
  supermarketDepartment.supermarketDepartmentManagerFirstName =  "Terry";
  supermarketDepartment.supermarketDepartmentManagerLastName = "Pheto";
  supermarketDepartment.numberOfRequiredEmployees = 18;
  supermarketDepartment.employeesCurrentlyPresentCount = 18;
  std::cout << "Department Name: " << supermarketDepartment.supermarketDepartmentName << "\n";
  std::cout << "Manager's First Name: " << supermarketDepartment.supermarketDepartmentManagerFirstName << "\n";
  std::cout << "Manager's Last Name: " << supermarketDepartment.supermarketDepartmentManagerLastName << "\n";
  std::cout << "Required Number of Employees: " << supermarketDepartment.numberOfRequiredEmployees << "\n";
  std::cout << "Employee count: " << supermarketDepartment.employeesCurrentlyPresentCount << "\n";
  if (supermarketDepartment.numberOfRequiredEmployees == supermarketDepartment.employeesCurrentlyPresentCount) {
    supermarketDepartment.supermarketDepartmentStatus =
        "The team is full in " +  supermarketDepartment.supermarketDepartmentName + "\n";
  } else {
    supermarketDepartment.supermarketDepartmentStatus =  
        "There is a shortage of employees in " + supermarketDepartment.supermarketDepartmentName + "\n";
  }
  std::cout << "Department status: " << supermarketDepartment.supermarketDepartmentStatus << "\n";
  std::cout << "-----------------------------------\n";
}
// Function to check sales supermarketDepartment
void checkSalesDepartment(SupermarketDepartment &supermarketDepartment) {
  std::cout << "\n";
  std::cout << "-----------------------------------\n";
  std::cout << "Checking sales Department...\n";
  std::cout << "-----------------------------------\n";
  std::this_thread::sleep_for(std::chrono::seconds(3));
  supermarketDepartment.supermarketDepartmentName = "Sales";
  supermarketDepartment.supermarketDepartmentManagerFirstName = "Mbulelo";
  supermarketDepartment.supermarketDepartmentManagerLastName = "Mahlangu";
  supermarketDepartment.numberOfRequiredEmployees = 12;
  supermarketDepartment.employeesCurrentlyPresentCount = 10;
  std::cout << "Department: " << supermarketDepartment.supermarketDepartmentName << "\n";
  std::cout << "Manager's First Name: " << supermarketDepartment.supermarketDepartmentManagerFirstName << "\n";
  std::cout << "Manager's Last Name: " << supermarketDepartment.supermarketDepartmentManagerLastName << "\n";
  std::cout << "Required Number of Employees: " << supermarketDepartment.numberOfRequiredEmployees << "\n";
  std::cout << "Employee count: " << supermarketDepartment.employeesCurrentlyPresentCount << "\n";
  if (supermarketDepartment.numberOfRequiredEmployees == supermarketDepartment.employeesCurrentlyPresentCount) {
    supermarketDepartment.supermarketDepartmentStatus =
        "The team is full in " + supermarketDepartment.supermarketDepartmentName + "\n";
  } else {
    supermarketDepartment.supermarketDepartmentStatus =
        "There is a shortage of employees in " + supermarketDepartment.supermarketDepartmentName + "\n";
  }
  std::cout << "Department status: " << supermarketDepartment.supermarketDepartmentStatus << "\n";
  std::cout << "-----------------------------------\n";
}
// Function to check stock supermarketDepartment
void checkStockDepartment(SupermarketDepartment &supermarketDepartment) {
  std::cout << "\n";
  std::cout << "-----------------------------------\n";
  std::cout << "Checking stock Department...\n";
  std::cout << "-----------------------------------\n";
  std::this_thread::sleep_for(std::chrono::seconds(3));
  supermarketDepartment.supermarketDepartmentName = "Stock";
  supermarketDepartment.supermarketDepartmentManagerFirstName = "Zukile";
  supermarketDepartment.supermarketDepartmentManagerLastName = "Stokwe";
  supermarketDepartment.numberOfRequiredEmployees = 6;
  supermarketDepartment.employeesCurrentlyPresentCount = 6;
  std::cout << "Department: " << supermarketDepartment.supermarketDepartmentName << "\n";
  std::cout << "Manager's First Name: " << supermarketDepartment.supermarketDepartmentManagerFirstName << "\n";
  std::cout << "Manager's Last Name: " << supermarketDepartment.supermarketDepartmentManagerLastName << "\n";
  std::cout << "Required Number of Employees: " << supermarketDepartment.numberOfRequiredEmployees << "\n";
  std::cout << "Employee count: " << supermarketDepartment.employeesCurrentlyPresentCount << "\n";
  if (supermarketDepartment.employeesCurrentlyPresentCount == supermarketDepartment.numberOfRequiredEmployees) {
    supermarketDepartment.supermarketDepartmentStatus =
        "The team is full in " + supermarketDepartment.supermarketDepartmentName + "\n";
  } else {
    supermarketDepartment.supermarketDepartmentStatus =
        "There is a shortage of employees in " + supermarketDepartment.supermarketDepartmentName + "\n";
  }
  std::cout << "Department status: " << supermarketDepartment.supermarketDepartmentStatus << "\n";
  std::cout << "-----------------------------------\n";
}
// Function to check human resources supermarketDepartment
void checkHumanResourcesDepartment(SupermarketDepartment &supermarketDepartment) {
  std::cout << "\n";
  std::cout << "-----------------------------------\n";
  std::cout << "Checking human resources Department...\n";
  std::cout << "-----------------------------------\n";
  std::this_thread::sleep_for(std::chrono::seconds(3));
  supermarketDepartment.supermarketDepartmentName = "Human Resources";
  supermarketDepartment.supermarketDepartmentManagerFirstName = "Sindiswa";
  supermarketDepartment.supermarketDepartmentManagerLastName = "Dlala";
  supermarketDepartment.numberOfRequiredEmployees = 20;
  supermarketDepartment.employeesCurrentlyPresentCount = 20;
  std::cout << "Department Name: " << supermarketDepartment.supermarketDepartmentName << "\n";
  std::cout << "Manager's First Name: " << supermarketDepartment.supermarketDepartmentManagerFirstName << "\n";
  std::cout << "Manager's Last Name: " << supermarketDepartment.supermarketDepartmentManagerLastName << "\n";
  std::cout << "Required Number of Employees: " << supermarketDepartment.numberOfRequiredEmployees << "\n";
  std::cout << "Employee count: " << supermarketDepartment.employeesCurrentlyPresentCount << "\n";
  if (supermarketDepartment.numberOfRequiredEmployees == supermarketDepartment.employeesCurrentlyPresentCount) {
    supermarketDepartment.supermarketDepartmentStatus =
        "The team is full in " + supermarketDepartment.supermarketDepartmentName + "\n";
  } else {
    supermarketDepartment.supermarketDepartmentStatus =
        "There is a shortage of employees in " + supermarketDepartment.supermarketDepartmentName;
  }
  std::cout << "Department status: " << supermarketDepartment.supermarketDepartmentStatus << "\n";
  std::cout << "-----------------------------------\n";
}
// Function to check bakery supermarketDepartment
void checkBakeryDepartment(SupermarketDepartment &supermarketDepartment) {
  std::cout << "\n";
  std::cout << "-----------------------------------\n";
  std::cout << "Checking bakery Department...\n";
  std::cout << "-----------------------------------\n";
  std::this_thread::sleep_for(std::chrono::seconds(3));
  supermarketDepartment.supermarketDepartmentName = "Bakery";
  supermarketDepartment.supermarketDepartmentManagerFirstName = "Peter";
  supermarketDepartment.supermarketDepartmentManagerLastName = "Fine";
  supermarketDepartment.numberOfRequiredEmployees = 16;
  supermarketDepartment.employeesCurrentlyPresentCount = 16;
  std::cout << "Department: " << supermarketDepartment.supermarketDepartmentName << "\n";
  std::cout << "Manager's First Name: " << supermarketDepartment.supermarketDepartmentManagerFirstName << "\n";
  std::cout << "Manager's Last Name: " << supermarketDepartment.supermarketDepartmentManagerLastName << "\n";
  std::cout << "Required Number of Employees: " << supermarketDepartment.numberOfRequiredEmployees << "\n";
  std::cout << "Employee count: " << supermarketDepartment.employeesCurrentlyPresentCount << "\n";
  if (supermarketDepartment.numberOfRequiredEmployees == supermarketDepartment.employeesCurrentlyPresentCount) {
    supermarketDepartment.supermarketDepartmentStatus =
        "The team is full in " + supermarketDepartment.supermarketDepartmentName + "\n";
  } else {
    supermarketDepartment.supermarketDepartmentStatus =
        "There is a shortage of employees in " + supermarketDepartment.supermarketDepartmentName;
  }
  std::cout << "Department status: " << supermarketDepartment.supermarketDepartmentStatus << "\n";
  std::cout << "-----------------------------------\n";
}
// Function to check Security Department
void checkSupermarketSecurity(SupermarketDepartment &supermarketDepartment) {
  std::cout << "\n";
  std::cout << "-----------------------------------\n";
  std::cout << "Checking security Department...\n";
  std::cout << "-----------------------------------\n";
  std::this_thread::sleep_for(std::chrono::seconds(3));
  supermarketDepartment.supermarketDepartmentName = "Security";
  supermarketDepartment.supermarketDepartmentManagerFirstName = "Caiphus";
  supermarketDepartment.supermarketDepartmentManagerLastName = "Mabizela";
  supermarketDepartment.numberOfRequiredEmployees = 12;
  supermarketDepartment.employeesCurrentlyPresentCount = 12;
  std::cout << "Department: " << supermarketDepartment.supermarketDepartmentName << "\n";
  std::cout << "Manager's First Name: " << supermarketDepartment.supermarketDepartmentManagerFirstName << "\n";
  std::cout << "Manager's Last Name: " << supermarketDepartment.supermarketDepartmentManagerLastName << "\n";
  std::cout << "Required Number of Employees: " << supermarketDepartment.numberOfRequiredEmployees << "\n";
  std::cout << "Employee count: " << supermarketDepartment.employeesCurrentlyPresentCount << "\n";
  if (supermarketDepartment.numberOfRequiredEmployees == supermarketDepartment.employeesCurrentlyPresentCount) {
    supermarketDepartment.supermarketDepartmentStatus =
        "The team is full in " + supermarketDepartment.supermarketDepartmentName + "\n";
  } else {
    supermarketDepartment.supermarketDepartmentStatus =
        "There is a shortage of employees in " + supermarketDepartment.supermarketDepartmentName;
  }
  std::cout << "Department status: " << supermarketDepartment.supermarketDepartmentStatus << "\n";
  std::cout << "-----------------------------------\n";
}
// Function to check grocery supermarketDepartment
void checkGroceryDepartment(SupermarketDepartment &supermarketDepartment) {
  std::cout << "\n";
  std::cout << "-----------------------------------\n";
  std::cout << "Checking grocery Department...\n";
  std::cout << "-----------------------------------\n";
  std::this_thread::sleep_for(std::chrono::seconds(3));
  supermarketDepartment.supermarketDepartmentName = "Grocery";
  supermarketDepartment.supermarketDepartmentManagerFirstName = "Andile";
  supermarketDepartment.supermarketDepartmentManagerLastName = "Danse";
  supermarketDepartment.numberOfRequiredEmployees = 4;
  supermarketDepartment.employeesCurrentlyPresentCount = 4;
  std::cout << "Department: " << supermarketDepartment.supermarketDepartmentName << "\n";
  std::cout << "Manager's First Name: " << supermarketDepartment.supermarketDepartmentManagerFirstName << "\n";
  std::cout << "Manager's Last Name: " << supermarketDepartment.supermarketDepartmentManagerLastName << "\n";
  std::cout << "Required Number of Employees: " << supermarketDepartment.numberOfRequiredEmployees << "\n";
  std::cout << "Employee count: " << supermarketDepartment.employeesCurrentlyPresentCount << "\n";
  if (supermarketDepartment.numberOfRequiredEmployees == supermarketDepartment.employeesCurrentlyPresentCount) {
    supermarketDepartment.supermarketDepartmentStatus =
        "The team is full in " + supermarketDepartment.supermarketDepartmentName + "\n";
  } else {
    supermarketDepartment.supermarketDepartmentStatus =
        "There is a shortage of employees in " + supermarketDepartment.supermarketDepartmentName;
  }
  std::cout << "Department status: " << supermarketDepartment.supermarketDepartmentStatus << "\n";
  std::cout << "-----------------------------------\n";
}
// Function to check cleaning supermarketDepartment
void checkCleaningDepartment(SupermarketDepartment &supermarketDepartment) {
  std::cout << "\n";
  std::cout << "-----------------------------------\n";
  std::cout << "Checking cleaning Department...\n";
  std::cout << "-----------------------------------\n";
  std::this_thread::sleep_for(std::chrono::seconds(3));
  supermarketDepartment.supermarketDepartmentName = "Cleaning";
  supermarketDepartment.supermarketDepartmentManagerFirstName = "Bulumko";
  supermarketDepartment.supermarketDepartmentManagerLastName = "Dlala";
  supermarketDepartment.numberOfRequiredEmployees = 8;
  supermarketDepartment.employeesCurrentlyPresentCount = 8;
  std::cout << "Department: " << supermarketDepartment.supermarketDepartmentName << "\n";
  std::cout << "Manager's First Name: " << supermarketDepartment.supermarketDepartmentManagerFirstName << "\n";
  std::cout << "Manager's Last Name: " << supermarketDepartment.supermarketDepartmentManagerLastName << "\n";
  std::cout << "Required Number of Employees: " << supermarketDepartment.numberOfRequiredEmployees << "\n";
  std::cout << "Employee count: " <<supermarketDepartment.employeesCurrentlyPresentCount << "\n";
  if (supermarketDepartment.numberOfRequiredEmployees == supermarketDepartment.employeesCurrentlyPresentCount) {
    supermarketDepartment.supermarketDepartmentStatus =
        "The team is full in " + supermarketDepartment.supermarketDepartmentName + "\n";
  } else {
    supermarketDepartment.supermarketDepartmentStatus =
        "There is a shortage of employees in " + supermarketDepartment.supermarketDepartmentName;
  }
  std::cout << "Department status: " << supermarketDepartment.supermarketDepartmentStatus << "\n";
  std::cout << "-----------------------------------\n";
}
// Function to check beverages supermarketDepartment
void checkBeveragesDepartment(SupermarketDepartment &supermarketDepartment) {
  std::cout << "\n";
  std::cout << "-----------------------------------\n";
  std::cout << "Checking beverages Department...\n";
  std::cout << "-----------------------------------\n";
  std::this_thread::sleep_for(std::chrono::seconds(3));
  supermarketDepartment.supermarketDepartmentName = "Beverages";
  supermarketDepartment.supermarketDepartmentManagerFirstName = "John";
  supermarketDepartment.supermarketDepartmentManagerLastName = "Smith";
  supermarketDepartment.numberOfRequiredEmployees = 16;
  supermarketDepartment.employeesCurrentlyPresentCount = 16;
  std::cout << "Department: " << supermarketDepartment.supermarketDepartmentName << "\n";
  std::cout << "Manager's First Name: " << supermarketDepartment.supermarketDepartmentManagerFirstName << "\n";
  std::cout << "Manager's Last Name: " << supermarketDepartment.supermarketDepartmentManagerLastName << "\n";
  std::cout << "Required Number of Employees: " << supermarketDepartment.numberOfRequiredEmployees << "\n";
  std::cout << "Employee count: " << supermarketDepartment.employeesCurrentlyPresentCount << "\n";
  if (supermarketDepartment.numberOfRequiredEmployees == supermarketDepartment.employeesCurrentlyPresentCount) {
    supermarketDepartment.supermarketDepartmentStatus =
        "The team is full in " + supermarketDepartment.supermarketDepartmentName + "\n";
  } else {
    supermarketDepartment.supermarketDepartmentStatus =
        "There is a shortage of employees in " + supermarketDepartment.supermarketDepartmentName;
  }
  std::cout << "Department status: " << supermarketDepartment.supermarketDepartmentStatus << "\n";
  std::cout << "-----------------------------------\n";
}
// Function to check fruits and vegetables supermarketDepartment
void checkFruitsAndVegetablesDepartment(SupermarketDepartment &supermarketDepartment) {
  std::cout << "\n";
  std::cout << "-----------------------------------\n";
  std::cout << "Checking fruits and vegetables Department...\n";
  std::cout << "-----------------------------------\n";
  std::this_thread::sleep_for(std::chrono::seconds(3));
  supermarketDepartment.supermarketDepartmentName = "Fruits and Vegetables";
  supermarketDepartment.supermarketDepartmentManagerFirstName = "Michael";
  supermarketDepartment.supermarketDepartmentManagerLastName = "Stone";
  supermarketDepartment.numberOfRequiredEmployees = 18;
  supermarketDepartment.employeesCurrentlyPresentCount = 18;
  std::cout << "Department: " << supermarketDepartment.supermarketDepartmentName << "\n";
  std::cout << "Manager's First Name: " << supermarketDepartment.supermarketDepartmentManagerFirstName << "\n";
  std::cout << "Manager's Last Name: " << supermarketDepartment.supermarketDepartmentManagerLastName << "\n";
  std::cout << "Required Number of Employees: " << supermarketDepartment.numberOfRequiredEmployees << "\n";
  std::cout << "Employee count: " << supermarketDepartment.employeesCurrentlyPresentCount << "\n";
  if (supermarketDepartment.numberOfRequiredEmployees == supermarketDepartment.employeesCurrentlyPresentCount) {
    supermarketDepartment.supermarketDepartmentStatus =
        "The team is full in " + supermarketDepartment.supermarketDepartmentName + "\n";
  } else {
    supermarketDepartment.supermarketDepartmentStatus =
        "There is a shortage of employees in " + supermarketDepartment.supermarketDepartmentName;
  }
  std::cout << "Department status: " << supermarketDepartment.supermarketDepartmentStatus << "\n";
  std::cout << "-----------------------------------\n";
}
// Function to check meat and seafood supermarketDepartment
void checkMeatAndSeafoodDepartment(SupermarketDepartment &supermarketDepartment) {
  std::cout << "\n";
  std::cout << "-----------------------------------\n";
  std::cout << "Checking meat and seafood Department...\n";
  std::cout << "-----------------------------------\n";
  std::this_thread::sleep_for(std::chrono::seconds(3));
  supermarketDepartment.supermarketDepartmentName = "Meat and Seafood";
  supermarketDepartment.supermarketDepartmentManagerFirstName = "Joseph";
  supermarketDepartment.supermarketDepartmentManagerLastName = "Mabizela";
  supermarketDepartment.numberOfRequiredEmployees = 16;
  supermarketDepartment.employeesCurrentlyPresentCount = 16;
  std::cout << "Department: " << supermarketDepartment.supermarketDepartmentName << "\n";
  std::cout << "Manager's First Name: " << supermarketDepartment.supermarketDepartmentManagerFirstName << "\n";
  std::cout << "Manager's Last Name: " << supermarketDepartment.supermarketDepartmentManagerLastName << "\n";
  std::cout << "Required Number of Employees: " << supermarketDepartment.numberOfRequiredEmployees << "\n";
  std::cout << "Employee count: " << supermarketDepartment.employeesCurrentlyPresentCount << "\n";
  if (supermarketDepartment.numberOfRequiredEmployees == supermarketDepartment.employeesCurrentlyPresentCount) {
    supermarketDepartment.supermarketDepartmentStatus =
        "The team is full in " + supermarketDepartment.supermarketDepartmentName + "\n";
  } else {
    supermarketDepartment.supermarketDepartmentStatus =
        "There is a shortage of employees in " + supermarketDepartment.supermarketDepartmentName;
  }
  std::cout << "Department status: " << supermarketDepartment.supermarketDepartmentStatus << "\n";
  std::cout << "-----------------------------------\n";
}
// Function to stock up the store
void stockUpStore(SupermarketItem &supermarketItem) {
  // The items entered by the user will be added to the stock database
  std::cout << "Stocking up the store...\n";
  std::cout << "-----------------------------------\n";
  std::ofstream outFile("stockDatabase.txt", std::ios::app);
  if (!outFile) {
    std::cerr << "Error opening file\n";
    return;
  }
  std::cout << "Enter Item Name: ";
  std::getline(std::cin, supermarketItem.name);
  supermarketItem.name = capitaliseFirstLetter(supermarketItem.name);
  while (supermarketItem.name.empty()) {
    std::cout << "Item name cannot be empty. Please enter a valid item name\n";
    std::cout << "Enter Item Name: ";
    std::getline(std::cin, supermarketItem.name);
    supermarketItem.name = capitaliseFirstLetter(supermarketItem.name);
  }
  std::ifstream stockFile("stockDatabase.txt");
  if (!stockFile) {
    std::cerr << "Unable to open stock database file.\n";
  }
  stockFile.close();
}
// Function to capture sales data
void captureSupermarketSalesData() {
  SupermarketItem supermarketItem;
  std::cout << "Capturing sales data...\n";
  std::cout << "-----------------------------------\n";
  std::cout << "Enter Item Name: ";
  std::getline(std::cin, supermarketItem.name);
  supermarketItem.name = capitaliseFirstLetter(supermarketItem.name);
  while (supermarketItem.name.empty()) {
    std::cout << "Item name cannot be empty. Please enter a valid item name\n";
    std::cout << "Enter Item Name: ";
    std::getline(std::cin, supermarketItem.name);
    supermarketItem.name = capitaliseFirstLetter(supermarketItem.name);
  }
  std::ifstream existingFile("salesDatabase.txt");
  // The program will deduct the quantity of the sold item from the stock
  // database
  if (existingFile.is_open()) {
    std::string line;
    while (std::getline(existingFile, line)) {
      if (line.find("Item: " + supermarketItem.name) != std::string::npos) {
        std::cout << "-----------------------------------\n";
        std::cout << "Item: " << supermarketItem.name << "\n";
        std::cout << "Description: " << supermarketItem.description << "\n";
        std::cout << "Category: " << supermarketItem.category << "\n";
        std::cout << "Colour: " << supermarketItem.colour << "\n";
        std::cout << "Size: " << supermarketItem.size << "\n";
        std::cout << "Price: R" << supermarketItem.price << "\n";
        std::cout << "Quantity: " << supermarketItem.quantity << "\n";
        std::cout << "Total: R" << supermarketItem.total << "\n";
        std::cout << "-----------------------------------\n";
        supermarketItem.quantity = std::to_string(std::stoi(supermarketItem.quantity) - 1);
        supermarketItem.total =
            std::to_string(std::stod(supermarketItem.total) - std::stod(supermarketItem.price));
        break;
      }
    }
  }
}
// Function to save employee data
void saveSupermarketEmployeeData(SupermarketEmployee &supermarketEmployee) {
  std::cout << "Saving employee data...\n";
  std::cout << "-----------------------------------\n";
  std::ofstream outFile("supermarkeEmployeeDatabase.txt", std::ios::app);
  if (!outFile) {
    std::cerr << "Error opening file\n";
    return;
  }
  outFile << "Title: " << supermarketEmployee.title << "\n";
  outFile << "First Name: " << supermarketEmployee.firstName << "\n";
  outFile << "Middle Name: " << supermarketEmployee.middleName << "\n";
  outFile << "Last Name: " << supermarketEmployee.lastName << "\n";
  outFile << "Gender: " << supermarketEmployee.gender << "\n";
  outFile << "Date of Birth: " << supermarketEmployee.dateOfBirth << "\n";
  outFile << "Age: " << supermarketEmployee.age << "\n";
  outFile << "ID Number: " << supermarketEmployee.idNumber << "\n";
  outFile << "Marital Status: " << supermarketEmployee.maritalStatus << "\n";
  if (supermarketEmployee.maritalStatus == "Married") {
    outFile << "Spouse First Name: " << supermarketEmployee.spouseFirstName << "\n";
    outFile << "Spouse Last Name: " << supermarketEmployee.spouseLastName << "\n";
    outFile << "Spouse Phone Number: " << supermarketEmployee.spousePhoneNumber << "\n";
  }
  outFile << "Phone Number: " << supermarketEmployee.phoneNumber << "\n";
  outFile << "Email Address: " << supermarketEmployee.emailAddress << "\n";
  outFile << "House Number: " << supermarketEmployee.houseNumber << "\n";
  outFile << "Street Name: " << supermarketEmployee.streetName << "\n";
  outFile << "Town: " << supermarketEmployee.town << "\n";
  outFile << "City: " << supermarketEmployee.city << "\n";
  outFile << "Postal Code: " << supermarketEmployee.postalCode << "\n";
  outFile << "Province: " << supermarketEmployee.province << "\n";
  outFile << "Clock ID: " << supermarketEmployee.clockId << "\n";
  outFile << "Position: " << supermarketEmployee.position << "\n";
  outFile << "Start Date: " << supermarketEmployee.startDate << "\n";
  outFile << "Department: " << supermarketEmployee.supermarketDepartment << "\n";
  outFile << RECORD_SEPARATOR << "\n";
  outFile.close();
  std::this_thread::sleep_for(std::chrono::seconds(2));
  std::cout << "Employee data saved successfully.\n";
}
// Function to access employee information
void accessSupermarketEmployeeInformation(SupermarketEmployee &supermarketEmployee, bool canModify) {
  std::cout << "Accessing employee information...\n";
  std::cout << "-----------------------------------\n";
  std::cout << "1. View Employee Data\n";
  if (canModify) {
    std::cout << "2. Add Employee Data\n";
    std::cout << "3. Update Employee Data\n";
    std::cout << "4. Remove Employee Data\n";
    std::cout << "5. View all Employee Data\n";
  } else {
    std::cout << "2. View all Employee Data\n";
  }
  std::cout << "0. Exit\n";
  std::cout << "Please select an option: ";
  int option;
  std::cin >> option;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  while (std::cin.fail() || option < 0 || option > (canModify ? 5 : 2)) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cerr << "Invalid input. Please try again.\n";
    std::cout << "1. View Employee Data\n";
    if (canModify) {
      std::cout << "2. Add Employee Data\n";
      std::cout << "3. Update Employee Data\n";
      std::cout << "4. Remove Employee Data\n";
      std::cout << "5. View all Employee Data\n";
    } else {
      std::cout << "2. View all Employee Data\n";
    }
    std::cout << "0. Exit\n";
    std::cout << "Please select an option: ";
    std::cin >> option;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  if (option == 1) {
    viewSupermarketEmployeeData(supermarketEmployee);
  } else if (canModify && option == 2) {
    addEmployeeData(supermarketEmployee);
  } else if (canModify && option == 3) {
    editSupermarketEmployeeInformation(supermarketEmployee);
  } else if (canModify && option == 4) {
    deleteEmployeeData(supermarketEmployee);
  } else if ((canModify && option == 5) || (!canModify && option == 2)) {
    viewAllEmployeeData(supermarketEmployee);
  } else if (option == 0) {
    std::cout << "Exiting...\n";
  }
}
// Function to view all employee data
void viewAllEmployeeData(SupermarketEmployee &supermarketEmployee) {
  (void)supermarketEmployee;
  std::cout << "Viewing all employee data...\n";
  std::cout << "-----------------------------------\n";
  std::ifstream inFile("supermarkeEmployeeDatabase.txt");
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
void deleteEmployeeData(SupermarketEmployee &supermarketEmployee) {
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
  supermarketEmployee.clockId = clockId;
  std::ifstream inFile("supermarketEmployeeDatabase.txt");
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
    remove("supermarketEmployeeDatabase.txt");
    rename("temp.txt", "supermarketEmployeeDatabase.txt");
    std::cout << "Employee data removed successfully.\n";
  } else {
    remove("temp.txt");
    std::cout << "Employee data not found.\n";
  }
}
// Parse a passenger record (list of lines) into a Passenger object
SupermarketEmployee parseEmployee(const std::vector<std::string> &record) {
  SupermarketEmployee e;
  for (const auto &line : record) {
    size_t colonPos = line.find(": ");
    if (colonPos == std::string::npos) {
      continue;
    }
    std::string key = line.substr(0, colonPos);
    std::string value = line.substr(colonPos + 2);

    if (key == "Clock ID")
      e.clockId = value;
    else if (key == "Title")
      e.title = value;
    else if (key == "First Name")
      e.firstName = value;
    else if (key == "Middle Name")
      e.middleName = value;
    else if (key == "Last Name")
      e.lastName = value;
    else if (key == "Gender")
      e.gender = value;
    else if (key == "Age") {
      try {
        e.age = std::stoi(value);
      } catch (...) {
        e.age = 0;
      }
    } else if (key == "Date of Birth")
      e.dateOfBirth = value;
    else if (key == "ID Number")
      e.idNumber = value;
    else if (key == "Marital Status")
      e.maritalStatus = value;
    else if (key == "Spouse First Name")
      e.spouseFirstName = value;
    else if (key == "Spouse Last Name")
      e.spouseLastName = value;
    else if (key == "Spouse Phone Number")
      e.spousePhoneNumber = value;
    else if (key == "Phone Number")
      e.phoneNumber = value;
    else if (key == "Email Address")
      e.emailAddress = value;
    else if (key == "House Number")
      e.houseNumber = value;
    else if (key == "Street Name")
      e.streetName = value;
    else if (key == "Town")
      e.town = value;
    else if (key == "City")
      e.city = value;
    else if (key == "Postal Code")
      e.postalCode = value;
    else if (key == "Province")
      e.province = value;
  }
  return e;
}

// Format an Employee object into a list of lines representing a record
std::vector<std::string> formatEmployeeRecord(const SupermarketEmployee &supermarketEmployee) {
  std::vector<std::string> lines;
  lines.push_back("Clock ID: " + supermarketEmployee.clockId);
  lines.push_back("Title: " + supermarketEmployee.title);
  lines.push_back("First Name: " + supermarketEmployee.firstName);
  lines.push_back("Middle Name: " + supermarketEmployee.middleName);
  lines.push_back("Last Name: " + supermarketEmployee.lastName);
  lines.push_back("Gender: " + supermarketEmployee.gender);
  lines.push_back("Age: " + std::to_string(supermarketEmployee.age) + " years");
  lines.push_back("Date of Birth: " + supermarketEmployee.dateOfBirth);
  lines.push_back("ID Number: " + supermarketEmployee.idNumber);
  lines.push_back("Marital Status: " + supermarketEmployee.maritalStatus);
  if (supermarketEmployee.maritalStatus == "Married") {
    lines.push_back("Spouse First Name: " + supermarketEmployee.spouseFirstName);
    lines.push_back("Spouse Last Name: " + supermarketEmployee.spouseLastName);
    lines.push_back("Spouse Phone Number: " + supermarketEmployee.spousePhoneNumber);
  }
  lines.push_back("Phone Number: " + supermarketEmployee.phoneNumber);
  lines.push_back("Email Address: " + supermarketEmployee.emailAddress);
  lines.push_back("House Number: " + supermarketEmployee.houseNumber);
  lines.push_back("Street Name: " + supermarketEmployee.streetName);
  lines.push_back("Town: " + supermarketEmployee.town);
  lines.push_back("City: " + supermarketEmployee.city);
  lines.push_back("Postal Code: " + supermarketEmployee.postalCode);
  lines.push_back("Province: " + supermarketEmployee.province);
  lines.push_back(RECORD_SEPARATOR);
  return lines;
}

std::vector<std::vector<std::string>>
readAllRecords(const std::string &filename) {
  std::vector<std::vector<std::string>> records;
  std::ifstream inFile(filename);
  if (!inFile.good()) {
    return records;
  }
  std::vector<std::string> currentRecord;
  std::string line;
  while (std::getline(inFile, line)) {
    if (line == RECORD_SEPARATOR) {
      if (!currentRecord.empty()) {
        records.push_back(currentRecord);
        currentRecord.clear();
      }
      continue;
    }
    currentRecord.emplace_back(line);
  }
  if (!currentRecord.empty()) {
    records.push_back(currentRecord);
  }
  inFile.close();
  return records;
}

bool writeAllRecords(const std::string &filename,
                     const std::vector<std::vector<std::string>> &records) {
  std::ofstream outFile(filename);
  if (!outFile.good()) {
    return false;
  }
  for (const auto &rec : records) {
    for (const auto &l : rec) {
      outFile << l << "\n";
    }
    outFile << RECORD_SEPARATOR << "\n";
  }
  outFile.close();
  return true;
}

int findSupermarketEmployeeRecordIndex(
    const std::vector<std::vector<std::string>> &records,
    const std::string &clockId) {
  if (clockId.empty())
    return -1;
  for (size_t i = 0; i < records.size(); ++i) {
    for (const auto &l : records[i]) {
      if (l == "Clock ID: " + clockId ||
          l.find("Clock ID: " + clockId) != std::string::npos) {
        return static_cast<int>(i);
      }
    }
  }
  return -1;
}

// Enum for employee fields
enum SupermarketEmployeeField {
  ClockId,
  Title,
  FirstName,
  MiddleName,
  LastName,
  Gender,
  Age,
  DateOfBirth,
  IdNumber,
  MaritalStatus,
  SpouseFirstName,
  SpouseLastName,
  SpousePhoneNumber,
  PhoneNumber,
  EmailAddress,
  HouseNumber,
  StreetName,
  Town,
  City,
  PostalCode,
  Province
};

struct FieldOption {
  SupermarketEmployeeField field;
  std::string label;
  std::string currentValue;
};

std::vector<FieldOption> getFieldOptions(const SupermarketEmployee &supermarketEmployee) {
  std::vector<FieldOption> options;
  options.push_back({SupermarketEmployeeField::ClockId, "Clock ID", supermarketEmployee.clockId});
  options.push_back({SupermarketEmployeeField::Title, "Title", supermarketEmployee.title});
  options.push_back(
      {SupermarketEmployeeField::FirstName, "First Name", supermarketEmployee.firstName});
  options.push_back(
      {SupermarketEmployeeField::MiddleName, "Middle Name", supermarketEmployee.middleName});
  options.push_back({SupermarketEmployeeField::LastName, "Last Name", supermarketEmployee.lastName});
  options.push_back({SupermarketEmployeeField::Gender, "Gender", supermarketEmployee.gender});
  options.push_back(
      {SupermarketEmployeeField::Age, "Age", std::to_string(supermarketEmployee.age) + " years"});
  options.push_back(
      {SupermarketEmployeeField::DateOfBirth, "Date of Birth", supermarketEmployee.dateOfBirth});
  options.push_back({SupermarketEmployeeField::IdNumber, "ID Number", supermarketEmployee.idNumber});
  options.push_back(
      {SupermarketEmployeeField::MaritalStatus, "Marital Status", supermarketEmployee.maritalStatus});
  if (supermarketEmployee.maritalStatus == "Married") {
    options.push_back({SupermarketEmployeeField::SpouseFirstName, "Spouse First Name",
                       supermarketEmployee.spouseFirstName});
    options.push_back({SupermarketEmployeeField::SpouseLastName, "Spouse Last Name",
                       supermarketEmployee.spouseLastName});
    options.push_back({SupermarketEmployeeField::SpousePhoneNumber, "Spouse Phone Number",
                       supermarketEmployee.spousePhoneNumber});
  }
  options.push_back(
      {SupermarketEmployeeField::PhoneNumber, "Phone Number", supermarketEmployee.phoneNumber});
  options.push_back(
      {SupermarketEmployeeField::EmailAddress, "Email Address", supermarketEmployee.emailAddress});
  options.push_back(
      {SupermarketEmployeeField::HouseNumber, "House Number", supermarketEmployee.houseNumber});
  options.push_back(
      {SupermarketEmployeeField::StreetName, "Street Name", supermarketEmployee.streetName});
  options.push_back({SupermarketEmployeeField::Town, "Town", supermarketEmployee.town});
  options.push_back({SupermarketEmployeeField::City, "City", supermarketEmployee.city});
  options.push_back(
      {SupermarketEmployeeField::PostalCode, "Postal Code", supermarketEmployee.postalCode});
  options.push_back({SupermarketEmployeeField::Province, "Province", supermarketEmployee.province});
  return options;
}

void editSingleField(SupermarketEmployee &supermarketEmployee, SupermarketEmployeeField field, bool &modified) {
  switch (field) {
  case SupermarketEmployeeField::Title: {
    std::cout << "Enter new Title (Mr/Ms/Dr etc.): ";
    std::string title;
    std::getline(std::cin, title);
    title = capitaliseFirstLetter(title);
    while (!isValidTitle(title)) {
      if (std::cin.eof())
        return;
      std::cerr << "Invalid title. Please enter valid title(Mr/Ms/Dr etc.)\n";
      std::cout << "Title: ";
      std::getline(std::cin, title);
      title = capitaliseFirstLetter(title);
    }
    supermarketEmployee.title = title;
    modified = true;
    std::cout << "Title updated successfully.\n";
    break;
  }
  case SupermarketEmployeeField::FirstName: {
    std::cout << "Enter new First name: ";
    std::string firstName;
    std::getline(std::cin, firstName);
    firstName = capitaliseFirstLetter(firstName);
    while (!isValidName(firstName) || firstName.empty()) {
      if (std::cin.eof())
        return;
      std::cerr << "Invalid first name. Please enter valid first name(Letters "
                   "only)\n";
      std::cout << "First name: ";
      std::getline(std::cin, firstName);
      firstName = capitaliseFirstLetter(firstName);
    }
    supermarketEmployee.firstName = firstName;
    modified = true;
    std::cout << "First name updated successfully.\n";
    break;
  }
  case SupermarketEmployeeField::MiddleName: {
    std::cout
        << "Enter new Middle name (optional, press enter to leave blank): ";
    std::string middleName;
    std::getline(std::cin, middleName);
    middleName = capitaliseFirstLetter(middleName);
    while (!isValidName(middleName)) {
      if (std::cin.eof() || middleName.empty()) {
        break;
      }
      std::cerr << "Invalid middle name. Please enter valid middle "
                   "name(Letters only)\n";
      std::cout << "Middle name (optional): ";
      std::getline(std::cin, middleName);
      middleName = capitaliseFirstLetter(middleName);
    }
    supermarketEmployee.middleName = middleName;
    modified = true;
    std::cout << "Middle name updated successfully.\n";
    break;
  }
  case SupermarketEmployeeField::LastName: {
    std::cout << "Enter new Last name: ";
    std::string lastName;
    std::getline(std::cin, lastName);
    lastName = capitaliseFirstLetter(lastName);
    while (!isValidName(lastName) || lastName.empty()) {
      if (std::cin.eof())
        return;
      std::cerr
          << "Invalid last name. Please enter valid last name(Letters only)\n";
      std::cout << "Last name: ";
      std::getline(std::cin, lastName);
      lastName = capitaliseFirstLetter(lastName);
    }
    supermarketEmployee.lastName = lastName;
    modified = true;
    std::cout << "Last name updated successfully.\n";
    break;
  }
  case SupermarketEmployeeField::Gender: {
    std::cout << "Enter new Gender (Male/Female/Other): ";
    std::string gender;
    std::getline(std::cin, gender);
    gender = capitaliseFirstLetter(gender);
    while (!isValidGender(gender)) {
      if (std::cin.eof())
        return;
      std::cerr << "Invalid gender. Please enter Male, Female, or Other\n";
      std::cout << "Gender: ";
      std::getline(std::cin, gender);
      gender = capitaliseFirstLetter(gender);
    }
    supermarketEmployee.gender = gender;
    modified = true;
    std::cout << "Gender updated successfully.\n";
    break;
  }
  case SupermarketEmployeeField::Age: {
    std::cout << "Enter new Age: ";
    std::string ageStr;
    std::getline(std::cin, ageStr);
    while (ageStr.empty() || !all_of(ageStr.begin(), ageStr.end(), ::isdigit) ||
           std::stoi(ageStr) < 18 || std::stoi(ageStr) > 65) {
      if (std::cin.eof())
        return;
      std::cerr
          << "Invalid age. Please enter a valid age(Digits only, 18-65)\n";
      std::cout << "Age: ";
      std::getline(std::cin, ageStr);
    }
    supermarketEmployee.age = std::stoi(ageStr);
    modified = true;
    std::cout << "Age updated successfully.\n";
    break;
  }
  case SupermarketEmployeeField::DateOfBirth: {
    std::cout << "Enter new Date of Birth (dd/mm/yyyy): ";
    std::string dateOfBirth;
    std::getline(std::cin, dateOfBirth);
    while (!isValidDate(dateOfBirth)) {
      if (std::cin.eof())
        return;
      std::cerr << "Invalid date of birth. Please enter in DD/MM/YYYY format\n";
      std::cout << "Date of Birth: ";
      std::getline(std::cin, dateOfBirth);
    }
    supermarketEmployee.dateOfBirth = dateOfBirth;
    modified = true;
    std::cout << "Date of Birth updated successfully.\n";
    break;
  }
  case SupermarketEmployeeField::IdNumber: {
    std::cout << "Enter new ID Number (13 digits): ";
    std::string newId;
    std::getline(std::cin, newId);
    while (!isValidIdNumber(newId)) {
      if (std::cin.eof())
        return;
      std::cerr << "Invalid ID Number. Please enter a 13-digit number\n";
      std::cout << "ID Number: ";
      std::getline(std::cin, newId);
    }
    supermarketEmployee.idNumber = newId;
    modified = true;
    std::cout << "ID Number updated successfully.\n";
    break;
  }
  case SupermarketEmployeeField::MaritalStatus: {
    std::cout << "Enter new Marital Status "
                 "(Single/Married/Divorced/Widowed/Separated): ";
    std::string maritalStatus;
    std::getline(std::cin, maritalStatus);
    maritalStatus = capitaliseFirstLetter(maritalStatus);
    while (!isValidMaritalStatus(maritalStatus)) {
      if (std::cin.eof())
        return;
      std::cerr << "Invalid marital status. Please enter Single, Married, "
                   "Divorced, Widowed, or Separated\n";
      std::cout << "Marital Status: ";
      std::getline(std::cin, maritalStatus);
      maritalStatus = capitaliseFirstLetter(maritalStatus);
    }
    supermarketEmployee.maritalStatus = maritalStatus;
    if (maritalStatus == "Married") {
      std::cout << "Spouse First Name: ";
      std::string sFirst;
      std::getline(std::cin, sFirst);
      sFirst = capitaliseFirstLetter(sFirst);
      while (!isValidName(sFirst) || sFirst.empty()) {
        if (std::cin.eof())
          return;
        std::cerr << "Invalid spouse first name. Please enter valid first "
                     "name(Letters only)\n";
        std::cout << "Spouse First Name: ";
        std::getline(std::cin, sFirst);
        sFirst = capitaliseFirstLetter(sFirst);
      }
      supermarketEmployee.spouseFirstName = sFirst;

      std::cout << "Spouse Last Name: ";
      std::string sLast;
      std::getline(std::cin, sLast);
      sLast = capitaliseFirstLetter(sLast);
      while (!isValidName(sLast) || sLast.empty()) {
        if (std::cin.eof())
          return;
        std::cerr << "Invalid spouse last name. Please enter valid last "
                     "name(Letters only)\n";
        std::cout << "Spouse Last Name: ";
        std::getline(std::cin, sLast);
        sLast = capitaliseFirstLetter(sLast);
      }
      supermarketEmployee.spouseLastName = sLast;

      std::cout << "Spouse Phone Number (optional): ";
      std::string sPhone;
      std::getline(std::cin, sPhone);
      while (!isValidPhoneNumber(sPhone)) {
        if (std::cin.eof() || sPhone.empty()) {
          break;
        }
        std::cerr << "Invalid spouse phone number. Please enter valid phone "
                     "number(10 Digits only) or leave blank\n";
        std::cout << "Spouse Phone Number: ";
        std::getline(std::cin, sPhone);
      }
      supermarketEmployee.spousePhoneNumber = sPhone;
    } else {
      supermarketEmployee.spouseFirstName.clear();
      supermarketEmployee.spouseLastName.clear();
      supermarketEmployee.spousePhoneNumber.clear();
    }
    modified = true;
    std::cout << "Marital Status updated successfully.\n";
    break;
  }
  case SupermarketEmployeeField::SpouseFirstName: {
    std::cout << "Enter new Spouse First Name: ";
    std::string sFirst;
    std::getline(std::cin, sFirst);
    sFirst = capitaliseFirstLetter(sFirst);
    while (!isValidName(sFirst) || sFirst.empty()) {
      if (std::cin.eof())
        return;
      std::cerr << "Invalid spouse first name. Please enter valid first "
                   "name(Letters only)\n";
      std::cout << "Spouse First Name: ";
      std::getline(std::cin, sFirst);
      sFirst = capitaliseFirstLetter(sFirst);
    }
    supermarketEmployee.spouseFirstName = sFirst;
    modified = true;
    std::cout << "Spouse First Name updated successfully.\n";
    break;
  }
  case SupermarketEmployeeField::SpouseLastName: {
    std::cout << "Enter new Spouse Last Name: ";
    std::string sLast;
    std::getline(std::cin, sLast);
    sLast = capitaliseFirstLetter(sLast);
    while (!isValidName(sLast) || sLast.empty()) {
      if (std::cin.eof())
        return;
      std::cerr << "Invalid spouse last name. Please enter valid last "
                   "name(Letters only)\n";
      std::cout << "Spouse Last Name: ";
      std::getline(std::cin, sLast);
      sLast = capitaliseFirstLetter(sLast);
    }
    supermarketEmployee.spouseLastName = sLast;
    modified = true;
    std::cout << "Spouse Last Name updated successfully.\n";
    break;
  }
  case SupermarketEmployeeField::SpousePhoneNumber: {
    std::cout
        << "Enter new Spouse Phone Number (optional, leave blank to omit): ";
    std::string sPhone;
    std::getline(std::cin, sPhone);
    while (!isValidPhoneNumber(sPhone)) {
      if (std::cin.eof() || sPhone.empty()) {
        break;
      }
      std::cerr << "Invalid spouse phone number. Please enter valid phone "
                   "number(10 Digits only) or leave blank\n";
      std::cout << "Spouse Phone Number: ";
      std::getline(std::cin, sPhone);
    }
    supermarketEmployee.spousePhoneNumber = sPhone;
    modified = true;
    std::cout << "Spouse Phone Number updated successfully.\n";
    break;
  }
  case SupermarketEmployeeField::PhoneNumber: {
    std::cout << "Enter new Phone Number (optional, leave blank to omit): ";
    std::string phone;
    std::getline(std::cin, phone);
    while (!isValidPhoneNumber(phone)) {
      if (std::cin.eof() || phone.empty()) {
        break;
      }
      std::cerr << "Invalid phone number. Please enter valid phone number(10 "
                   "Digits only) or leave blank\n";
      std::cout << "Phone Number: ";
      std::getline(std::cin, phone);
    }
    supermarketEmployee.phoneNumber = phone;
    modified = true;
    std::cout << "Phone Number updated successfully.\n";
    break;
  }
  case SupermarketEmployeeField::EmailAddress: {
    std::cout << "Enter new Email Address (optional, leave blank to omit): ";
    std::string email;
    std::getline(std::cin, email);
    while (!isValidEmail(email)) {
      if (std::cin.eof() || email.empty()) {
        break;
      }
      std::cerr << "Invalid email address. Please enter valid email address or "
                   "leave blank\n";
      std::cout << "Email Address: ";
      std::getline(std::cin, email);
    }
    supermarketEmployee.emailAddress = email;
    modified = true;
    std::cout << "Email Address updated successfully.\n";
    break;
  }
  case SupermarketEmployeeField::HouseNumber: {
    std::cout << "Enter new House Number: ";
    std::string houseNum;
    std::getline(std::cin, houseNum);
    while (houseNum.empty()) {
      if (std::cin.eof())
        return;
      std::cerr << "Invalid house number. Please enter valid house number\n";
      std::cout << "House Number: ";
      std::getline(std::cin, houseNum);
    }
    supermarketEmployee.houseNumber = houseNum;
    modified = true;
    std::cout << "House Number updated successfully.\n";
    break;
  }
  case SupermarketEmployeeField::StreetName: {
    std::cout << "Enter new Street Name: ";
    std::string street;
    std::getline(std::cin, street);
    street = capitaliseFirstLetter(street);
    while (street.empty()) {
      if (std::cin.eof())
        return;
      std::cerr << "Invalid street name. Please enter valid street name\n";
      std::cout << "Street Name: ";
      std::getline(std::cin, street);
      street = capitaliseFirstLetter(street);
    }
    supermarketEmployee.streetName = street;
    modified = true;
    std::cout << "Street Name updated successfully.\n";
    break;
  }
  case SupermarketEmployeeField::Town: {
    std::cout << "Enter new Town: ";
    std::string town;
    std::getline(std::cin, town);
    town = capitaliseFirstLetter(town);
    while (!isValidName(town) || town.empty()) {
      if (std::cin.eof())
        return;
      std::cerr << "Invalid town. Please enter valid town\n";
      std::cout << "Town: ";
      std::getline(std::cin, town);
      town = capitaliseFirstLetter(town);
    }
    supermarketEmployee.town = town;
    modified = true;
    std::cout << "Town updated successfully.\n";
    break;
  }
  case SupermarketEmployeeField::City: {
    std::cout << "Enter new City: ";
    std::string city;
    std::getline(std::cin, city);
    city = capitaliseFirstLetter(city);
    while (!isValidName(city) || city.empty()) {
      if (std::cin.eof())
        return;
      std::cerr << "Invalid city. Please enter valid city\n";
      std::cout << "City: ";
      std::getline(std::cin, city);
      city = capitaliseFirstLetter(city);
    }
    supermarketEmployee.city = city;
    modified = true;
    std::cout << "City updated successfully.\n";
    break;
  }
  case SupermarketEmployeeField::PostalCode: {
    std::cout << "Enter new Postal Code: ";
    std::string postalCode;
    std::getline(std::cin, postalCode);
    while (!isValidPostalCode(postalCode)) {
      if (std::cin.eof())
        return;
      std::cerr << "Invalid postal code. Please enter valid postal code\n";
      std::cout << "Postal Code: ";
      std::getline(std::cin, postalCode);
    }
    supermarketEmployee.postalCode = postalCode;
    modified = true;
    std::cout << "Postal Code updated successfully.\n";
    break;
  }
  case SupermarketEmployeeField::Province: {
    std::cout << "Enter new Province: ";
    std::string prov;
    std::getline(std::cin, prov);
    prov = capitaliseFirstLetter(prov);
    while (!isValidProvince(prov)) {
      if (std::cin.eof())
        return;
      std::cerr << "Invalid province. Please enter valid province\n";
      std::cout << "Province: ";
      std::getline(std::cin, prov);
      prov = capitaliseFirstLetter(prov);
    }
    supermarketEmployee.province = prov;
    modified = true;
    std::cout << "Province updated successfully.\n";
    break;
  }
  case ClockId:
    break;
  }
}

// Function to edit passenger details
void editSupermarketEmployeeInformation(SupermarketEmployee &supermarketEmployee) {
  std::cout << "Editing employee details...\n";
  std::cout << "Enter the Clock ID of the employee: ";
  std::string clockId;
  std::getline(std::cin, clockId);
  while (!isValidClockId(clockId)) {
    if (std::cin.eof())
      return;
    std::cerr << "Invalid input. Please enter a valid clock ID.\n";
    std::cout << "Enter the Clock ID (6 digits): ";
    std::getline(std::cin, clockId);
  }
  std::vector<std::vector<std::string>> records =
      readAllRecords("supermarkeEmployeeDatabase.txt");
  int targetIndex = -1;
  for (size_t i = 0; i < records.size(); ++i) {
    for (const auto &line : records[i]) {
      if (line == "Clock ID: " + clockId) {
        targetIndex = static_cast<int>(i);
        break;
      }
    }
    if (targetIndex != -1) {
      break;
    }
  }

  if (targetIndex == -1) {
    std::cerr << "Employee with clock ID " << clockId << " not found.\n";
    return;
  }

  supermarketEmployee = parseEmployee(records[targetIndex]);
  bool modified = false;

  while (true) {
    std::cout << "\nEmployee with clock number " << clockId << " found:\n";
    std::cout << "----------------------------------------\n";
    std::vector<FieldOption> options = getFieldOptions(supermarketEmployee);
    for (size_t i = 0; i < options.size(); ++i) {
      std::cout << (i + 1) << ". " << options[i].label << ": "
                << options[i].currentValue << "\n";
    }
    std::cout << "----------------------------------------\n";
    std::cout << "0. Save and exit\n";
    std::cout << "Enter the line number you would like to edit (0 to save and "
                 "exit): ";

    int choice;
    if (!(std::cin >> choice)) {
      if (std::cin.eof()) {
        return;
      }
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cerr << "Invalid choice. Please enter a valid number.\n";
      continue;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (choice == 0) {
      break;
    }

    if (choice < 1 || choice > static_cast<int>(options.size())) {
      std::cerr << "Invalid choice. Please enter a number between 0 and "
                << options.size() << ".\n";
      continue;
    }

    SupermarketEmployeeField selectedField = options[choice - 1].field;
    editSingleField(supermarketEmployee, selectedField, modified);
  }

  if (modified) {
    records[targetIndex] = formatEmployeeRecord(supermarketEmployee);
    if (!writeAllRecords("supermarkeEmployeeDatabase.txt", records)) {
      std::cerr << "Error opening file for writing\n";
      return;
    }
    std::cout << "Employee details updated successfully.\n";
  } else {
    std::cout << "No changes made.\n";
  }
}
// Function to add employee data
void addEmployeeData(SupermarketEmployee &supermarketEmployee) { 
  captureSupermarketEmployeeData(supermarketEmployee); 
}

// Function to capture employee data
void captureSupermarketEmployeeData(SupermarketEmployee &supermarketEmployee) {
  std::cout << "Capturing employee data...\n";
  std::cout << "Title: ";
  std::getline(std::cin, supermarketEmployee.title);
  supermarketEmployee.title = capitaliseFirstLetter(supermarketEmployee.title);
  while (!isValidTitle(supermarketEmployee.title)) {
    std::cerr << "Invalid title. Please enter a valid title (Mr, Mrs, Miss, Ms, Dr or Prof).\n";
    std::cout << "Title: ";
    std::getline(std::cin, supermarketEmployee.title);
    supermarketEmployee.title = capitaliseFirstLetter(supermarketEmployee.title);
  }
  std::cout << "First Name: ";
  std::getline(std::cin, supermarketEmployee.firstName);
  supermarketEmployee.firstName = capitaliseFirstLetter(supermarketEmployee.firstName);
  while (!isValidName(supermarketEmployee.firstName)) {
    std::cerr << "Invalid first name. Please enter a valid name (no numbers or special characters).\n";
    std::cout << "First Name: ";
    std::getline(std::cin, supermarketEmployee.firstName);
    supermarketEmployee.firstName = capitaliseFirstLetter(supermarketEmployee.firstName);
  }
  std::cout << "Middle Name: ";
  std::getline(std::cin, supermarketEmployee.middleName);
  supermarketEmployee.middleName = capitaliseFirstLetter(supermarketEmployee.middleName);
  while (!isValidName(supermarketEmployee.middleName)) {
    if (supermarketEmployee.middleName.empty()) {
      break; // allow blank middle name
    }
    std::cerr << "Invalid middle name. Please enter a valid name (no numbers or special characters).\n";
    std::cout << "Middle Name: ";
    std::getline(std::cin, supermarketEmployee.middleName);
    supermarketEmployee.middleName = capitaliseFirstLetter(supermarketEmployee.middleName);
  }
  std::cout << "Last Name: ";
  std::getline(std::cin, supermarketEmployee.lastName);
  supermarketEmployee.lastName = capitaliseFirstLetter(supermarketEmployee.lastName);
  while (!isValidName(supermarketEmployee.lastName)) {
    std::cerr << "Invalid last name. Please enter a valid name (no numbers or special characters).\n";
    std::cout << "Last Name: ";
    std::getline(std::cin, supermarketEmployee.lastName);
    supermarketEmployee.lastName = capitaliseFirstLetter(supermarketEmployee.lastName);
  }
  std::cout << "Gender: ";
  std::getline(std::cin, supermarketEmployee.gender);
  supermarketEmployee.gender = capitaliseFirstLetter(supermarketEmployee.gender);
  while (!isValidGender(supermarketEmployee.gender)) {
    std::cerr << "Invalid gender. Please enter a valid gender (Male or Female).\n";
    std::cout << "Gender: ";
    std::getline(std::cin, supermarketEmployee.gender);
    supermarketEmployee.gender = capitaliseFirstLetter(supermarketEmployee.gender);
  }
  std::cout << "Date of Birth: ";
  std::getline(std::cin, supermarketEmployee.dateOfBirth);
  supermarketEmployee.dateOfBirth = capitaliseFirstLetter(supermarketEmployee.dateOfBirth);
  while (!isValidDate(supermarketEmployee.dateOfBirth)) {
    std::cerr << "Invalid date of birth. Please enter a valid date (dd/mm/yyyy).\n";
    std::cout << "Date of Birth: ";
    std::getline(std::cin, supermarketEmployee.dateOfBirth);
  }
  std::cout << "Age: ";
  std::cin >> supermarketEmployee.age;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  while (std::cin.fail() || supermarketEmployee.age < 18 || supermarketEmployee.age > 60) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cerr << "Invalid age. Please enter a valid age (18-60).\n";
    std::cout << "Age: ";
    std::cin >> supermarketEmployee.age;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  std::cout << "ID Number: ";
  std::getline(std::cin, supermarketEmployee.idNumber);
  while (!isValidIdNumber(supermarketEmployee.idNumber)) {
    std::cerr << "Invalid ID number. Please enter a valid ID number (13 digits).\n";
    std::cout << "ID Number: ";
    std::getline(std::cin, supermarketEmployee.idNumber);
  }
  std::cout << "Marital Status: ";
  std::getline(std::cin, supermarketEmployee.maritalStatus);
  supermarketEmployee.maritalStatus = capitaliseFirstLetter(supermarketEmployee.maritalStatus);
  while (!isValidMaritalStatus(supermarketEmployee.maritalStatus)) {
    std::cerr << "Invalid marital status. Please enter a valid marital status (Single, Married, Divorced, Widowed).\n";
    std::cout << "Marital Status: ";
    std::getline(std::cin, supermarketEmployee.maritalStatus);
    supermarketEmployee.maritalStatus = capitaliseFirstLetter(supermarketEmployee.maritalStatus);
  }
  if (supermarketEmployee.maritalStatus == "Married") {
    std::cout << "Spouse First Name: ";
    std::getline(std::cin, supermarketEmployee.spouseFirstName);
    supermarketEmployee.spouseFirstName = capitaliseFirstLetter(supermarketEmployee.spouseFirstName);
    while (!isValidName(supermarketEmployee.spouseFirstName)) {
      std::cerr << "Invalid spouse first name. Please enter a valid name (no numbers or special characters).\n";
      std::cout << "Spouse First Name: ";
      std::getline(std::cin, supermarketEmployee.spouseFirstName);
      supermarketEmployee.spouseFirstName = capitaliseFirstLetter(supermarketEmployee.spouseFirstName);
    }
    std::cout << "Spouse Last Name: ";
    std::getline(std::cin, supermarketEmployee.spouseLastName);
    supermarketEmployee.spouseLastName = capitaliseFirstLetter(supermarketEmployee.spouseLastName);
    while (!isValidName(supermarketEmployee.spouseLastName)) {
      std::cerr << "Invalid spouse last name. Please enter a valid name (no numbers or special characters).\n";
      std::cout << "Spouse Last Name: ";
      std::getline(std::cin, supermarketEmployee.spouseLastName);
      supermarketEmployee.spouseLastName = capitaliseFirstLetter(supermarketEmployee.spouseLastName);
    }
    std::cout << "Spouse Phone Number: ";
    std::getline(std::cin, supermarketEmployee.spousePhoneNumber);
    while (!isValidPhoneNumber(supermarketEmployee.spousePhoneNumber)) {
      if (supermarketEmployee.spousePhoneNumber.empty()) {
        break; // allow blank phone number
      }
      std::cerr << "Invalid spouse phone number. Please enter a valid phone number (10 digits).\n";
      std::cout << "Spouse Phone Number: ";
      std::getline(std::cin, supermarketEmployee.spousePhoneNumber);
    }
  }
  std::cout << "Phone Number: ";
  std::getline(std::cin, supermarketEmployee.phoneNumber);
  while (!isValidPhoneNumber(supermarketEmployee.phoneNumber)) {
    if (supermarketEmployee.phoneNumber.empty()) {
      break; // allow blank phone number
    }
    std::cerr << "Invalid phone number. Please enter a valid phone number (10 digits).\n";
    std::cout << "Phone Number: ";
    std::getline(std::cin, supermarketEmployee.phoneNumber);
  }
  std::cout << "Email Address: ";
  std::getline(std::cin, supermarketEmployee.emailAddress);
  while (!isValidEmail(supermarketEmployee.emailAddress)) {
    if (supermarketEmployee.emailAddress.empty()) {
      break; // allow blank email address
    }
    std::cerr << "Invalid email address. Please enter a valid email address.\n";
    std::cout << "Email Address: ";
    std::getline(std::cin, supermarketEmployee.emailAddress);
  }
  std::cout << "House Number: ";
  std::getline(std::cin, supermarketEmployee.houseNumber);
  while (supermarketEmployee.houseNumber.empty()) {
    std::cerr << "Invalid house number. Please enter a valid house number.\n";
    std::cout << "House Number: ";
    std::getline(std::cin, supermarketEmployee.houseNumber);
  }
  std::cout << "Street Name: ";
  std::getline(std::cin, supermarketEmployee.streetName);
  supermarketEmployee.streetName = capitaliseFirstLetter(supermarketEmployee.streetName);
  while (supermarketEmployee.streetName.empty()) {
    std::cerr << "Invalid street name. Please enter a valid street name.\n";
    std::cout << "Street Name: ";
    std::getline(std::cin, supermarketEmployee.streetName);
    supermarketEmployee.streetName = capitaliseFirstLetter(supermarketEmployee.streetName);
  }
  std::cout << "Town: ";
  std::getline(std::cin, supermarketEmployee.town);
  supermarketEmployee.town = capitaliseFirstLetter(supermarketEmployee.town);
  while (!isValidName(supermarketEmployee.town)) {
    std::cerr << "Invalid town. Please enter a valid town (no numbers or special characters).\n";
    std::cout << "Town: ";
    std::getline(std::cin, supermarketEmployee.town);
    supermarketEmployee.town = capitaliseFirstLetter(supermarketEmployee.town);
  }
  std::cout << "City: ";
  std::getline(std::cin, supermarketEmployee.city);
  supermarketEmployee.city = capitaliseFirstLetter(supermarketEmployee.city);
  while (!isValidName(supermarketEmployee.city)) {
    std::cerr << "Invalid city. Please enter a valid city (no numbers or special characters).\n";
    std::cout << "City: ";
    std::getline(std::cin, supermarketEmployee.city);
    supermarketEmployee.city = capitaliseFirstLetter(supermarketEmployee.city);
  }
  std::cout << "Postal Code: ";
  std::getline(std::cin, supermarketEmployee.postalCode);
  while (!isValidPostalCode(supermarketEmployee.postalCode)) {
    std::cerr << "Invalid postal code. Please enter a valid postal code (4-6 digits).\n";
    std::cout << "Postal Code: ";
    std::getline(std::cin, supermarketEmployee.postalCode);
  }
  std::cout << "Province: ";
  std::getline(std::cin, supermarketEmployee.province);
  supermarketEmployee.province = capitaliseFirstLetter(supermarketEmployee.province);
  while (!isValidProvince(supermarketEmployee.province)) {
    std::cerr << "Invalid province. Please enter a valid province (no numbers or special characters).\n";
    std::cout << "Province: ";
    std::getline(std::cin, supermarketEmployee.province);
    supermarketEmployee.province = capitaliseFirstLetter(supermarketEmployee.province);
  }
  std::cout << "Clock ID: ";
  std::getline(std::cin, supermarketEmployee.clockId);
  while (!isValidClockId(supermarketEmployee.clockId)) {
    std::cerr << "Invalid clock ID. Please enter a valid clock ID (6 digits).\n";
    std::cout << "Clock ID: ";
    std::getline(std::cin, supermarketEmployee.clockId);
  }
  std::cout << "Position: ";
  std::getline(std::cin, supermarketEmployee.position);
  supermarketEmployee.position = capitaliseFirstLetter(supermarketEmployee.position);
  while (!isValidName(supermarketEmployee.position)) {
    std::cerr << "Invalid position. Please enter a valid position (no numbers or special characters).\n";
    std::cout << "Position: ";
    std::getline(std::cin, supermarketEmployee.position);
    supermarketEmployee.position = capitaliseFirstLetter(supermarketEmployee.position);
  }
  std::cout << "Start Date: ";
  std::getline(std::cin, supermarketEmployee.startDate);
  while (!isValidDate(supermarketEmployee.startDate)) {
    std::cerr << "Invalid start date. Please enter a valid start date (dd/mm/yyyy).\n";
    std::cout << "Start Date: ";
    std::getline(std::cin, supermarketEmployee.startDate);
  }
  std::cout << "Department: ";
  std::getline(std::cin, supermarketEmployee.supermarketDepartment);
  supermarketEmployee.supermarketDepartment = capitaliseFirstLetter(supermarketEmployee.supermarketDepartment);
  while (!isValidName(supermarketEmployee.supermarketDepartment)) {
    std::cerr << "Invalid supermarketDepartment. Please enter a valid supermarketDepartment (no numbers or special characters).\n";
    std::cout << "Department: ";
    std::getline(std::cin, supermarketEmployee.supermarketDepartment);
    supermarketEmployee.supermarketDepartment = capitaliseFirstLetter(supermarketEmployee.supermarketDepartment);
  }
  saveSupermarketEmployeeData(supermarketEmployee);
}
// Function to view the employee data
void viewSupermarketEmployeeData(SupermarketEmployee &supermarketEmployee) {
  std::cout << "Viewing an employee's data...\n";
  std::cout << "Enter clock ID to view employee data: ";
  std::string clockId;
  std::getline(std::cin, clockId);
  while (!isValidClockId(clockId)) {
    std::cerr << "Invalid clock ID. Please enter a valid clock ID (6 digits).\n";
    std::cout << "Enter clock ID to view employee data: ";
    std::getline(std::cin, clockId);
  }
  supermarketEmployee.clockId = clockId;
  std::ifstream inFile("supermarkeEmployeeDatabase.txt");
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
    std::cout << "Employee's information not found.\n";
  }
  inFile.close();
}
// Function to check the doors
void checkDoors(SupermarketSecurity &supermarketSecurity) {
  (void)supermarketSecurity;
  std::cout << "Checking the Security door...\n";
  std::this_thread::sleep_for(std::chrono::seconds(3));
  std::string securityDoor = "Closed";
  std::cout << "The Security Door is " << securityDoor << ".\n";
  return;
}

// Function to check the windows
void checkWindows(SupermarketSecurity &supermarketSecurity) {
  (void)supermarketSecurity;
  std::cout << "Checking the windows...\n";
  std::this_thread::sleep_for(std::chrono::seconds(3));
  std::string windows = "Closed";
  std::cout << "The windows are " << windows << "...\n";
  return;
}

// Function to check the lights
void checkLights(SupermarketSecurity &supermarketSecurity) {
  (void)supermarketSecurity;
  std::cout << "Checking the lights...\n";
  std::this_thread::sleep_for(std::chrono::seconds(3));
  std::string lights = "On";
  std::cout << "The lights are " << lights << "...\n";
  return;
}

// Function to check the alarms
void checkAlarms(SupermarketSecurity &supermarketSecurity) {
  (void)supermarketSecurity;
  std::cout << "Checking the alarm...\n";
  std::this_thread::sleep_for(std::chrono::seconds(3));
  std::string alarms = "Off";
  std::cout << "The alarm is " << alarms << "...\n";
  return;
}
// Function to check the drop safe
void checkDropSafe(SupermarketSecurity &supermarketSecurity) {
  (void)supermarketSecurity;
  std::cout << "Checking the drop safe...\n";
  std::this_thread::sleep_for(std::chrono::seconds(3));
  std::string dropSafe = "Closed";
  std::cout << "The drop safe is " << dropSafe << "...\n";
  return;
}

// Function to view the store security
void viewStoreSecurity(SupermarketSecurity &supermarketSecurity) {
  std::cout << "Viewing the store security status...\n";
  std::this_thread::sleep_for(std::chrono::seconds(3));
  checkDoors(supermarketSecurity);
  checkWindows(supermarketSecurity);
  checkLights(supermarketSecurity);
  checkAlarms(supermarketSecurity);
  checkDropSafe(supermarketSecurity);
  std::cout << "This is the current store security status.\n";
  std::cout << "------------------------------------------\n";
}
// Function to open the store
void openStore(SupermarketSecurity &supermarketSecurity) {
  std::cout << "Running security checks...\n";
  checkDoors(supermarketSecurity);
  checkWindows(supermarketSecurity);
  checkLights(supermarketSecurity);
  checkAlarms(supermarketSecurity);
  checkDropSafe(supermarketSecurity);
  std::cout << "The store is now open.\n";
}
// Function to view the store status
void viewStoreStatus(SupermarketDepartment &supermarketDepartment) {
  std::cout << "Viewing the store status...\n";
  checkManagementDepartment(supermarketDepartment);
  checkHumanResourcesDepartment(supermarketDepartment);
  checkSupermarketSecurity(supermarketDepartment);
  checkStockDepartment(supermarketDepartment);
  checkSalesDepartment(supermarketDepartment);
  checkGroceryDepartment(supermarketDepartment);
  checkMeatAndSeafoodDepartment(supermarketDepartment);
  checkBeveragesDepartment(supermarketDepartment);
  checkFruitsAndVegetablesDepartment(supermarketDepartment);
  checkBakeryDepartment(supermarketDepartment);
  checkCleaningDepartment(supermarketDepartment);
  std::cout << "The store is currently open.\n";
}
// Function to manage the supermarket
void manageTheSupermarket(bool canModify) {
  std::cout << "Supermarket Management\n";
  while (true) {
    if (canModify) {
      std::cout << "1. Open The Store\n";
      std::cout << "2. View Store Security\n";
      std::cout << "3. View Store Status\n";
      std::cout << "4. Stock up the store\n";
      std::cout << "5. Access Departments Information\n";
      std::cout << "6. Access Employees Information\n";
      std::cout << "7. Close The Store\n";
    } else {
      std::cout << "1. View Store Security\n";
      std::cout << "2. View Store Status\n";
      std::cout << "3. Access Departments Information\n";
      std::cout << "4. Access Employees Information\n";
    }
    std::cout << "0. Exit\n";
    std::cout << "Please select an option: ";
    int option;
    std::cin >> option;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (std::cin.fail() || option < 0 || option > (canModify ? 7 : 4)) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cerr << "Invalid input. Please try again.\n";
      if (canModify) {
        std::cout << "1. Open The Store\n";
        std::cout << "2. View Store Security\n";
        std::cout << "3. View Store Status\n";
        std::cout << "4. Stock up the store\n";
        std::cout << "5. Access Departments Information\n";
        std::cout << "6. Access Employees Information\n";
        std::cout << "7. Close The Store\n";
      } else {
        std::cout << "1. View Store Security\n";
        std::cout << "2. View Store Status\n";
        std::cout << "3. Access Departments Information\n";
        std::cout << "4. Access Employees Information\n";
      }
      std::cout << "0. Exit\n";
      std::cout << "Please select an option: ";
      std::cin >> option;
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    if (canModify && option == 1) {
      SupermarketSecurity supermarketSecurity;
      openStore(supermarketSecurity);
    } else if ((canModify && option == 2) || (!canModify && option == 1)) {
      SupermarketSecurity supermarketSecurity;
      viewStoreSecurity(supermarketSecurity);
    } else if ((canModify && option == 3) || (!canModify && option == 2)) {
      SupermarketDepartment supermarketDepartment;
      viewStoreStatus(supermarketDepartment);
    } else if (canModify && option == 4) {
      SupermarketItem supermarketItem;
      stockUpStore(supermarketItem);
    } else if ((canModify && option == 5) || (!canModify && option == 3)) {
      SupermarketDepartment supermarketDepartment;
      viewStoreStatus(supermarketDepartment);
    } else if ((canModify && option == 6) || (!canModify && option == 4)) {
      SupermarketEmployee supermarketEmployee;
      accessSupermarketEmployeeInformation(supermarketEmployee, canModify);
    } else if (canModify && option == 7) {
      std::cout << "The store is now closed.\n";
    } else if (option == 0) {
      std::cout << "Returning to the main menu...\n";
      break;
    }
  }
}

void manageSecurity(SupermarketSecurity &supermarketSecurity, bool canModify) {
  std::cout << "Security Management\n";
  (void) supermarketSecurity;
  while (true) {
    if (canModify) {
      std::cout << "1. Open The Store\n";
      std::cout << "2. View Store Security\n";
      std::cout << "3. Check Security Door\n";
      std::cout << "4. Check Windows\n";
      std::cout << "5. Check Lights\n";
      std::cout << "6. Check Alarms\n";
      std::cout << "7. Check Drop Safe\n";
    } else {
      std::cout << "1. View Store Security\n";
      std::cout << "2. Check Security Door\n";
      std::cout << "3. Check Windows\n";
      std::cout << "4. Check Lights\n";
      std::cout << "5. Check Alarms\n";
      std::cout << "6. Check Drop Safe\n";
    }
    std::cout << "0. Exit\n";
    std::cout << "Please select an option: ";
    int option;
    std::cin >> option;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (std::cin.fail() || option < 0 || option > (canModify ? 7 : 6)) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cerr << "Invalid input. Please try again.\n";
      if (canModify) {
        std::cout << "1. Open The Store\n";
        std::cout << "2. View Store Security\n";
        std::cout << "3. Check Security Door\n";
        std::cout << "4. Check Windows\n";
        std::cout << "5. Check Lights\n";
        std::cout << "6. Check Alarms\n";
        std::cout << "7. Check Drop Safe\n";
      } else {
        std::cout << "1. View Store Security\n";
        std::cout << "2. Check Security Door\n";
        std::cout << "3. Check Windows\n";
        std::cout << "4. Check Lights\n";
        std::cout << "5. Check Alarms\n";
        std::cout << "6. Check Drop Safe\n";
      }
      std::cout << "0. Exit\n";
      std::cout << "Please select an option: ";
      std::cin >> option;
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    SupermarketSecurity supermarketSecurity;
    if (canModify && option == 1) {
      openStore(supermarketSecurity);
    } else if ((canModify && option == 2) || (!canModify && option == 1)) {
      viewStoreSecurity(supermarketSecurity);
    } else if ((canModify && option == 3) || (!canModify && option == 2)) {
      checkDoors(supermarketSecurity);
    } else if ((canModify && option == 4) || (!canModify && option == 3)) {
      checkWindows(supermarketSecurity);
    } else if ((canModify && option == 5) || (!canModify && option == 4)) {
      checkLights(supermarketSecurity);
    } else if ((canModify && option == 6) || (!canModify && option == 5)) {
      checkAlarms(supermarketSecurity);
    } else if ((canModify && option == 7) || (!canModify && option == 6)) {
      checkDropSafe(supermarketSecurity);
    } else if (option == 0) {
      std::cout << "Returning to the main menu...\n";
      break;
    }
  }
}
// Function to show main menu
void showMenu(bool &canModify) {
  std::cout << "Please select a task\n";
  while (true) {
    std::cout << "\n";
    std::cout << "--------------------------\n";
    std::cout << "What would you like to do?\n";
    std::cout << "--------------------------\n";
    std::cout << "\n";
    std::cout << "1. Manage The Store\n";
    std::cout << "2. Manage Employees\n";
    std::cout << "3. Manage Security\n";
    if (canModify) {
      std::cout << "4. Manage Manager Account\n";
    }
    std::cout << "0. Exit\n";
    std::cout << "Selection: ";
    int option;
    std::cin >> option;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (std::cin.fail() || option < 0 || option > (canModify ? 4 : 3)) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cerr << "Invalid input. Please try again.\n";
      std::cout << "1. Manage The Store\n";
      std::cout << "2. Manage Employees\n";
      std::cout << "3. Manage Security\n";
      if (canModify) {
        std::cout << "4. Manage Manager Account\n";
      }
      std::cout << "0. Exit\n";
      std::cout << "Selection: ";
      std::cin >> option;
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    if (option == 1) {
      SupermarketSecurity supermarketSecurity;
      manageTheSupermarket(canModify);
    } else if (option == 2) {
      SupermarketEmployee supermarketEmployee;
      accessSupermarketEmployeeInformation(supermarketEmployee, canModify);
    } else if (option == 3) {
      SupermarketSecurity supermarketSecurity;
      manageSecurity(supermarketSecurity, canModify);
    } else if (canModify && option == 4) {
      manageManagerAccount(canModify);
    } else if (option == 0) {
      std::cout << "Closing the manager's desk... Goodbye!\n";
      sleep_for(seconds(2));
      return;
    }
  }
  return;
}
int main () {
  int choice;
  std::cout << "Welcome to the Manager's Desk Application\n";
  createEmployeeDataBaseFile();
  createSalesDataBaseFile();
  createStockDataBaseFile();
  bool canModify = false;
  std::string loggedInUser;
  if (hasManagerAccounts()) {
    std::cout << "1. Sign in\n";
    std::cout << "2. Continue as read-only guest\n";
    std::cout << "3. Remove manager credentials (system password required)\n";
    std::cout << "0. Quit\n";
    std::cout << "Selection: ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (std::cin.fail() || choice < 0 || choice > 3) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cerr << "Invalid input. Please select between 1 and 3, or 0 to close the program.\n";
      std::cin >> choice;
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    if (choice == 1) {
      canModify = loginUser(loggedInUser);
    } else if (choice == 2) {
        std::cout << "Continuing with read-only access.\n";  
    } else if (choice == 3) {
      recoverManagerAccount(canModify);
    } else if (choice == 0) {
      exit(0);
    }
  } else {
    std::cout << "No manager account exists.\n";
    std::cout << "1. Create manager account\n";
    std::cout << "2. Continue as read-only guest\n";
    std::cout << "0. Exit\n";
    std::cout << "Selection: ";
    std::string choice;
    std::getline(std::cin, choice);
    if (choice == "1") {
      createAccount();
      canModify = hasManagerAccounts();
    } else if (choice == "3") {
      exit(0);
    }
  }
  showMenu(canModify);
  return 0;
}
  
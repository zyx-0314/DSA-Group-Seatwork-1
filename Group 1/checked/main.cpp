/*
 * Create a system that accepts list of patients
 */

/*
 * Create a system that accepts list of patients
 */

#include <iostream>
#include <string>

// Define macros for platform-specific console clearing and pausing
#ifdef _WIN32
#define CLEAR_CONSOLE system("cls");
#else
#define CLEAR_CONSOLE system("clear");
#endif

#ifdef _WIN32
#define PAUSE_CONSOLE system("pause");
#else
#define PAUSE_CONSOLE ;
#endif

struct Patient {
  bool notOccupied = true;
  std::string fName;
  std::string lName;
  std::string age;
  std::string arrivalDate;
};

void PatientDataEntry(Patient &);
void DataEntry(std::string, std::string &);
void DisplayPatientList(Patient &);
void Menu(int &);

int main() {
  const int MAX_PATIENT = 5;
  Patient patient[MAX_PATIENT];
  int choice;
  bool isFull = false;

  do {
    Menu(choice);

    switch (choice) {
    case 1:
      if (!isFull) {
        std::cout << "\nRegistering Patient\n";
        for (int i = 0; i < MAX_PATIENT; i++) {
          if (patient[i].notOccupied) {
            PatientDataEntry(patient[i]);
            if (i == MAX_PATIENT - 1) {
              isFull = true;
            }
            CLEAR_CONSOLE;
            break;
          }
        }
      } else {
        std::cout << "Capacity Full" << std::endl;
      }
      break;
    case 2:
      std::cout << "\nPatient Details:\n";
      for (int i = 0; i < MAX_PATIENT; i++) {
        if (!patient[i].notOccupied) {
          DisplayPatientList(patient[i]);
        }
      }
      PAUSE_CONSOLE;
      CLEAR_CONSOLE;
      break;
    case 3:
      do {
        std::cout << "\nEnter ID (1-" << MAX_PATIENT << "): ";
        std::cin >> choice;
        std::cin.ignore();
      } while (choice < 1 || choice > MAX_PATIENT);

      CLEAR_CONSOLE;

      choice--;

      PatientDataEntry(patient[choice]);
      CLEAR_CONSOLE;
      break;
    case 4:
      std::cout << "Exiting program...\n";
      break;
    default:
      CLEAR_CONSOLE;
      std::cout << "Invalid choice!\n";
      PAUSE_CONSOLE;
      CLEAR_CONSOLE;
      break;
    }
  } while (choice != 4);

  return 0;
}

void PatientDataEntry(Patient &patient) {
  patient.notOccupied = false;
  std::cout << "First Name: ";
  std::getline(std::cin, patient.fName);
  std::cout << "Last Name: ";
  std::getline(std::cin, patient.lName);
  std::cout << "Age: ";
  std::getline(std::cin, patient.age);
  std::cout << "Arrival Date: ";
  std::getline(std::cin, patient.arrivalDate);
}

void DataEntry(std::string prompt, std::string &input) {
  std::cout << prompt;
  std::getline(std::cin, input);
}

void DisplayPatientList(const Patient &patient) {
  std::cout << "First Name: " << patient.fName << std::endl;
  std::cout << "Last Name: " << patient.lName << std::endl;
  std::cout << "Age: " << patient.age << std::endl;
  std::cout << "Arrival Date: " << patient.arrivalDate << std::endl;
}

void Menu(int &choice) {
  do {
    std::cout << "\n-----------------MENU-----------------\n";
    std::cout << "1. Register Patient\n";
    std::cout << "2. Display Patient Details\n";
    std::cout << "3. Update Patient Details\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    std::cin.ignore();
  } while (choice < 1 || choice > 4);

  CLEAR_CONSOLE;
}

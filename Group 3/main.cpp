#include <iostream>
#include <string>
struct patient {
  std::string fName = "";
  std::string lName = "";
  std::string age = "";
  std::string arrivalDate = "";
};
// Function declarations
void Registration(patient *Patients, int index); // Handles patient
registration at a specific index void
DataEntry(const std::string &prompt, std::string &input); // Helper function
to prompt and take input void
DisplayPatients(patient *Patients, int size); // Displays all patients'
data void UpdatePatient(patient *Patients,
                        int index); // Updates patient info at a
specific index int main() {
  patient Patients[10]; // Array to store up to 10 patients
  int numPatients = 0;  // To keep track of how many patients have been
  registered int choice;
  do {
    std::cout << "\nMenu:\n";
    std::cout << "1. Register New Patient\n";
    std::cout << "2. Update Existing Patient Info\n";
    std::cout << "3. Display All Patients\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    std::cin.ignore(); // Clear newline character from the input buffer
    switch (choice) {
    case 1:
      if (numPatients < 10) {
        Registration(Patients, numPatients); // Register a new patient
        numPatients++;
      } else {
        std::cout << "Patient list is full!\n";
      }
      break;
    case 2:
      int indexToUpdate;
      std::cout << "Enter patient index to update (0 - " << numPatients - 1
                << "): ";
      std::cin >> indexToUpdate;
      std::cin.ignore(); // Clear buffer
      if (indexToUpdate >= 0 && indexToUpdate < numPatients) {
        UpdatePatient(Patients, indexToUpdate); // Update existing
        patient info
      } else {
        std::cout << "Invalid index!\n";
      }
      break;
    case 3:
      DisplayPatients(Patients, numPatients); // Display all patients
      break;
    case 4:
      std::cout << "Exiting...\n";
      break;
    default:
      std::cout << "Invalid choice. Try again.\n";
    }
  } while (choice != 4);
  return 0;
}
// Handles patient registration
void Registration(patient *Patients, int index) {
  std::cout << "\nRegistering Patient at index " << index << ":\n";
  DataEntry("First Name: ", Patients[index].fName);
  DataEntry("Last Name: ", Patients[index].lName);
  DataEntry("Age: ", Patients[index].age);
  DataEntry("Arrival Date: ", Patients[index].arrivalDate);
}
// Helper function to prompt and take input for each field
void DataEntry(const std::string &prompt, std::string &input) {
  std::cout << prompt;
  getline(std::cin, input);
}
// Displays all registered patients' data
void DisplayPatients(patient *Patients, int size) {
  if (size == 0) {
    std::cout << "\nNo patients registered yet.\n";
    return;
  }
  std::cout << "\nCurrent Patient List:\n";
  for (int i = 0; i < size; i++) {
    std::cout << "Patient " << i << ":\n";
    std::cout << " First Name: " << Patients[i].fName << "\n";
    std::cout << " Last Name: " << Patients[i].lName << "\n";
    std::cout << " Age: " << Patients[i].age << "\n";
    std::cout << " Arrival Date: " << Patients[i].arrivalDate << "\n";
    std::cout << "------------------------\n";
  }
}
// Allows updating an existing patient's information at a specific index
void UpdatePatient(patient *Patients, int index) {
  std::cout << "\nUpdating Patient at index " << index << ":\n";
  DataEntry("First Name: ", Patients[index].fName);
  DataEntry("Last Name: ", Patients[index].lName);
  DataEntry("Age: ", Patients[index].age);
  DataEntry("Arrival Date: ", Patients[index].arrivalDate);
}

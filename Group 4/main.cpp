#include <iostream>
#include <string>
using namespace std;
// Structure representing a patient with basic information
struct patient {
  string fName = "";       // Patient's first name
  string lName = "";       // Patient's last name
  string age = "";         // Patient's age
  string arrivalDate = ""; // Date when the patient arrived
};
// Function declarations
void Registration(patient *, int); // Register a patient at a specific index
void DataEntry(string,
               string &); // Helper function to take input for patient data
void DisplayPatients(patient *, int); // Display all patients
void UpdatePatient(patient *,
                   int); // Update a patient's data at a specific index
int main() {
  // Array to hold data for 10 patients
  patient Patients[10]; // Array of 10 patients
  int choice, index;    // Variables to store menu choice and patient index
  // Main menu for the program
  do {
    // Display menu options to the user
    cout << "\nMain Menu:\n";
    cout << "1. Register a patient\n";
    cout << "2. Display all patients\n";
    cout << "3. Update a patient\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice; // Get the user's menu choice
    cin.ignore();  // Ignore any leftover newline character in input buffer
    // Switch case to handle different menu options
    switch (choice) {
    case 1:
      // Register a new patient
      while (true) {
        cout << "Enter index to store patient data (0-9): ";
        cin >> index; // Get the index to store patient data
        cin.ignore(); // Ignore any leftover newline character
        // Check if the index is valid (within 0-9)
        if (index >= 0 && index < 10) {
          Registration(&Patients[index], index); // Register patient
          at the specified index break; // Exit the loop if the index is valid
        } else {
          cout << "Invalid index. Please try again.\n"; // Prompt
for
  correct input
        }
      }
      break;
    case 2:
      // Display all patients' information
      DisplayPatients(Patients, 10); // Call the function to display all
      patients break;
    case 3:
      // Update an existing patient's data
      while (true) {
        cout << "Enter index to update patient data (0-9): ";
        cin >> index; // Get the index to update patient data
        cin.ignore(); // Ignore any leftover newline character
        // Check if the index is valid (within 0-9)
        if (index >= 0 && index < 10) {
          UpdatePatient(&Patients[index], index); // Update patient
          data at the specified
              index break; // Exit the loop if the index is valid
        } else {
          cout << "Invalid index. Please try again.\n"; // Prompt
for
  correct input
        }
      }
      break;
    case 4:
      // Exit the program
      cout << "Exiting the program...\n";
      break;
    default:
      // Handle invalid menu choices
      cout << "Invalid choice. Please try again.\n";
      break;
    }
  } while (choice != 4); // Keep displaying the menu until the user chooses to
  exit
}
// Function to register a new patient at a specific index
void Registration(patient *Patient, int index) {
  cout << "Registering patient at index " << index << "...\n";
  // Collecting patient's first name
  DataEntry("First Name: ", Patient->fName); // Collect and store the patient's
  first name
      // Collecting patient's last name
      DataEntry("Last Name: ",
                Patient->lName); // Collect and store the patient's
  last name
      // Collecting patient's age
      DataEntry("Age: ", Patient->age); // Collect and store the patient's
  age
      // Collecting patient's arrival date
      DataEntry("Arrival Date: ",
                Patient->arrivalDate); // Collect and store the
  patient's arrival date
}
// Function to input patient data
void DataEntry(string instructions, string &input) {
  cout << instructions; // Display the prompt for input (e.g., "First Name: ")
  getline(cin, input);  // Get the input from the user, allowing for spaces in
  the input
}
// Function to display all patients' data
void DisplayPatients(patient *Patients, int size) {
  cout << "\nDisplaying all patients:\n";
  // Loop through the array to display each patient's data
  for (int i = 0; i < size; i++) {
    // Check if the patient at index i has been registered (i.e., first name is
not empty)
if (Patients[i].fName != "") {
  // Print the patient's information
  cout << "Patient at index " << i << ":\n";
  cout << "First Name: " << Patients[i].fName << "\n";
  cout << "Last Name: " << Patients[i].lName << "\n";
  cout << "Age: " << Patients[i].age << "\n";
  cout << "Arrival Date: " << Patients[i].arrivalDate << "\n\n";
}
else {
  // If no patient is registered at this index, display a message
  cout << "Patient at index " << i << " is empty.\n\n";
}
  }
}
// Function to update the data of a specific patient
void UpdatePatient(patient *Patient, int index) {
  cout << "Updating patient at index " << index << "...\n";
  // Update the patient's first name
  DataEntry("First Name: ", Patient->fName); // Collect and update the patient's
  first name
      // Update the patient's last name
      DataEntry("Last Name: ",
                Patient->lName); // Collect and update the patient's
  last name
      // Update the patient's age
      DataEntry("Age: ", Patient->age); // Collect and update the patient's
  age
      // Update the patient's arrival date
      DataEntry("Arrival Date: ",
                Patient->arrivalDate); // Collect and update the
  patient's arrival date
}

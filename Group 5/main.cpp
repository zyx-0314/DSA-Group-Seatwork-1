#include <iostream>
#include <string>
using namespace std;
// Patient structure for holding essential information
struct PatientRecord {
  string FirstName = ""; // First name of the patient
  string LastName = "";  // Last name of the patient
  string Age = "";       // Age of the patient
  string Arrival = "";   // Date of patient's arrival
};
// Function declarations
void RegisterPatient(PatientRecord *,
                     int);         // Add patient data at specific index
void InputField(string, string &); // Gather individual patient details
void ShowAllPatients(PatientRecord *, int); // Display details of all patients
void ModifyPatient(PatientRecord *,
                   int); // Modify patient data at specific index
int main() {
  PatientRecord Records[10]; // Array to store 10 patient records
  int Position;
  // Loop to register patient at a valid index
  while (true) {
    cout << "Please choose an index for storing patient data (0-9): ";
    cin >> Position;
    cin.ignore(); // Clear input buffer
    if (Position >= 0 && Position < 10) {
      RegisterPatient(&Records[Position], Position); // Store patient data
      break; // Exit loop after valid index
    } else {
      cout << "Index out of range. Try again.\n";
    }
  }
  // Menu for displaying or updating patients
  int Action;
  do {
    cout << "\nMenu:\n1. View all patients\n2. Edit patient data\n3. Exit "
            "program\nYour selection : ";
    cin >> Action;
    cin.ignore(); // Clear input buffer
    switch (Action) {
    case 1:
      ShowAllPatients(Records, 10); // Display all records
      break;
    case 2:
      while (true) {
        cout << "Which index would you like to update (0-9)?: ";
        cin >> Position;
        cin.ignore(); // Clear input buffer
        if (Position >= 0 && Position < 10) {
          ModifyPatient(&Records[Position],
                        Position); // Modify existing patient
          break;
        } else {
          cout << "Invalid index. Please try again.\n";
        }
      }
      break;
    case 3:
      cout << "Exiting the program.\n";
      break;
    default:
      cout << "Unrecognized option. Please try again.\n";
    }
  } while (Action != 3);
}
// Function to register new patient data
void RegisterPatient(PatientRecord *Record, int Position) {
  cout << "Storing patient data at index " << Position << "...\n";
  InputField("Enter first name: ", Record->FirstName);
  InputField("Enter last name: ", Record->LastName);
  InputField("Enter age: ", Record->Age);
  InputField("Enter arrival date: ", Record->Arrival);
}
// Helper function to take input for each field
void InputField(string Prompt, string &InputField) {
  cout << Prompt;
  getline(cin, InputField);
}
// Display details of all patients
void ShowAllPatients(PatientRecord *Records, int Total) {
  cout << "\nPatient records:\n";
  for (int i = 0; i < Total; i++) {
    if (Records[i].FirstName != "") { // Display only if data exists
      cout << "Record at index " << i << ":\n";
      cout << "First Name: " << Records[i].FirstName << "\n";
      cout << "Last Name: " << Records[i].LastName << "\n";
      cout << "Age: " << Records[i].Age << "\n";
      cout << "Arrival Date: " << Records[i].Arrival << "\n\n";
    } else {
      cout << "No data at index " << i << ".\n\n";
    }
  }
}
// Modify existing patient record
void ModifyPatient(PatientRecord *Record, int Position) {
  cout << "Modifying patient at index " << Position << "...\n";
  InputField("New first name: ", Record->FirstName);
  InputField("New last name: ", Record->LastName);
  InputField("New age: ", Record->Age);
  InputField("New arrival date: ", Record->Arrival);
}

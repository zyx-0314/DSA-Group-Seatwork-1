#include <iostream>
#include <string>
// Define a structure to hold patient information such as first name, last name, age, and arrival date
struct patient {
std::string fName = "";
std::string lName = "";
std::string age = "";
std::string arrivalDate = "";
};
// Function prototypes
void Registration(patient*); // Function to register a patient
void DataEntry(std::string, std::string&); // Function to get input for a specific field like first name, last name, etc.
void DisplayPatient(patient*, int); // Function to display patient data at Index 3
void UpdatePatient(patient*); // Function to update patient data at Index 3
int main() {
patient Patient;
int choice; // Variable to store the user's menu choice
do {
// Display a simple menu to the user
std::cout << "\n-----------------MENU-----------------";
std::cout << "\n1. Register Patient\n";
std::cout << "2. Display Patient Details\n";
std::cout << "3. Update Patient Details\n";
std::cout << "4. Exit\n";
std::cout << "Enter your choice: ";
std::cin >> choice; // Read the user's choice
std::cin.ignore(); // This clears the input buffer to avoid issues with the next input
// Process the user's choice using a switch statement
switch (choice) {
case 1:
// Register the patient at Index 3
std::cout << "\nRegistering Patient\n";
Registration(&Patient); // Pass reference to the patient
break;
case 2:
// Display the patient's information at Index 3
std::cout << "\nPatient Details:\n";
DisplayPatient(&Patient, 3); // Display the patient at Index 3
break;
case 3:
// Update the patient at Index 3
std::cout << "\nUpdating Patient Details\n";
UpdatePatient(&Patient); // Update the patient data
break;
case 4:
// Exit the program
std::cout << "Exiting program...\n";
break;
default:
// Handle invalid choices
std::cout << "Invalid choice!\n";
break;
}
} while (choice != 4); // The menu will keep showing until the user chooses to exit (option 4)
return 0;
}
// Function to register a patient by asking the user to input their details
void Registration(patient* Patient) {
// Use the DataEntry function to get input from the user for each field.
DataEntry("First Name: ", Patient->fName);
DataEntry("Last Name: ", Patient->lName);
DataEntry("Age: ", Patient->age);
DataEntry("Arrival Date: ", Patient->arrivalDate);
}
// Function to get input from the user for a specific field
void DataEntry(std::string instructions, std::string& input) {
std::cout << instructions; // Display the message like the first name, last name, etc.
getline(std::cin, input); // Read the user's input and store it in the 'input' variable
}
// Function to display the patient's details at index 3
void DisplayPatient(patient* Patient) {
std::cout << "First Name: " << Patient->fName << "\n";
std::cout << "Last Name: " << Patient->lName << "\n";
std::cout << "Age: " << Patient->age << "\n";
std::cout << "Arrival Date: " << Patient->arrivalDate << "\n";
}
// Function to update the patient at index 3
void UpdatePatient(patient* Patient) {
Registration(Patient); // Reuse the Registration function to update the patient's data
}


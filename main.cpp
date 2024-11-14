/*
* Create a system that accepts list of patients
*/

#include <iostream>
#include <string>

// Define a structure to hold patient information such as first name, last name, age, and arrival date
struct Patient {
	bool notOccupied = false;
	std::string fName = "";
	std::string lName = "";
	std::string age = "";
	std::string arrivalDate = "";
};

// Function prototypes
void PatientDataEntry(Patient&);				// Function to register a patient
void DataEntry(std::string, std::string&);  // Function to get input for a specific field like first name, last name, etc.
void DisplayPatientList(Patient&);			// Function to display patient data
void Menu(int&);

int main() {
	const int MAX_PATIENT = 5;

	Patient patient[MAX_PATIENT];
	int choice;

	do {
		// 1. Display a simple menu to the user
		Menu(choice);

		// 2. Process the user's choice using a switch statement
		switch (choice) {
		// 2.1 Register Patient
		case 1:
			// 2.1.1 Initialize a boolean which indicates if the data is not yet stored
			bool isNotStored = false;

			std::cout << "\nRegistering Patient\n";
			// 2.1.2 Loop for each patient until last slot
			for (int i = 0; i < MAX_PATIENT; i++)
			{
				// 2.1.3 Check each patient id if it has value of 0
				if (!patient[i].notOccupied) {
					PatientDataEntry(patient[i]);		// Pass reference to the patient
				}
			}
			break;
		// 2.2 Display patient's list information
		case 2:
			std::cout << "\nPatient Details:\n";
			// 2.2.1 Loop for each patient until last slot
			for (int i = 0; i < MAX_PATIENT; i++)
			{
				// 2.2.2 Check each patient id if it has value is more than 0
				if (!patient[i].notOccupied) {
					DisplayPatient(patient[i]);
				}
			}
			break;
		case 3:
			int choice;

			std::cout
				<< "\nUpdating Patient Details\n"
				<< "\nEnter ID (1 -" << MAX_PATIENT << "): ";
			std::cin >> choice;
			PatientDataEntry(patient[choice]); // Update the patient data
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
void PatientDataEntry(Patient& patient) {
	// Use the DataEntry function to get input from the user for each field.
	DataEntry("First Name: ", patient.fName);
	DataEntry("Last Name: ", patient.lName);
	DataEntry("Age: ", patient.age);
	DataEntry("Arrival Date: ", patient.arrivalDate);
}

// Function to get input from the user for a specific field
void DataEntry(std::string instructions, std::string& input) {
	std::cout << instructions; // Display the message like the first name, last name, etc.
	getline(std::cin, input); // Read the user's input and store it in the 'input' variable
}

// Function to display the patient's details at index 3
void DisplayPatient(Patient& patient) {
	std::cout << "First Name: " << patient.fName << "\n";
	std::cout << "Last Name: " << patient.lName << "\n";
	std::cout << "Age: " << patient.age << "\n";
	std::cout << "Arrival Date: " << patient.arrivalDate << "\n";
}

void Menu(int& choice)
{
	std::cout << "\n-----------------MENU-----------------";
	std::cout << "\n1. Register Patient\n";
	std::cout << "2. Display Patient Details\n";
	std::cout << "3. Update Patient Details\n";
	std::cout << "4. Exit\n";
	std::cout << "Enter your choice: ";
	std::cin >> choice; // Read the user's choice
	std::cin.clear(); // This clears the input buffer to avoid issues with the next input
}

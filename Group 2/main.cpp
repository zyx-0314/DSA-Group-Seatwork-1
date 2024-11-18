#include <iostream>
#include <string>
using namespace std;
// Struct store patients detail
struct patient {
  string fname = "";
  string lname = "";
  string age = "";
  string arrivalDate = "";
};
// Function declaration
void Registration(patient *, int);
void DataEntry(string, string &);
void PatientDetail(patient *, int);
void DisplayAll(patient *, int);
void UpdatePatient(patient *, int);
int main() {
  patient Patients[10]; // Array that stores up 10 patients
  int index = 0;        // index for array
  int count = 0;        // number of patients entered
  char choice;          // Choice input for patient
  cout << "====[ WELCOME TO HOSPITAL ]====" << endl;
  cout << "INPUT A PATIENT? [Y/N] : ";
  cin >> choice;
  if (choice == 'Y' || choice == 'y') {
    if (count < 10) {
      cout << "===============================" << endl;
      cout << "INPUT AN INDEX NUMBER [0 - 9]: ";
      cin >> index;
      cin.ignore();
      if (index >= 0 && index < 10) {
        Registration(&Patients[index], index);
        count++;
      } else {
        cout << "INVALID INDEX NUMBER. PLEASE ENTER A VALID INDEX NUMBER."
             << endl;
      }
    } else {
      cout << "PATIENT LIST IS FULL!" << endl;
    }
    int option;
    do {
      // Menu options
      cout << "===========[ MENU ]==========" << endl;
      cout << "[ 1 ] ADD PATIENT" << endl;
      cout << "[ 2 ] PATIENT DETAILS" << endl;
      cout << "[ 3 ] DISPLAY ALL PATIENTS" << endl;
      cout << "[ 4 ] MODIFY PATIENTS" << endl;
      cout << "[ 5 ] EXIT" << endl;
      cout << "===============================" << endl;
      cout << "Input your choice: ";
      cin >> option;
      cout << "===============================" << endl;
      // Switch case for the different options
      switch (option) {
      case 1:
        if (count < 10) {
          cout << "INPUT AN INDEX NUMBER [0 - 9]: ";
          cin >> index;
          cin.ignore();
          if (index >= 0 && index < 10) {
            Registration(&Patients[index],
                         index); // add patient at index count++;
          } else {
            cout << "INVALID INDEX NUMBER. PLEASE ENTER A VALID INDEX NUMBER."
                 << endl;
          }
        } else {
          cout << "PATIENT LIST IS FULL!" << endl;
        }
        break;
      case 2:
        int indexToView;
        cout << "INPUT AN INDEX NUMBER [0 - 9]: ";
        cin >> indexToView;
        cin.ignore();
        PatientDetail(Patients,
                      indexToView); // view detail of patients in specific index
        break;
      case 3:
        cout << "DISPLAYING ALL PATIENTS" << endl;
        DisplayAll(Patients, count); // view all patients
        break;
      case 4:
        int indexToUpdate;
        cout << "INPUT AN INDEX NUMBER [0 - 9]: ";
        cin >> indexToUpdate;
        cin.ignore();
        UpdatePatient(Patients, indexToUpdate); // update patients
        break;
      case 5:
        cout << "GOODBYE...." << endl; // exit program
        break;
      default:
        cout << "Invalid Input. Try Again." << endl;
      }
    } while (option != 5);
  } else {
    cout << "Exiting...." << endl;
  }
  return 0;
}
// Func to register patient details
void Registration(patient *Patient, int index) {
  cout << "===============================" << endl;
  cout << "PATIENT INDEX NUMBER " << index << endl;
  DataEntry("Input First Name: ", Patient->fname);
  DataEntry("Input Last Name: ", Patient->lname);
  DataEntry("Input Age: ", Patient->age);
  DataEntry("Input Date of Arrival: ", Patient->arrivalDate);
}
// Func to handle data entry
void DataEntry(string instructions, string &input) {
  cout << instructions;
  getline(cin, input);
}
// Displays the details of specific patient
void PatientDetail(patient *Patients, int index) {
  if (index >= 0 && index < 10) {
    cout << "===============================" << endl;
    cout << "DISPLAYING PATIENT DETAILS OF INDEX NUMBER: " << index << "\n";
    cout << "First Name: " << Patients[index].fname << "\n";
    cout << "Last Name: " << Patients[index].lname << "\n";
    cout << "Age: " << Patients[index].age << "\n";
    cout << "Arrival Date: " << Patients[index].arrivalDate << "\n";
  } else {
    cout << "Invalid index.\n";
  }
}
// Displays all patient
void DisplayAll(patient *Patients, int count) {
  cout << "\n";
  for (int i = 0; i < count; i++) {
    cout << "Index " << i << ": " << Patients[i].fname << " "
         << Patients[i].lname << "\n";
    cout << "\n";
  }
}
// Update details of an existing patient
void UpdatePatient(patient *Patients, int index) {
  if (index >= 0 && index < 10) {
    cout << "UPDATING THE PATIENT AT INDEX NUMBER " << index << ":\n";
    cout << "New First Name: ";
    getline(cin, Patients[index].fname);
    cout << "New Last Name: ";
    getline(cin, Patients[index].lname);
    cout << "New Age: ";
    getline(cin, Patients[index].age);
    cout << "New Arrival Date: ";
    getline(cin, Patients[index].arrivalDate);
  } else {
    cout << "Invalid index.\n";
  }
}

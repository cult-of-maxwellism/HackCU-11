#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;
void before();
void after();
void during();
void all();
<<<<<<< HEAD
void diagnostic(string type);
void preventative(string type);
=======
void diagnostic(string carname, string filepath);
void preventative(string carname, string filepath);
>>>>>>> 4d76de2dfe4b1612ce456f5eafa8e7549fdef387
string get_valid_vehicle_type();


int main()
{
    cout << "Welcome to the Preventative Maintenance Diagnostic Tool.\n";
    cout << "Enter 1 for preventative maintenance or 2 to diagnose an issue: ";

    int input;
    cin >> input;

    while (input != 1 && input != 2)
    {
        cout << "Invalid input. Please enter 1 for preventative maintenance or 2 to diagnose an issue: ";
        cin >> input;
    }

    string carname = get_valid_vehicle_type();
    string filepath;
    filepath = "./vehicle-directory/";
    filepath += carname;

    if (input == 1)
        preventative(carname,filepath);
    else
        diagnostic(carname,filepath);
    return 0;
}

void before(){
    int num = 3;
    ifstream inputFile("prev_before.txt");
    ofstream outputFile("prev.txt", ios::app); // Ensure truncation for fresh writing

    if (!inputFile)
    {
        cerr << "Error: Unable to open 'prev_before.txt'. Ensure the file exists.\n";
        return;
    }
    if (!outputFile)
    {
        cerr << "Error: Unable to create 'prev.txt'. Check file permissions.\n";
        return;
    }

    string line;
    bool wroteData = false;
    while (getline(inputFile, line))
    {
        outputFile << "" << "\n"; // Write to file
        wroteData = true;
    }

    // Flush and close files properly
    outputFile.flush();
    inputFile.close();
    outputFile.close();

    if (wroteData)
    {
        cout << "Preventative maintenance log successfully saved to 'prev.txt'.\n";
    }
    else
    {
        cout << "Warning: 'prev_before.txt' was empty. No data written to 'preventative.txt'.\n";
    }
}

void during(){

    ifstream inputFile("prev_during.txt");
    ofstream outputFile("prev.txt", ios::app); // Ensure truncation for fresh writing

    if (!inputFile)
    {
        cerr << "Error: Unable to open 'prev_during.txt'. Ensure the file exists.\n";
        return;
    }
    if (!outputFile)
    {
        cerr << "Error: Unable to create 'prev.txt'. Check file permissions.\n";
        return;
    }

    string line;
    bool wroteData = false;
    while (getline(inputFile, line))
    {
        outputFile << line << "\n"; // Write to file
        wroteData = true;
    }

    // Flush and close files properly
    outputFile.flush();
    inputFile.close();
    outputFile.close();

    if (wroteData)
    {
        cout << "Preventative maintenance log successfully saved to 'prev.txt'.\n";
    }
    else
    {
        cout << "Warning: 'prev_during.txt' was empty. No data written to 'preventative.txt'.\n";
    }
}

void after(){

    ifstream inputFile("prev_after.txt");
    ofstream outputFile("prev.txt", ios::app); // Ensure truncation for fresh writing

    if (!inputFile)
    {
        cerr << "Error: Unable to open 'prev_after.txt'. Ensure the file exists.\n";
        return;
    }
    if (!outputFile)
    {
        cerr << "Error: Unable to create 'prev.txt'. Check file permissions.\n";
        return;
    }

    string line;
    bool wroteData = false;
    while (getline(inputFile, line))
    {
        outputFile << line << "\n"; // Write to file
        wroteData = true;
    }

    // Flush and close files properly
    outputFile.flush();
    inputFile.close();
    outputFile.close();

    if (wroteData)
    {
        cout << "Preventative maintenance log successfully saved to 'prev.txt'.\n";
    }
    else
    {
        cout << "Warning: 'prev_after.txt' was empty. No data written to 'preventative.txt'.\n";
    }
}

void all(){

    ifstream inputFile("prev_all.txt");
    ofstream outputFile("prev.txt", ios::app); // Ensure truncation for fresh writing

    if (!inputFile)
    {
        cerr << "Error: Unable to open 'prev_all.txt'. Ensure the file exists.\n";
        return;
    }
    if (!outputFile)
    {
        cerr << "Error: Unable to create 'prev.txt'. Check file permissions.\n";
        return;
    }

    string line;
    bool wroteData = false;
    while (getline(inputFile, line))
    {
        outputFile << line << "\n"; // Write to file
        wroteData = true;
    }

    // Flush and close files properly
    outputFile.flush();
    inputFile.close();
    outputFile.close();

    if (wroteData)
    {
        cout << "Preventative maintenance log successfully saved to 'prev.txt'.\n";
    }
    else
    {
        cout << "Warning: 'prev_all.txt' was empty. No data written to 'preventative.txt'.\n";
    }
}

void diagnostic(string type)
{
    int part;
    ofstream file("diagnostic_report.txt", ios::app);
    if (!file)
    {
        cerr << "Error opening diagnostic report file!" << endl;
        return;
    }

    cout << "Diagnosing issue for " << type << " vehicle.\n";
    cout << "Select the system experiencing trouble:\n";
    cout << "1. Engine\n";
    cout << "2. Transmission\n";
    cout << "3. Drivetrain/Wheels/Suspension\n";
    cout << "4. Doors/Windows\n";
    cout << "5. Accessories\n";
    cout << "6. Engine Accessories\n";
    cout << "7. Exhaust System\n";
    cout << "8. Lights/Horn\n";

    cin >> part;

    while (part < 1 || part > 8)
    {
        cout << "Invalid option. Please enter a valid number (1-8): ";
        cin >> part;
    }

    file << "Diagnostic report for " << type << " vehicle:\n";
    switch (part)
    {
    case 1:
        file << "Issue reported: Engine\n";
        cout << "Check engine oil, fuel system, and spark plugs (if applicable).\n";
        break;
    case 2:
        file << "Issue reported: Transmission\n";
        cout << "Check transmission fluid levels and signs of slipping.\n";
        break;
    case 3:
        file << "Issue reported: Drivetrain/Wheels/Suspension\n";
        cout << "Inspect CV joints, wheel bearings, and alignment.\n";
        break;
    case 4:
        file << "Issue reported: Doors/Windows\n";
        cout << "Check power window motors and door locking mechanisms.\n";
        break;
    case 5:
        file << "Issue reported: Accessories\n";
        cout << "Check radio, air conditioning, and electronic accessories.\n";
        break;
    case 6:
        file << "Issue reported: Engine Accessories\n";
        cout << "Inspect alternator, water pump, and serpentine belt.\n";
        break;
    case 7:
        file << "Issue reported: Exhaust System\n";
        cout << "Check for leaks, catalytic converter issues, and unusual noises.\n";
        break;
    case 8:
        file << "Issue reported: Lights/Horn\n";
        cout << "Inspect headlight bulbs, fuses, and horn functionality.\n";
        break;
    }

    cout << "Diagnostic report saved to 'diagnostic_report.txt'.\n";
    file.close();
}
void preventative(string type)
{
    cout << "Enter a number from the menu:\n";
    cout << "1. Before driving\n";
    cout << "2. During driving\n";
    cout << "3. After driving\n";
    cout << "4. All\n"; 
    int option;
    cin >> option;
    switch(option){

        case 1:
        case 2:
        case 3:
        case 4:
    }
    
}

<<<<<<< HEAD
string get_vehicle_number_type()
=======
string get_vehicle_number()
>>>>>>> 4d76de2dfe4b1612ce456f5eafa8e7549fdef387
{
    //this needs to check each line of the string to ensure vehicle name doesn't have spaces or \ or / characters -anything file doesn't like
    string VehicleNum;
    cout << "Enter vehicle identification number: ";
    cin >> VehicleNum;

    return VehicleNum;
}

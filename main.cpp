#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

void diagnostic(string type)
{
    int part;
    ofstream file("diagnostic_report.txt", ios::trunc);
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
    ifstream inputFile("prev_before.txt");
    ofstream outputFile("prev.txt", ios::trunc); // Ensure truncation for fresh writing

    if (!inputFile)
    {
        cerr << "Error: Unable to open 'prev_before.txt'. Ensure the file exists.\n";
        return;
    }
    if (!outputFile)
    {
        cerr << "Error: Unable to create 'preventative.txt'. Check file permissions.\n";
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
        cout << "Warning: 'prev_before.txt' was empty. No data written to 'preventative.txt'.\n";
    }
}

string get_valid_vehicle_type()
{
    string fuel_type;
    cout << "Enter vehicle type: Gas, Diesel, or Electric: ";
    cin >> fuel_type;

    transform(fuel_type.begin(), fuel_type.end(), fuel_type.begin(), ::tolower);

    while (fuel_type != "gas" && fuel_type != "diesel" && fuel_type != "electric")
    {
        cout << "Invalid input. Please enter Gas, Diesel, or Electric: ";
        cin >> fuel_type;
        transform(fuel_type.begin(), fuel_type.end(), fuel_type.begin(), ::tolower);
    }
    return fuel_type;
}

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

    string fuel_type = get_valid_vehicle_type();

    if (input == 1)
        preventative(fuel_type);
    else
        diagnostic(fuel_type);

    return 0;
}

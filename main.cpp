#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main()
{
    cout << "Welcome to the Preventative Maintenance Diagnostic Tool.\n\n\n";
    cout << "Please enter 1 for preventative maintenance or 2 to diagnose an issue\n\n";
    int input;
    string fuel_type;
    cin >> input;

    while (input != 1 && input != 2)
    {
        cout << "Invalid input. Please enter 1 for preventative maintenance or 2 to diagnose an issue: ";
        cin >> input;
    }

    cout << "Please enter type of vehicle: Gas, Diesel, or Electric\n\n";
    cin >> fuel_type;

    transform(fuel_type.begin(), fuel_type.end(), fuel_type.begin(), [](unsigned char c)
              { return tolower(c); });

    while (fuel_type != "gas" && fuel_type != "diesel" && fuel_type != "electric")
    {
        cout << "Invalid input, please enter a valid type of vehicle (Gas, Diesel, or Electric): ";
        cin >> fuel_type;
        transform(fuel_type.begin(), fuel_type.end(), fuel_type.begin(), [](unsigned char c)
                  { return tolower(c); });
    }

    unordered_set<string> valid_parts = {"engine", "transmission", "drivetrain", "wheels", "suspension", "doors", "windows", "accessories", "engine accessories", "exhaust system", "lights", "horn"};

    string part;

    switch (input)
    {
    case 1:
        cout << "Performing preventative maintenance for " << fuel_type << " vehicle.\n";
        cout << "Please open the hood and find the engine. Check for the following items:\n";
        break;

    case 2:
        cout << "Diagnosing issue for " << fuel_type << " vehicle.\n";
        cout << "What is having trouble?\n";
        cout << "Engine\n";
        cout << "Transmission\n";
        cout << "Drivetrain/wheels/suspension\n";
        cout << "Doors/windows\n";
        cout << "Accessories\n";
        cout << "Engine Accessories\n";
        cout << "Exhaust system\n";
        cout << "Lights/Horn\n";

        cin >> part;
        ofstream file("diagnostic_report.txt", ios::app); // Open in append mode

        if (!file)
        {
            cerr << "Error opening file!" << endl;
            return 1;
        }

        while (valid_parts.find(part) == valid_parts.end())
        {
            cout << "Invalid part, please enter a valid part: ";
            cin >> part;
        }

        if (part == "engine")
        {
            file << "Checking the engine.\n"; // Only output to file for engine
        }
        else if (part == "transmission")
        {
            file << "Checking the transmission.\n"; // Only output to file for transmission
        }
        else if (part == "drivetrain" || part == "wheels" || part == "suspension")
        {
            file << "Checking the drivetrain, wheels, or suspension.\n"; // Only output to file for drivetrain/wheels/suspension
        }
        else if (part == "doors" || part == "windows")
        {
            file << "Checking the doors or windows.\n"; // Only output to file for doors/windows
        }
        else if (part == "accessories")
        {
            file << "Checking the accessories.\n"; // Only output to file for accessories
        }
        else if (part == "engine accessories")
        {
            file << "Checking the engine accessories.\n"; // Only output to file for engine accessories
        }
        else if (part == "exhaust system")
        {
            file << "Checking the exhaust system.\n"; // Only output to file for exhaust system
        }
        else if (part == "lights" || part == "horn")
        {
            file << "Checking the lights or horn.\n"; // Only output to file for lights/horn
        }

        break;

    default:
        cout << "Invalid input, please enter 1 or 2.\n";
        break;
    }

    return 0;
}

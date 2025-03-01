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

        while (valid_parts.find(part) == valid_parts.end()) 
        {
            cout << "Invalid part, please enter a valid part: ";
            cin >> part;
        }

        if (part == "engine")
        {
        }
        else if (part == "transmission")
        {
        }
        else if (part == "drivetrain" || part == "wheels" || part == "suspension")
        {
        }
        else if (part == "doors" || part == "windows")
        {
        }
        else if (part == "accessories")
        {
        }
        else if (part == "engine accessories")
        {
        }
        else if (part == "exhaust system")
        {
        }
        else if (part == "lights" || part == "horn")
        {
        }

        break;

    default:
        cout << "Invalid input, please enter 1 or 2.\n";
        break;
    }

    return 0;
}

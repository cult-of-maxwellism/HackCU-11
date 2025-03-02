#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>
#include <unordered_set>

using namespace std;

void diagnostic(string type){

    int part;
    ofstream file("diagnostic_report.txt", ios::app); // Open in append mode
    cout << "Diagnosing issue for " << type << " vehicle. \n";
        cout << "What is having trouble? Enter the number of the option wanted\n";
        cout << "1. Engine\n";
        cout << "2. Transmission\n";
        cout << "3. Drivetrain/wheels/suspension\n";
        cout << "4. Doors/windows\n";
        cout << "5. Accessories\n";
        cout << "6. Engine Accessories\n";
        cout << "7. Exhaust system\n";
        cout << "8. Lights/Horn\n";

        cin >> part;

        if (!file)
        {
            cerr << "Error opening file!" << endl;
            return;
        }

        while (part)
        {
            cout << "Invalid part, please enter a valid part: ";
            cin >> part;
        }

        switch(part)
{
            case 1:
                
            case 2:

            case 3:

            case 4:

            case 5:

            case 6:

            case 7:

            case 8:

            default:
            break;
}
        return;
}
bool preventative_helper(bool x)
{
    x = true;
    return x;
}

void preventative(string type)
{
    return;
}

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

   

    switch (input)
    {
    case 1:
        preventative(fuel_type);

    case 2:
        diagnostic(fuel_type);
    default:
        cout << "Invalid input, please enter 1 or 2.\n";
        break;
    }

    return 0;
}

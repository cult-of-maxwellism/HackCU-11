#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

int main()
{
    cout << "Welcome to the Preventative Maintenance Diagnostic Tool.\n\n\n";
    cout << "Please enter 1 for preventative maintenance or 2 to diagnose an issue\n\n";
    int input;
    string fuel_type;
    cin >> input;

    // Validate the main input (1 or 2)
    while (input != 1 && input != 2) {
        cout << "Invalid input. Please enter 1 for preventative maintenance or 2 to diagnose an issue: ";
        cin >> input;
    }

    // Now, ask for fuel type (this applies for both 1 and 2 cases)
    cout << "Please enter type of vehicle: Gas, Diesel, or Electric\n\n";
    cin >> fuel_type;
    
    // Convert the input to lowercase
    transform(fuel_type.begin(), fuel_type.end(), fuel_type.begin(), [](unsigned char c) { return tolower(c); });

    // Validate the fuel type input
    while (fuel_type != "gas" && fuel_type != "diesel" && fuel_type != "electric") {
        cout << "Invalid input, please enter a valid type of vehicle (Gas, Diesel, or Electric): ";
        cin >> fuel_type;
        transform(fuel_type.begin(), fuel_type.end(), fuel_type.begin(), [](unsigned char c) { return tolower(c); });
    }

    // Now, handle the valid fuel types based on the main choice
    switch (input)
    {
        case 1:
            cout << "Performing preventative maintenance for " << fuel_type << " vehicle.\n";
            break;

        case 2:
            cout << "Diagnosing issue for " << fuel_type << " vehicle.\n";
            break;

        default:
            cout << "Invalid input, please enter 1 or 2.\n";
            break;
    }

    return 0;
}

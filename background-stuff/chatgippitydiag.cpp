#include <iostream>
#include <fstream>
#include <map>
#include <functional>

using namespace std;

void engine(string filepath);
void transmission(string filepath);
void drivetrain(string filepath);
void bodywork(string filepath);
void EngAcc(string filepath);
void exhaust(string filepath);
void lights(string filepath);
void accessories(string filepath);

int UserInput(int valid) {
    int userIn;
    cin >> userIn;
    while (userIn < 1 || userIn > valid) {
        cout << "Invalid input! Please select from 1 to " << valid << endl;
        cin >> userIn;
    }
    return userIn;
}

void diagnostic(string carname, string filepath) {
    ofstream file(filepath);
    if (!file) return;

    // Map of diagnostic functions
    map<int, function<void(string)>> diagnosticFunctions = {
        {1, engine}, {2, transmission}, {3, drivetrain},
        {4, bodywork}, {5, EngAcc}, {6, exhaust},
        {7, lights}, {8, accessories}
    };

    int userIn;
    do {
        cout << "Diagnosing issue for vehicle " << carname << ".\n"
             << "Select the system experiencing trouble:\n"
             << "1. Engine\n2. Transmission\n3. Drivetrain/Wheels/Suspension\n"
             << "4. Bodywork/Doors/Windows\n5. Engine Accessories\n"
             << "6. Exhaust System\n7. Lights/Horn\n8. Accessories\n"
             << "9. Return to main menu\n";

        userIn = UserInput(9);
        if (userIn == 9) break;

        file << "Issue reported: ";
        switch (userIn) {
            case 1: file << "Engine\n"; break;
            case 2: file << "Transmission\n"; break;
            case 3: file << "Drivetrain/Wheels/Suspension\n"; break;
            case 4: file << "Bodywork/Doors\n"; break;
            case 5: file << "Engine Accessories\n"; break;
            case 6: file << "Exhaust System\n"; break;
            case 7: file << "Lights/Horn\n"; break;
            case 8: file << "Accessories\n"; break;
            default: cout << "Invalid Input! How did you get this error?" << endl; return;
        }

        // Call the corresponding function
        diagnosticFunctions[userIn](filepath);

    } while (userIn != 9);

    cout << "Diagnostic report saved to " << filepath << endl;
    file.close();
}

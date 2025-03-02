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
void diagnostic(string carname, string filepath);
void preventative(string carname, string filepath);
string get_valid_vehicle_type();

void driving (string carname, string filepath) {
    cout <<  "Did any of the following happen?" << endl;
    cout << "1. engine suddently shuts off" << endl;

    if userin = 1 {
        ofstream fout(filepath.c_str(), ios::trunc);      

        if (fout) fout << "Severity: Deadline.  Fix: Transmission or engine needs to be replaced.     Maint. Note: order Trans/Eng for " << carname << endl;
        else cout << "failed to open file\n";
    }
}
 /*if the car doesn't stay in a straight line
            check tie rods
                if they're bent, you can attempt to straighten them to get home (not recommended), but replace ASAP.
                if not, get an alignment
        if the car is incredibly "bouncy" over bumps:
            Your suspension is too old, replace suspension
        if the car pulls to the left or right while braking:
            flush brake fluid, if that doesn't fix it
            check for (and replace) seized brake cylinders, if none are siezed check and replace brake fluid pump
        if the car doesn't stop when braking
            check and replace brake pads
            flush brake fluid, if that doesn't fix it
            check for (and replace) seized brake cylinders, if none are siezed check and replace brake fluid pump
        if the car shifts hard or doesn't change gear:
            transmission or clutch is going, recommend seeing a mechanic.
        if the car vibrates heavily when stopped
            the motor mounts are going or mis-sized, see mechanic to replace.
        if vehicle doesn't move when pushing on the gas and in gear
            either the clutch is out or the drivetrain is disconnected, tow to mechanic. */

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

string get_vehicle_number()
{
    string VehicleNum;
    cout << "Enter vehicle identification number: ";
    cin >> VehicleNum;

    return VehicleNum;
}
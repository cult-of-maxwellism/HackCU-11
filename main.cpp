#include <cctype>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

#include "diagnostic.cpp"

using namespace std;

ofstream open_file(const string &filepath);
string get_vehicle_number();

void performPreventative(string carname, string filepath);
void checkStart(string filepath);
void inspectEngine(string filepath);
void checkBattery(string filepath);
void checkFluids(string filepath);
void checkBrakePads(string filepath);
void inspectTires(string filepath);

void diagnostic(string carname, string filepath);
void engine(string filepath);
void transmission(string filepath);
void drivetrain(string filepath);
void bodywork(string filepath);
void EngAcc(string filepath);
void exhaust(string filepath);
void lights(string filepath);
void accessories(string filepath);

int main() {
  int input;
  string carname, filepath = "./vehicle-directory/";
  do {
    cout << "Welcome to the Preventative Maintenance Diagnostic Tool.\n";
    cout
        << "Enter 1 for preventative maintenance, 2 to diagnose an issue, or 3 "
           "to exit:\n";

    cin >> input;

    if (input == 1 || input == 2) {
      time_t t = time(0); // get time now
      tm *now = localtime(&t);
      carname = get_vehicle_number();
      filepath += carname;
      filepath += ".txt";

      ofstream file = open_file(filepath);
      if (!file)
        return 0;

      file << "Check on vehicle " << carname << " performed on "
           << (now->tm_year + 1900) << '-' << (now->tm_mon + 1) << '-'
           << now->tm_mday << "\n"
           << endl;

      if (input == 1) {
        performPreventative(carname, filepath);
        file.close();
      } else if (input == 2) {
        diagnostic(carname, filepath);
        file.close();
      } else {
        cout << "Exiting Program..." << endl;
        file.close();
      }
    }
  } while (input != 3);

  return 0;
}
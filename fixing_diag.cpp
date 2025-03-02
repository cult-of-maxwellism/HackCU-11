#include <cctype>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string get_vehicle_number();
void engine(string filepath);
void transmission(string filepath);
void drivetrain(string filepath);
void bodywork(string filepath);
void EngAcc(string filepath);
void exhaust(string filepath);
void lights(string filepath);
void accessories(string filepath);

// Helper function to open a file and handle failure
ofstream open_file(const string &filepath) {
  ofstream file(filepath, ios::app);
  if (!file) {
    cerr << "Error opening diagnostic report file!" << endl;
  }
  return file;
}

// Helper function to request user input for yes/no type decisions
/*int request_user_input(const string &prompt) {
    int userInput;
    cout << prompt;
    cin >> userInput;
    return userInput;
}*/

void diagnostic(string carname, string filepath) {
  int part;
  ofstream file = open_file(filepath);
  if (!file)
    return;
  cout << "Diagnosing issue for vehicle " << carname << ".\n";
  cout << "Select the system experiencing trouble:\n"
       << "1. Engine\n"
       << "2. Transmission\n"
       << "3. Drivetrain/Wheels/Suspension\n"
       << "4. Bodywork/Doors/Windows\n"
       << "5. Engine Accessories\n"
       << "6. Exhaust System\n"
       << "7. Lights/Horn\n"
       << "8. Accessories\n";
  cin >> part;

  while (part < 1 || part > 8) {
    cout << "Invalid option. Please enter a valid number (1-8): ";
    cin >> part;
  }

  file << "Diagnostic report for " << carname << " vehicle:\n";
  switch (part) {
  case 1:
    file << "Issue reported: Engine\n";
    engine(filepath);
    break;
  case 2:
    file << "Issue reported: Transmission\n";
    transmission(filepath);
    break;
  case 3:
    file << "Issue reported: Drivetrain/Wheels/Suspension\n";
    drivetrain(filepath);
    break;
  case 4:
    file << "Issue reported: Bodywork/Doors\n";
    bodywork(filepath);
    break;
  case 5:
    file << "Issue reported: Engine Accessories\n";
    EngAcc(filepath);
    break;
  case 6:
    file << "Issue reported: Exhaust System\n";
    exhaust(filepath);
    break;
  case 7:
    file << "Issue reported: Lights/Horn\n";
    lights(filepath);
    break;
  case 8:
    file << "Issue reported: Accessories\n";
    accessories(filepath);
    break;
  default:
    cout << "Invalid Input! How did you get this error?" << endl;
  }

  cout << "Diagnostic report saved to " << filepath << endl;
  file.close();
}

void engine(string filepath) {
  int userIn;
  ofstream file = open_file(filepath);
  if (!file)
    return;

  cout << "Select engine behavior:\n"
       << "1. Overheating\n"
       << "2. Misfiring\n"
       << "3. Engine Flooded\n"
       << "4. Headgasket Leak\n"
       << "5. Holes or Other\n"
       << "9. Exit\n";

  cin >> userIn;

  switch (userIn) {
  case 1: {
    file << "Be aware: the engine is overheating on this vehicle." << endl;
    cout << "Verify coolant levels. If coolant levels are not the issue, select 1. Otherwise, 2 to exit:" << endl;
    cin >> userIn;
    if (userIn == 2) {
      file << "Issue: radiator inoperable. Order: radiator, cooling assembly."
           << endl;
    } else {
      cout << "Inspect and flush the radiator. If there's no issue with the radiator, select 1. Otherwise, select 2 to write and exit:" << endl;
      if (userIn == 2) {
        file << "Issue: radiator inoperable. Order: radiator, cooling assembly."
             << endl;
      } else {
        cout << "Check thermostat/water pump. If those are fine, select 1 to "
            "notate vehicle needs third-party inspection. Otherwise, 2 to "
            "write and exit: "<< endl;
        if (userIn == 1) {
          file << "Issue unknown, third-party inspection and fix required."
               << endl;
        } else {
          file << "Issue: thermostat and water pump inoperable. Order: water "
                  "pump, cooling assembly wiring."
               << endl;
        }
      }
    }
    break;
  }
  case 2: {
    file << "Be aware: the engine is misfiring on this vehicle." << endl;
    cout << "Inspect spark plugs and ignition coils. If these are in working "
        "condition, select 1. Otherwise, 2 to exit: " << endl;
    if (userIn == 2) {
      file << "Issue: misfire caused by faulty spark plugs or ignition coils. "
              "Order: spark plugs, ignition coils."
           << endl;
    } else {
        cout << "Check fuel injectors. If injectors are working, "
                             "select 1. Otherwise, select 2 to exit: " << endl;
      if (userIn == 2) {
        file << "Issue: faulty fuel injectors. Order: fuel injectors." << endl;
      } else {
        file << "Issue unknown, third-party inspection required." << endl;
      }
    }
    break;
  }
  case 3: {
    file << "Be aware: the engine is flooded." << endl;
    cout <<         "Turn off the engine and wait for a while. Then, try restarting. If "
        "engine starts, select 1. Otherwise, select 2 to exit: "<< endl;
    if (userIn == 2) {
      file << "Issue: flooded engine. Order: spark plugs, air filter." << endl;
    } else {
      cout <<           "If problem persists, check fuel pressure regulator. If not faulty, "
          "select 1. Otherwise, select 2 to exit: "<< endl;
      if (userIn == 2) {
        file << "Issue: faulty fuel pressure regulator. Order: fuel pressure "
                "regulator."
             << endl;
      } else {
        file << "Issue unknown, third-party inspection required." << endl;
      }
    }
    break;
  }
  case 4: {
    file << "Be aware: the engine has a headgasket leak." << endl;
    cout <<         "Check for visible signs of coolant leaks. If no leak is found, select "
        "1. Otherwise, select 2 to exit: "<< endl;
    if (userIn == 2) {
      file << "Issue: headgasket leak detected. Order: headgasket replacement."
           << endl;
    } else {
      cout <<           "Check for white smoke from the exhaust. If smoke is present, select "
          "1. Otherwise, select 2 to exit: "<< endl;
      if (userIn == 2) {
        file
            << "Issue: headgasket leak detected. Order: headgasket replacement."
            << endl;
      } else {
        file << "Issue: suspected headgasket failure. Order: headgasket, "
                "related gaskets."
             << endl;
      }
    }
    break;
  }
  case 5: {
    file << "Be aware: engine has holes or other issues." << endl;
    cout <<         "Inspect the engine block for visible damage. If no damage is found, "
        "select 1. Otherwise, select 2 to exit: " << endl;
    if (userIn == 2) {
      file << "Issue: holes in the engine block. Order: engine block repair or "
              "replacement."
           << endl;
    } else {
      cout <<           "Check for any other unusual noises or vibrations. If abnormal "
          "sounds persist, select 1. Otherwise, select 2 to exit: "<< endl;
      if (userIn == 2) {
        file << "Issue: abnormal noises or vibrations. Order: inspect engine "
                "components for loose parts."
             << endl;
      } else {
        file << "Issue unknown, third-party inspection required." << endl;
      }
    }
    break;
  }
  default:
    cout << "Invalid input, please retry!" << endl;
  }
  cout << "Issue noted. Items listed to order." << endl;
}

int main() {
  cout << "Welcome to the Preventative Maintenance Diagnostic Tool.\n";
  cout << "Enter 1 for preventative maintenance or 2 to diagnose an issue: ";

  int input;
  cin >> input;

  while (input != 1 && input != 2) {
    cout << "Invalid input. Please enter 1 for Preventative Maintenance, 2 to "
            "diagnose an issue, or 3 to exit: ";
    cin >> input;
  }

  string carname = get_vehicle_number();
  string filepath;
  filepath = "./vehicle-directory/";
  filepath += carname;

  if (input != 2) {
    cout << "Not avalible here...";
    // preventative(carname,filepath);
  } else {
    diagnostic(carname, filepath);
  }

  return 0;
}
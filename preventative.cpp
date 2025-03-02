#include <fstream>
#include <iostream>
#include <string>

#include "univ-function.cpp"

using namespace std;

void performPreventative(string carname, string filepath);
void checkStart(string filepath);
void inspectEngine(string filepath);
void checkBattery(string filepath);
void checkFluids(string filepath);
void checkBrakePads(string filepath);
void inspectTires(string filepath);
// Helper function to handle user input and conditionally log the output

bool getUserInput(const string &prompt) {
  string input;
  while (true) {
    cout << prompt;
    cin >> input;
    if (input == "yes") {
      return true;
    } else if (input == "no") {
      return false;
    } else {
      cout << "Invalid input. Please enter 'yes' or 'no'.\n";
    }
  }
}

void inspectTires(string filepath) {
  ofstream file = open_file(filepath);
  if (!file)
    return;
  cout << "Inspecting tires...\n";
  if (getUserInput("Are the tires unevenly worn? (yes/no): ")) {
    if (getUserInput("Are the tie rods fine? (yes/no): ")) {
      cout << "Get an alignment and replace worn tires in the next month.\n";
      file << ("Get an alignment and replace worn tires in the next month.")
           << endl;
    } else {
      cout << "Replace the tie rods.\n";
      file << "Replace the tie rods." << endl;
    }
  }

  if (getUserInput("Is the tire pressure low but above 10 PSI? (yes/no): ")) {
    if (getUserInput("Has this issue been noticed before? (yes/no): ")) {
      cout << "Service the tires within the next month.\n";
      file << "Service the tires within the next month." << endl;
    }
    cout << "Fill the tire with air.\n";
    file << "Fill the tire with air." << endl;
  }
}

void checkBrakePads(string filepath) {
  ofstream file = open_file(filepath);
  if (!file)
    return;
  cout << "Checking brake pads...\n";
  if (getUserInput("Are the brake pads worn out? (yes/no): ")) {
    cout << "You need to replace the brake pads soon.\n";
    file << "You need to replace the brake pads soon." << endl;
  }
}

void checkFluids(string filepath) {
  ofstream file = open_file(filepath);
  if (!file)
    return;
  cout << "Checking fluids...\n";
  if (getUserInput("Are any fluid levels low? (yes/no): ")) {
    cout << "Top off the fluids.\n";
    file << "Top off the fluids." << endl;
  }
}

void checkBattery(string filepath) {
  ofstream file = open_file(filepath);
  if (!file)
    return;
  cout << "Inspecting battery connectors...\n";
  if (getUserInput(
          "Do the battery connectors appear grimy or corroded? (yes/no): ")) {
    cout << "Disconnect and clean the battery connectors.\n";
    file << "Disconnect and clean the battery connectors." << endl;
  }
}

void inspectEngine(string filepath) {
  ofstream file = open_file(filepath);
  if (!file)
    return;
  cout << "Checking for oily/grimy residue or leaks...\n";
  if (getUserInput("Do you see any leaks? (yes/no): ")) {
    string leakSeverity;
    cout << "How bad is the leak? (1 - Minor, 2 - Active Moisture, 3 - "
            "Actively Beading): ";
    cin >> leakSeverity;
    if (leakSeverity == "1") {
      cout << "Fix if you want.\n";
      file << "Fix if you want." << endl;
    } else if (leakSeverity == "2") {
      cout << "Fix within the next month.\n";
      file << "Fix within the next month." << endl;
    } else if (leakSeverity == "3") {
      cout << "Do not drive, fix immediately.\n";
      file << "Do not drive, fix immediately." << endl;
    } else {
      cout << "Invalid input for leak severity. Please enter 1, 2, or 3.\n";
    }
  }
}

void checkStart(string filepath) {
  ofstream file = open_file(filepath);
  if (!file)
    return;
  cout << "Trying to start vehicle...\n";
  if (getUserInput("Does the vehicle fail to start? (yes/no): ")) {
    string starterIssue;
    cout << "Does the starter chug for a second? (yes/no): ";
    cin >> starterIssue;
    if (starterIssue == "yes") {
      cout << "Battery may be low. Jump start the car.\n";
      file << "Battery may be low. Jump start the car." << endl;
    } else if (starterIssue == "no") {
      cout << "The starter needs to be replaced.\n";
      file << "The starter needs to be replaced." << endl;
    } else {
      cout << "Invalid input. Please enter 'yes' or 'no'.\n";
    }
  }
}

void performPreventative(string carname, string filepath) {
  ofstream file = open_file(filepath);
  if (!file)
    return;
  if (getUserInput("Do you want to perform a preventative maintenance check? "
                   "(yes/no): ")) {
    string checkTime;
    cout << "Do you want to check before, during, after, or all? ";
    cin >> checkTime;

    file << "Preventative Maintenace Check for vehicle " << carname << ":"
         << endl;
    if (checkTime == "before" || checkTime == "all") {
      cout << "--- BEFORE DRIVING CHECKS ---\n";
      inspectTires(filepath);
      checkBrakePads(filepath);
      checkFluids(filepath);
      checkBattery(filepath);
      inspectEngine(filepath);
      checkStart(filepath);
    } else if (checkTime != "during" && checkTime != "after" &&
               checkTime != "all") {
      cout << "Invalid input. Please enter 'before', 'during', 'after', or "
              "'all'.\n";
      return;
    }

    if (checkTime == "during" || checkTime == "all") {
      cout << "--- DURING DRIVING CHECKS ---\n";
      if (getUserInput("Has the engine suddenly shut off? (yes/no): ")) {
        cout << "Either you stalled or your engine needs to be replaced.\n";
        file << "Either you stalled or your engine needs to be replaced."
             << endl;
      }

      if (getUserInput(
              "Does the car not stay in a straight line? (yes/no): ")) {
        cout << "Check tie rods and get an alignment.\n";
        file << "Check tie rods and get an alignment." << endl;
      }

      if (getUserInput("Is the car incredibly bouncy over bumps? (yes/no): ")) {
        cout << "Your suspension is too old, replace suspension.\n";
        file << "Your suspension is too old, replace suspension." << endl;
      }

      if (getUserInput("Does the car pull to the left or right while braking? "
                       "(yes/no): ")) {
        cout << "Flush brake fluid, and check for seized brake cylinders.\n";
        file << "Flush brake fluid, and check for seized brake cylinders."
             << endl;
      }

      if (getUserInput("Does the car not stop when braking? (yes/no): ")) {
        cout << "Check and replace brake pads.\n";
        file << "Check and replace brake pads." << endl;
      }

      if (getUserInput(
              "Does the car shift hard or not change gear? (yes/no): ")) {
        cout << "Transmission or clutch is going, recommend seeing a "
                "mechanic.\n";
        file << "Transmission or clutch is going, recommend seeing a mechanic."
             << endl;
      }

      if (getUserInput(
              "Does the car vibrate heavily when stopped? (yes/no): ")) {
        cout << "The motor mounts are going or mis-sized, see mechanic to "
                "replace.\n";
        file << "The motor mounts are going or mis-sized, see mechanic to "
                "replace."
             << endl;
      }

      if (getUserInput("Does the vehicle not move when pressing on the gas and "
                       "in gear? (yes/no): ")) {
        cout << "Either the clutch is out or the drivetrain is disconnected, "
                "tow to mechanic.\n";
        file << "Either the clutch is out or the drivetrain is "
                "disconnected, tow to mechanic."
             << endl;
      }
    }

    if (checkTime == "after" || checkTime == "all") {
      cout << "--- AFTER DRIVING CHECKS ---\n";
      if (getUserInput("Do you see any new cracks or holes in the tires? "
                       "(yes/no): ")) {
        cout << "Put the spare on and replace the tire when possible.\n";
        file << "Put the spare on and replace the tire when possible." << endl;
      }

      if (getUserInput("Did you hit anything or run over a curb? (yes/no): ")) {
        cout << "Inspect under the car for any damage.\n";
        file << "Inspect under the car for any damage." << endl;
      }

      if (getUserInput(
              "Is there any oily/grimy residue or leaks? (yes/no): ")) {
        string leakSeverity;
        cout << "How bad is the leak? (1 - Minor, 2 - Active Moisture, 3 - "
                "Actively Beading): ";
        cin >> leakSeverity;
        if (leakSeverity == "1") {
          cout << "Fix if you want.\n";
          file << "Fix if you want." << endl;
        } else if (leakSeverity == "2") {
          cout << "Fix within the next month.\n";
          file << "Fix within the next month." << endl;
        } else if (leakSeverity == "3") {
          cout << "Do not drive, fix immediately.\n";
          file << "Do not drive, fix immediately." << endl;
        } else {
          cout << "Invalid input for leak severity. Please enter 1, 2, or "
                  "3.\n";
        }
      }
    }
  }
}
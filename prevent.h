//#include "headers.h"

using namespace std;

bool getUserInput(const string& prompt) {
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

/*
void writeToFile(const string& content) {
    ofstream outputFile;
    outputFile.open("preventative_results.txt", ios::app);
    if (outputFile.is_open()) {
        outputFile << content << endl;
    }
    outputFile.close();
}
*/
void inspectTires() {
    cout << "Inspecting tires...\n";
    if (getUserInput("Are the tires unevenly worn? (yes/no): ")) {
        if (getUserInput("Are the tie rods fine? (yes/no): ")) {
            cout << "Get an alignment and replace worn tires in the next month.\n";
            writeToFile("Get an alignment and replace worn tires in the next month.");
        } else {
            cout << "Replace the tie rods.\n";
            writeToFile("Replace the tie rods.");
        }
    }

    if (getUserInput("Is the tire pressure low but above 10 PSI? (yes/no): ")) {
        if (getUserInput("Has this issue been noticed before? (yes/no): ")) {
            cout << "Service the tires within the next month.\n";
            writeToFile("Service the tires within the next month.");
        }
        cout << "Fill the tire with air.\n";
        writeToFile("Fill the tire with air.");
    }
}

void checkBrakePads() {
    cout << "Checking brake pads...\n";
    if (getUserInput("Are the brake pads worn out? (yes/no): ")) {
        cout << "You need to replace the brake pads soon.\n";
        writeToFile("You need to replace the brake pads soon.");
    }
}

void checkFluids() {
    cout << "Checking fluids...\n";
    if (getUserInput("Are any fluid levels low? (yes/no): ")) {
        cout << "Top off the fluids.\n";
        writeToFile("Top off the fluids.");
    }
}

void checkBattery() {
    cout << "Inspecting battery connectors...\n";
    if (getUserInput("Do the battery connectors appear grimy or corroded? (yes/no): ")) {
        cout << "Disconnect and clean the battery connectors.\n";
        writeToFile("Disconnect and clean the battery connectors.");
    }
}

void inspectEngine() {
    cout << "Checking for oily/grimy residue or leaks...\n";
    if (getUserInput("Do you see any leaks? (yes/no): ")) {
        string leakSeverity;
        cout << "How bad is the leak? (1 - Minor, 2 - Active Moisture, 3 - Actively Beading): ";
        cin >> leakSeverity;
        if (leakSeverity == "1") {
            cout << "Fix if you want.\n";
            writeToFile("Fix if you want.");
        } else if (leakSeverity == "2") {
            cout << "Fix within the next month.\n";
            writeToFile("Fix within the next month.");
        } else if (leakSeverity == "3") {
            cout << "Do not drive, fix immediately.\n";
            writeToFile("Do not drive, fix immediately.");
        } else {
            cout << "Invalid input for leak severity. Please enter 1, 2, or 3.\n";
        }
    }
}

void checkStart() {
    cout << "Trying to start vehicle...\n";
    if (getUserInput("Does the vehicle fail to start? (yes/no): ")) {
        string starterIssue;
        cout << "Does the starter chug for a second? (yes/no): ";
        cin >> starterIssue;
        if (starterIssue == "yes") {
            cout << "Battery may be low. Jump start the car.\n";
            writeToFile("Battery may be low. Jump start the car.");
        } else if (starterIssue == "no") {
            cout << "The starter needs to be replaced.\n";
            writeToFile("The starter needs to be replaced.");
        } else {
            cout << "Invalid input. Please enter 'yes' or 'no'.\n";
        }
    }
}

void performPreventative() {
    if (getUserInput("Do you want to perform a preventative maintenance check? (yes/no): ")) {
        string checkTime;
        cout << "Do you want to check before, during, after, or all? ";
        cin >> checkTime;

        if (checkTime == "before" || checkTime == "all") {
            cout << "--- BEFORE DRIVING CHECKS ---\n";
            inspectTires();
            checkBrakePads();
            checkFluids();
            checkBattery();
            inspectEngine();
            checkStart();
        } else if (checkTime != "during" && checkTime != "after" && checkTime != "all") {
            cout << "Invalid input. Please enter 'before', 'during', 'after', or 'all'.\n";
            return;
        }

        if (checkTime == "during" || checkTime == "all") {
            cout << "--- DURING DRIVING CHECKS ---\n";
            if (getUserInput("Has the engine suddenly shut off? (yes/no): ")) {
                cout << "Either you stalled or your engine needs to be replaced.\n";
                writeToFile("Either you stalled or your engine needs to be replaced.");
            }

            if (getUserInput("Does the car not stay in a straight line? (yes/no): ")) {
                cout << "Check tie rods and get an alignment.\n";
                writeToFile("Check tie rods and get an alignment.");
            }

            if (getUserInput("Is the car incredibly bouncy over bumps? (yes/no): ")) {
                cout << "Your suspension is too old, replace suspension.\n";
                writeToFile("Your suspension is too old, replace suspension.");
            }

            if (getUserInput("Does the car pull to the left or right while braking? (yes/no): ")) {
                cout << "Flush brake fluid, and check for seized brake cylinders.\n";
                writeToFile("Flush brake fluid, and check for seized brake cylinders.");
            }

            if (getUserInput("Does the car not stop when braking? (yes/no): ")) {
                cout << "Check and replace brake pads.\n";
                writeToFile("Check and replace brake pads.");
            }

            if (getUserInput("Does the car shift hard or not change gear? (yes/no): ")) {
                cout << "Transmission or clutch is going, recommend seeing a mechanic.\n";
                writeToFile("Transmission or clutch is going, recommend seeing a mechanic.");
            }

            if (getUserInput("Does the car vibrate heavily when stopped? (yes/no): ")) {
                cout << "The motor mounts are going or mis-sized, see mechanic to replace.\n";
                writeToFile("The motor mounts are going or mis-sized, see mechanic to replace.");
            }

            if (getUserInput("Does the vehicle not move when pressing on the gas and in gear? (yes/no): ")) {
                cout << "Either the clutch is out or the drivetrain is disconnected, tow to mechanic.\n";
                writeToFile("Either the clutch is out or the drivetrain is disconnected, tow to mechanic.");
            }
        }

        if (checkTime == "after" || checkTime == "all") {
            cout << "--- AFTER DRIVING CHECKS ---\n";
            if (getUserInput("Do you see any new cracks or holes in the tires? (yes/no): ")) {
                cout << "Put the spare on and replace the tire when possible.\n";
                writeToFile("Put the spare on and replace the tire when possible.");
            }

            if (getUserInput("Did you hit anything or run over a curb? (yes/no): ")) {
                cout << "Inspect under the car for any damage.\n";
                writeToFile("Inspect under the car for any damage.");
            }

            if (getUserInput("Is there any oily/grimy residue or leaks? (yes/no): ")) {
                string leakSeverity;
                cout << "How bad is the leak? (1 - Minor, 2 - Active Moisture, 3 - Actively Beading): ";
                cin >> leakSeverity;
                if (leakSeverity == "1") {
                    cout << "Fix if you want.\n";
                    writeToFile("Fix if you want.");
                } else if (leakSeverity == "2") {
                    cout << "Fix within the next month.\n";
                    writeToFile("Fix within the next month.");
                } else if (leakSeverity == "3") {
                    cout << "Do not drive, fix immediately.\n";
                    writeToFile("Do not drive, fix immediately.");
                } else {
                    cout << "Invalid input for leak severity. Please enter 1, 2, or 3.\n";
                }
            }
        }
    }
}
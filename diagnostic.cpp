#include <cctype>
#include <diagnostic.hpp>

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
    userIn =
        request_user_input("Verify coolant levels. If coolant levels are not "
                           "the issue, select 1. Otherwise, 2 to exit: ");
    if (userIn == 2) {
      file << "Issue: radiator inoperable. Order: radiator, cooling assembly."
           << endl;
    } else {
      userIn = request_user_input(
          "Inspect and flush the radiator. If there's no issue with the "
          "radiator, select 1. Otherwise, select 2 to write and exit: ");
      if (userIn == 2) {
        file << "Issue: radiator inoperable. Order: radiator, cooling assembly."
             << endl;
      } else {
        userIn = request_user_input(
            "Check thermostat/water pump. If those are fine, select 1 to "
            "notate vehicle needs third-party inspection. Otherwise, 2 to "
            "write and exit: ");
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
    userIn = request_user_input(
        "Inspect spark plugs and ignition coils. If these are in working "
        "condition, select 1. Otherwise, 2 to exit: ");
    if (userIn == 2) {
      file << "Issue: misfire caused by faulty spark plugs or ignition coils. "
              "Order: spark plugs, ignition coils."
           << endl;
    } else {
      userIn =
          request_user_input("Check fuel injectors. If injectors are working, "
                             "select 1. Otherwise, select 2 to exit: ");
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
    userIn = request_user_input(
        "Turn off the engine and wait for a while. Then, try restarting. If "
        "engine starts, select 1. Otherwise, select 2 to exit: ");
    if (userIn == 2) {
      file << "Issue: flooded engine. Order: spark plugs, air filter." << endl;
    } else {
      userIn = request_user_input(
          "If problem persists, check fuel pressure regulator. If not faulty, "
          "select 1. Otherwise, select 2 to exit: ");
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
    userIn = request_user_input(
        "Check for visible signs of coolant leaks. If no leak is found, select "
        "1. Otherwise, select 2 to exit: ");
    if (userIn == 2) {
      file << "Issue: headgasket leak detected. Order: headgasket replacement."
           << endl;
    } else {
      userIn = request_user_input(
          "Check for white smoke from the exhaust. If smoke is present, select "
          "1. Otherwise, select 2 to exit: ");
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
    userIn = request_user_input(
        "Inspect the engine block for visible damage. If no damage is found, "
        "select 1. Otherwise, select 2 to exit: ");
    if (userIn == 2) {
      file << "Issue: holes in the engine block. Order: engine block repair or "
              "replacement."
           << endl;
    } else {
      userIn = request_user_input(
          "Check for any other unusual noises or vibrations. If abnormal "
          "sounds persist, select 1. Otherwise, select 2 to exit: ");
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

void transmission(string filepath) {
  int userIn;
  ofstream file = open_file(filepath);
  if (!file)
    return;

  cout << "Select transmission behavior: " << endl
       << "1. Slipping Transmission" << endl
       << "2. Hard/Shifting Problems" << endl
       << "3. Fluid Leaks" << endl
       << "4. Transmission Noise" << endl
       << "5. Delayed or No Engagement" << endl
       << "9. Exit" << endl;

  cin >> userIn;
  switch (userIn) {
  case 1:
    file << "Be aware: the transmission is slipping." << endl;
    cout << "Check transmission fluid levels. If low, add fluid and select 1. "
            "Otherwise, select 2 to exit."
         << endl;
    cin >> userIn;
    if (userIn == 2) {
      file << "Issue: slipping transmission caused by low fluid. Order: "
              "transmission fluid."
           << endl;
    } else {
      cout
          << "If fluid level is fine, check the condition of the fluid. If the "
             "fluid is dirty or burnt, select 1. Otherwise, select 2 to exit."
          << endl;
      cin >> userIn;
      if (userIn == 2) {
        file << "Issue: dirty or burnt transmission fluid. Order: transmission "
                "fluid flush."
             << endl;
      } else {
        file << "Issue unknown, third-party inspection required." << endl;
      }
    }
    cout << "Issue noted. Items listed to order." << endl;
    break;

  case 2:
    file << "Be aware: there are hard shifting problems." << endl;
    cout << "Check for low transmission fluid. If fluid is low, add fluid and "
            "select 1. Otherwise, select 2 to exit."
         << endl;
    cin >> userIn;
    if (userIn == 2) {
      file << "Issue: hard shifting caused by low fluid. Order: transmission "
              "fluid."
           << endl;
    } else {
      cout << "If fluid is fine, check for a faulty shift solenoid. If "
              "solenoid is faulty, select 1. Otherwise, select 2 to exit."
           << endl;
      cin >> userIn;
      if (userIn == 2) {
        file << "Issue: faulty shift solenoid. Order: shift solenoid "
                "replacement."
             << endl;
      } else {
        file << "Issue: transmission control module malfunction. Order: TCM "
                "replacement."
             << endl;
      }
    }
    cout << "Issue noted. Items listed to order." << endl;
    break;

  case 3:
    file << "Be aware: there are transmission fluid leaks." << endl;
    cout << "Inspect the transmission pan and gasket for visible leaks. If the "
            "pan or gasket is faulty, select 1. Otherwise, select 2 to exit."
         << endl;
    cin >> userIn;
    if (userIn == 2) {
      file << "Issue: transmission pan or gasket leaking. Order: transmission "
              "pan, gasket."
           << endl;
    } else {
      cout << "Inspect cooler lines for leaks. If found, select 1. Otherwise, "
              "select 2 to exit."
           << endl;
      cin >> userIn;
      if (userIn == 2) {
        file << "Issue: transmission cooler line leaking. Order: cooler lines."
             << endl;
      } else {
        file << "Issue unknown, third-party inspection required." << endl;
      }
    }
    cout << "Issue noted. Items listed to order." << endl;
    break;

  case 4:
    file << "Be aware: there is transmission noise." << endl;
    cout << "Check transmission fluid level and condition. If fluid is low or "
            "dirty, select 1. Otherwise, select 2 to exit."
         << endl;
    cin >> userIn;
    if (userIn == 2) {
      file << "Issue: noisy transmission caused by low or dirty fluid. Order: "
              "transmission fluid flush."
           << endl;
    } else {
      cout << "If the fluid is fine, check for loose or worn components in the "
              "transmission. If components are worn, select 1. Otherwise, "
              "select 2 to exit."
           << endl;
      cin >> userIn;
      if (userIn == 2) {
        file << "Issue: worn or loose transmission components. Order: "
                "component replacement."
             << endl;
      } else {
        file << "Issue unknown, third-party inspection required." << endl;
      }
    }
    cout << "Issue noted. Items listed to order." << endl;
    break;

  case 5:
    file << "Be aware: delayed or no engagement in transmission." << endl;
    cout << "Check transmission fluid level and condition. If low or burnt, "
            "select 1. Otherwise, select 2 to exit."
         << endl;
    cin >> userIn;
    if (userIn == 2) {
      file << "Issue: delayed engagement due to low or burnt fluid. Order: "
              "transmission fluid."
           << endl;
    } else {
      cout << "If fluid is fine, inspect the valve body for issues. If the "
              "valve body is faulty, select 1. Otherwise, select 2 to exit."
           << endl;
      cin >> userIn;
      if (userIn == 2) {
        file << "Issue: faulty valve body. Order: valve body replacement."
             << endl;
      } else {
        file << "Issue unknown, third-party inspection required." << endl;
      }
    }
    cout << "Issue noted. Items listed to order." << endl;
    break;

  default:
    cout << "Invalid input, please retry!" << endl;
  }
}

void drivetrain(string filepath) {
  int userIn;
  ofstream file(filepath, ios::app);
  if (!file) {
    cerr << "Error opening diagnostic report file!" << endl;
    return;
  }
  cout << "Select drivetrain, wheels, and suspension behavior: " << endl
       << "1. Drivetrain Noise or Vibration" << endl
       << "2. Poor Handling or Steering" << endl
       << "3. Wheel Alignment Issues" << endl
       << "4. Suspension Issues (Shocks/Struts)" << endl
       << "5. Wheel or Tire Problems" << endl
       << "9. Exit" << endl;

  cin >> userIn;
  switch (userIn) {
  case 1:
    file << "Be aware: drivetrain noise or vibration." << endl;
    cout << "Inspect the driveshaft and axles for damage or wear. If damaged, "
            "select 1. Otherwise, select 2 to exit."
         << endl;
    cin >> userIn;
    if (userIn == 2) {
      file << "Issue: damaged driveshaft or axles. Order: driveshaft, axle "
              "replacement."
           << endl;
    } else {
      cout << "Check for worn-out U-joints. If found, select 1. Otherwise, "
              "select 2 to exit."
           << endl;
      cin >> userIn;
      if (userIn == 2) {
        file << "Issue: worn-out U-joints. Order: U-joints replacement."
             << endl;
      } else {
        file << "Issue unknown, third-party inspection required." << endl;
      }
    }
    cout << "Issue noted. Items listed to order." << endl;
    break;

  case 2:
    file << "Be aware: poor handling or steering." << endl;
    cout << "Inspect the steering rack and tie rods for wear. If damaged, "
            "select 1. Otherwise, select 2 to exit."
         << endl;
    cin >> userIn;
    if (userIn == 2) {
      file << "Issue: worn steering rack or tie rods. Order: steering rack, "
              "tie rods replacement."
           << endl;
    } else {
      cout << "Check for problems with the power steering pump. If the pump is "
              "faulty, select 1. Otherwise, select 2 to exit."
           << endl;
      cin >> userIn;
      if (userIn == 2) {
        file << "Issue: faulty power steering pump. Order: power steering pump "
                "replacement."
             << endl;
      } else {
        file << "Issue unknown, third-party inspection required." << endl;
      }
    }
    cout << "Issue noted. Items listed to order." << endl;
    break;

  case 3:
    file << "Be aware: wheel alignment issues." << endl;
    cout << "Check tire wear patterns. If uneven wear is found, select 1. "
            "Otherwise, select 2 to exit."
         << endl;
    cin >> userIn;
    if (userIn == 2) {
      file << "Issue: wheel alignment problems. Order: wheel alignment service."
           << endl;
    } else {
      cout << "Inspect suspension components (ball joints, control arms, "
              "etc.). If worn, select 1. Otherwise, select 2 to exit."
           << endl;
      cin >> userIn;
      if (userIn == 2) {
        file << "Issue: worn suspension components affecting alignment. Order: "
                "suspension components replacement."
             << endl;
      } else {
        file << "Issue unknown, third-party inspection required." << endl;
      }
    }
    cout << "Issue noted. Items listed to order." << endl;
    break;

  case 4:
    file << "Be aware: suspension issues (shocks/struts)." << endl;
    cout << "Inspect the shocks or struts for leaks or damage. If damaged, "
            "select 1. Otherwise, select 2 to exit."
         << endl;
    cin >> userIn;
    if (userIn == 2) {
      file << "Issue: damaged shocks or struts. Order: shock/strut replacement."
           << endl;
    } else {
      cout << "Check the suspension bushings for wear. If worn, select 1. "
              "Otherwise, select 2 to exit."
           << endl;
      cin >> userIn;
      if (userIn == 2) {
        file << "Issue: worn suspension bushings. Order: bushings replacement."
             << endl;
      } else {
        file << "Issue unknown, third-party inspection required." << endl;
      }
    }
    cout << "Issue noted. Items listed to order." << endl;
    break;


  case 5:
    file << "Be aware: wheel or tire problems." << endl;
    cout << "Inspect tires for visible damage or excessive wear. If found, "
            "select 1. Otherwise, select 2 to exit."
         << endl;
    cin >> userIn;
    if (userIn == 2) {
      file << "Issue: damaged or worn tires. Order: new tires." << endl;
    } else {
      cout << "Check tire pressure. If pressure is low or inconsistent, select "
              "1. Otherwise, select 2 to exit."
           << endl;
      cin >> userIn;
      if (userIn == 2) {
        file << "Issue: tire pressure issues. Order: tire pressure check, air "
                "supply."
             << endl;
      } else {
        file << "Issue: potential rim damage affecting tire pressure. Order: "
                "wheel rim inspection or replacement."
             << endl;
      }
    }
    cout << "Issue noted. Items listed to order." << endl;
    break;

  default:
    cout << "Invalid input, please retry!" << endl;
  }
}
void bodywork(string filepath) {
  int userIn;
  ofstream file = open_file(filepath);
  if (!file)
    return;
  cout << "Select problem area: " << endl
       << "1. Doors" << endl
       << "2. General Bodywork/Cosmetic Issues" << endl
       << "9. Exit" << endl;

  cin >> userIn;
  if (userIn == 1) {
    // Diagnose door-related issues
   {
      int doorIssue, doorPos;
      string doorType;
      cout << "Select door-related issue: " << endl
           << "1. Door Alignment" << endl
           << "2. Locks" << endl
           << "3. Power Windows" << endl
           << "9. Back to Main Menu" << endl;
      cin >> doorIssue;

      if (doorIssue > 0 && doorIssue <= 4) {
        cout << "Enter the affected door(s):" << endl
             << "1. Driver's door" << endl
             << "2. Passenger's door" << endl
             << "3. Rear driver's side door" << endl
             << "4. Rear passenger's side door" << endl
             << "5. All doors" << endl 
             << "6. Trunk/Rear Door" << endl;
        cin >> doorPos;
      }

      switch (doorPos) {
        case 1: doorType = "Driver's door";
        break;
        case 2: doorType = "Passenger's door";
        break;
        case 3: doorType = "Rear driver's side door";
        break;
        case 4: doorType = "Rear passenger's side door";
        break;
        case 5: doorType = "all doors";
        break;
        case 6: doorType = "Trunk/Rear Door";
        break;
        default: cout << "Invalid input!" << endl;
      }

      switch (doorIssue) {
      case 1:
        file << "Issue: " << doorType << " is misaligned. Order: send to third party to fix." << endl;
        break;
      case 2:
        file << "Issue: " << doorType << " lock is non-functional. Order: send to third party to fix." << endl;
        break;
      case 3:
        file << "Issue: " << doorType << " power window(s) are non-functional. Order: motor and window lift assembly." << endl;
        break;
      case 9:
        break;
      default:
        cout << "Invalid input." << endl;
      }
    }

  } else if (userIn == 2) {
    
  } else if (userIn == 9) {

  } else {
    cout << "Invalid input!" << endl;
  }
}
void EngAcc(string filepath) {
  int userIn;
  ofstream file(filepath, ios::app);
  if (!file) {
    cerr << "Error opening diagnostic report file!" << endl;
    return;
  }
  cout << "Select engine accessory behavior: " << endl
       << "1. Starter Motor Issues" << endl
       << "2. Alternator Issues" << endl
       << "3. Battery Problems" << endl
       << "4. Belt or Pulley Issues" << endl
       << "5. Serpentine Belt Issues" << endl
       << "9. Exit" << endl;

  cin >> userIn;
  switch (userIn) {
  case 1:
    file << "Be aware: starter motor issues." << endl;
    cout << "Check for a clicking sound or failure to start. If these occur, "
            "select 1. Otherwise, select 2 to exit."
         << endl;
    cin >> userIn;
    if (userIn == 2) {
      file << "Issue: starter motor failure. Order: new starter motor." << endl;
    } else {
      cout << "Inspect the battery connections and cables. If corroded or "
              "loose, select 1. Otherwise, select 2 to exit."
           << endl;
      cin >> userIn;
      if (userIn == 2) {
        file << "Issue: poor battery connections. Order: battery cables and "
                "connectors."
             << endl;
      } else {
        file << "Issue unknown, third-party inspection required." << endl;
      }
    }
    cout << "Issue noted. Items listed to order." << endl;
    break;

  case 2:
    file << "Be aware: alternator issues." << endl;
    cout << "Check for dimming lights, electrical problems, or battery warning "
            "lights. If present, select 1. Otherwise, select 2 to exit."
         << endl;
    cin >> userIn;
    if (userIn == 2) {
      file << "Issue: alternator failure. Order: new alternator." << endl;
    } else {
      cout << "Inspect the alternator belt for wear or damage. If worn or "
              "damaged, select 1. Otherwise, select 2 to exit."
           << endl;
      cin >> userIn;
      if (userIn == 2) {
        file << "Issue: alternator belt worn or damaged. Order: new alternator "
                "belt."
             << endl;
      } else {
        file << "Issue unknown, third-party inspection required." << endl;
      }
    }
    cout << "Issue noted. Items listed to order." << endl;
    break;

  case 3:
    file << "Be aware: battery problems." << endl;
    cout << "Check for a weak or dead battery by testing voltage. If low "
            "voltage is detected, select 1. Otherwise, select 2 to exit."
         << endl;
    cin >> userIn;
    if (userIn == 2) {
      file << "Issue: weak or dead battery. Order: new battery." << endl;
    } else {
      cout << "Inspect battery terminals for corrosion. If corrosion is found, "
              "clean or replace the battery terminals. Select 1. Otherwise, "
              "select 2 to exit."
           << endl;
      cin >> userIn;
      if (userIn == 2) {
        file << "Issue: corroded battery terminals. Order: terminal cleaning "
                "or replacement."
             << endl;
      } else {
        file << "Issue unknown, third-party inspection required." << endl;
      }
    }
    cout << "Issue noted. Items listed to order." << endl;
    break;

  case 4:
    file << "Be aware: belt or pulley issues." << endl;
    cout << "Inspect belts for cracks, wear, or squealing noises. If any "
            "issues are found, select 1. Otherwise, select 2 to exit."
         << endl;
    cin >> userIn;
    if (userIn == 2) {
      file << "Issue: damaged or worn belts. Order: new belts." << endl;
    } else {
      cout << "Check pulleys for wobbling, noise, or wear. If the pulleys are "
              "damaged, select 1. Otherwise, select 2 to exit."
           << endl;
      cin >> userIn;
      if (userIn == 2) {
        file << "Issue: damaged pulleys. Order: new pulleys." << endl;
      } else {
        file << "Issue unknown, third-party inspection required." << endl;
      }
    }
    cout << "Issue noted. Items listed to order." << endl;
    break;

  case 5:
    file << "Be aware: serpentine belt issues." << endl;
    cout << "Inspect the serpentine belt for any visible cracks, fraying, or "
            "wear. If any issues are found, select 1. Otherwise, select 2 to "
            "exit."
         << endl;
    cin >> userIn;
    if (userIn == 2) {
      file << "Issue: worn serpentine belt. Order: new serpentine belt."
           << endl;
    } else {
      cout << "Check for misalignment of the serpentine belt. If misaligned, "
              "select 1. Otherwise, select 2 to exit."
           << endl;
      cin >> userIn;
      if (userIn == 2) {
        file << "Issue: misaligned serpentine belt. Order: serpentine belt "
                "tensioner or pulleys."
             << endl;
      } else {
        file << "Issue unknown, third-party inspection required." << endl;
      }
    }
    cout << "Issue noted. Items listed to order." << endl;
    break;

  default:
    cout << "Invalid input, please retry!" << endl;
  }
}
void exhaust(string filepath) {
  int userIn;
  ofstream file(filepath, ios::app);
  if (!file) {
    cerr << "Error opening diagnostic report file!" << endl;
    return;
  }
  cout << "Select exhaust system behavior: " << endl
       << "1. Exhaust Leaks" << endl
       << "2. Clogged Catalytic Converter" << endl
       << "3. Damaged Muffler" << endl
       << "4. Broken Exhaust Hangers" << endl
       << "5. Excessive Exhaust Smoke" << endl
       << "9. Exit" << endl;

  cin >> userIn;
  switch (userIn) {
  case 1:
    file << "Be aware: exhaust leaks." << endl;
    cout << "Inspect for loud engine noises or unusual odors. If a leak is "
            "suspected, select 1. Otherwise, select 2 to exit."
         << endl;
    cin >> userIn;
    if (userIn == 2) {
      file << "Issue: exhaust leak. Order: exhaust system sealant or gasket "
              "replacement."
           << endl;
    } else {
      cout
          << "Check the exhaust manifold and piping for visible damage or "
             "holes. If damage is found, select 1. Otherwise, select 2 to exit."
          << endl;
      cin >> userIn;
      if (userIn == 2) {
        file << "Issue: damaged exhaust manifold or piping. Order: replacement "
                "exhaust manifold or pipes."
             << endl;
      } else {
        file << "Issue unknown, third-party inspection required." << endl;
      }
    }
    cout << "Issue noted. Items listed to order." << endl;
    break;

  case 2:
    file << "Be aware: clogged catalytic converter." << endl;
    cout << "Check for decreased engine performance, poor acceleration, or a "
            "rotten egg smell. If any of these symptoms are present, select 1. "
            "Otherwise, select 2 to exit."
         << endl;
    cin >> userIn;
    if (userIn == 2) {
      file << "Issue: clogged catalytic converter. Order: new catalytic "
              "converter."
           << endl;
    } else {
      cout << "Check for a high exhaust temperature. If it's abnormally high, "
              "select 1. Otherwise, select 2 to exit."
           << endl;
      cin >> userIn;
      if (userIn == 2) {
        file << "Issue: high exhaust temperature due to clogged catalytic "
                "converter. Order: catalytic converter replacement."
             << endl;
      } else {
        file << "Issue unknown, third-party inspection required." << endl;
      }
    }
    cout << "Issue noted. Items listed to order." << endl;
    break;

  case 3:
    file << "Be aware: damaged muffler." << endl;
    cout << "Listen for loud exhaust noises or rattling sounds coming from the "
            "rear of the vehicle. If such sounds are heard, select 1. "
            "Otherwise, select 2 to exit."
         << endl;
    cin >> userIn;
    if (userIn == 2) {
      file << "Issue: damaged muffler. Order: new muffler." << endl;
    } else {
      cout << "Check for visible rust or holes in the muffler. If damage is "
              "visible, select 1. Otherwise, select 2 to exit."
           << endl;
      cin >> userIn;
      if (userIn == 2) {
        file << "Issue: rusted or perforated muffler. Order: muffler "
                "replacement."
             << endl;
      } else {
        file << "Issue unknown, third-party inspection required." << endl;
      }
    }
    cout << "Issue noted. Items listed to order." << endl;
    break;

  case 4:
    file << "Be aware: broken exhaust hangers." << endl;
    cout << "Inspect the exhaust system for sagging or loose components. If "
            "the hangers are broken, select 1. Otherwise, select 2 to exit."
         << endl;
    cin >> userIn;
    if (userIn == 2) {
      file << "Issue: broken exhaust hangers. Order: new exhaust hangers."
           << endl;
    } else {
      cout << "Check for any components that may be dragging on the ground or "
              "near the tires. If components are dragging, select 1. "
              "Otherwise, select 2 to exit."
           << endl;
      cin >> userIn;
      if (userIn == 2) {
        file << "Issue: dragging exhaust components due to broken hangers. "
                "Order: new hangers and reinstallation."
             << endl;
      } else {
        file << "Issue unknown, third-party inspection required." << endl;
      }
    }
    cout << "Issue noted. Items listed to order." << endl;
    break;

  case 5:
    file << "Be aware: excessive exhaust smoke." << endl;
    cout << "Check for unusual exhaust smoke color, such as black, blue, or "
            "white smoke. If excessive smoke is noted, select 1. Otherwise, "
            "select 2 to exit."
         << endl;
    cin >> userIn;
    if (userIn == 2) {
      file << "Issue: excessive exhaust smoke. Order: engine inspection."
           << endl;
    } else {
      cout << "Black smoke may indicate rich fuel mixture, blue smoke could "
              "indicate burning oil, and white smoke might point to coolant "
              "leaks. Check for related engine issues, and select 1 for "
              "further diagnostics."
           << endl;
      cin >> userIn;
      if (userIn == 2) {
        file << "Issue: engine-related exhaust smoke. Order: engine "
                "diagnostics or repair."
             << endl;
      } else {
        file << "Issue unknown, third-party inspection required." << endl;
      }
    }
    cout << "Issue noted. Items listed to order." << endl;
    break;

  default:
    cout << "Invalid input, please retry!" << endl;
  }
}
void lights(string filepath) {
  ofstream file = open_file(filepath);
  if (!file)
    return;
  cout << "Select lighting and horn behavior: " << endl
       << "1. Headlight Issues" << endl
       << "2. Brake Light Issues" << endl
       << "3. Horn Issues" << endl
       << "9. Exit" << endl;

  cin >> userIn;
  switch (userIn) {
  case 1:
    file << "Be aware: headlight issues." << endl;
    cout << "Check if the headlight is dim, flickering, or not working. If any "
            "issues are noticed, select 1. Otherwise, select 2 to exit."
         << endl;
    cin >> userIn;
    if (userIn == 2) {
      file << "Issue: non-functioning headlight. Order: new headlight bulb."
           << endl;
    } else {
      cout << "Inspect the headlight bulb, wiring, and fuse. If any of these "
              "are faulty, select 1. Otherwise, select 2 to exit."
           << endl;
      cin >> userIn;
      if (userIn == 2) {
        file << "Issue: faulty bulb, wiring, or fuse. Order: new bulb, wiring, "
                "or fuse."
             << endl;
      } else {
        file << "Issue unknown, third-party inspection required." << endl;
      }
    }
    cout << "Issue noted. Items listed to order." << endl;
    break;

  case 2:
    file << "Be aware: brake light issues." << endl;
    cout << "Check if the brake light is not illuminating or is dim. If you "
            "notice any issues, select 1. Otherwise, select 2 to exit."
         << endl;
    cin >> userIn;
    if (userIn == 2) {
      file << "Issue: non-functioning brake light. Order: new brake light bulb."
           << endl;
    } else {
      cout << "Inspect the brake light bulb, wiring, and fuse. If any of these "
              "are faulty, select 1. Otherwise, select 2 to exit."
           << endl;
      cin >> userIn;
      if (userIn == 2) {
        file << "Issue: faulty brake light bulb, wiring, or fuse. Order: new "
                "bulb, wiring, or fuse."
             << endl;
      } else {
        file << "Issue unknown, third-party inspection required." << endl;
      }
    }
    cout << "Issue noted. Items listed to order." << endl;
    break;

  case 3:
    file << "Be aware: horn issues." << endl;
    cout << "Check if the horn is not working or making an unusual sound. If "
            "there's a problem, select 1. Otherwise, select 2 to exit."
         << endl;
    cin >> userIn;
    if (userIn == 2) {
      file << "Issue: horn not working. Order: new horn." << endl;
    } else {
      cout << "Inspect the horn fuse and wiring. If there is a blown fuse or "
              "damaged wiring, select 1. Otherwise, select 2 to exit."
           << endl;
      cin >> userIn;
      if (userIn == 2) {
        file
            << "Issue: blown fuse or damaged wiring. Order: new fuse or wiring."
            << endl;
      } else {
        file << "Issue unknown, third-party inspection required." << endl;
      }
    }
    cout << "Issue noted. Items listed to order." << endl;
    break;

  default:
    cout << "Invalid input, please retry!" << endl;
  }
}
void accessories(string filepath) {
  ofstream file = open_file(filepath);
  if (!file)
    return;
  cout << "Select internal component behavior: " << endl
       << "1. Radio Issues" << endl
       << "2. Dash Light Issues" << endl
       << "3. Climate Control or HVAC Issues" << endl
       << "4. Power Window or Lock Issues" << endl
       << "9. Exit" << endl;

  cin >> userIn;
  switch (userIn) {
  case 1:
    file << "Be aware: radio issues." << endl;
    cout << "Check if the radio isn't turning on or has no sound. If so, "
            "select 1. Otherwise, select 2 to exit."
         << endl;
    cin >> userIn;
    if (userIn == 2) {
      file << "Issue: radio not functioning. Order: new radio unit or wiring "
              "inspection."
           << endl;
    } else {
      cout << "Inspect the radio fuse, wiring, and connections. If any of "
              "these are faulty, select 1. Otherwise, select 2 to exit."
           << endl;
      cin >> userIn;
      if (userIn == 2) {
        file << "Issue: blown fuse or faulty wiring. Order: fuse replacement "
                "or wiring repair."
             << endl;
      } else {
        file << "Issue unknown, third-party inspection required." << endl;
      }
    }
    cout << "Issue noted. Items listed to order." << endl;
    break;

  case 2:
    file << "Be aware: dash light issues." << endl;
    cout << "Check if the dash lights aren't turning on or are flickering. If "
            "they aren't working properly, select 1. Otherwise, select 2 to "
            "exit."
         << endl;
    cin >> userIn;
    if (userIn == 2) {
      file << "Issue: dash lights not working. Order: new dash light bulbs or "
              "wiring inspection."
           << endl;
    } else {
      cout << "Inspect the dash light fuse, wiring, and connections. If any of "
              "these are faulty, select 1. Otherwise, select 2 to exit."
           << endl;
      cin >> userIn;
      if (userIn == 2) {
        file << "Issue: blown fuse or faulty wiring. Order: fuse replacement "
                "or wiring repair."
             << endl;
      } else {
        file << "Issue unknown, third-party inspection required." << endl;
      }
    }
    cout << "Issue noted. Items listed to order." << endl;
    break;

  case 3:
    file << "Be aware: climate control or HVAC issues." << endl;
    cout << "Check if the climate control or HVAC system isn't blowing air, is "
            "too warm or cold, or isn't working at all. If there is an issue, "
            "select 1. Otherwise, select 2 to exit."
         << endl;
    cin >> userIn;
    if (userIn == 2) {
      file << "Issue: HVAC system malfunctioning. Order: HVAC system "
              "inspection or repair."
           << endl;
    } else {
      cout
          << "Inspect the blower motor, fuse, and climate control settings. If "
             "any of these are faulty, select 1. Otherwise, select 2 to exit."
          << endl;
      cin >> userIn;
      if (userIn == 2) {
        file << "Issue: faulty blower motor or fuse. Order: new blower motor "
                "or fuse."
             << endl;
      } else {
        file << "Issue unknown, third-party inspection required." << endl;
      }
    }
    cout << "Issue noted. Items listed to order." << endl;
    break;

  case 4:
    file << "Be aware: power window or lock issues." << endl;
    cout << "Check if the power windows or locks aren't functioning properly. "
            "If the issue is identified, select 1. Otherwise, select 2 to exit."
         << endl;
    cin >> userIn;
    if (userIn == 2) {
      file << "Issue: power window or lock malfunction. Order: new window "
              "motor or lock actuator."
           << endl;
    } else {
      cout << "Inspect the switches, wiring, and fuse. If any of these are "
              "faulty, select 1. Otherwise, select 2 to exit."
           << endl;
      cin >> userIn;
      if (userIn == 2) {
        file << "Issue: faulty switch, wiring, or fuse. Order: switch "
                "replacement, wiring repair, or fuse replacement."
             << endl;
      } else {
        file << "Issue unknown, third-party inspection required." << endl;
      }
    }
    cout << "Issue noted. Items listed to order." << endl;
    break;

  default:
    cout << "Invalid input, please retry!" << endl;
  }
}

string get_vehicle_number() {
  // this needs to check each line of the string to ensure vehicle name doesn't
  // have spaces or \ or / characters -anything file doesn't like
  string VehicleNum;
  cout << "Enter vehicle identification number: ";
  cin >> VehicleNum;

  return VehicleNum;
}
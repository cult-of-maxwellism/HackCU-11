#include <cctype>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ofstream open_file(const string &filepath) {
    ofstream file(filepath, ios::app);
    if (!file) {
      cerr << "Error opening diagnostic report file!" << endl;
    }
    return file;
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
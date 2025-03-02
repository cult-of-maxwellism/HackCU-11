#include <cctype>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

ofstream open_file(const string &filepath) {
  ofstream file(filepath, ios::app);
  if (!file) {
    cerr << "Error opening diagnostic report file!" << endl;
  }
  return file;
}

string get_vehicle_number() {
  // this needs to check each line of the string to ensure vehicle name doesn't
  // have spaces or \ or / characters -anything file doesn't like
  string VehicleNum;
  cout << "Enter vehicle identification number: ";
  cin >> VehicleNum;

  return VehicleNum;
}
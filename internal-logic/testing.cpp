#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // use a dynamic sized buffer, like std::string
    string filename, filepath;
    filepath = "./vehicle-directory/";
    getline(cin, filename);
    filepath += filename;
    // open file, 
    // and define the openmode to output and truncate file if it exists before
    ofstream fout(filepath.c_str(), ios::trunc);
    // try to write
    if (fout) fout << "Hello World!\n";
    else cout << "failed to open file\n";
}
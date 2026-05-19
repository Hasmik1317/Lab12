#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <sys/stat.h>

using namespace std;

int main() {
    ifstream file("packed.bin", ios::binary);
    if(!file) { cout << "Error: packed.bin not found!\n"; return 1; }

    vector<char> data((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());

    for (auto& b : data) b ^= 0xAA; // Decryption

    string temp_file = "./unpacked_temp";
    ofstream out(temp_file, ios::binary);
    out.write(data.data(), data.size());
    out.close();

    // Linux-ում ֆայլը պետք է դարձնել Executable
    chmod(temp_file.c_str(), 0755);

    cout << "Unpacking and running...\n";
    system(temp_file.c_str()); 

    // Ջնջել ժամանակավոր ֆայլը աշխատանքից հետո
    remove(temp_file.c_str());

    return 0;
}

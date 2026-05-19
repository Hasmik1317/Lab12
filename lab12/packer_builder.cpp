#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    string input = "hello"; // Թիրախային ծրագիրը
    string output = "packed.bin";
    char key = 0xAA;

    ifstream file(input, ios::binary);
    if(!file) { cout << "Error: Run 'g++ hello.cpp -o hello' first!\n"; return 1; }

    vector<char> data((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    
    for (auto& b : data) b ^= key; // Encryption

    ofstream out(output, ios::binary);
    out.write(data.data(), data.size());

    cout << "Binary 'hello' packed into 'packed.bin' successfully!\n";
    return 0;
}

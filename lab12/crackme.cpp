#include <iostream>
#include <string>

using namespace std;

bool check(string input) {
    int key[] = {29, 12, 16, 21, 26}; // XOR-ված գաղտնաբառ
    if (input.length() != 5) return false;

    for (int i = 0; i < 5; i++) {
        if ((input[i] ^ 0x55) != key[i]) return false;
    }
    return true;
}

int main() {
    string pass;
    cout << "Enter password: ";
    cin >> pass;

    if (check(pass)) cout << "Access Granted!\n";
    else cout << "Access Denied!\n";
    
    return 0;
}

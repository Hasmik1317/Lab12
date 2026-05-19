#include <iostream>
using namespace std;

int main() {
    int key[] = {29, 12, 16, 21, 26};
    cout << "Decoded Password: ";
    for (int i = 0; i < 5; i++) {
        char c = key[i] ^ 0x55;
        cout << c;
    }
    cout << endl;
    return 0;
}

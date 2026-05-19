#include <iostream>
#include <sys/ptrace.h>
#include <unistd.h>

using namespace std;

int main() {
    // Եթե ptrace-ը չի կարողանում կցվել, նշանակում է debugger-ն արդեն կցված է
    if (ptrace(PTRACE_TRACEME, 0, 1, 0) < 0) {
        cout << "DEBUGGER DETECTED! Exiting...\n";
        return 1;
    }
    ptrace(PTRACE_DETACH, 0, 1, 0);
    
    cout << "Normal execution. No debugger found.\n";
    return 0;
}

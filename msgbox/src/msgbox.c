#include <windows.h>

int main() {
    MessageBoxA(0, "Hello from C app!", "my MsgBox", MB_ICONINFORMATION);
    ExitProcess(0);
}
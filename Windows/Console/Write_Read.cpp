#include <windows.h>
#include <iostream>
#include <string>

using namespace std;

void writeConsoleLine(const std::wstring& text) {
    DWORD charsWritten;
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    WriteConsoleW(hOutput, text.c_str(), static_cast<DWORD>(text.length()), &charsWritten, nullptr);
}

std::wstring readConsoleLine() {
    wchar_t buffer[256];
    DWORD charsRead;
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    ReadConsoleW(hInput, buffer, 256, &charsRead, nullptr);

    if (charsRead >= 2 && buffer[charsRead - 2] == L'\r') {
        buffer[charsRead - 2] = L'\0';
    } else {
        buffer[charsRead] = L'\0';
    }

    return wstring(buffer);
}

int main() {
    writeConsoleLine(L"What's your name? ");
    wstring name = readConsoleLine();

    writeConsoleLine(L"Hello, " + name + L"!\n");

    return 0;
}

#include <windows.h>
#include <iostream>

void setConsoleColor(int fg, int bg)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bg << 4) | fg);
}

#include <windows.h>
#include <iostream>
#include <string>

void printColored(const std::string &text, int fg, int bg)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    WORD originalAttributes = consoleInfo.wAttributes;

    WORD newAttributes = (bg << 4) | fg;
    SetConsoleTextAttribute(hConsole, newAttributes);
    std::cout << text;

    SetConsoleTextAttribute(hConsole, originalAttributes);
}

enum ConsoleColor
{
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Yellow = 6,
    LightGray = 7,
    DarkGray = 8,
    LightBlue = 9,
    LightGreen = 10,
    LightCyan = 11,
    LightRed = 12,
    LightMagenta = 13,
    LightYellow = 14,
    White = 15
};

int main()
{
    std::cout << "Normal text\n";

    printColored("This is yellow on blue\n", 14, 0);
    printColored("This is red on black\n", 12, 0);

    std::cout << "Back to normal again!\n";

    return 0;
}
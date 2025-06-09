#include <windows.h>
#include <iostream>

void clearScreen()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD written;
    COORD homeCoords = {0, 0};

    if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
        return;

    DWORD consoleSize = csbi.dwSize.X * csbi.dwSize.Y;

    FillConsoleOutputCharacter(hConsole, ' ', consoleSize, homeCoords, &written);

    FillConsoleOutputAttribute(hConsole, csbi.wAttributes, consoleSize, homeCoords, &written);

    SetConsoleCursorPosition(hConsole, homeCoords);
}

void clearRegion(int x, int y, int width, int height)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD written;
    COORD startPos = {(SHORT)x, (SHORT)y};

    DWORD size = width * height;

    for (int row = 0; row < height; ++row)
    {
        COORD pos = {(SHORT)x, (SHORT)(y + row)};
        FillConsoleOutputCharacter(hConsole, ' ', width, pos, &written);
    }
}

int main()
{
    std::cout << "Hello, this will be cleared in 3 seconds...\n";

    std::cout << "3 seconds...\n";
    Sleep(1000);
    std::cout << "2 seconds...\n";
    Sleep(1000);
    std::cout << "1 seconds...\n";
    Sleep(1000);
    clearScreen();

    std::cout << "Screen cleared!\n";

    std::cout << "..............................\n";
    std::cout << "..............................\n";
    std::cout << "..............................\n";
    std::cout << "..............................\n";
    std::cout << "..............................\n";

    std::cout << "3 seconds...\n";
    Sleep(1000);
    std::cout << "2 seconds...\n";
    Sleep(1000);
    std::cout << "1 seconds...\n";
    Sleep(1000);

    clearRegion(5, 1, 5, 3);
    Sleep(1000);
    clearRegion(10, 1, 5, 3);
    Sleep(1000);
    clearRegion(15, 1, 5, 3);
    Sleep(1000);
    clearRegion(20, 1, 5, 3);

    return 0;
}

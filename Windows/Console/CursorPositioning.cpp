#include <windows.h>
#include <iostream>

void gotoXY(int x, int y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = {(SHORT)x, (SHORT)y};
    SetConsoleCursorPosition(hConsole, position);
}

void createRealConsole()
{
    AllocConsole();

    FILE *fp;
    freopen_s(&fp, "CONOUT$", "w", stdout); // std::cout
    freopen_s(&fp, "CONIN$", "r", stdin);   // std::cin
    freopen_s(&fp, "CONOUT$", "w", stderr); // std::cerr

    std::ios::sync_with_stdio();
}

void moveToNextLine() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);

    COORD nextLine = csbi.dwCursorPosition;
    nextLine.X = 0;            
    nextLine.Y += 1;              

    SetConsoleCursorPosition(hConsole, nextLine);
}


int main()
{
    createRealConsole();
    std::cout << "Line 1\n";
    std::cout << "Line 2\n";

    gotoXY(10, 5);
    std::cout << "Moved text";

    gotoXY(10, 20);
    std::cout << "Moved text";

    moveToNextLine();

    system("pause");
    return 0;
}

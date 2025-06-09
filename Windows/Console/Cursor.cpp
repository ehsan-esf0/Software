#include <windows.h>
#include <iostream>


void showCursor(bool show)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = show;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}


void setCursorSize(int size)
{
    if (size < 1) size = 1;
    if (size > 100) size = 100;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.dwSize = size;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}


void gotoXY(int x, int y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {(SHORT)x, (SHORT)y};
    SetConsoleCursorPosition(hConsole, pos);
}

int main()
{
    std::cout << "Normal cursor visible...\n";
    Sleep(2000);

    std::cout << "Cursor will be hidden for 3 seconds...\n";
    showCursor(false);
    Sleep(3000);

    std::cout << "Cursor back visible and bigger...\n";
    showCursor(true);
    setCursorSize(50); 
    Sleep(2000);

    std::cout << "Moving cursor to (10, 10)...\n";
    gotoXY(10, 10);
    std::cout << "Here I am!";
    Sleep(3000);

    gotoXY(0, 15);
    std::cout << "\nBack to normal position.\n";

    return 0;
}

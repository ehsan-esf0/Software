#include <windows.h>
#include <iostream>
#include <fstream>

void createRealConsole() {
    AllocConsole(); 

    FILE* fp;
    freopen_s(&fp, "CONOUT$", "w", stdout);  // std::cout
    freopen_s(&fp, "CONIN$", "r", stdin);    // std::cin
    freopen_s(&fp, "CONOUT$", "w", stderr);  // std::cerr

    std::ios::sync_with_stdio(); 
}

int main() {
    createRealConsole();

    std::cout << "This is a real console window!\n";
    std::string name;
    std::cout << "What's your name? ";
    std::cin >> name;
    std::cout << "Hello, " << name << "!\n";

    system("pause"); 
    return 0;
}

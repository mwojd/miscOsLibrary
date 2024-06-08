#include "./multiOsFramework.h"

char mof::optInput() {
    char key;
#ifdef _WIN32 //if windows get input as a key press
    key = _getch();
#else //if another os (like linux) handle it in the usual way using std::cin
    std::cin >> key;
    if (std::cin.fail() || std::cin.get() != '\n') {
        //if the user input is incorrect then clear input and try again
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return optInput();
    }
#endif
    return key;
}
void mof::sleep(int ms) {
#ifdef _WIN32
    Sleep(ms);
#else
    usleep(ms);
#endif
}
void mof::clear() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}
#ifdef _WIN32
void mof::colored(std::string string, WORD color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
    std::cout << string;
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
#else
void mof::colored(std::string text, std::string textCol = "", std::string bkgCol = "", std::string format = "") {
    std::string escape_code = "\033[";

    if (!format.empty()) {
        escape_code += format;
    }

    if (!textCol.empty()) {
        if (!escape_code.empty() && escape_code != "\033[") escape_code += ";";
        escape_code += textCol;
    }

    if (!bkgCol.empty()) {
        if (!escape_code.empty() && escape_code != "\033[") escape_code += ";";
        escape_code += bkgCol;
    }

    escape_code += "m" + text + "\033[0m";
    std::cout << escape_code;
}
#endif
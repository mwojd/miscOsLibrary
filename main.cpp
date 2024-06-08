#include <iostream>
#include "./framework/multiOsFramework.h"
class App {
public:
	App() {};
	void menu() {
#ifdef _WIN32
		mof::colored("menu\n", FOREGROUND_RED);
#else
		mof::colored("menu\n", "31", "", "");
#endif // _WIN32

		std::cout << "1. opt1" << std::endl;
		std::cout << "2. opt2" << std::endl;
	}
	void opt1() {
		std::cout << "opt1" << std::endl;
		std::cout << "[l] to leave" << std::endl;
		if (mof::optInput() == 'l') run();
	}
	void opt2() {
		std::cout << "opt2" << std::endl;
		std::cout << "[l] to leave" << std::endl;
		if (mof::optInput() == 'l') run();
	}
	void run() {
		char option;
		menu();
		option = mof::optInput();
		std::cout << option << "\n";
		if (option == '1') opt1();
		else if (option == '2') opt2();
		else {
			std::cout << "try again\n";
			run();
		}
	}
};
int main() {
	App app;
	app.run();
	return 0;
}
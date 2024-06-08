#pragma once
#ifdef _WIN32
#include <Windows.h>
#include <stdlib.h>
#include <conio.h> // handles windows input
#else
#include <unistd.h>
#endif 
#include <iostream>
#include <limits>
namespace mof {
	char optInput();
	void sleep(int ms);
	void clear();
#ifdef _WIN32
	void colored(std::string string, WORD color);
#else
	void colored(std::string text, std::string textCol, std::string bkgCol, std::string format);
#endif

	namespace clipboard {//for the future
		void clear();
		void copy();
		void load();
	}
	namespace proc {//for the future
		void writeMem();
		void getPrc();
		void readMem();
		void killProc();
		void freezeProc();
		void resumeProc();
		void createThread();
		void destroyThread();
	}
}
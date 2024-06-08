# misc os library
---
## what is it?
- this is a library that provides various miscellaneous functions that should work on both windows and linux
## what are the current features?
so far there are only a few functions however I'll try to expand this if anything comes to mind
1. optInput() - returns 1 char input, on windows takes a key press on linux takes a standard std::cin with a failsafe
2. sleep(int ms) - a standard sleep function in ms
3. clear() - clears the console
4. colored() - prints colored text, takes different arguments based on system, however both take a string at first
	- windows: text, WORD color, the list of different colors can be found online
	- linux: text, string color code, backgroud color code, format code
	- I'm planning on optimizing this function to take the same args on both systems
## how to use?
- put both files from the framework folder in your project and include the multiOsFramework.h in your project
- main.cpp is just an example use of the library
- the library includes the following(dont include them again!):
	- windows:
		1. Windows.h
		2. stdlib.h
		3. conio.h
	- linux:
		1. unistd.h
	- both:
		1. iostream
		2. limits
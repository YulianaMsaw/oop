#include "Console.h"
int main()
{
	setlocale(LC_ALL, "Russian");

	ConsoleUserInterface console;
	console.Run();

	return 0;
}

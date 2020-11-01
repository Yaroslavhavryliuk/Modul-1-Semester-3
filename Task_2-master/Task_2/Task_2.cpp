#include "Stdafx.h"

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(0, "ru");
	srand(time(0));
	UnitTests unit_test;	
	unit_test.Start();
}


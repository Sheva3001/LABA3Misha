#include "Stack.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	ifstream file("file.txt");
	if (!file) {
		cout << "Файл не найден!\n";
		return 0;
	}
	string str;
	getline(file, str);
	bracketsPosition(str);
}
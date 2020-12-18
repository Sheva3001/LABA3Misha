#include "Stack.h"
#include <iostream>
#include <string>

using namespace std;

void init(Tstack& top) { 
	top = 0;
}

bool isEmpty(Tstack top) {
	return top == NULL;
}

void push(Tstack& top, int elem) {
	Tstack p = new Node;
	p->data = elem;
	p->next = top;
	top = p;
}

void pop(Tstack& top) {
	Tstack p = top;
	top = top->next;
	p->next = NULL;
	delete p;
	p = NULL;
}

int getTop(Tstack top) {
	return top->data;
}

void clearStack(Tstack& top) {
	while (!isEmpty(top))
		pop(top);
	top = NULL;
}

void bracketsPosition(string& str) { // Передаём в функцию строку
	Tstack stack; string temp; int tmpi; // Создаём стек и 2 временные переменные, они нужны, чтобы выводить позиции скобок в нужном порядке, если не принцииально, то можно и без них
	string outstr; // Строка для позиций скобок
	init(stack); // Инициализация стека
	for (int i = 0; i < str.length(); i++) { // Проход по строке
		if (str[i] == '(') // Если видим открывающую скобку
			push(stack, i+1); // Засовываем в стек ее индекс+1, т.к. отчсет от 0
		else if (str[i] == ')') { // Если видим закрывающую скобку
			tmpi = getTop(stack); // Получаем из стека последний элемент (индекс последней открывающей скобки)
			temp = to_string(tmpi) + " " + to_string(i+1) + ";"; // Строка = ИНДЕКС_ОТКРЫВАЮЩЕЙ ИНДЕКС_ЗАКРЫВАЮЩЕЙ;
			outstr = temp + outstr; // В начало строки помещаем строку, которую составили выше
			pop(stack); // Удалаяем верхний элемент стека
		}
	}
	cout << outstr;
}
#pragma once
#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
};
typedef Node* Tstack;

void init(Tstack& top); // Инициализация
bool isEmpty(Tstack top); // Проверка на пустоту
void push(Tstack& top, int elem); // Добавление в стек
void pop(Tstack& top); // Удалене из стека
int getTop(Tstack top); // Просмотреть верхний элемент
void clearStack(Tstack& top); // Очистка стека
void bracketsPosition(string& str); // Позиции скобок
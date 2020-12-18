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

void bracketsPosition(string& str) { // ������� � ������� ������
	Tstack stack; string temp; int tmpi; // ������ ���� � 2 ��������� ����������, ��� �����, ����� �������� ������� ������ � ������ �������, ���� �� ������������, �� ����� � ��� ���
	string outstr; // ������ ��� ������� ������
	init(stack); // ������������� �����
	for (int i = 0; i < str.length(); i++) { // ������ �� ������
		if (str[i] == '(') // ���� ����� ����������� ������
			push(stack, i+1); // ���������� � ���� �� ������+1, �.�. ������ �� 0
		else if (str[i] == ')') { // ���� ����� ����������� ������
			tmpi = getTop(stack); // �������� �� ����� ��������� ������� (������ ��������� ����������� ������)
			temp = to_string(tmpi) + " " + to_string(i+1) + ";"; // ������ = ������_����������� ������_�����������;
			outstr = temp + outstr; // � ������ ������ �������� ������, ������� ��������� ����
			pop(stack); // �������� ������� ������� �����
		}
	}
	cout << outstr;
}
#pragma once
#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
};
typedef Node* Tstack;

void init(Tstack& top); // �������������
bool isEmpty(Tstack top); // �������� �� �������
void push(Tstack& top, int elem); // ���������� � ����
void pop(Tstack& top); // ������� �� �����
int getTop(Tstack top); // ����������� ������� �������
void clearStack(Tstack& top); // ������� �����
void bracketsPosition(string& str); // ������� ������
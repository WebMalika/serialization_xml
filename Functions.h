#pragma once
#include <string>
#include <iostream>
#include <conio.h>

using namespace std;

//�������������� ������� � ������
string array_to_string(string array[], int size_array);

//���� �������� ��������
string InputVariant(string text, string array[], int size_array);

//���� ������
size_t InputNumber(string text, size_t max_value);

//���� ��������� �������� � ���������� ���������
float Input(string text, string text_error, float min_value, float max_value);
//���� ��������� ��������
float Input(string text);





#pragma once
#include <string>
#include <iostream>
#include <conio.h>

using namespace std;

//Преобразование массива в строку
string array_to_string(string array[], int size_array);

//Ввод варианта значения
string InputVariant(string text, string array[], int size_array);

//Ввод номера
size_t InputNumber(string text, size_t max_value);

//Ввод числового значения в допустимом диапазоне
float Input(string text, string text_error, float min_value, float max_value);
//Ввод числового значения
float Input(string text);





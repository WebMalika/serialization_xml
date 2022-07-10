#include "Functions.h"


using namespace std;

//�������������� ������� � ������
string array_to_string(string array[], int size_array)
{
	string str = "";
	for (int i = 0; i < size_array; i++)
	{
		str += to_string(i+1) + "-" + array[i] + " ";
	}
	return str;
}

//���� �������� ��������
string InputVariant(string text, string array[], int size_array)
{
	int number = 0;
	int size = size_array / sizeof(array[0]);
	do {
		cout << text + array_to_string(array, size);
		char symbol = _getche();
		number = symbol - '0' - 1;
		cout << endl;
	} while (number < 0 || number >= size);
	string item = array[number];
	cout << "������: " << item << endl;
	return item;
}
//���� ������
size_t InputNumber(string text, size_t max_value)
{
	size_t number = -1;
	while (1)
	{
		cout << text;
		char symbol = _getche();
		number = symbol - '0' - 1;
		cout << endl;
		if (number < 0 || number >= max_value)
		{
			cout << "��������� � ����� ������� �� ����������" << endl;
		}
		else
		{
			break;
		}
	}
	return number;
}


//���� ��������� ��������
float Input(string text, string text_error, float min_value, float max_value)
{
	float value = 0;
	while(1){
		cout << text;
		cin >> value;
		if (value >= min_value && value <= max_value)
		{
			break;
		}
		cin.clear();
		cin.ignore(256, '\n');
		cout << text_error << endl;
	}
	return value;
}

//���� ��������� ��������
float Input(string text)
{
	string str;
	while (1)
	{
		float value = -1;
		try
		{
			cout << text;
			cin >> str;
			return stof(str);
		}
		catch (const std::exception&)
		{
			cout << "������� ������������ ��������" << endl;
		}
	}
}



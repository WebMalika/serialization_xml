#include "Jewerly.h"

BOOST_CLASS_EXPORT(Bangle);
BOOST_CLASS_EXPORT(Ring);

//********�������************
template<class Archive>
void Product::serialize(Archive& ar, const unsigned int version)
{
	ar& BOOST_SERIALIZATION_NVP(code);
	ar& BOOST_SERIALIZATION_NVP(price);
}
Product::Product()
{
}
Product::Product(string code, float price)
{
	this->code = code;
	this->price = price;
}

string Product::ProductInfo()
{
	string str = "��� ������: " + code + "\r\n";
	str += "����: " + to_string(price)+ "\r\n";
	return str;
}

//********�������������*********
//Jewerly
template<class Archive>
void Jewerly::serialize(Archive& ar, const unsigned int version)
{
	ar& BOOST_SERIALIZATION_NVP(name);
	ar& BOOST_SERIALIZATION_NVP(material);
}
Jewerly::Jewerly()
{
}
Jewerly::Jewerly(string name, string material)
{
	this->name = name;
	this->material = material;
}
string Jewerly::JewerlyInfo()
{
	string result;
	result = "  ��������: " + name + "\n";
	result += "  ��������: " + material + "\n";
	return result;
}
string Jewerly::ShowInfo() { return NULL; }
void Jewerly::Edit() {}

//**********�������**********
//Bangle
template<class Archive>
void Bangle::serialize(Archive& ar, const unsigned int version)
{
	ar& BOOST_SERIALIZATION_BASE_OBJECT_NVP(Product);
	ar& BOOST_SERIALIZATION_BASE_OBJECT_NVP(Jewerly);
	ar& BOOST_SERIALIZATION_NVP(thickness);
	ar& BOOST_SERIALIZATION_NVP(weaving);
	ar& BOOST_SERIALIZATION_NVP(lock);
}
Bangle::Bangle()
{
}
Bangle::Bangle(string code,float price, string name, string material, float thickness, string weaving, string lock): Jewerly(name, material), Product(code,price)
{
	this->thickness = thickness;
	this->weaving = weaving;
	this->lock = lock;
}
//����� ���������� �������
string Bangle::ShowInfo()
{
	string result = "**�������**\n";
	result += ProductInfo();
	result += JewerlyInfo();
	result += "  �������: " + to_string(thickness) + "\n";
	result += "  ��� ��������: " + weaving + "\n";
	result += "  ��� �����: " + lock + "\n";
	return result;
}
void Bangle::Edit()
{
	cout << "�������������� �������� " << name << endl;
	cout << ShowInfo() << endl;
	char option;
	do {
		cout << "�������� �������� ��� ��������������: 1-��� ������, 2-����, 3-��������, 4-��������, 5-�������, 6-��� ��������, 7-��� �����. Esc - ����� ";
		option = _getche();
		cout << endl << endl;
		switch (option)
		{
		case '1':
		{
			cout << "������� ����� ��� ������: ";
			cin >> code;
			break;
		}
		case '2':
			price = Input("������� ����� ����: ");
			break;
		case '3':
		{
			cout << "������� ����� ��������: ";
			cin >> name;
			break;
		}
		case '4':
		{
			material = InputVariant("�������� ����� ��������: ", Material, sizeof(Material));
			break;
		}
		case '5':
		{
			thickness = Input("������� ����� �������: ", ("������� �� ����� ���� ������ " +
				to_string(MIN_THICKNESS) + " � ������ " + to_string(MAX_THICKNESS) + " ��!"),
				MIN_THICKNESS, MAX_THICKNESS);
			break;
		}
		case '6':
		{
			weaving = InputVariant("�������� ����� ��� ��������: ", WeavingType, sizeof(WeavingType));
			break;
		}
		case '7':
		{
			lock = InputVariant("�������� ����� ��� �����: ", LockType, sizeof(LockType));
			break;
		}
		}
		cout << endl << endl;
	} while (option != 27);
}
//**********������************

//RingTop
template<class Archive>
void RingTop::serialize(Archive& ar, const unsigned int version)
{
	ar& BOOST_SERIALIZATION_NVP(insertion);
	ar& BOOST_SERIALIZATION_NVP(kast);
	ar& BOOST_SERIALIZATION_NVP(rant);
	ar& BOOST_SERIALIZATION_NVP(onlay);
}
RingTop::RingTop()
{
}
RingTop::RingTop(string insertion, string kast, string rant, string onlay)
{
	this->insertion = insertion;
	this->kast = kast;
	this->rant = rant;
	this->onlay = onlay;
}
string RingTop::ShowInfo()
{
	string result = "<��������>\n";
	result += "    �������: " + insertion + "\n";
	result += "    ������ ��� �������: " + kast + "\n";
	result += "    ������ ������: " + rant + "\n";
	result += "    ��������: " + onlay + "\n";
	return result;
}
void RingTop::Edit()
{
	cout << "�������������� �������� ������ " << endl;
	char option;
	do {
		cout << "�������� �������� ��� ��������������: 1-�������, 2-������, 3-������ ������, 4-��������. Esc - ����� ";
		option = _getche();
		cout << endl << endl;
		switch (option)
		{
		case '1':
		{
			insertion = InputVariant("�������� ����� �������: ", InsertionType, sizeof(InsertionType));
			break;
		}
		case '2':
		{
			kast = InputVariant("�������� ����� ������ �������: ", KastType, sizeof(KastType));
			break;
		}
		case '3':
		{
			rant = InputVariant("�������� ����� ������ ������: ", RantType, sizeof(RantType));
			break;
		}
		case '4':
		{
			onlay = InputVariant("�������� ����� ��������: ", OnLayType, sizeof(OnLayType));
			break;
		}
		}
		cout << endl << endl;
	} while (option != 27);
}


//����� ������
template<class Archive>
void RingShink::serialize(Archive& ar, const unsigned int version)
{
	ar& BOOST_SERIALIZATION_NVP(form);
	ar& BOOST_SERIALIZATION_NVP(width);
	ar& BOOST_SERIALIZATION_NVP(thickness);
}

RingShink::RingShink()
{
}

RingShink::RingShink(string form, float width, float thickness)
{
	this->form = form;
	this->width = width;
	this->thickness = thickness;
}

string RingShink::ShowInfo()
{
	string result = "<�����>\n";
	result += "    �����: " + form + "\n";
	result += "    ������: " + to_string(width) + "\n";
	result += "    �������: " + to_string(thickness) + "\n";
	return result;
}

//��������������
void RingShink::Edit()
{
	cout << "�������������� ����� ������ " << endl;
	char option;
	do {
		cout << "�������� �������� ��� ��������������: 1-�����, 2-������, 3-�������. Esc - ����� ";
		option = _getche();
		cout << endl << endl;
		switch (option)
		{
		case '1':
		{
			form = InputVariant("�������� ����� �������: ", FormShink, sizeof(FormShink));
			break;
		}
		case '2':
		{
			width = Input("������� ����� ������: ", ("������ �� ����� ���� ������ " +
				to_string(SHINK_MIN_WIDTH) + " � ������ " + to_string(SHINK_MAX_WIDTH) + " ��!"),
				SHINK_MIN_WIDTH, SHINK_MAX_WIDTH);
			break;
		}
		case '3':
		{
			thickness = Input("������� ����� �������: ", ("������� �� ����� ���� ������ " +
				to_string(MIN_THICKNESS) + " � ������ " + to_string(MAX_THICKNESS) + " ��!"),
				MIN_THICKNESS, MAX_THICKNESS);
			break;
		}
		}
		cout << endl << endl;
	} while (option != 27);
}

template<class Archive>
void Ring::serialize(Archive& ar, const unsigned int version)
{
	ar& BOOST_SERIALIZATION_BASE_OBJECT_NVP(Product);
	ar& BOOST_SERIALIZATION_BASE_OBJECT_NVP(Jewerly);
	ar& BOOST_SERIALIZATION_NVP(top);
	ar& BOOST_SERIALIZATION_NVP(shink);
}

Ring::Ring()
{
}

Ring::Ring(string code, float price,string name, string material, RingTop* top, RingShink* shink) :Jewerly(name, material),Product(code,price)
{
	this->top = top;
	this->shink = shink;
}

Ring::~Ring()
{
	delete top;
	delete shink;
}

string Ring::ShowInfo()
{
	string result = "**������**\n";
	result += ProductInfo();
	result += JewerlyInfo();
	result += "  " + top->ShowInfo();
	result += "  " + shink->ShowInfo();
	return result;
}
void Ring::Edit()
{
	cout << "�������������� ������ " << name << endl;
	cout << ShowInfo() << endl;
	char option;
	do {
		cout << "�������� �������� ��� ��������������: 1-��� ������, 2-����, 3-��������, 4-��������, 5-�������� ������, 6-����� ������. Esc - ����� ";
		option = _getche();
		cout << endl << endl;
		switch (option)
		{
		case '1':
		{
			cout << "������� ����� ��� ������: ";
			cin >> code;
			break;
		}
		case '2':
			price = Input("������� ����� ����: ");
			break;
		case '3':
		{
			cout << "������� ����� ��������: ";
			cin >> name;
			break;
		}
		case '4':
		{
			material = InputVariant("�������� ����� ��������: ", Material, sizeof(Material));
			break;
		}
		case '5':
		{
			top->Edit();
			break;
		}
		case '6':
		{
			shink->Edit();
			break;
		}
		}
		cout << endl << endl;
	}while (option != 27);
}
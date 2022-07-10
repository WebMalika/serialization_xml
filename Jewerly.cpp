#include "Jewerly.h"

BOOST_CLASS_EXPORT(Bangle);
BOOST_CLASS_EXPORT(Ring);

//********Продукт************
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
	string str = "Код товара: " + code + "\r\n";
	str += "Цена: " + to_string(price)+ "\r\n";
	return str;
}

//********Драгоценность*********
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
	result = "  Название: " + name + "\n";
	result += "  Материал: " + material + "\n";
	return result;
}
string Jewerly::ShowInfo() { return NULL; }
void Jewerly::Edit() {}

//**********Браслет**********
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
//Вывод информации объекта
string Bangle::ShowInfo()
{
	string result = "**Браслет**\n";
	result += ProductInfo();
	result += JewerlyInfo();
	result += "  Толщина: " + to_string(thickness) + "\n";
	result += "  Тип плетения: " + weaving + "\n";
	result += "  Тип замка: " + lock + "\n";
	return result;
}
void Bangle::Edit()
{
	cout << "Редактирование браслета " << name << endl;
	cout << ShowInfo() << endl;
	char option;
	do {
		cout << "Выберите параметр для редактирования: 1-Код товара, 2-Цена, 3-Название, 4-Материал, 5-Толщина, 6-Тип плетения, 7-Тип замка. Esc - выход ";
		option = _getche();
		cout << endl << endl;
		switch (option)
		{
		case '1':
		{
			cout << "Введите новый код товара: ";
			cin >> code;
			break;
		}
		case '2':
			price = Input("Введите новую цену: ");
			break;
		case '3':
		{
			cout << "Введите новое название: ";
			cin >> name;
			break;
		}
		case '4':
		{
			material = InputVariant("Выберите новый материал: ", Material, sizeof(Material));
			break;
		}
		case '5':
		{
			thickness = Input("Введите новую толщину: ", ("Толщина не может быть меньше " +
				to_string(MIN_THICKNESS) + " и больше " + to_string(MAX_THICKNESS) + " мм!"),
				MIN_THICKNESS, MAX_THICKNESS);
			break;
		}
		case '6':
		{
			weaving = InputVariant("Выберите новый тип плетения: ", WeavingType, sizeof(WeavingType));
			break;
		}
		case '7':
		{
			lock = InputVariant("Выберите новый тип замка: ", LockType, sizeof(LockType));
			break;
		}
		}
		cout << endl << endl;
	} while (option != 27);
}
//**********Кольцо************

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
	string result = "<Верхушка>\n";
	result += "    Вставка: " + insertion + "\n";
	result += "    Оправа для вставки: " + kast + "\n";
	result += "    Ободок оправы: " + rant + "\n";
	result += "    Накладка: " + onlay + "\n";
	return result;
}
void RingTop::Edit()
{
	cout << "Редактирование верхушки кольца " << endl;
	char option;
	do {
		cout << "Выберите параметр для редактирования: 1-Вставка, 2-Оправа, 3-Ободок оправы, 4-Накладка. Esc - выход ";
		option = _getche();
		cout << endl << endl;
		switch (option)
		{
		case '1':
		{
			insertion = InputVariant("Выберите новую вставку: ", InsertionType, sizeof(InsertionType));
			break;
		}
		case '2':
		{
			kast = InputVariant("Выберите новую оправу вставки: ", KastType, sizeof(KastType));
			break;
		}
		case '3':
		{
			rant = InputVariant("Выберите новый ободок оправы: ", RantType, sizeof(RantType));
			break;
		}
		case '4':
		{
			onlay = InputVariant("Выберите новую накладку: ", OnLayType, sizeof(OnLayType));
			break;
		}
		}
		cout << endl << endl;
	} while (option != 27);
}


//Шинка кольца
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
	string result = "<Шинка>\n";
	result += "    Форма: " + form + "\n";
	result += "    Ширина: " + to_string(width) + "\n";
	result += "    Толщина: " + to_string(thickness) + "\n";
	return result;
}

//Редактирование
void RingShink::Edit()
{
	cout << "Редактирование шинки кольца " << endl;
	char option;
	do {
		cout << "Выберите параметр для редактирования: 1-Форма, 2-Ширина, 3-Толщина. Esc - выход ";
		option = _getche();
		cout << endl << endl;
		switch (option)
		{
		case '1':
		{
			form = InputVariant("Выберите новую вставку: ", FormShink, sizeof(FormShink));
			break;
		}
		case '2':
		{
			width = Input("Введите новую ширину: ", ("Ширина не может быть меньше " +
				to_string(SHINK_MIN_WIDTH) + " и больше " + to_string(SHINK_MAX_WIDTH) + " мм!"),
				SHINK_MIN_WIDTH, SHINK_MAX_WIDTH);
			break;
		}
		case '3':
		{
			thickness = Input("Введите новую толщину: ", ("Толщина не может быть меньше " +
				to_string(MIN_THICKNESS) + " и больше " + to_string(MAX_THICKNESS) + " мм!"),
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
	string result = "**Кольцо**\n";
	result += ProductInfo();
	result += JewerlyInfo();
	result += "  " + top->ShowInfo();
	result += "  " + shink->ShowInfo();
	return result;
}
void Ring::Edit()
{
	cout << "Редактирование кольца " << name << endl;
	cout << ShowInfo() << endl;
	char option;
	do {
		cout << "Выберите параметр для редактирования: 1-Код товара, 2-Цена, 3-Название, 4-Материал, 5-Верхушка кольца, 6-Шинка кольца. Esc - выход ";
		option = _getche();
		cout << endl << endl;
		switch (option)
		{
		case '1':
		{
			cout << "Введите новый код товара: ";
			cin >> code;
			break;
		}
		case '2':
			price = Input("Введите новую цену: ");
			break;
		case '3':
		{
			cout << "Введите новое название: ";
			cin >> name;
			break;
		}
		case '4':
		{
			material = InputVariant("Выберите новый материал: ", Material, sizeof(Material));
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
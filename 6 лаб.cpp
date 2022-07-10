#include <Windows.h>
#include "Storage.h"


using namespace std;

Storage* storage;//Хранилище драгоценностей
string data_url = "Storage.xml";//Адрес хранения объектов хранилища

//Функция добавления ювелирного украшения
Jewerly* Add_Console()
{
	char Jewerly_type;
	while (1)
	{
		//system("cls");
		//Определение типа украшения
		cout << "Выберите вид ювелирного изделия: 1 - Браслет, 2 - Кольцо. Esc - Назад";
		Jewerly_type = _getch();
		cout << endl;
		switch (Jewerly_type)
		{
		case '1':
		{
			cout << "Добавление браслета" << endl << endl;
			//Код товара
			string code;
			cout << "Введите код товара: ";
			cin >> code;
			//Название
			string name;
			cout << "Введите название: ";
			cin >> name;
			//Цена товара
			float price;
			price = Input("Введите цену: ");
			//Толщина
			float thickness = Input("Введите толщину: ", ("Толщина не может быть меньше " +
				to_string(MIN_THICKNESS) + " и больше " + to_string(MAX_THICKNESS) + " мм!"),
				MIN_THICKNESS, MAX_THICKNESS);
			//////////////////////////////////////
			string weaving_type = InputVariant("Укажите тип плетения: ", WeavingType,sizeof(WeavingType));
			string lock_type = InputVariant("Укажите тип замка: ", LockType,sizeof(LockType));
			string material = InputVariant("Выберите материал: ", Material,sizeof(Material));
			Bangle* bangle = new Bangle(code,price,name, material, thickness, weaving_type,lock_type);
			cout << endl << "Браслет " << name << " добавлен." << endl;
			return bangle;
		}
		case '2':
		{
			cout << "Добавление кольца" << endl;
			//Код товара
			string code;
			cout << "Введите код товара: ";
			cin >> code;
			//Название
			string name;
			cout << "Введите название: ";
			cin >> name;
			//Цена товара
			float price;
			price = Input("Введите цену: ");
			//Материал
			string material = InputVariant("Выберите материал ", Material,sizeof(Material));
			//Верхушка кольца
			//Вставка
			string insertion = InputVariant("Выберите вставку: ", InsertionType,sizeof(InsertionType));
			//Оправа для вставки
			string kast = InputVariant("Выберите оправу: ", KastType,sizeof(KastType));
			//Ободок оправы
			string rant = InputVariant("Выберите ободок для оправы: ", RantType,sizeof(RantType));
			//Накладка
			string onlay = InputVariant("Выберите тип накладки: ", OnLayType,sizeof(OnLayType));
			//Шинка кольца
			//Форма
			string form = InputVariant("Выберите форму шинки: ", FormShink,sizeof(FormShink));
			//Ширина
			float width = Input("Введите ширину: ", ("Ширина не может быть меньше " +
				to_string(SHINK_MIN_WIDTH) + " и больше " + to_string(SHINK_MAX_WIDTH) + " мм!"),
				SHINK_MIN_WIDTH, SHINK_MAX_WIDTH);
			//Толщина
			float thickness = Input("Введите толщину: ", ("Толщина не может быть меньше " +
				to_string(MIN_THICKNESS) + " и больше " + to_string(MAX_THICKNESS) + " мм!"),
				MIN_THICKNESS, MAX_THICKNESS);
			//Верхушка кольца
			RingTop* top = new RingTop(insertion, kast, rant, onlay);
			//Шинка кольца
			RingShink* shink = new RingShink(form, width, thickness);
			Ring* ring = new Ring(code,price,name, material, top, shink);
			cout << endl<< "Кольцо " << name << " добавлено." << endl;
			return ring;
		}
		case 27:
		{
			return NULL;
		}
		}
	}
}
//Функция редактирования украшения
void Edit()
{
	size_t number = InputNumber("Выберите номер редактируемого украшения: ", storage->Count());
	storage->GetItem(number)->Edit();
	cout << endl << "Редактирование украшения прошло успешно" << endl;
}
//Функция удаления украшения
void Remove() 
{
	size_t number = InputNumber("Выберите номер удаляемого украшения: ", storage->Count());
	storage->Remove(number);
	cout << endl << "Украшение было удалено" << endl;
}
//Функция отображения списка украшений
void View() 
{
	cout << "Список драгоценностей:" << endl << endl;
	cout << storage->View() << endl;
}

	
int main()
{
	//Настройка отображения кириллицы
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	storage = new Storage();
	char put;
	do{
		//system("cls");
		cout << "Выберите действие: 1-Добавление, 2-Редактирование, 3-Удаление, 4-Вывод, 5-Сохранение, Escape-для выхода ";
		put = _getch();
		cout << endl;
		if (put != '1' && storage->Count() == 0) 
		{
			cout << "Список драгоценностей пуст" << endl;
		}
		else {
			switch (put)
			{
			case'1'://Добавление
			{
				cout << "Выберите способ ввода: 1-С клавиатуры, 2-Из файла";
				char option = _getch();
				cout << endl;
				switch (option)
				{
				case'1'://Добавление с клавиатуры
				{
					Jewerly* Jewerly = Add_Console();
					if (Jewerly != NULL)
					{
						storage->Add(Jewerly);
					}
					break;
				}
				case '2'://Добавление из файла
					if (storage->Load(data_url)) {
						View();
					}
					else 
					{
						cout << "Файл не найден";
					}
				}
				break;
			}
			case '2'://Редактирование
			{
				Edit();
				break;
			}
			case '3'://Удаление
			{
				Remove();
				break;
			}
			case '4'://Вывод
			{
				View();
				break;
			}
			case '5'://Сохранение
			{
				storage->Save(data_url);
				cout << "Сохранение прошло успешно" << endl;
				break;
			}
			}
		}
		cout << endl;
	} while (put != 27);
}

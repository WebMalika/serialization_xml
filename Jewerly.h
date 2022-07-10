#pragma once
#include "Functions.h"
#include <boost/serialization/export.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>

//********Продукт************
class Product
{
protected:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& ar, const unsigned int version);
	string code;//Код товара
	float price;//Цена
public:
	Product();
	Product(string code, float price);
	//Метод, отображающий характеристики продукта
	string ProductInfo();
};


//********Драгоценность*********
static string Material[2] = { "Серебро", "Золото" };//Материал

const int MIN_THICKNESS = 1;//Минимальная толщина
const int MAX_THICKNESS = 10;//Максимальная толщина

class Jewerly
{
protected:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& ar, const unsigned int version);
	string name;//название
	string  material;//материал
public:
	Jewerly();
	Jewerly(string name, string material);
	//Метод, отображающий характеристики драгоценности
	string JewerlyInfo();
	//Метод, отображающий характеристики дочерних объектов
	virtual string ShowInfo();
	//Метод, осуществляющий редактирование драгоценности
	virtual void Edit();
};

//**********Браслет**********
static string WeavingType[3] = { "Бисмарк", "Панцирное", "Якорное" };//Тип плетения
static string LockType[2] = { "Карабин", "Винт" };//Тип замка браслета

class Bangle : public Jewerly,public Product
{
private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& ar, const unsigned int version);
	float thickness;//Толщина
	string weaving;//Тип плетения
	string lock;//Тип замка браслета
public:
	Bangle();
	Bangle(string code, float price, string name, string material, float thickness, string weaving, string lock);
	//Вывод информации объекта
	string ShowInfo() override;
	//Редактирование объекта
	void Edit() override;
};

//**********Кольцо************
static string InsertionType[3] = { "Рубин","Сапфир","Изумруд" };//Типы вставок
static string KastType[2] = { "Глухая", "Ободковая" };//Виды оправ
static string RantType[2] = { "Прямой", "Конический" };//Типы ободков оправы
static string OnLayType[3] = { "Гладкая", "Чеканная", "Со вставками" };//Типы накладок

//Верхушка кольца
class RingTop
{
private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& ar, const unsigned int version);
	string insertion;//Вставка
	string kast;// Оправа для вставки
	string rant;// Ободок оправы
	string onlay;// Накладка
public:
	RingTop();
	RingTop(string insertion, string kast, string rant, string onlay);
	//Вывод информации объекта
	string ShowInfo();
	//Редактирование
	void Edit();
};

const int SHINK_MIN_WIDTH = 2;//Минимальная ширина шинки
const int SHINK_MAX_WIDTH = 10;//Максимальная ширина шинки
static string FormShink[3] = { "Круглая","Овальная","Прямоугольная" };//Форма шинки кольца

//Шинка кольца
class RingShink {
private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& ar, const unsigned int version);
	string form;//Форма
	float width;//Ширина
	float thickness;//Толщина
public:
	RingShink();
	RingShink(string form, float width, float thickness);
	//Вывод информации объекта
	string ShowInfo();
	//Редактирование
	void Edit();
};

//Кольцо
class Ring : public Jewerly,public Product
{
private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& ar, const unsigned int version);
	RingTop* top;//Верхушка кольца
	RingShink* shink;//Шинка кольца
public:
	Ring();
	Ring(string code, float price, string name, string material, RingTop* top, RingShink* shink);
	~Ring();
	string ShowInfo() override;
	void Edit() override;
};
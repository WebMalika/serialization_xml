#pragma once
#include <fstream>
#include <vector>
#include "Jewerly.h"
#include <boost/serialization/vector.hpp>

//Объект хранилища драгоценностей
class Storage
{
private:
	//Список драгоценностей
	vector<Jewerly*> objects;
	//Сериализация
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& ar, const unsigned int version);
public:
	Storage();
	~Storage();
	//Метод, возвращающий кол-во объектов
	size_t Count();
	//Метод получения объекта по номеру
	Jewerly* GetItem(size_t number_item);
	//Метод добавления нового объекта
	void Add(Jewerly* new_object);
	//Метод удаления объекта
	void Remove(size_t number);
	//Метод, возвращающий строковое представление характеристик объекта
	string View();
	//Метод загрузки объектов из файла (Десериализация)
	bool Load(string url);
	//Метол сохранения объектов (Сериализация)
	void Save(string url);
};
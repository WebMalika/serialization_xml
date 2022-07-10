#pragma once
#include <fstream>
#include <vector>
#include "Jewerly.h"
#include <boost/serialization/vector.hpp>

//������ ��������� ��������������
class Storage
{
private:
	//������ ��������������
	vector<Jewerly*> objects;
	//������������
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& ar, const unsigned int version);
public:
	Storage();
	~Storage();
	//�����, ������������ ���-�� ��������
	size_t Count();
	//����� ��������� ������� �� ������
	Jewerly* GetItem(size_t number_item);
	//����� ���������� ������ �������
	void Add(Jewerly* new_object);
	//����� �������� �������
	void Remove(size_t number);
	//�����, ������������ ��������� ������������� ������������� �������
	string View();
	//����� �������� �������� �� ����� (��������������)
	bool Load(string url);
	//����� ���������� �������� (������������)
	void Save(string url);
};
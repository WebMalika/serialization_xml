#pragma once
#include "Functions.h"
#include <boost/serialization/export.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>

//********�������************
class Product
{
protected:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& ar, const unsigned int version);
	string code;//��� ������
	float price;//����
public:
	Product();
	Product(string code, float price);
	//�����, ������������ �������������� ��������
	string ProductInfo();
};


//********�������������*********
static string Material[2] = { "�������", "������" };//��������

const int MIN_THICKNESS = 1;//����������� �������
const int MAX_THICKNESS = 10;//������������ �������

class Jewerly
{
protected:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& ar, const unsigned int version);
	string name;//��������
	string  material;//��������
public:
	Jewerly();
	Jewerly(string name, string material);
	//�����, ������������ �������������� �������������
	string JewerlyInfo();
	//�����, ������������ �������������� �������� ��������
	virtual string ShowInfo();
	//�����, �������������� �������������� �������������
	virtual void Edit();
};

//**********�������**********
static string WeavingType[3] = { "�������", "���������", "�������" };//��� ��������
static string LockType[2] = { "�������", "����" };//��� ����� ��������

class Bangle : public Jewerly,public Product
{
private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& ar, const unsigned int version);
	float thickness;//�������
	string weaving;//��� ��������
	string lock;//��� ����� ��������
public:
	Bangle();
	Bangle(string code, float price, string name, string material, float thickness, string weaving, string lock);
	//����� ���������� �������
	string ShowInfo() override;
	//�������������� �������
	void Edit() override;
};

//**********������************
static string InsertionType[3] = { "�����","������","�������" };//���� �������
static string KastType[2] = { "������", "���������" };//���� �����
static string RantType[2] = { "������", "����������" };//���� ������� ������
static string OnLayType[3] = { "�������", "��������", "�� ���������" };//���� ��������

//�������� ������
class RingTop
{
private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& ar, const unsigned int version);
	string insertion;//�������
	string kast;// ������ ��� �������
	string rant;// ������ ������
	string onlay;// ��������
public:
	RingTop();
	RingTop(string insertion, string kast, string rant, string onlay);
	//����� ���������� �������
	string ShowInfo();
	//��������������
	void Edit();
};

const int SHINK_MIN_WIDTH = 2;//����������� ������ �����
const int SHINK_MAX_WIDTH = 10;//������������ ������ �����
static string FormShink[3] = { "�������","��������","�������������" };//����� ����� ������

//����� ������
class RingShink {
private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& ar, const unsigned int version);
	string form;//�����
	float width;//������
	float thickness;//�������
public:
	RingShink();
	RingShink(string form, float width, float thickness);
	//����� ���������� �������
	string ShowInfo();
	//��������������
	void Edit();
};

//������
class Ring : public Jewerly,public Product
{
private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& ar, const unsigned int version);
	RingTop* top;//�������� ������
	RingShink* shink;//����� ������
public:
	Ring();
	Ring(string code, float price, string name, string material, RingTop* top, RingShink* shink);
	~Ring();
	string ShowInfo() override;
	void Edit() override;
};
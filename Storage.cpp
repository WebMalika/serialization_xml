#include "Storage.h"

//Storage
template<class Archive>
void Storage::serialize(Archive& ar, const unsigned int version)
{
	ar& BOOST_SERIALIZATION_NVP(objects);
}
Storage::Storage()
{
	objects = {};
}
Storage::~Storage()
{
	size_t count_objects = objects.size();
	for (int i = 0; i < count_objects; i++)
	{
		delete objects[i];
	}
}
size_t Storage::Count()
{
	return objects.size();
}
Jewerly* Storage::GetItem(size_t number_item)
{
	if (number_item >= 0 && number_item < objects.size())
	{
		return objects[number_item];
	}
	else
	{
		return NULL;
	}
}
void Storage::Add(Jewerly* new_object)
{
	objects.push_back(new_object);
}
void Storage::Remove(size_t number)
{
	if (number > 0 || number < objects.size())
	{
		objects.erase(objects.begin() + number);
	}
}
string Storage::View()
{
	size_t size = objects.size();
	string str;
	for (int i = 0; i < size; i++)
	{
		str += to_string(i + 1) + ") ";
		str += objects[i]->ShowInfo() + "\n";
	}
	return str;
}
bool Storage::Load(string url)
{
	try
	{
		ifstream ifs(url);
		boost::archive::xml_iarchive xmlIn(ifs, boost::archive::no_header);
		xmlIn >> boost::serialization::make_nvp("Jewerly", objects);
		ifs.close();
		return true;
	}
	catch (const std::exception&)
	{
		return false;
	}

}
void Storage::Save(string url)
{
	ofstream ofs(url);
	boost::archive::xml_oarchive xmlOut(ofs, boost::archive::no_header);
	xmlOut << boost::serialization::make_nvp("Jewerly", objects);
	ofs.close();
}
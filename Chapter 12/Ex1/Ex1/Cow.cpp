#include "Cow.h"

Cow::Cow()
{
	name[0] = '\0';
	hobby = nullptr;
	weight = 0;
}

Cow::Cow(const char* nm, const char* ho, double wt)
{
	strcpy_s(name, strlen(nm) + 1, nm);
	int len = strlen(ho);
	hobby = new char[len + 1];
	strcpy_s(hobby, len + 1, ho);
	weight = wt;

}

Cow::Cow(const Cow& c)
{
	strcpy_s(name, strlen(c.name) + 1, c.name);
	int len = strlen(c.hobby);
	hobby = new char[len + 1];
	strcpy_s(hobby, len + 1, c.hobby);
	weight = c.weight;
}

Cow::~Cow()
{
	delete[] hobby;
}

Cow& Cow::operator=(const Cow& c)
{
	delete[] hobby;
	strcpy_s(name, strlen(c.name) + 1, c.name);
	int len = strlen(c.hobby);
	hobby = new char[len + 1];
	strcpy_s(hobby, len + 1, c.hobby);
	weight = c.weight;
	return *this;
}

void Cow::ShowCow() const
{
	cout << "Name: " << name;
	cout << "\nHobby: " << hobby;
	cout << "\nWeight: " << weight << endl;
}
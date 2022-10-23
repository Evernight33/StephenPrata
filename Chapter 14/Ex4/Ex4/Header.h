#ifndef Header_h
#define Header_h

#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
	std::string name;
	std::string surname;
public:
	Person(const std::string& n = "", const std::string& s = "");
	virtual ~Person() {}
	virtual void Show() const;
	virtual void Data() const;
	virtual void Set();
};

class Sniper : virtual public Person
{
private:
	int count;
	double drawtime;
public:
	Sniper(const std::string& n = "", const std::string& s = "", double dr = 0, int cnt = 0);
	~Sniper() {}
	double Draw() const { return drawtime; }
	int Count() { return count; }
	virtual void Show() const;
	virtual void Data() const;
	void SetData();
	void SetDrawTime(double d);
	void SetCount(int c);
};

class PokerPlayer : virtual public Person
{
private:

public:
	PokerPlayer(std::string n = "", std::string s = "");
	int Draw() const { return rand() % 52; }
	virtual void Show() const;
};

class BadDude : public Sniper, public  PokerPlayer
{
private:

public:
	BadDude(std::string n = "", std::string s = "", double dr = 0, int cnt = 0);
	~BadDude() {}
	virtual void Show() const;
	double Gdraw() const { return Sniper::Draw(); }
	double Cdraw() const { return PokerPlayer::Draw(); }
	virtual void Set();
};

#endif
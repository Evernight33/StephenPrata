#pragma once

#include <iostream>
#include <string>
using namespace std;

class CopyMove
{
public:
	struct Info
	{
		string qcode;
		string lcode;
	};

private:
	Info* pi = nullptr;

public:
	CopyMove();
	CopyMove(string q, string l);
	CopyMove(const CopyMove& copy);
	CopyMove(CopyMove&& move);

	~CopyMove();

	CopyMove& operator=(const CopyMove& copy);
	CopyMove& operator=(CopyMove&& move);
	CopyMove operator+(const CopyMove& obj) const;
	void Display() const;
};
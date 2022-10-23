#ifndef DMA_H
#define DMA_H

#include <iostream>
using namespace std;

class absDMA
{
private:
	char* label;
	int rating;
protected:
	const char* ret_lab() { return label; }
	int ret_rat() { return rating; }
public:
	absDMA(const char* l = "NULL", int r = 0);
	absDMA(const absDMA& rs);
	virtual ~absDMA();
	virtual void Show() const = 0;
	absDMA& operator=(const absDMA& rs);
	friend ostream& operator<< (ostream& os, const absDMA& rs);
};

class baseDMA : public absDMA
{
private:

public:
	baseDMA(const char* l = "NULL", int r = 0);
	baseDMA(const baseDMA& rs);
	virtual ~baseDMA();
	baseDMA& operator=(const baseDMA& rs);
	friend ostream& operator<< (ostream& os, const baseDMA& rs);
	virtual void Show() const;
};

class lacksDMA : public absDMA
{
private:
	enum { COL_LEN = 40 };
	char color[COL_LEN];
public:
	lacksDMA(const char* c = "blank", const char* l = "null", int r = 0);
	lacksDMA(const char* c, const baseDMA& rs);
	friend ostream& operator<< (ostream& os, const lacksDMA& rs);
	virtual void Show() const;
};

class hasDMA : public absDMA
{
private:
	char* style;
public:
	hasDMA(const char* s = "none", const char* l = "null", int r = 0);
	hasDMA(const char* s, const baseDMA& rs);
	hasDMA(const hasDMA& rs);
	~hasDMA();
	hasDMA& operator=(const hasDMA& rs);
	friend ostream& operator<< (ostream& os, const hasDMA& rs);
	virtual void Show() const;
};

#endif
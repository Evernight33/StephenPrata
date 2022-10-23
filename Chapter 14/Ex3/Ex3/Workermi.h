#ifndef Header_h
#define Header_h

#include <iostream>
#include <string>
using namespace std;

class Worker
{
private:
	string fullname;
	long id;
protected:
	virtual void Data() const;
	virtual void Get();
public:
	Worker() : fullname("no one"), id(0L)
	{}
	Worker(const string& s, long n) : fullname(s), id(n)
	{}
	virtual ~Worker() = 0;
	virtual void Set() = 0;
	virtual void Show() const = 0;
};

class Waiter : virtual public Worker
{
private:
	int panache;
protected:
	void Data() const;
	void Get();
public:
	Waiter() : Worker(), panache(0)
	{}
	Waiter(const string& s, long n, int p = 0) : Worker(s, n), panache(0)
	{}
	Waiter(const Worker& wk, int p = 0) : Worker(wk), panache(p)
	{}
	void Set();
	void Show() const;
};

class Singer : virtual public Worker
{
protected:
	enum { other, alto, contralto, soprano, bass, baritone, tenor };
	enum { Vtypes = 7 };
	void Data() const;
	void Get();
private:
	static string pv[Vtypes];
	int voice;
public:
	Singer() : Worker(), voice(other)
	{}
	Singer(const string& s, long n, int v = other) : Worker(s, n), voice(v)
	{}
	Singer(const Worker& wk, int v = other) : Worker(wk), voice(v)
	{}
	void Set();
	void Show() const;
};

class SingingWaiter : public Waiter, public Singer
{
protected:
	void Data() const;
	void Get();
public:
	SingingWaiter()
	{}
	SingingWaiter(const string& s, long n, int p = 0, int v = other) : Worker(s, n), Waiter(s, n, p), Singer(s, n, v)
	{}
	SingingWaiter(const Worker& wk, int p = 0, int v = other) : Worker(wk), Waiter(wk, p), Singer(wk, v)
	{}
	SingingWaiter(const Waiter wt, int v = other) : Worker(wt), Waiter(wt), Singer(wt, v)
	{}
	SingingWaiter(const Singer sg, int v = other) : Worker(sg), Waiter(sg), Singer(sg, v)
	{}
	void Set();
	void Show() const;
};

template <typename T>
class QueueTp
{
private:
	struct Node
	{
		T value;
		Node* next = nullptr;
		Node* prev = nullptr;
	};
	using link = Node*;
	link head = nullptr;
	link tail = nullptr;
	void emptyList();
public:
	QueueTp();
	QueueTp(const QueueTp<T>& q);
	~QueueTp();

	bool enqueue(const T& val);
	bool dequeue(T& val);
	bool isEmpty() const;

	QueueTp<T>& operator = (const QueueTp<T>& q);
};
//-------------------------------------------------------------------------------------------------
template <typename T>
QueueTp<T>::QueueTp() : head(nullptr), tail(nullptr)
{

}
//-------------------------------------------------------------------------------------------------
template <typename T>
QueueTp<T>::QueueTp(const QueueTp<T>& q)
{
	link tail = q.tail;
	while (tail != nullptr)
	{
		enqueue(tail->value);
		tail = tail->prev;
	}
}
//-------------------------------------------------------------------------------------------------
template <typename T>
QueueTp<T>::~QueueTp()
{
	emptyList();
}
//-------------------------------------------------------------------------------------------------
template <typename T>
void QueueTp<T>::emptyList()
{
	link t = head;
	while (t != nullptr && t != tail)
	{
		t = t->next;
		delete t->prev;
	}
	delete t;
	head = nullptr;
	tail = nullptr;
}
//-------------------------------------------------------------------------------------------------
template <typename T>
bool QueueTp<T>::enqueue(const T& val)
{
	link l = new (std::nothrow) Node;
	if (l == nullptr)
	{
		return false;
	}
	else
		if (isEmpty())
		{
			l->value = val;
			l->next = nullptr;
			l->prev = nullptr;
			head = l;
			tail = l;
		}
		else
		{
			l->value = val;
			l->next = head;
			l->prev = nullptr;
			head->prev = l;
			head = l;
		}
	return true;
}
//-------------------------------------------------------------------------------------------------
template <typename T>
bool QueueTp<T>::dequeue(T& val)
{
	if (isEmpty())
	{
		return false;
	}
	else
		if (head == tail)
		{
			val = tail->value;
			delete tail;
			head = tail = nullptr;
		}
		else
		{
			val = tail->value;
			tail = tail->prev;
			delete tail->next;
			tail->next = nullptr;
		}
	return true;
}
//-------------------------------------------------------------------------------------------------
template <typename T>
bool QueueTp<T>::isEmpty() const
{
	if (nullptr == head && nullptr == tail)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//-------------------------------------------------------------------------------------------------
template <typename T>
QueueTp<T>& QueueTp<T>::operator = (const QueueTp<T>& q)
{
	if (&q == this)
	{
		return *this;
	}

	emptyList();
	link t = q.tail;
	while (t != nullptr)
	{
		enqueue(t->value);
		t = t->prev;
	}
}

#endif
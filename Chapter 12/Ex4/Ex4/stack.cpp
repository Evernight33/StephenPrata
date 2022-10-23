// stack.cpp -- Stack member functions
#include "stack.h"
Stack::Stack(int n)    // create an empty stack
{
    if (n < 1)
    {
        cerr << "Stack can't be empty or < 0\n";
        n = 10;
    }
    top = size = 0;
    pitems = new Item[n];
}

Stack::Stack(const Stack& st)
{
    pitems = new Item[st.size];
    for (int i = 0; i < st.size; i++)
    {
        pitems[i] = (st.pitems)[i];
    }
    size = st.size;
    top = st.top;
}

bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const
{
    return top == MAX;
}

bool Stack::push(const Item& item)
{
    if (top < MAX)
    {
        pitems[top++] = item;
        return true;
    }
    else
        return false;
}

bool Stack::pop(Item& item)
{
    if (top > 0)
    {
        item = pitems[--top];
        return true;
    }
    else
        return false;
}

Stack& Stack::operator= (const Stack& st)
{
    if (&st == this)
    {
        return *this;
    }
    delete[] pitems;
    pitems = new Item[st.size];
    for (int i = 0; i < st.size; i++)
    {
        pitems[i] = (st.pitems)[i];
    }
    size = st.size;
    top = st.top;
    return *this;
}

ostream& operator<< (std::ostream& os, const Stack& s)
{
    for (int i = 0; i < s.top; i++)
    {
        os << "item" << i + 1 << ": " << (s.pitems)[i] << endl;
    }
    return os;
}

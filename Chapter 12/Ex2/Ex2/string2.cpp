// string1.cpp -- String class methods
#include <cstring>                 // string.h for some
#include "string2.h"               // includes <iostream>
using std::cin;
using std::cout;

// initializing static class member

int String::num_strings = 0;

// static method
int String::HowMany()
{
    return num_strings;
}

// class methods
String::String(const char* s)     // construct String from C string
{
    len = std::strlen(s);          // set size
    str = new char[len + 1];       // allot storage
    strcpy_s(str, len + 1, s);           // initialize pointer
    num_strings++;                 // set object count
}

String::String()                   // default constructor
{
    len = 4;
    str = new char[1];
    str[0] = '\0';                 // default string
    num_strings++;
}

String::String(const String& st)
{
    num_strings++;             // handle static member update
    len = st.len;              // same length
    str = new char[len + 1];  // allot space
    strcpy_s(str, len + 1, st.str);  // copy string to new location
}

String::~String()                     // necessary destructor
{
    --num_strings;                    // required
    delete[] str;                    // required
}

// overloaded operator methods    

    // assign a String to a String
String& String::operator=(const String& st)
{
    if (this == &st)
        return *this;
    delete[] str;
    len = st.len;
    str = new char[len + 1];
    strcpy_s(str, len + 1, st.str);
    return *this;
}

// assign a C string to a String
String& String::operator=(const char* s)
{
    delete[] str;
    len = std::strlen(s);
    str = new char[len + 1];
    strcpy_s(str, len + 1, s);
    return *this;
}

// read-write char access for non-const String
char& String::operator[](int i)
{
    return str[i];
}

// read-only char access for const String
const char& String::operator[](int i) const
{
    return str[i];
}



String operator+(const char* s1, const String& s2)
{
    String temp;
    delete[] temp.str;

    temp.len = strlen(s1) + s2.len + 1;
    temp.str = new char[temp.len];
    strcpy_s(temp.str, strlen(s1) + 1, s1);
    strcat_s(temp.str, temp.len, s2.str);
    return temp;
}

String operator+(const String& st, const String& st2)
{
    String temp;
    delete temp.str;

    temp.len = strlen(st.str) + strlen(st2.str);
    temp.str = new char[temp.len + 1];
    strcpy_s(temp.str, strlen(st.str) + 1, st.str);
    strcat_s(temp.str, temp.len + 1, st2.str);

    return temp;
}

void String::stringlow()
{
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        str[i] = tolower(str[i]);
    }
}

void String::stringup()
{
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        str[i] = toupper(str[i]);
    }
}

int String::howmany(char ch)
{
    int i = 0;
    int sum = 0;
    while (str)
    {
        if (str[i] == ch)
            sum++;
        i++;
    }
    return sum;
}

// overloaded operator friends

bool operator<(const String& st1, const String& st2)
{
    return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String& st1, const String& st2)
{
    return st2 < st1;
}

bool operator==(const String& st1, const String& st2)
{
    return (std::strcmp(st1.str, st2.str) == 0);
}

// simple String output
ostream& operator<<(ostream& os, const String& st)
{
    os << st.str;
    return os;
}

// quick and dirty String input
istream& operator>>(istream& is, String& st)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is)
        st = temp;
    while (is && is.get() != '\n')
        continue;
    return is;
}



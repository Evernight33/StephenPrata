// stonewt.cpp -- Stonewt methods
#include <iostream>
using std::cout;
#include "stonewt.h"

// construct Stonewt object from double value
Stonewt::Stonewt(double lbs, State s)
{
    switch (s)
    {
        case st:
        {
            stone = int(lbs) / Lbs_per_stn;    // integer division
            break;
        }

        case in:
        {
            pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
            break;
        }

        case fl:
        {
            pounds = lbs;
            break;
        }
    }
}

// construct Stonewt object from stone, double values
Stonewt::Stonewt(int stn, double lbs, State s)
{
    switch (s)
    {
        case st:
        {
            stone = stn;
            break;
        }
        case in:
        {
            pds_left = lbs;
            break;
        }
        case fl:
        {
            pounds = stn * Lbs_per_stn + lbs;
            break;
        }      
    }
}

Stonewt::Stonewt()          // default constructor, wt = 0
{
    stone = pounds = pds_left = 0;

}

Stonewt::~Stonewt()         // destructor
{
}

// show weight in stones
void Stonewt::show_stn() const
{
    cout << stone << " stone, " << pds_left << " pounds\n";
}

// show weight in pounds
void Stonewt::show_lbs() const
{
    cout << pounds << " pounds\n";
}

ostream& operator<<(ostream& os, Stonewt& s)
{
    os << s.stone << " stone, " << s.pds_left << " pounds\n";
    os << s.pounds << " pounds\n";
    return os;
}


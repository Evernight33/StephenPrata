// stonewt.h -- definition for the Stonewt class
#ifndef STONEWT_H_
#define STONEWT_H_
using namespace std;

enum State { st, in, fl };
class Stonewt
{
private:
    enum { Lbs_per_stn = 14 };      // pounds per stone
    int stone;                    // whole stones
    double pds_left;              // fractional pounds
    double pounds;
    // entire weight in pounds
public:
    Stonewt(double lbs, State);          // constructor for double pounds
    Stonewt(int stn, double lbs, State s); // constructor for stone, lbs
    Stonewt();                    // default constructor
    ~Stonewt();
    void show_lbs() const;        // show weight in pounds format
    void show_stn() const;      
    friend ostream& operator<<(ostream& os, Stonewt& s);
    // show weight in stone format
};
#endif

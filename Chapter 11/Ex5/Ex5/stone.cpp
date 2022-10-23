// stone.cpp -- user-defined conversions
// compile with stonewt.cpp
#include <iostream>
#include "stonewt.h"
void display(const Stonewt& st, int n);
int main()
{
    Stonewt incognito(2456, in); // uses constructor to initialize
    Stonewt wolfe(285.7, fl);    // same as Stonewt wolfe = 285.7;
    Stonewt taft(21, 8, st);
    cout << "The celebrity weighed ";
    cout << incognito;
    cout << "The detective weighed ";
    cout << wolfe;
    cout << "The President weighed ";
    taft.show_lbs();
    cout << "After dinner, the celebrity weighed ";
    incognito.show_stn();
    cout << "After dinner, the President weighed ";
    cout << taft;
    display(taft, 2);
    cout << "The wrestler weighed even more.\n";
    cout << "No stone left unearned\n";
    // std::cin.get();
    return 0;
}

void display(const Stonewt& st, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Wow! ";
        st.show_stn();
    }
}

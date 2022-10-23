#include <iostream>
#include <cmath>
#include "coordin.h"
using namespace std;

polar rect_to_polar(rect xypos)
{
	polar answer;
	answer.dis = sqrt(xypos.x * xypos.x + xypos.y * xypos.y);
	answer.ang = atan2(xypos.x, xypos.y);
	return answer;
}

void show_polar(polar dapos)
{
	const double Rad_to_deg = 57.29577951;
	cout << "distance: " << dapos.dis << endl;
	cout << "angle = " << Rad_to_deg * dapos.ang << endl;
}
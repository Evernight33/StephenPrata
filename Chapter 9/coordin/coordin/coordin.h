#ifndef COORDIN_H_
#define COORDIN_H_

struct polar
{
	double dis;
	double ang;
};

struct rect
{
	double x;
	double y;
};

polar rect_to_polar(rect xypos);
void show_polar(polar dapos);

#endif
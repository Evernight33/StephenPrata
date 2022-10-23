#ifndef FILE_H
#define FILE_H
using namespace std;


const int len = 40;
class Golf
{
private:
	char fullname[len];
	int hand;
public:
	Golf(const char* name, int hc);
	Golf();
	bool setgolf();
	void handicap(int hc);
	void showgolf();
};

#endif
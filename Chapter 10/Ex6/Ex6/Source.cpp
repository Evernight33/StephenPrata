#include <iostream>
using namespace std;

class Move
{
private:
	double x;
	double y;
public:
	Move(double a = 0, double b = 0); // ������������� �, � � �, �
	void showmove() const; // ���������� ������� �������� �, �
	Move add(const Move& m) const;
		// ��� ������� ��������� � �� m � � ����������� �������,
		// ����� �������� ����� �������� �,
		// ��������� � �� m � � ������������ �������, ����� �������� �����
		// �������� �, ����������� ������������������� ������� �������� �, �
		// � ���������� ���
	void reset(double a = 0, double b = 0); // ���������� �, � � �, �
};

int main()
{
	Move obj1(3,7);
	obj1.showmove();
	Move obj2(6, 9);
	obj2.showmove();
	Move obj3 = obj1.add(obj2);
	obj3.showmove();
	obj1.reset();
	obj1.showmove();

}

Move::Move(double a, double b) : x(a), y(b)
{}

void Move::showmove() const
{
	cout << "X: " << x << endl;
	cout << "Y: " << y << endl;
	cout << "\n";
}

Move Move::add(const Move& m) const
{
	Move obj;
	obj.x = this->x + m.x;
	obj.y = this->y + m.y;
	return obj;
}
void Move::reset(double a, double b) 
{
	x = a;
	y = b;
}
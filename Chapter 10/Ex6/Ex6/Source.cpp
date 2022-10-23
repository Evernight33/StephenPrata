#include <iostream>
using namespace std;

class Move
{
private:
	double x;
	double y;
public:
	Move(double a = 0, double b = 0); // устанавливает х, у в а, Ь
	void showmove() const; // отображает текущие значения х, у
	Move add(const Move& m) const;
		// Эта функция добавляет х из m к х вызывающего объекта,
		// чтобы получить новое значение х,
		// Добавляет у из m к у вызывакхцего объекта, чтобы получить новое
		// значение у, присваивает инициализированному объекту значения х, у
		// и возвращает его
	void reset(double a = 0, double b = 0); // сбрасывает х, у в а, Ь
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
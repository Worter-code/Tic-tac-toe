#include "x_o.h"
int point :: get_x()
{
	return x;
};
int point :: get_y()
{
	return y;
};

void point :: set_x(int new_x)
{
	x = new_x;
};

void point ::set_y(int new_y)
{
	y = new_y;
};

point :: point(int A, int B)
{
	x = A;
	y = B;
	/*cout << "Тут сработал конструктор, который принимает параметры: " << endl;
	cout << "x = " << x << endl;
	cout << "y = " << y << endl << endl;*/
}

point::point()
{
	x = 0;
	y = 0;
}
#pragma once
#include <iostream>
using namespace std;
class point
{
private:
	int x; ///координата €чеки по х
	int y;///координата €чеки по y

public:
	int get_x();
	

	int get_y();
	

	void set_x(int new_x);
	

	void set_y(int new_y);
	

	point(int A, int B);

	point();
		
};






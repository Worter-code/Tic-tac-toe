#include "cell.h"
#include "x_o.h"

int cell::get_cost()
{
	return cost;
}

void cell::set_cost(int i)
{
	this->cost = i;
}

cell::cell()
{
	set_x(0);
	set_y(0);
	set_cost(0);
}

cell::cell(int x, int y, int cost)
{
	set_x(x);
	set_y(y);
	set_cost(cost);

}


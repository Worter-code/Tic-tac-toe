#pragma once
#include <vector>
#include "x_o.h"


class cell : public point
{
	private:
		int cost;
	public:
		int get_cost();

		void set_cost(int);

		cell();

		cell(int, int, int);

			   
};
#pragma once
#include <SFML/Graphics.hpp>
#include "x_o.h"
#include "cell.h"

using namespace std;
using namespace sf;

class Functions
{
	public:
		bool Status(vector <point>);

		bool Board_cell_check(vector <point>, vector <point>, int, int); //проверка на занятость ячейки

		void Skreen_winner(char); //вывод окна о победе игрока

		point Move_board(point); //движение доски

		point AI(vector <point>, vector <point>); //действия пк

		int check_cost(vector <point>, vector <point>, cell); //проверка приоритетности клетки

		bool chek_before(vector <point>, vector <point>, point, int, int);

		bool check_in_vector(vector <point>, int, int);

};



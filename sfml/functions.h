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

		bool Board_cell_check(vector <point>, vector <point>, int, int); //�������� �� ��������� ������

		void Skreen_winner(char); //����� ���� � ������ ������

		point Move_board(point); //�������� �����

		point AI(vector <point>, vector <point>); //�������� ��

		int check_cost(vector <point>, vector <point>, cell); //�������� �������������� ������

		bool chek_before(vector <point>, vector <point>, point, int, int);

		bool check_in_vector(vector <point>, int, int);

};



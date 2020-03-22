#include "functions.h"
#include "x_o.h"
#include "cell.h"
#include <vector>
using namespace std;

bool Functions::Status(vector <point> q)
{
	////œ–Œ¬≈– ¿ Õ¿ –ﬂƒ »« œﬂ“» ›À≈Ã≈Õ“Œ¬
	for (unsigned short i = 0; i < q.size(); i++)
	{
		unsigned short up = 0, right_up_diag = 0, right = 0, right_down_diag = 0;
		for (int j = 0; j < q.size(); j++)
		{
			if (q[j].get_x() == q[i].get_x() && q[j].get_y() - q[i].get_y() <= 4 && q[j].get_y() > q[i].get_y()) up++;
			if (q[j].get_y() == q[i].get_y() && q[j].get_x() - q[i].get_x() <= 4 && q[j].get_x() > q[i].get_x()) right++;
			if (((q[j].get_x() - q[i].get_x()) == (q[i].get_y() - q[j].get_y())) && ((q[i].get_y() - q[j].get_y()) <= 4) && ((q[j].get_x() - q[i].get_x()) <= 4) && (q[j].get_x() > q[i].get_x()) && (q[i].get_y() > q[j].get_y())) right_down_diag++;
			if (((q[j].get_x() - q[i].get_x()) == (q[j].get_y() - q[i].get_y())) && ((q[j].get_y() - q[i].get_y()) <= 4) && ((q[j].get_x() - q[i].get_x()) <= 4) && (q[j].get_x() > q[i].get_x()) && (q[i].get_y() < q[j].get_y())) right_up_diag++;
			if (up == 4 || right_up_diag == 4 || right == 4 || right_down_diag == 4) return 1;
		}
	}
	return 0;
}

bool Functions::Board_cell_check(vector <point> v, vector <point> o, int x, int y)
////œ–Œ¬≈– ¿ Õ¿ «¿Õﬂ“Œ—“‹ ﬂ◊≈… »
{
	for (int i = 0; i < v.size(); i++)
		if (v[i].get_x() == x && v[i].get_y() == y) return 0;
	for (int i = 0; i < o.size(); i++)
		if (o[i].get_x() == x && o[i].get_y() == y) return 0;
	return 1;
}

void Functions::Skreen_winner(char winner)
{
	////¬€‚Ó‰ Ì‡‰ÔËÒË Ó ÔÓ·Â‰Â
	Texture winner_picture;
	if (winner == 1)
		winner_picture.loadFromFile("Images/Winner_X.png");
	else winner_picture.loadFromFile("Images/Winner_O.png");
	Sprite winner_skreen(winner_picture);
	Event event;

	RenderWindow window(VideoMode(575, 150), "Winner", Style::Close);

	while (window.isOpen())
	{
		window.draw(winner_skreen);
		window.display();
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

	};

}

point Functions::Move_board(point Board_move)
{
	
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		Board_move.set_x((Board_move.get_x() - 1));
		cout << "¬ÎÂ‚Ó" << endl;
	}

	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		Board_move.set_x((Board_move.get_x() + 1));
		cout << "¬Ô‡‚Ó" << endl;
	}

	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		Board_move.set_y((Board_move.get_y() - 1));
		cout << "¬‚Âı, ÌÓ‚ÓÂ y = " << Board_move.get_y() << endl;
	}

	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		Board_move.set_y((Board_move.get_y() + 1));
		cout << "¬ÌËÁ, ÌÓ‚ÓÂ y = " << Board_move.get_y() << endl;
	};

	return Board_move;
}


int Functions::check_cost(vector <point> x, vector <point> o, cell q)
{
	point check(q.get_x(), q.get_y());
	x.push_back(check);
	
	for (unsigned short i = 0; i < x.size(); i++)
	{
		unsigned short up = 0, right_up_diag = 0, right = 0, right_down_diag = 0;
		for (int j = 0; j < x.size(); j++)
		{
			if (x[j].get_x() == x[i].get_x() && x[i].get_y() - x[j].get_y() <= 4 && x[i].get_y() > x[j].get_y() && chek_before(x, o, x[i], 1, x[i].get_y() - x[j].get_y())) up++;
			if (x[j].get_y() == x[i].get_y() && x[j].get_x() - x[i].get_x() <= 4 && x[j].get_x() > x[i].get_x() && chek_before(x, o, x[i], 2, x[j].get_x() - x[i].get_x()) ) right++;
			if (((x[j].get_x() - x[i].get_x()) == (x[j].get_y() - x[i].get_y())) && ((x[j].get_y() - x[i].get_y()) <= 4) && ((x[j].get_x() - x[i].get_x()) <= 4) && (x[j].get_x() > x[i].get_x()) && (x[j].get_y() > x[i].get_y()) && chek_before(x, o, x[i], 3, x[j].get_x() - x[i].get_x())) right_down_diag++;
			if (((x[j].get_x() - x[i].get_x()) == (x[i].get_y() - x[j].get_y())) && ((x[i].get_y() - x[j].get_y()) <= 4) && ((x[j].get_x() - x[i].get_x()) <= 4) && (x[j].get_x() > x[i].get_x()) && (x[j].get_y() < x[i].get_y()) && chek_before(x, o, x[i], 4, x[j].get_x() - x[i].get_x())) right_up_diag++;
			if (up == 1 || right_up_diag == 1 || right == 1 || right_down_diag == 1) ;
			if (up == 2 || right_up_diag == 2 || right == 2 || right_down_diag == 2) q.set_cost(q.get_cost() + 200);
			if (up == 3 || right_up_diag == 3 || right == 3 || right_down_diag == 3) q.set_cost(q.get_cost() + 9000);
			if (up == 4 || right_up_diag == 4 || right == 4 || right_down_diag == 4) q.set_cost(q.get_cost() + 70000);
		}
	};
	x.erase(x.begin() + x.size() - 1);
	o.push_back(check);
	for (unsigned short i = 0; i < o.size(); i++)
	{
		unsigned short up = 0, right_up_diag = 0, right = 0, right_down_diag = 0;
		for (int j = 0; j < o.size(); j++)
		{
			if (o[j].get_x() == o[i].get_x() && o[i].get_y() - o[j].get_y() <= 4 && o[i].get_y() > o[j].get_y() && chek_before(o, x, o[i], 1, o[i].get_y() - o[j].get_y())) up++;
			if (o[j].get_y() == o[i].get_y() && o[j].get_x() - o[i].get_x() <= 4 && o[j].get_x() > o[i].get_x() && chek_before(o, x, o[i], 2, o[j].get_x() - o[i].get_x()) ) right++;
			if (((o[j].get_x() - o[i].get_x()) == (o[j].get_y() - o[i].get_y())) && ((o[j].get_y() - o[i].get_y()) <= 4) && ((o[j].get_x() - o[i].get_x()) <= 4) && (o[j].get_x() > o[i].get_x()) && (o[j].get_y() > o[i].get_y()) && chek_before(o, x, o[i], 3, o[j].get_x() - o[i].get_x())) right_down_diag++;
			if (((o[j].get_x() - o[i].get_x()) == (o[i].get_y() - o[j].get_y())) && ((o[i].get_y() - o[j].get_y()) <= 4) && ((o[j].get_x() - o[i].get_x()) <= 4) && (o[j].get_x() > o[i].get_x()) && (o[j].get_y() < o[i].get_y()) && chek_before(o, x, o[i], 4, o[j].get_x() - o[i].get_x())) right_up_diag++;
			
			if (up == 1 || right_up_diag == 1 || right == 1 || right_down_diag == 1) q.set_cost(q.get_cost() + 5);
			if (up == 2 || right_up_diag == 2 || right == 2 || right_down_diag == 2) q.set_cost(q.get_cost() + 4000);
			if (up == 3 || right_up_diag == 3 || right == 3 || right_down_diag == 3) q.set_cost(q.get_cost() + 20000);
			if (up == 4 || right_up_diag == 4 || right == 4 || right_down_diag == 4) q.set_cost(q.get_cost() + 999999);
		}
	};
	
	o.erase(o.begin() + o.size() - 1);
	return q.get_cost();
}

bool Functions::check_in_vector(vector <point> v, int x, int y)
{
	for (int i = 0; i < v.size(); i++)
		if (v[i].get_x() == x && v[i].get_y() == y) return 1;
	return 0;
}



bool Functions::chek_before(vector<point>now, vector<point>anower, point q, int line, int difference)
{	
	bool answer = 1;
	switch (line)
	{
		case 1:
			for (int i = difference - 1; i > 0; i--)
				if (Board_cell_check(now, anower, q.get_x(), q.get_y() - i) || check_in_vector(now, q.get_x(), q.get_y() - i)) ;
				else answer = 0;
			break;
	
		case 2:
			for (int i = difference - 1; i > 0; i--)
				if (Board_cell_check(now, anower, q.get_x() + i, q.get_y()) || check_in_vector(now, q.get_x() + i, q.get_y()));
				else answer = 0;
			break;

		case 3:
			for (int i = difference - 1; i > 0; i--)
				if (Board_cell_check(now, anower, q.get_x() + i, q.get_y() + i) || check_in_vector(now, q.get_x() + i, q.get_y() + i));
				else answer = 0;
			break;

		case 4:
			for (int i = difference - 1; i > 0; i--)
				if (Board_cell_check(now, anower, q.get_x() + i, q.get_y() - i) || check_in_vector(now, q.get_x() + i, q.get_y() - i));
				else answer = 0;
			break;

	}
	return answer;
}

point Functions::AI(vector <point> x, vector <point> o)
{
	vector <cell> cells;

	for (int i = 0; i < x.size(); i++)
	{
		if (Board_cell_check(x, o, x[i].get_x() - 1, x[i].get_y() - 1))
		{
			cell q(x[i].get_x() - 1, x[i].get_y() - 1, 0);
			q.set_cost(check_cost(x, o, q));
			cells.push_back(q);
		};
		if (Board_cell_check(x, o, x[i].get_x() - 1, x[i].get_y()))
		{
			cell q(x[i].get_x() - 1, x[i].get_y(), 0);
			q.set_cost(check_cost(x, o, q));
			cells.push_back(q);
		};
		if (Board_cell_check(x, o, x[i].get_x() - 1, x[i].get_y() + 1))
		{
			cell q(x[i].get_x() - 1, x[i].get_y() + 1, 0);
			q.set_cost(check_cost(x, o, q));
			cells.push_back(q);
		};
		if (Board_cell_check(x, o, x[i].get_x(), x[i].get_y() + 1))
		{
			cell q(x[i].get_x(), x[i].get_y() + 1, 0);
			q.set_cost(check_cost(x, o, q));
			cells.push_back(q);
		};
		if (Board_cell_check(x, o, x[i].get_x() + 1, x[i].get_y() + 1))
		{
			cell q(x[i].get_x() + 1, x[i].get_y() + 1, 0);
			q.set_cost(check_cost(x, o, q));
			cells.push_back(q);
		};
		if (Board_cell_check(x, o, x[i].get_x() + 1, x[i].get_y()))
		{
			cell q(x[i].get_x() + 1, x[i].get_y(), 0);
			q.set_cost(check_cost(x, o, q));
			cells.push_back(q);
		};
		if (Board_cell_check(x, o, x[i].get_x() + 1, x[i].get_y() - 1))
		{
			cell q(x[i].get_x() + 1, x[i].get_y() - 1, 0);
			q.set_cost(check_cost(x, o, q));
			cells.push_back(q);

		};
		if (Board_cell_check(x, o, x[i].get_x(), x[i].get_y() - 1))
		{
			cell q(x[i].get_x(), x[i].get_y() - 1, 0);
			q.set_cost(check_cost(x, o, q));
			cells.push_back(q);

		};
	};
	for (int i = 0; i < o.size(); i++)
	{
		if (Board_cell_check(x, o, o[i].get_x() - 1, o[i].get_y() - 1))
		{
			cell q(o[i].get_x() - 1, o[i].get_y() - 1, 0);
			q.set_cost(check_cost(x, o, q));
			cells.push_back(q);
		};
		if (Board_cell_check(x, o, o[i].get_x() - 1, o[i].get_y()))
		{
			cell q(o[i].get_x() - 1, o[i].get_y(), 0);
			q.set_cost(check_cost(x, o, q));
			cells.push_back(q);
		};
		if (Board_cell_check(x, o, o[i].get_x() - 1, o[i].get_y() + 1))
		{
			cell q(o[i].get_x() - 1, o[i].get_y() + 1, 0);
			q.set_cost(check_cost(x, o, q));
			cells.push_back(q);
		};
		if (Board_cell_check(x, o, o[i].get_x(), o[i].get_y() + 1))
		{
			cell q(o[i].get_x(), o[i].get_y() + 1, 0);
			q.set_cost(check_cost(x, o, q));
			cells.push_back(q);
		};
		if (Board_cell_check(x, o, o[i].get_x() + 1, o[i].get_y() + 1))
		{
			cell q(o[i].get_x() + 1, o[i].get_y() + 1, 0);
			q.set_cost(check_cost(x, o, q));
			cells.push_back(q);
		};
		if (Board_cell_check(x, o, o[i].get_x() + 1, o[i].get_y()))
		{
			cell q(o[i].get_x() + 1, o[i].get_y(), 0);
			q.set_cost(check_cost(x, o, q));
			cells.push_back(q);
		};
		if (Board_cell_check(x, o, o[i].get_x() + 1, o[i].get_y() - 1))
		{
			cell q(o[i].get_x() + 1, o[i].get_y() - 1, 0);
			q.set_cost(check_cost(x, o, q));
			cells.push_back(q);

		};
		if (Board_cell_check(x, o, o[i].get_x(), o[i].get_y() - 1))
		{
			cell q(o[i].get_x(), o[i].get_y() - 1, 0);
			q.set_cost(check_cost(x, o, q));
			cells.push_back(q);

		};
	};
	int max_cost = 0;
	for (int i = 0; i < cells.size(); i++)
		if (cells[i].get_cost() > max_cost) max_cost = cells[i].get_cost();
	int j = 0;
	point a;
	for (int i = 0; i < cells.size(); i++)
		if (cells[i].get_cost() == max_cost && j == 0)
		{

			a.set_x(cells[i].get_x());
			a.set_y(cells[i].get_y());
			j++;
		};
	
	return a;
}


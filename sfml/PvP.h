#pragma once
#include "functions.h"
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "x_o.h"

using namespace sf;
using namespace std;

/////////////////PLAYER_VS_PLAYER///////////////////////
void PvP()
{
	Functions optional;
	vector <point> x;
	vector <point> o;
	bool Game_status = 1, turn = 0;
	char winner = 0;
	point Board_move(500, 500);
	
	Texture x_texture, o_texture;
	x_texture.loadFromFile("Images/X.png");
	o_texture.loadFromFile("Images/O.png");
	Sprite x_draw(x_texture), o_draw(o_texture);

	RenderWindow window(VideoMode(895, 895), "PvP", Style::Close);
	window.clear(Color::Black);
	RectangleShape square(Vector2f(25,25));
	
	

	while (window.isOpen())
	{
		for (int y = 0; y < 895 ; y += 29 )
			for (int x = 0; x < 895; x += 29)
			{
				square.setPosition(x, y);
				window.draw(square);
			};
			// проверить все события окна, которые были вызваны с последней итерации цикла
		Event event;
		while (window.pollEvent(event))
		{
			
			if (Game_status)
			{	///////Движение поля
				Board_move = optional.Move_board(Board_move);

				if (Mouse::isButtonPressed(Mouse::Left))
				{
					Vector2f mouse_position = window.mapPixelToCoords(Mouse::getPosition(window));
					int x_map = mouse_position.x / 29;
					int y_map = mouse_position.y / 29;
					if (optional.Board_cell_check(x, o, Board_move.get_x() + x_map, Board_move.get_y() + y_map) && x_map <= 30 && x_map >= 0 && y_map >= 0 && y_map <= 30)
						if (turn)
						{


							point a(Board_move.get_x() + x_map, Board_move.get_y() + y_map);
							o.push_back(a);
							turn = 0;
							Game_status -= optional.Status(o);
							if (optional.Status(o)) winner = 2; ///////// PLAYER_0_WINS


						}
						else
						{
							
							point b(Board_move.get_x() + x_map, Board_move.get_y() + y_map);
							x.push_back(b);
							turn = 1;
							Game_status -= optional.Status(x);
							if (optional.Status(x)) winner = 1;   ///////// PLAYER_X_WINS
						};
				};
				
			};
			//ОТРИСОВКА МАРКЕРОВ
			for (int i = 0; i < x.size(); i++)
				if (x[i].get_x() <= Board_move.get_x() + 30 && x[i].get_x() >= Board_move.get_x() && x[i].get_y() <= Board_move.get_y() + 30 && x[i].get_y() >= Board_move.get_y())
				{
					x_draw.setPosition((x[i].get_x() - Board_move.get_x()) * 29, (x[i].get_y() - Board_move.get_y()) * 29);
					window.draw(x_draw);
				};

			for (int i = 0; i < o.size(); i++)
				if (o[i].get_x() <= Board_move.get_x() + 30 && o[i].get_x() >= Board_move.get_x() && o[i].get_y() <= Board_move.get_y() + 30 && o[i].get_y() >= Board_move.get_y())
				{
					o_draw.setPosition((o[i].get_x() - Board_move.get_x()) * 29, (o[i].get_y() - Board_move.get_y()) * 29);
					window.draw(o_draw);
				};
			window.display();
			switch (winner)
			{
			case 1:
				optional.Skreen_winner(winner);
				window.close();//////ВЫВОД НАДПИСИ О ПОБЕДЕ ПЕРВОГО ИГРОКА
				break;
			case 2:
				optional.Skreen_winner(winner);
				window.close();//////ВЫВОД НАДПИСИ О ПОБЕДЕ ВТОРОГО ИГРОКА
				break;
			default:
				break;

			}
			

			// "запрос закрытия" событие: мы закрываем окно
			if (event.type == Event::Closed)
				window.close();
			
		}
	}
}

	

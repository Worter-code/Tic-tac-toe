#pragma once
#include <SFML/Graphics.hpp>
#include "PvP.h"
#include "PvE.h"
using namespace std;
using namespace sf;


void menu(RenderWindow & window) {
	Texture menuTexture1, menuTexture2, menuTexture3, menuBackground, skobkiTexture;
	Image menu_1, menu_2, menu_3, skobki;
	menu_1.loadFromFile("Images/1_player.png");
	menu_2.loadFromFile("Images/2_players.png");
	menu_3.loadFromFile("Images/Exit.png");
	skobki.loadFromFile("Images/skobki.png");
	menu_1.createMaskFromColor(Color::White);
	menu_2.createMaskFromColor(Color::White);
	menu_3.createMaskFromColor(Color::White);
	skobki.createMaskFromColor(Color::White);
	skobkiTexture.loadFromImage(skobki);
	menuTexture1.loadFromImage(menu_1);
	menuTexture2.loadFromImage(menu_2);
	menuTexture3.loadFromImage(menu_3);
	menuBackground.loadFromFile("Images/Back.png");
	Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), menuBg(menuBackground), skobki_sprite(skobkiTexture);

	menu1.setPosition(309, 200);
	menu2.setPosition(300, 350);
	menu3.setPosition(325, 500);
	skobki_sprite.setPosition(245, 5000);

	int menuNum = 0;

	/////MENU/////
	while (window.isOpen())
	{
		Event event;
		menu1.setColor(Color::White);
		menu2.setColor(Color::White);
		menu3.setColor(Color::White);
		menuNum = 0;
		while (window.pollEvent(event))
		{
			// "запрос закрытия" событие: мы закрываем окно
			if (event.type == Event::Closed)
				window.close();
			if (IntRect(309, 200, 300, 50).contains(Mouse::getPosition(window)))
			{

				skobki_sprite.setPosition(245, 200);

				menuNum = 1;
			}

			if (IntRect(300, 350, 189, 45).contains(Mouse::getPosition(window)))
			{
				skobki_sprite.setPosition(245, 350);
				menuNum = 2;
			}

			if (IntRect(325, 500, 139, 41).contains(Mouse::getPosition(window)))
			{

				skobki_sprite.setPosition(245, 500);
				menuNum = 3;
			}

			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (menuNum == 1)
				{
					window.close();
					PvE();
					RenderWindow window(VideoMode(789, 786), "Tic Tac Toe", Style::Close);
					menu(window);
				}
				//if (menuNum == 2) { window.draw(about); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape)); }
				if (menuNum == 2)
				{
					window.close();
					PvP();
					RenderWindow window(VideoMode(789, 786), "Tic Tac Toe", Style::Close);
					menu(window);
				}

				if (menuNum == 3)
				{
					window.close();
				}
			}
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.draw(menuBg);
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);
		window.draw(skobki_sprite);
		window.display();
	}
	/////END_MENU/////
}
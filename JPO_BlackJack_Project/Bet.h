#pragma once

#include<SFML/Graphics.hpp>
#include <time.h>

#define DELETE_KEY 8 

class TextBox {
	void add(int value) {
		betValue = betValue * 10 + value;
	}
	void deleteLastNum() {
		betValue /= 10;
	}
public:
	sf::Text balanceBet;
	int betValue = 0;
	std::string h;
	void input(sf::Event input, bool enable) {
		if (enable == true) {
			int charType = input.text.unicode;
			if (charType <= 57 and charType >= 48) {
				switch (charType) {
				case 48: {
					add(0);
					break;
				}
				case 49: {
					add(1);
					break;
				}
				case 50: {
					add(2);
					break;
				}
				case 51: {
					add(3);
					break;
				}
				case 52: {
					add(4);
					break;
				}
				case 53: {
					add(5);
					break;
				}
				case 54: {
					add(6);
					break;
				}
				case 55: {
					add(7);
					break;
				}
				case 56: {
					add(8);
					break;
				}
				case 57: {
					add(9);
					break;
				}
				}
			}
			if (betValue > 0 and charType == DELETE_KEY) {
				deleteLastNum();
			}
		}
	}
	void drawBetBar(sf::RenderWindow& window) {
		sf::Font font;
		font.loadFromFile("fonts/Arial.ttf");
		balanceBet.setFont(font);
		balanceBet.setOutlineColor(sf::Color::Black);
		balanceBet.getOutlineThickness();
		balanceBet.setPosition(30, 545);
		balanceBet.setCharacterSize(35);
		h = "Bet value: " + std::to_string(betValue);
		balanceBet.setString(h);
		window.draw(balanceBet);
	}

	void addButton(int num) {
		betValue += num;
	}
};

#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
class button
{
public:
	button(std::string t);
	void setFont(sf::Font& font);
	void setPosition(sf::Vector2f pos);
	void drawTo(sf::RenderWindow& window);
	bool isMouseOver(sf::RenderWindow& window);
	void setBackColor(sf::Color color);
private:
	sf::RectangleShape m_button;
	sf::Text text;
};


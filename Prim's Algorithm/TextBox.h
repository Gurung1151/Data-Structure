#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include<sstream>

#define Delete_Key 8
#define Enter_Key 13
#define Escape_Key 27


class TextBox
{
public:
	TextBox(bool sel);

	void setFont(sf::Font& font);
	
	void setPosition(sf::Vector2f pos);

	void setSelected(bool sel);

	std::string getText();

	void drawto(sf::RenderWindow &window);

	void TypeOn(sf::Event input);


private:
	sf::Text textbox;
	std::ostringstream text;
	bool isSelected = false;


	void InputLogic(int charTyped);
	void DeleteLastChar();
};


#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

class nodes
{
public:
	nodes() {}
	void CreateNode(sf::Vector2f pos, sf::Texture &texture);
	void draw(sf::RenderWindow& window);
private:
	sf::CircleShape circle;
	sf::Text text;
};
#include "Node.h"

void nodes::CreateNode(sf::Vector2f pos, sf::Texture &texture)
{
	circle.setRadius(30);
	circle.setPosition(pos);
	circle.setTexture(&texture);
	
}

void nodes::draw(sf::RenderWindow& window)
{
	window.draw(circle);
	window.draw(text);
}

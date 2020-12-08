#include "button.h"

button::button(std::string t)
{
	m_button.setSize(sf::Vector2f(120.0, 50.0));
	m_button.setFillColor(sf::Color::Red);

	text.setString(t);
	text.setFillColor(sf::Color::Black);
	text.setCharacterSize(24);
}

void button::setFont(sf::Font& font)
{
	text.setFont(font);
}

void button::setPosition(sf::Vector2f pos)
{
	m_button.setPosition(pos);
	float xPos = (pos.x + m_button.getLocalBounds().width / 2) - (text.getLocalBounds().width / 2);
	float yPos = (pos.y + m_button.getLocalBounds().height / 3) - (text.getLocalBounds().height / 3);
	text.setPosition(xPos, yPos);
}

void button::drawTo(sf::RenderWindow& window)
{
	window.draw(m_button);
	window.draw(text);
}

bool button::isMouseOver(sf::RenderWindow& window)
{
	float MousePosX = sf::Mouse::getPosition(window).x;
	float MousePosY = sf::Mouse::getPosition(window).y;

	float btnPosX = m_button.getPosition().x;
	float btnPosY = m_button.getPosition().y;

	float btnPosXwidth = m_button.getPosition().x + m_button.getLocalBounds().width;
	float btnPosXheight = m_button.getPosition().y + m_button.getLocalBounds().height;

	if (MousePosX > btnPosX && MousePosX<btnPosXwidth && MousePosY>btnPosY && MousePosY < btnPosXheight)
	{
		return true;
	}

	return false;
}

void button::setBackColor(sf::Color color)
{
	m_button.setFillColor(color);
}

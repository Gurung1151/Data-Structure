#include "TextBox.h"

TextBox::TextBox(bool sel)
{

	textbox.setCharacterSize(24);
	textbox.setFillColor(sf::Color::White);
	isSelected=sel;
	if (sel)
	{
		textbox.setString("_");
	}
	else
	{
		textbox.setString("");
	}
}

void TextBox::setFont(sf::Font& font)
{
	textbox.setFont(font);
}

void TextBox::setPosition(sf::Vector2f pos)
{
	textbox.setPosition(pos);
	
}

void TextBox::setSelected(bool sel)
{
	isSelected = sel;
	if (!sel)
	{
		std::string t = text.str();
		std::string newT = "";
		for (int i = 0; i < t.length(); i++)
		{
			newT += t[i];
		}
		textbox.setString(newT);
	}
}

std::string TextBox::getText()
{
	return text.str();
}

void TextBox::drawto(sf::RenderWindow& window)
{
	window.draw(textbox);

}

void TextBox::TypeOn(sf::Event input)
{
	if (isSelected)
	{
		int charTyped = input.text.unicode;
		if (charTyped < 128)
		{
			InputLogic(charTyped);
		}
	}
}




void TextBox::InputLogic(int charTyped)
{
	if (charTyped != Delete_Key && charTyped != Enter_Key && charTyped != Escape_Key)
	{
		text << static_cast<char>(charTyped);
	}
	else if (charTyped==Delete_Key)
	{
		if(text.str().length()>0)
		DeleteLastChar();
	}
	textbox.setString(text.str()+"_");
}

void TextBox::DeleteLastChar()
{
	std::string t = text.str();
	std::string newT = "";
	for (int i = 0; i < t.length() - 1; i++)
	{
		newT += t[i];
	}
	text.str("");
	text << newT;
	textbox.setString(text.str());
}


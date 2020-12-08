#include<iostream>
#include<SFML\Graphics.hpp>
#include<chrono>
#include"button.h"

const int arrsize = 15;
sf::RenderWindow window(sf::VideoMode(720, 720), "circle", sf::Style::Default);

sf::Texture texture;

struct bar
{
	sf::RectangleShape rect;
	int rect_height;
};
bar graph[arrsize];

void Swap(int i, int j)
{
	int temp = graph[i].rect_height;
	graph[i].rect_height = graph[j].rect_height;
	graph[j].rect_height = temp;

	sf::Vector2f firstValue = graph[i].rect.getSize();
	sf::Vector2f secondValue = graph[j].rect.getSize();
	graph[i].rect.setSize(secondValue);
	graph[i].rect.setOrigin(10, graph[i].rect.getSize().y);
	graph[j].rect.setSize(firstValue);
	graph[j].rect.setOrigin(10, graph[j].rect.getSize().y);

}



void randomize()
{
	unsigned int seed = (unsigned)time(NULL);
	srand(seed);
	texture.loadFromFile("assets/texture.jpg");
	for (int i = 0; i < arrsize; i++)
	{
		graph[i].rect_height = rand() % 600;
		graph[i].rect.setPosition(sf::Vector2f(50*i,600));
		graph[i].rect.setSize(sf::Vector2f(10, graph[i].rect_height));
		//graph[i].rect.setFillColor(sf::Color::Green);
		graph[i].rect.setTexture(&texture);
		graph[i].rect.setOrigin(sf::Vector2f(10, graph[i].rect.getSize().y));
	}
	for (int k = 0; k < arrsize; k++)
	{
	
		int r = k + rand() % (arrsize - k); // careful here!
		Swap(k, r);
	}

}




void bubbleSort()
{
	for (int i = 0; i < arrsize - 1; i++)
	{
		for (int j = 0; j < arrsize - 1 - i; j++)
		{
			if (graph[j + 1].rect_height < graph[j].rect_height)
			{
				Swap(j, j + 1);
				window.draw(graph[i].rect);
			}
		}
	}
}



int main()
{
	
	sf::Font font;
	font.loadFromFile("assets/arial.ttf");

	button btn1("SORT"), btn2("SHUFFLE");
	btn1.setFont(font);
	btn2.setFont(font);
	btn1.setPosition(sf::Vector2f(10,640));
	btn2.setPosition(sf::Vector2f(200, 640));
	
	sf::Texture bgGround;
	bgGround.loadFromFile("assets/bamboo.jpg");

	sf::RectangleShape box;
	box.setSize(sf::Vector2f(720, 600));
	box.setTexture(&bgGround);
	//box.setFillColor(sf::Color::White);
	
	
	
    randomize();
	


	while (window.isOpen())
	{
		sf::Event e;
		while (window.pollEvent(e)) {
			switch (e.type)
			{
			case sf::Event::Closed:
				window.close();
			case sf::Event::MouseMoved:
				if (btn1.isMouseOver(window))
				{
					btn1.setBackColor(sf::Color::Green);

				}
				else
				{
					btn1.setBackColor(sf::Color::Red);
				}
				
				if (btn2.isMouseOver(window))
				{
					btn2.setBackColor(sf::Color::Green);

				}
				else
				{
					btn2.setBackColor(sf::Color::Red);
				}
				case sf::Event::MouseButtonPressed:
					if (btn1.isMouseOver(window) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
					{
						bubbleSort();
					}
					if (btn2.isMouseOver(window) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
					{
						randomize();
					}
			}
		}
		window.draw(box);
		btn1.drawTo(window);
		btn2.drawTo(window);
		for (int i=0;i<arrsize;i++)
		{
			window.draw(graph[i].rect);
		}
		window.display();
	}
	return 0;
}
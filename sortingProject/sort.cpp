#include "sort.h"
sort::sort()
{
	randomize();

	sf::RectangleShape box;
	box.setSize(sf::Vector2f(720, 600));
	box.setFillColor(sf::Color::White);


}
void sort::SwapValues(int i, int j)
{
	int temp = graph[i].rect_height;
	graph[i].rect_height = graph[j].rect_height;
	graph[j].rect_height = temp;

}

void sort::swapRectangles(int i, int j)
{
	graph[i].rect.setSize(graph[j].rect.getSize());
	graph[i].rect.setOrigin(0, graph[i].rect.getSize().y);
	graph[j].rect.setSize(graph[i].rect.getSize());
	graph[j].rect.setOrigin(0, graph[j].rect.getSize().y);
}

void sort::randomize()
{
	unsigned int seed = (unsigned)time(NULL);
	srand(seed);
	for (int i = 0; i < arrsize; i++)
	{
		graph[i].rect_height = rand() % 600;
		graph[i].rect.setPosition(sf::Vector2f(10 * i, 600));
		graph[i].rect.setSize(sf::Vector2f(8, graph[i].rect_height));
		graph[i].rect.setFillColor(sf::Color::Magenta);
		graph[i].rect.setOrigin(sf::Vector2f(0, graph[i].rect.getSize().y));
	}
	for (int k = 0; k < arrsize; k++)
	{

		int r = k + rand() % (arrsize - k); // careful here!
		SwapValues(k, r);
		//SwapRectangle(k, r);
	}

}

void sort::Selectionsort()
{
	if (start == false)
	{
		prevCount = 0;          //Main Iterator (For Pivot)
		key = 0;       //Returns smallest element
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
			start = true;
	}

	if (start == true && prevCount < arrsize)
	{
		int i, j, min_idx;

		// Find the minimum element in unsorted array  
		min_idx = prevCount;
		for (j = prevCount + 1; j < arrsize; j++)
			if (graph[j].rect_height < graph[min_idx].rect_height)
				min_idx = j;

		// Swap the found minimum element with the first element  
		SwapValues(min_idx, prevCount);
		//SwapRectangle(min_idx, prevCount);
		key = min_idx;
		//CHART[min_idx].rect.setFillColor(sf::Color::Red);
		//CHART[prevCount].rect.setFillColor(sf::Color::Red);
		prevCount++;

	}
	draw();
}

void sort::draw()
{
	sf::RectangleShape box;
	box.setSize(sf::Vector2f(720, 600));
	box.setFillColor(sf::Color::White);

	window.draw(box);
	for (int i = 0; i < arrsize; i++)
	{
		
		
		if (i == prevCount || i == key)
		{
			graph[i].rect.setFillColor(sf::Color::Cyan);
		}
		else
		{
			graph[i].rect.setFillColor(sf::Color::Magenta);
		}
		
		window.draw(graph[i].rect);
	}
	
}

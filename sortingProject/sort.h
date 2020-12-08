#pragma once
#include<SFML/Graphics.hpp>
#include"Header.h"

;
struct bar
{
	sf::RectangleShape rect;
	int rect_height;
};


class sort
{
private:
	bool start = false;
	static const int arrsize = 128;
	//TO swap
	int count, prevCount, key;
	bool swapping = false;
	
	bar graph[arrsize];
public:
	sort();
	void SwapValues(int i, int j);
	void swapRectangles(int i, int j);
	void randomize();
	void Selectionsort();
	void draw();
};


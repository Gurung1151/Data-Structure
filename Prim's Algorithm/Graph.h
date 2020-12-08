#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include"button.h"
#include"Node.h"

#define V 8

class Graph
{
public:
	Graph(){}
	void findMst(int graph[V][V]);
	int min_key(int key[],bool mstSet[]);
	void updateGraph(int parent[],int graph[V][V],sf::RectangleShape rect[V][V]);
	void start();
	void title(sf::RenderWindow &window);
	sf::RectangleShape rect[V][V];
	sf::Text weight[V][V];
};
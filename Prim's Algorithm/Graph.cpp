#include "Graph.h"

int Graph::min_key(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void Graph::updateGraph(int parent[], int graph[V][V], sf::RectangleShape rect[V][V])
{
    std::cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
    {
        std::cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
        rect[parent[i]][i].setFillColor(sf::Color::Green);
    }
}

void Graph::title(sf::RenderWindow &window)
{
    sf::Font titleFont;
    titleFont.loadFromFile("dragon.ttf");
    sf::Text title1;
    title1.setFont(titleFont);
    title1.setPosition(10, 20);
    title1.setString("PRIM'S ALGORITHM");
    title1.setCharacterSize(100);
    title1.setFillColor(sf::Color::White);

    window.draw(title1);

}

void Graph::start()
{
    int graph[V][V] = { { 0, 2, 0, 0, 0, 7, 0, 0 },
                        { 2, 0, 4, 0, 3, 5, 0, 0 },
                        { 0, 4, 0, 6, 0, 0, 9, 0 },
                        { 0, 0, 6, 0, 11, 0, 2, 8 },
                        { 0, 3, 0, 11, 0, 3, 0, 0 },
                        { 7, 5, 0, 0, 3, 0, 0, 0 },
                        { 0, 0, 9, 2, 0, 0, 0, 7 }, 
                        { 0, 0, 0, 8, 0, 0, 7, 0 }, };


    sf::RenderWindow window(sf::VideoMode(720, 720), "tree", sf::Style::Default);

    sf::Texture background;
    background.loadFromFile("assets/background.jpg");
    sf::Sprite bground(background);

    sf::Font font;
    font.loadFromFile("arial.ttf");
    

   
    sf::Texture texture[V];
    texture[0].loadFromFile("assets/goku.png");
    texture[1].loadFromFile("assets/1.png");
    texture[2].loadFromFile("assets/2.png");
    texture[3].loadFromFile("assets/3.png");
    texture[4].loadFromFile("assets/4.png");
    texture[5].loadFromFile("assets/5.png");
    texture[6].loadFromFile("assets/6.png");
    texture[7].loadFromFile("assets/7.png");

    //button
    button btn1("start");
   
    btn1.setFont(font);
    btn1.setPosition(sf::Vector2f(500, 500));

    nodes circles[V];
    circles[0].CreateNode(sf::Vector2f(100, 360),texture[0]);
    circles[1].CreateNode(sf::Vector2f(200, 200), texture[1]);
    circles[2].CreateNode(sf::Vector2f(400, 200), texture[2]);
    circles[3].CreateNode(sf::Vector2f(400, 360), texture[3]);
    circles[4].CreateNode(sf::Vector2f(400, 520), texture[4]);
    circles[5].CreateNode(sf::Vector2f(200, 520), texture[5]);
    circles[6].CreateNode(sf::Vector2f(600, 200), texture[6]);
    circles[7].CreateNode(sf::Vector2f(600, 360), texture[7]);


    rect[1][2].setSize(sf::Vector2f(140, 5));
    rect[1][2].setPosition(sf::Vector2f(260, 230));
    weight[1][2].setPosition(sf::Vector2f(320,200));
    weight[1][2].setFont(font);
    weight[1][2].setCharacterSize(20);
    weight[1][2].setString("4");
    
    rect[2][3].setSize(sf::Vector2f(5, 100));
    rect[2][3].setPosition(sf::Vector2f(430, 260));
    weight[2][3].setPosition(sf::Vector2f(450, 300));
    weight[2][3].setFont(font);
    weight[2][3].setCharacterSize(20);
    weight[2][3].setString("6");
    

    rect[3][4].setSize(sf::Vector2f(5, 100));
    rect[3][4].setPosition(sf::Vector2f(430, 420));
    weight[3][4].setPosition(sf::Vector2f(450, 460));
    weight[3][4].setFont(font);
    weight[3][4].setCharacterSize(20);
    weight[3][4].setString("11");
 
    rect[4][5].setSize(sf::Vector2f(140, 5));
    rect[4][5].setPosition(sf::Vector2f(260, 550));
    weight[4][5].setPosition(sf::Vector2f(320, 520));
    weight[4][5].setFont(font);
    weight[4][5].setCharacterSize(20);
    weight[4][5].setString("3");
    
   rect[5][1].setSize(sf::Vector2f(5, 260));
    rect[5][1].setPosition(sf::Vector2f(230, 260));
    weight[5][1].setPosition(sf::Vector2f(250, 400));
    weight[5][1].setFont(font);
    weight[5][1].setCharacterSize(20);
    weight[5][1].setString("5");
    

    rect[0][1].setSize(sf::Vector2f(5, 140));
    rect[0][1].setPosition(sf::Vector2f(200, 240));
    rect[0][1].setRotation(30);
    weight[0][1].setPosition(sf::Vector2f(180, 280));
    weight[0][1].setFont(font);
    weight[0][1].setCharacterSize(20);
    weight[0][1].setString("2");
    
    rect[0][5].setSize(sf::Vector2f(5, 140));
    rect[0][5].setPosition(sf::Vector2f(130, 420));
    rect[0][5].setRotation(-30);
    weight[0][5].setPosition(sf::Vector2f(180, 480));
    weight[0][5].setFont(font);
    weight[0][5].setCharacterSize(20);
    weight[0][5].setString("7");
    
    rect[1][4].setSize(sf::Vector2f(5, 320));
    rect[1][4].setPosition(sf::Vector2f(250, 250));
    rect[1][4].setRotation(-30);
    weight[1][4].setPosition(sf::Vector2f(320, 320));
    weight[1][4].setFont(font);
    weight[1][4].setCharacterSize(20);
    weight[1][4].setString("3");
    
    rect[2][6].setSize(sf::Vector2f(140, 5));
    rect[2][6].setPosition(sf::Vector2f(460, 230));
    weight[2][6].setPosition(sf::Vector2f(460, 200));
    weight[2][6].setFont(font);
    weight[2][6].setCharacterSize(20);
    weight[2][6].setString("9");

    rect[3][7].setSize(sf::Vector2f(140, 5));
    rect[3][7].setPosition(sf::Vector2f(460, 390));
    weight[3][7].setPosition(sf::Vector2f(520, 400));
    weight[3][7].setFont(font);
    weight[3][7].setCharacterSize(20);
    weight[3][7].setString("8");

    rect[6][7].setSize(sf::Vector2f(5, 100));
    rect[6][7].setPosition(sf::Vector2f(630, 260));
    weight[6][7].setPosition(sf::Vector2f(650, 300));
    weight[6][7].setFont(font);
    weight[6][7].setCharacterSize(20);
    weight[6][7].setString("7");

    rect[3][6].setSize(sf::Vector2f(5, 205));
    rect[3][6].setPosition(sf::Vector2f(605, 240));
    rect[3][6].setRotation(50);
    weight[3][6].setPosition(sf::Vector2f(560, 280));
    weight[3][6].setFont(font);
    weight[3][6].setCharacterSize(20);
    weight[3][6].setString("2");


    while (window.isOpen())
    {
        sf::Event e;
        
        while (window.pollEvent(e))
        {
            switch (e.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseMoved:
                if (btn1.isMouseOver(window))
                {
                    btn1.setBackColor(sf::Color::Green);
                }
                else
                {
                    btn1.setBackColor(sf::Color::Red);
                }
            case sf::Event::MouseButtonPressed:
                if (btn1.isMouseOver(window) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                {
                    findMst(graph);
                }

            }
        }
        window.clear();
        //drawing button
        window.draw(bground);
        title(window);
        btn1.drawTo(window);
        
        //drawing nodes
        for (int i = 0; i < V; i++)
        {
            circles[i].draw(window);

        }
        //drawing edges
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                window.draw(rect[i][j]);
                window.draw(weight[i][j]);
            }
        }

        window.display();
    }
}

void Graph::findMst(int graph[V][V])
{
	int parent[V];
	bool mstSet[V];
	int key[V];

	for (int i=0;i<V;i++)
	{
		key[i] = INT_MAX, mstSet[i] = false;
	}
    key[0] = 0;
    parent[0] = -1; // First node is always root of MST  

    // The MST will have V vertices  
    for (int count = 0; count < V - 1; count++)
    {
        int u = min_key(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
            {
                parent[v] = u, key[v] = graph[u][v];
            }
        }
    }
    
    updateGraph(parent,graph,rect);
}


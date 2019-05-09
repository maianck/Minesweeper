void showGameWindow() {
    length = 15, height = 15;
    numBomb = 20;
    w = 32;
    RenderWindow window(sf::VideoMode((length+2)*w, (height+2)*w), "Minesweeper", sf::Style::Default);

    Texture t;
    t.loadFromFile("images/tiles.jpg");
    Sprite s;
    s.setTexture(t);

    createGrid();
    setShow();
    while (window.isOpen())
    {
        Vector2i pos = Mouse::getPosition(window);
        int x = pos.x/w;
        int y = pos.y/w;
        Event event;
        while (window.pollEvent(event))
        {
            if(event.type == Event::Closed) window.close(),showPlayWindow();
            if(event.type == Event::MouseButtonPressed) {
                if(event.mouseButton.button == Mouse::Left) show[x][y] = grid[x][y];
                else if(event.mouseButton.button == Mouse::Right) {
                    if(show[x][y]==10) show[x][y] = 11;
                    else if(show[x][y]==11) show[x][y] = 10;
                }
            }
        }
        if(show[x][y]==0) extend(x,y);

        window.clear(Color(200,0,0));
        for(int i=1;i<=length;++i)
        for(int j=1;j<=height;++j) {
            if(show[x][y]==9) show[i][j] = grid[i][j];
            s.setTextureRect(IntRect(show[i][j]*w,0,w,w));
            s.setPosition(i*w,j*w);
            window.draw(s);
        }
        window.display();
    }
}

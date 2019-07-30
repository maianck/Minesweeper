void showRankWindow() {
    RenderWindow mainW(sf::VideoMode(707, 437), "Minesweeper", sf::Style::Default);
    Texture t1;
    Sprite s1;
    Font font;
    if (!font.loadFromFile("visitor1.ttf"))
    {
        std::cout<<"Can't load visitor1.ttf";
    }
    Text number;
    number.setFont(font);
    number.setCharacterSize(30);
    number.setFillColor(sf::Color::Red);

    std::string file;

    while (mainW.isOpen()) {
        Vector2i pos = Mouse::getPosition(mainW);
        int xB = 37, yB = 19, x1B = 176, y1B = 67;
        int xM = 264, yM = 17, x1M = 417, y1M = 68;
        int xA = 503, yA = 15, x1A = 654, y1A = 67;
        Event event;
        while(mainW.pollEvent(event)) {
            if(event.type == Event::Closed) mainW.close(),showMainWindow();
            if(event.type == Event::MouseButtonPressed) {
                if(event.mouseButton.button == Mouse::Left) {
                    //rank beginner
                    if(inside(pos.x,pos.y,xB,yB,x1B,y1B)) {
                        file = "beginner.txt";
                    }
                    //rank medium
                    if(inside(pos.x,pos.y,xM,yM,x1M,y1M)) {
                        file = "medium.txt";
                    }
                    //rank advance
                    if(inside(pos.x,pos.y,xA,yA,x1A,y1A)) {
                        file = "advance.txt";
                    }
                }
            }
        }
        mainW.clear(Color(255,105,180));
        t1.loadFromFile("images/rank.png");
        s1.setTexture(t1);
        s1.setPosition(0,0);
        mainW.draw(s1);

        std::ifstream input;
        input.open(file);
        int n;
        input>>n;
        for(int i=1;i<=n;++i) {
            int u;
            input>>u;
            number.setString(std::to_string(i)+"\t"+std::to_string(u));
            number.setPosition(250, 150+i*40);
            mainW.draw(number);
        }

        mainW.display();
    }
}

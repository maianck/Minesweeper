//hiển thị màn hình đầu tiên
void showMainWindow() {
    RenderWindow mainW(sf::VideoMode(870, 510), "Minesweeper", sf::Style::Default);
    Texture t,t1;
    Sprite s,s1;
    while (mainW.isOpen()) {
        Vector2i pos = Mouse::getPosition(mainW);
        int xPlay = 541, yPlay = 106, x1Play = 750, y1Play = 154;
        int xRank = 540, yRank = 214, x1Rank = 752, y1Rank = 262;
        int xExit = 544, yExit = 327, x1Exit = 746, y1Exit = 377;
        Event event;
        while(mainW.pollEvent(event)) {
            if(event.type == Event::Closed) mainW.close();
            if(event.type == Event::MouseButtonPressed) {
                if(event.mouseButton.button == Mouse::Left) {
                    //nhấn nút play
                    if(inside(pos.x,pos.y,xPlay,yPlay,x1Play,y1Play)) {
                        mainW.close();
                        showPlayWindow();
                    }
                    //nhấn nút exit
                    if(inside(pos.x,pos.y,xExit,yExit,x1Exit,y1Exit)) {
                        mainW.close();
                    }
                    //nhấn nút ranking
                    if(inside(pos.x,pos.y,xRank,yRank,x1Rank,y1Rank)) {
                        mainW.close();
                        showRankWindow();
                    }
                }
            }
        }
        mainW.clear(Color(255,105,180));
        //giữ nút play
        if(inside(pos.x,pos.y,xPlay,yPlay,x1Play,y1Play)) {
            t1.loadFromFile("images/mainHoldPlay.png");
            s1.setTexture(t1);
            s1.setPosition(0,0);
            mainW.draw(s1);
        }
        //giữ nút exit
        else if(inside(pos.x,pos.y,xExit,yExit,x1Exit,y1Exit)) {
            t1.loadFromFile("images/mainHoldExit.jpg");
            s1.setTexture(t1);
            s1.setPosition(0,0);
            mainW.draw(s1);
        }
        //giữ nút rank
        else if(inside(pos.x,pos.y,xRank,yRank,x1Rank,y1Rank)) {
            t1.loadFromFile("images/mainHoldRank.jpg");
            s1.setTexture(t1);
            s1.setPosition(0,0);
            mainW.draw(s1);
        }
        //theme
        else {
            t1.loadFromFile("images/mainW.jpg");
            s1.setTexture(t1);
            s1.setPosition(0,0);
            mainW.draw(s1);
        }

        mainW.display();
    }
}

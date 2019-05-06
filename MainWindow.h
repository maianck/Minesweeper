//hiển thị màn hình đầu tiên
void showMainWindow() {
    RenderWindow mainW(sf::VideoMode(800, 500), "Minesweeper", sf::Style::Default);
    Texture t,t1;
    Sprite s,s1;
    while (mainW.isOpen()) {
        Vector2i pos = Mouse::getPosition(mainW);
        int xPlay = 100, yPlay = 100;
        int xRank = 100, yRank = 225;
        int xExit = 100, yExit = 350;
        Event event;
        while(mainW.pollEvent(event)) {
            if(event.type == Event::Closed) mainW.close();
            if(event.type == Event::MouseButtonPressed) {
                if(event.mouseButton.button == Mouse::Left) {
                    //nhấn nút play
                    if(inside(pos.x,pos.y,xPlay,yPlay,100,50)) {
                        mainW.close();
                        showPlayWindow();
                    }
                    //nhấn nút exit
                    if(inside(pos.x,pos.y,xExit,yExit,100,50)) {
                        mainW.close();
                    }
                    //nhấn nút ranking
                    if(inside(pos.x,pos.y,xRank,yRank,100,50)) {
                        mainW.close();
                        showRankWindow();
                    }
                }
            }
        }
        mainW.clear(Color::Black);
        //picture
        t1.loadFromFile("images/mainPic.jpg");
        s1.setTexture(t1);
        s1.setPosition(427,127);
        mainW.draw(s1);
        //play button
        t.loadFromFile("images/play.jpg");
        s.setTexture(t);
        s.setPosition(xPlay,yPlay);
        mainW.draw(s);
        //ranking button
        t.loadFromFile("images/rank.jpg");
        s.setTexture(t);
        s.setPosition(xRank,yRank);
        mainW.draw(s);
        //exit button
        t.loadFromFile("images/Exit.jpg");
        s.setTexture(t);
        s.setPosition(xExit,yExit);
        mainW.draw(s);
        mainW.display();
    }
}

//hiển thị new game và continue
void showPlayWindow() {
    RenderWindow mainW(sf::VideoMode(500, 500), "Minesweeper", sf::Style::Default);
    Texture t,t1;
    Sprite s,s1;
    while (mainW.isOpen()) {
        Vector2i pos = Mouse::getPosition(mainW);
        int xCon = 175, yCon = 150;
        int xNew = 175, yNew = 300;
        Event event;
        while(mainW.pollEvent(event)) {
            if(event.type == Event::Closed) mainW.close(),showMainWindow();
            if(event.type == Event::MouseButtonPressed) {
                if(event.mouseButton.button == Mouse::Left) {
                    //nhấn nút continue
                    if(inside(pos.x,pos.y,xCon,yCon,150,50)) {
                        mainW.close();
                        //hiển thị bản chơi dở lưu trong file
                    }
                    //nhấn nút new game
                    if(inside(pos.x,pos.y,xNew,yNew,150,50)) {
                        mainW.close();
                        showGameWindow();
                    }
                }
            }
        }
        mainW.clear(Color(200,0,0));
        //continue button
        t.loadFromFile("images/continue.jpg");
        s.setTexture(t);
        s.setPosition(xCon,yCon);
        mainW.draw(s);
        //new game button
        t.loadFromFile("images/newgame.jpg");
        s.setTexture(t);
        s.setPosition(xNew,yNew);
        mainW.draw(s);
        mainW.display();
    }
}

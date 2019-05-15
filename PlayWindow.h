//hiển thị new game và continue
void showPlayWindow() {
    RenderWindow mainW(sf::VideoMode(900, 500), "Minesweeper", sf::Style::Default);
    Texture t,t1;
    Sprite s,s1;
    while (mainW.isOpen()) {
        Vector2i pos = Mouse::getPosition(mainW);
        int xCon = 565, yCon = 288, x1Con = 784, y1Con = 366;
        int xNew = 566, yNew = 181, x1New = 782, y1New = 231;
        int xBack = 819, yBack = 5, x1Back = 894,y1Back = 35;
        Event event;
        while(mainW.pollEvent(event)) {
            if(event.type == Event::Closed) mainW.close(),showMainWindow();
            if(event.type == Event::MouseButtonPressed) {
                if(event.mouseButton.button == Mouse::Left) {
                    //nhấn nút continue
                    if(inside(pos.x,pos.y,xCon,yCon,x1Con,y1Con)) {
                        //hiển thị bản chơi dở lưu trong file
                        mainW.close();
                        std::ifstream read;
                        read.open("save.txt");
                        read>>length>>height>>numBomb>>w>>notOpen;
                        for(int i=1;i<=length;++i) {
                            for(int j=1;j<=height;++j) read>>grid[i][j];
                        }
                        for(int i=1;i<=length;++i)
                        for(int j=1;j<=height;++j){
                            read>>show[i][j];
                            if(show[i][j]==grid[i][j]) cl[i][j]=1;
                            else cl[i][j]=0;
                        }
                        read.close();
                        showGameWindow();
                    }
                    //nhấn nút new game
                    if(inside(pos.x,pos.y,xNew,yNew,x1New,y1New)) {
                        mainW.close();
                        setSize(9,9,10,32);
                        setShow();
                        showGameWindow();
                    }
                    //nhấn nút back
                    if(inside(pos.x,pos.y,xBack,yBack,x1Back,y1Back)) {
                        mainW.close();
                        showMainWindow();
                    }
                }
            }
        }
        mainW.clear(Color(200,0,0));
        //continue button
        if(inside(pos.x,pos.y,xCon,yCon,x1Con,y1Con)) {
            t.loadFromFile("images/playHoldCon.png");
            s.setTexture(t);
            s.setPosition(0,0);
            mainW.draw(s);
        }
        else if(inside(pos.x,pos.y,xNew,yNew,x1New,y1New)) {
            t.loadFromFile("images/playHoldNew.png");
            s.setTexture(t);
            s.setPosition(0,0);
            mainW.draw(s);
        }
        else if(inside(pos.x,pos.y,xBack,yBack,x1Back,y1Back)) {
            t.loadFromFile("images/playHoldBack.png");
            s.setTexture(t);
            s.setPosition(0,0);
            mainW.draw(s);
        }
        else {
            t.loadFromFile("images/playW.png");
            s.setTexture(t);
            s.setPosition(0,0);
            mainW.draw(s);
        }

        mainW.display();
    }
}

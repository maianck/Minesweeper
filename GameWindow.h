void showHelp() {
    RenderWindow hW(sf::VideoMode(396, 218), "Help", sf::Style::Default);
    while(hW.isOpen()) {
        Event event;
        while (hW.pollEvent(event))
        {
            if(event.type == Event::Closed) hW.close();
        }
        hW.clear();
        Texture tt;
        tt.loadFromFile("images/helpDetail.png");
        Sprite ss;
        ss.setTexture(tt);
        ss.setPosition(0,0);
        hW.draw(ss);
        hW.display();
    }
}

void showOption() {

}

void showGameWindow() {
    int dai = length*w + 20;
    int rong = height*w + 100;
    RenderWindow window(sf::VideoMode(dai, rong), "Minesweeper", sf::Style::Default);

    Texture t;
    if(w==32) t.loadFromFile("images/tiles.jpg");
    else t.loadFromFile("images/tiles25.jpg");
    Sprite s;
    s.setTexture(t);

    Texture t1;
    t1.loadFromFile("images/smileFace.png");
    Sprite s1;
    s1.setTexture(t1);

    Texture t2;
    Sprite s2;

    SoundBuffer buffer;
    buffer.loadFromFile("sound/boom-expose.wav");
    Sound sound;
    sound.setBuffer(buffer);

    bool isLost = false;
    int xFace = dai/2-20, yFace = 40;
    int xOption = 10, yOption = 10;
    int xHelp = 80, yHelp = 10;
    while (window.isOpen())
    {
        Vector2i pos = Mouse::getPosition(window);

        Event event;
        while (window.pollEvent(event))
        {
            if(event.type == Event::Closed) {
                if(isLost==false&&notOpen>0) {
                    //lưu lại ván chơi dở
                    std::ofstream write;
                    write.open("save.txt");
                    write<<length<<" "<<height<<" "<<numBomb<<" ";
                    write<<w<<" "<<notOpen<<"\n";
                    for(int i=1;i<=length;++i) {
                        for(int j=1;j<=height;++j) write<<grid[i][j]<<" ";
                        write<<"\n";
                    }
                    for(int i=1;i<=length;++i) {
                        for(int j=1;j<=height;++j) write<<show[i][j]<<" ";
                        write<<"\n";
                    }
                    write.close();
                }
                window.close(),showPlayWindow();
            }
            if(event.type == Event::MouseButtonPressed) {
                //xử lý mở các ô trên màn chơi
                if(inside(pos.x,pos.y,10,90,dai-10,rong-10)&&isLost==false&&notOpen>0) {
                    int x = (pos.x-10)/w + 1;
                    int y = (pos.y-90)/w + 1;
                    //nhấn chuột trái
                    if(event.mouseButton.button == Mouse::Left&&show[x][y]==10) {
                        //mở ô đầu tiên
                        if(notOpen == length*height-numBomb) {
                            createGrid(x,y);
                        }
                        //xử lí mở ô
                        show[x][y] = grid[x][y];
                        if(show[x][y]==0) extend(x,y);
                        else if(show[x][y]!=9) notOpen--,cl[x][y]=1;
                        if(show[x][y]==9) {
                            for(int i=1;i<=length;++i)
                                for(int j=1;j<=height;++j) if(grid[i][j]==9) show[i][j]=9;
                            show[x][y]=12;
                            isLost = true;
                            sound.play();
                        }
                    }
                    //nhấn chuột phải
                    else if(event.mouseButton.button == Mouse::Right&&show[x][y]>=10) {
                        if(show[x][y]==10) show[x][y] = 11;
                        else if(show[x][y]==11) show[x][y] = 13;
                        else if(show[x][y]==13) show[x][y] = 10;
                    }
                }
                //restart the game
                if(inside(pos.x,pos.y,xFace,yFace,xFace+40,yFace+40)) {
                    if(event.mouseButton.button == Mouse::Left) {
                        setShow();
                        notOpen = length*height-numBomb;
                        isLost = false;
                    }
                }
                //click help
                if(inside(pos.x,pos.y,xHelp,yHelp,xHelp+60,yHelp+20)) {
                    if(event.mouseButton.button == Mouse::Left) {
                        showHelp();
                    }
                }
                //choose option
                if(inside(pos.x,pos.y,xOption,yOption,xOption+60,yOption+20)) {
                    if(event.mouseButton.button == Mouse::Left) {
                        RenderWindow hW(sf::VideoMode(474, 275), "Help", sf::Style::Default);
                        while(hW.isOpen()) {
                            Vector2i pos1 = Mouse::getPosition(hW);
                            Event event1;
                            int xBg = 45, yBg = 32, x1Bg = 146, y1Bg = 68;
                            int xMd = 45, yMd = 107, x1Md = 148, y1Md = 146;
                            int xAd = 42, yAd = 185, x1Ad = 147, y1Ad = 229;
                            while (hW.pollEvent(event1))
                            {
                                if(event1.type == Event::Closed) hW.close();
                                if(event1.type == Event::MouseButtonPressed) {
                                    if(event1.mouseButton.button == Mouse::Left) {
                                        if(inside(pos1.x,pos1.y,xBg,yBg,x1Bg,y1Bg)) {
                                            hW.close();
                                            window.close();
                                            setSize(9,9,10,32);
                                            setShow();
                                            showGameWindow();
                                        }
                                        if(inside(pos1.x,pos1.y,xMd,yMd,x1Md,y1Md)) {
                                            hW.close();
                                            window.close();
                                            setSize(16,16,40,25);
                                            setShow();
                                            showGameWindow();
                                        }
                                        if(inside(pos1.x,pos1.y,xAd,yAd,x1Ad,y1Ad)) {
                                            hW.close();
                                            window.close();
                                            setSize(30,16,99,25);
                                            setShow();
                                            showGameWindow();
                                        }
                                    }
                                }
                            }
                            hW.clear();
                            Texture tt;
                            tt.loadFromFile("images/optionDetail.png");
                            Sprite ss;
                            ss.setTexture(tt);
                            ss.setPosition(0,0);
                            hW.draw(ss);
                            hW.display();
                        }
                    }
                }
            }
        }
        window.clear(Color(228,165,97));
        if(isLost==true) {
            s1.setTextureRect(IntRect(40,40,40,40));
            s1.setPosition(xFace,yFace);
            window.draw(s1);
        }
        else if(notOpen==0&&isLost==false) {
            s1.setTextureRect(IntRect(0,40,40,40));
            s1.setPosition(xFace,yFace);
            window.draw(s1);
        }
        else {
            s1.setTextureRect(IntRect(0,0,40,40));
            s1.setPosition(xFace,yFace);
            window.draw(s1);
        }
        for(int i=1;i<=length;++i)
        for(int j=1;j<=height;++j) {
            s.setTextureRect(IntRect(show[i][j]*w,0,w,w));
            s.setPosition((i-1)*w+10,(j-1)*w+90);
            window.draw(s);
        }
        t2.loadFromFile("images/options.png");
        s2.setTexture(t2);
        s2.setPosition(xOption,yOption);
        window.draw(s2);

        t2.loadFromFile("images/help.png");
        s2.setTexture(t2);
        s2.setPosition(xHelp,yHelp);
        window.draw(s2);

        window.display();
    }
}

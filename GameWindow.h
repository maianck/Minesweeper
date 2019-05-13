void showGameWindow() {
    int dai = length*w + 20;
    int rong = height*w + 100;
    RenderWindow window(sf::VideoMode(dai, rong), "Minesweeper", sf::Style::Default);

    Texture t;
    t.loadFromFile("images/tiles.jpg");
    Sprite s;
    s.setTexture(t);

    Texture t1;
    t1.loadFromFile("images/smileFace.png");
    Sprite s1;
    s1.setTexture(t1);

    SoundBuffer buffer;
    buffer.loadFromFile("sound/boom-expose.wav");
    Sound sound;
    sound.setBuffer(buffer);

    bool isLost = false;
    int xFace = dai/2-20, yFace = 40;
    while (window.isOpen())
    {
        Vector2i pos = Mouse::getPosition(window);

        Event event;
        while (window.pollEvent(event))
        {
            if(event.type == Event::Closed) window.close(),showPlayWindow();
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
        window.display();
    }
}

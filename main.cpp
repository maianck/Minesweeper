#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <bits/stdc++.h>
#define maxn 100

using namespace sf;

int grid[maxn][maxn];
int length,height;
int numBomb,notOpen;
int w;
int show[maxn][maxn];
int col[8]={-1,-1,-1,0,1,1,1,0};
int row[8]={-1,0,1,1,1,0,-1,-1};

void showGameWindow();
void showMainWindow();
void showRankWindow();
void showPlayWindow();
bool inside(int x,int y,int u,int v,int u1,int v1);
void setSize(int dai, int rong, int bom, int pix) {
    length = dai;
    height = rong;
    numBomb = bom;
    w = pix;
    notOpen = length*height-numBomb;
}

#include "GridCreation.h"
#include "Showing.h"
#include "GameWindow.h"
#include "MainWindow.h"
#include "PlayWindow.h"
#include "RankWindow.h"

//kiểm tra xem vị trí của chuột có nằm trong vùng từ (u,v) -> (u1,v1)
bool inside(int x,int y,int u,int v,int u1,int v1) {
    if(x<u||y<v) return false;
    if(x>u1||y>v1) return false;
    return true;
}

int main()
{
    srand(0);
    showMainWindow();
    return 0;
}

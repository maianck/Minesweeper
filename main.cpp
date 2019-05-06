#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#define maxn 100

using namespace sf;

int grid[maxn][maxn];
int length,height;
int numBomb;
int w;
int show[maxn][maxn];

void showGameWindow();
void showMainWindow();
void showRankWindow();
void showPlayWindow();
bool inside(int x,int y,int u,int v,int dai,int rong);

#include "GridCreation.h"
#include "Showing.h"
#include "GameWindow.h"
#include "MainWindow.h"
#include "PlayWindow.h"
#include "RankWindow.h"

//kiểm tra xem vị trí của chuột có nằm trong vùng có góc trên trái (u,v), dài rộng: dai,rong
bool inside(int x,int y,int u,int v,int dai,int rong) {
    if(x<u||y<v) return false;
    if(x>u+dai||y>v+rong) return false;
    return true;
}

int main()
{
    srand(0);
    showMainWindow();
    return 0;
}

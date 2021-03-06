bool ok(int u,int v,int x,int y) {
    if(grid[u][v]!=0) return false;
    if(u==x&&v==y) return false;
    for(int i=0;i<=7;++i) {
        if(u==x+col[i]&&v==y+row[i]) return false;
    }
    return true;
}

void createGrid(int x,int y) {
    //Tạo ra các ô chứa bom
    for(int i=1;i<=length;++i)
        for(int j=1;j<=length;++j) grid[i][j]=0;
    int num = 0;
    while(num<numBomb) {
        int u = rand()%length+1;
        int v = rand()%height+1;
        if(ok(u,v,x,y)) grid[u][v] = 9,num++;
    }
    //Xây dựng sơ đồ
    for(int i=1;i<=length;++i)
    for(int j=1;j<=height;++j) if(grid[i][j]==0) {
        for(int k=0;k<=7;++k) {
            int u = i+col[k], v = j+row[k];
            if(1<=u&&u<=length&&1<=v&&v<=height) {
                if(grid[u][v]==9) grid[i][j]++;
            }
        }
    }
}

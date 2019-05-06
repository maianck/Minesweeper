void createGrid() {
    //Tạo ra các ô chứa bom
    int num = 0;
    while(num<numBomb) {
        int u = rand()%length+1;
        int v = rand()%height+1;
        if(grid[u][v]==0) grid[u][v] = 9,num++;
    }
    //Xây dựng sơ đồ
    for(int i=1;i<=length;++i)
    for(int j=1;j<=height;++j) {
        if(grid[i][j]==9) continue;
        if(grid[i-1][j-1]==9) grid[i][j]++;
        if(grid[i-1][j]==9) grid[i][j]++;
        if(grid[i-1][j+1]==9) grid[i][j]++;
        if(grid[i][j+1]==9) grid[i][j]++;
        if(grid[i+1][j+1]==9) grid[i][j]++;
        if(grid[i+1][j]==9) grid[i][j]++;
        if(grid[i+1][j-1]==9) grid[i][j]++;
        if(grid[i][j-1]==9) grid[i][j]++;
    }
}

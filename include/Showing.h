int cl[maxn][maxn]={{0}};

void setShow() {
    //khởi tạo mảng sơ đồ gồm các ô trắng
    int m,n;
    m = length, n = height;
    for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j) show[i][j]=10;
    for(int i=1;i<=length;++i)
        for(int j=1;j<=height;++j) cl[i][j]=0;
}

//mở rộng khi nhấn vào ô 0

void extend(int x,int y) {
    int a[length*height+1],b[length*height+1];
    cl[x][y]=1;
    int sl = 0;
    a[++sl]=x,b[sl]=y;
    int i = 1;
    notOpen--;
    while(i<=sl) {
        int u = a[i], v = b[i];
        i++;
        for(int j=0;j<=7;++j) {
            int u1 = u+col[j], v1 = v+row[j];
            if(1<=u1&&u1<=length&&1<=v1&&v1<=height) {
                if(cl[u1][v1]==0) {
                    cl[u1][v1]=1;
                    if(grid[u1][v1]==0) a[++sl]=u1,b[sl]=v1;
                    show[u1][v1] = grid[u1][v1];
                    notOpen--;
                }
            }
        }
    }
}

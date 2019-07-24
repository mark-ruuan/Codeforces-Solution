bool visit[1000][1000];
int xx, yy;

bool go(int ** grid, int x, int y){
    if((x >= 0 && x <= xx && y >= 0 && y <= yy && !visit[x][y] && grid[x][y]) == 0) return 0;
    visit[x][y] = 1;
    if(grid[x][y] == 9) return 1;
    int xx = 0;
    xx |= go(grid, x + 1, y);
    xx |= go(grid, x - 1, y);
    xx |= go(grid, x, y + 1);
    xx |= go(grid, x, y - 1);
    xx |= go(grid, x + 1, y + 1);
    xx |= go(grid, x + 1, y - 1);
    xx |= go(grid, x - 1, y + 1);
    xx |= go(grid, x - 1, y - 1);
    return xx;

}

int isPath(int **grid, int m, int n){
    xx = m, yy = n;
    return go(grid, 0, 0);
}


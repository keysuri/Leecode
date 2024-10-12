#include <bits/stdc++.h>
using namespace std;

int dir[4][2] = {0,1,1,0,0,-1,-1,0};
void dfs(vector<vector<int>>& grid, int x, int y) {
    grid[x][y] = 2;
    for (int i = 0; i < 4; i++) {
        int nextX = x + dir[i][0];
        int nextY = y + dir[i][1];
        if (nextX < 0 || nextX >= grid.size() || nextY < 0 || nextY >= grid[0].size()) continue;
        if (grid[nextX][nextY] == 1) {
            grid[nextX][nextY] = 2;
            dfs(grid, nextX, nextY);
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    }
    //边上岛屿全加1
    for (int i = 0; i < n; i++) {
        if (grid[i][0] == 1) dfs(grid, i, 0);
        if (grid[i][m - 1] == 1) dfs(grid, i, m - 1);
    }
    for (int j = 0; j < m; j++) {
        if (grid[0][j] == 1) dfs(grid,  0, j);
        if (grid[n - 1][j] == 1) dfs(grid, n - 1, j);
    }

    for (int i = 0; i < n ; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) cout << 0 << " ";
            else if (grid[i][j] == 2) cout << 1 << " ";
            else cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

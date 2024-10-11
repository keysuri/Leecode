#include <bits/stdc++.h>
using namespace std;

int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
void dfs (vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
    //外面没有置0
    grid[x][y] = 0;
    for (int i = 0; i < 4; i++) {
        int nextX = x + dir[i][0];
        int nextY = y + dir[i][1];
        if (nextX < 0 || nextX >= grid.size() || nextY < 0 || nextY >= grid[0].size()) continue;
        if (!visited[nextX][nextY] && grid[nextX][nextY] == 1) {
            visited[nextX][nextY] = true;
            grid[nextX][nextY] = 0;
            dfs(grid, visited, nextX, nextY);
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
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    //边上岛屿全变成海洋
    for (int i = 0; i < n; i++) {
        if (grid[i][0] == 1) dfs(grid, visited, i, 0);
        if (grid[i][m - 1] == 1) dfs(grid, visited, i, m - 1);
    }
    for (int j = 0; j < m; j++) {
        if (grid[0][j] == 1) dfs(grid, visited, 0, j);
        if (grid[n - 1][j] == 1) dfs(grid, visited, n - 1, j);
    }
    int result = 0;
    for (int i = 0; i < n ; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) result++;
        }
    }
    cout << result;

}
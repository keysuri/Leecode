#include <bits/stdc++.h>
using namespace std;
//每个格子，都做dfs，看能否到第一，第二边，O(m*n*m*n)超时
int dir[4][2] = {0,1,1,0,0,-1,-1,0};
void dfs(vector<vector<int>>& grid, int x, int y, bool& isFirst, bool& isSecond, vector<vector<bool>>& visited) {
    visited[x][y] = true;
    if (x == 0 || y == 0) isFirst = true;
    if (x == grid.size() - 1 || y == grid[0].size() - 1) isSecond = true;
    for (int i = 0; i < 4; i++) {
        int nextX = x + dir[i][0];
        int nextY = y + dir[i][1];
        if (nextX < 0 || nextX >= grid.size() || nextY < 0 || nextY >= grid[0].size()) continue;
        if (grid[nextX][nextY] <= grid[x][y] && !visited[nextX][nextY]) {
            dfs(grid, nextX, nextY, isFirst, isSecond, visited);
        }
    }
}
//优化，从第一边界节点逆流而上，标记遍历的点，第二边界同样，找到双方都标记的点
void dfs2(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nextX = x + dir[i][0];
        int nextY = y + dir[i][1];
        if (nextX < 0 || nextX >= grid.size() || nextY < 0 || nextY >= grid[0].size()) continue;
        if (grid[nextX][nextY] >= grid[x][y] && !visited[nextX][nextY]) {
            dfs2(grid, visited, nextX, nextY);
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
    //暴力
//    for (int i = 0; i < n ; i++) {
//        for (int j = 0; j < m; j++) {
//            bool isFirst = false;
//            bool isSecond = false;
//            vector<vector<bool>> visited(n, vector<bool>(m, false));
//            dfs(grid, i, j, isFirst, isSecond, visited);
//            if (isFirst && isSecond) cout << i << " " << j << endl;
//        }
//    }

    //优化
    vector<vector<bool>> firstBorder(n, vector<bool>(m, false));
    vector<vector<bool>> secondBorder(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        dfs2(grid, firstBorder, i, 0);//第一组边界
        dfs2(grid, secondBorder, i, m - 1);//第二组边界
    }
    for (int j = 0; j < m; j++) {
        dfs2(grid, firstBorder, 0, j);//第一组边界
        dfs2(grid, secondBorder, n - 1, j);//第二组边界
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // 如果这个节点，从第一组边界和第二组边界出发都遍历过，就是结果
            if (firstBorder[i][j] && secondBorder[i][j]) cout << i << " " << j << endl;
        }
    }
}
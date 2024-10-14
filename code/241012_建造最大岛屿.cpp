#include <bits/stdc++.h>
using namespace std;

int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int& area, int mark) {
    if (visited[x][y] || grid[x][y] != 1) return;
    visited[x][y] = true;
    area++;
    //标记一块岛
    grid[x][y] = mark;
    for (int i = 0; i < 4; i++) {
        int nextX = x + dir[i][0];
        int nextY = y + dir[i][1];
        if (nextX < 0 || nextX >= grid.size() || nextY < 0 || nextY >= grid[0].size()) continue;
        dfs(grid, visited, nextX, nextY, area, mark);
    }
}

//先分别标记每座岛及其面积，遍历每个水，统计其四面的岛屿，面积相加
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    }
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    unordered_map<int ,int> gridNum;
    int area;
    int mark = 1;
    int result = 0;
    for (int i = 0; i < n ; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                area = 0;
                dfs(grid, visited, i, j, area, mark);
//                gridNum.emplace(mark, area);
//                gridNum.insert(pair<int, int>(mark, area));
//                gridNum.insert({mark, area});
                gridNum[mark] = area; //记录每座岛的面积
                result = max(area, result);
                mark++;//下一块岛
            }
        }
    }

    //防止重复添加一座岛
    unordered_set<int> visitedGrid;
    for (int i = 0; i < n ; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 0) {
                visitedGrid.clear();
                int count = 1;
                for (int k = 0; k < 4; k++) {
                    int nextX = i + dir[k][0];
                    int nextY = j + dir[k][1];
                    if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m) continue;
                    if (visitedGrid.count(grid[nextX][nextY])) continue;//遇到同一座岛
                    count += gridNum[grid[nextX][nextY]];
                    visitedGrid.insert(grid[nextX][nextY]);
                }
                result = max(result, count);
            }
        }
    }
    cout << result;

}
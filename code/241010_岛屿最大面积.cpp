#include <bits/stdc++.h>
using namespace std;

//dfs
int dir[4][2] = {0,1,1,0,-1,0,0,-1};
void dfs(const vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int& count) {
    for (int i = 0; i < 4; i++) {
        int nextx = x + dir[i][0];
        int nexty = y + dir[i][1];
        if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) continue;
        if (!visited[nextx][nexty] && grid[nextx][nexty] == 1) {
            count++;
            visited[nextx][nexty] = true;
            dfs(grid, visited, nextx, nexty, count);
        }
    }
}
//bfs
void bfs(const vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int& count) {
    queue<pair<int, int>> que;
    que.push({x, y});
    while (!que.empty()) {
        pair<int, int> cur = que.front(); que.pop();
        int curx = cur.first;
        int cury = cur.second;
        for (int i = 0; i < 4; i++) {
            int nextx = curx + dir[i][0];
            int nexty = cury + dir[i][1];
            if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) continue;
            if (!visited[nextx][nexty] && grid[nextx][nexty] == 1) {
                count++;
                visited[nextx][nexty] = true;
                dfs(grid, visited, nextx, nexty, count);
            }
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
    int result = 0;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && grid[i][j] == 1) {
                visited[i][j] = true;
                int count = 1;
                //dfs(grid, visited, i, j, count);
                bfs(grid, visited, i, j, count);
                result = max(result, count);
            }
        }
    }
    cout << result;
}

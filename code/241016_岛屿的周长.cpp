#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    }
    //1.总边数=岛屿数*4-相邻岛屿数*2
    int sum = 0;
    int cover = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                sum++;
                if (i + 1 < n && grid[i + 1][j] == 1) cover++;
                if (j + 1 < m && grid[i][j + 1] == 1) cover++;
            }
        }
    }
    cout << sum * 4 - cover * 2;
    //2.每座岛上下左右，有水域，边+1，出界，边+1
    int result = 0;
    int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                for (int k = 0; k < 4; k++) {
                    int nextI = i + dir[k][0];
                    int nextJ = j + dir[k][1];
                    if (nextI < 0 || nextI >= n || nextJ < 0 || nextJ >= m || grid[nextI][nextJ] == 0) result++;
                }
            }
        }
    }
    cout << result;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> grid(n + 1, vector<int>(n + 1));
    int x, y;
    for (int i = 0; i < k; i++) {
        cin >> x >> y;
        grid[x][y] = 1;
    }
    vector<bool> reachable(n + 1, false);
    queue<int> q;
    q.push(1);
    reachable[1] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 1; i <= n; i++) {
            if (grid[cur][i] == 1 && !reachable[i]) {
                reachable[i] = true;
                q.push(i);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!reachable[i]) {
            cout << -1;
            return 0;
        }
    }
    cout << 1;
}
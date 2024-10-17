#include <bits/stdc++.h>
using namespace std;
//和241014_有向图的完全可达性.cpp一样，用bfs遍历所有点就可以了
int main1() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n + 1, vector<int>(n + 1));
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        grid[x][y] = 1;
        grid[y][x] = 1;
    }
    int source, destination;
    cin >> source >> destination;

    unordered_set<int> visited;
    queue<int> q;
    q.push(source);
    visited.insert(source);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 1; i <= n; i++) {
            if (grid[cur][i] == 1 && visited.find(i) == visited.end()) {
                visited.insert(i);
                q.push(i);
            }
        }
    }
    if (visited.find(destination)!= visited.end()) cout << 1;
    else cout << 0;
}

//并查集
int n;
vector<int> father = vector<int>(n + 1, 0);
void init() {
    for (int i = 1; i <= n; i++)
        father[i] = i;
}
int find(int x) {
    return x == father[x]? x : father[x] = find(father[x]);//路径压缩
}
bool isSame(int x, int y) {
    return find(x) == find(y);
}
void join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    father[y] = x;
}
int main() {
    int m;
    cin >> n >> m;
    init();
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        join(x, y);
    }
    int source, destination;
    cin >> source >> destination;
    if (isSame(source, destination)) cout << 1;
    else cout << 0;
}
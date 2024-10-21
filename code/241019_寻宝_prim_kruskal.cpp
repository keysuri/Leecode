#include <bits/stdc++.h>
using namespace std;
//prim
int main1() {
    int v, e;
    int x, y, k;
    cin >> v >> e;
    vector<vector<int>> grid(v + 1, vector<int>(v + 1, 100001));
    while (e--) {
        cin >> x >> y >> k;
        grid[x][y] = k;
        grid[y][x] = k;
    }
    int sum = 0;

    vector<int> minDist(v + 1, 100001);
    vector<bool> inTree(v + 1, false);
    vector<int> parent(v + 1, -1);
    //共v-1条边
    for (int i = 1; i < v; i++) {
        int cur = -1;
        int minVal = INT_MAX;
        for (int j = 1; j <= v; j++) {
            if (!inTree[j] && minDist[j] < minVal) {
                cur = j;
                minVal = minDist[j];
            }
        }
        inTree[cur] = true;
        for (int j = 0; j <= v; j++) {
            if (!inTree[j] && grid[cur][j] < minDist[j]) {
                minDist[j] = grid[cur][j];
                parent[j] = cur;
            }
        }
    }
    //minDist[]: 100001 1 1 1 1 1 1
    for (int i = 2; i <= v; i++) {
        cout << minDist[i] << " " << parent[i] << " ->" << i << endl;
    }
}
//kruskal，并查集
int n;
vector<int> parent(n + 1);
void init() {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
}
int find(int x) {
    return x == parent[x] ? x : parent[x] = find(parent[x]);
}
bool isSame(int x, int y) {
    return find(x) == find(y);
}
void join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    parent[y] = x;
}
struct Edge {
    int l, r, val;
};
int main() {
    int v, e;
    int x, y, k;
    cin >> v >> e;
    n = v;
    vector<Edge> vec(v + 1);
    vector<Edge> result;
    while (e--) {
        cin >> x >> y >> k;
        vec.push_back({x, y, k});
    }
    int sum = 0;
    //从小到大排序
    sort(vec.begin(), vec.end(), [](const Edge& a, const Edge& b) {return a.val < b.val;});
    init();
    for (Edge edge : vec) {
        if (!isSame(edge.l, edge.r)) {
            result.push_back(edge);
            sum += edge.val;
            join(edge.l, edge.r);
        }
    }
    for (Edge edge : result) {
        cout << edge.l << " - " << edge.r << " : " << edge.val << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
//有向树：根节点入度为0，其他节点入度为1
int n;
vector<int> parent = vector<int>(1001);
void init() {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
}
int find(int x) {
    if (parent[x] == x) return x;
    else return parent[x] = find(parent[x]);
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
bool isTreeAfterRemoveEdge(vector<vector<int>>& edges, int deleteEdge) {
    init();
    for (int i = 0; i < n; i++) {
        if (i == deleteEdge) continue;
        if (isSame(edges[i][0], edges[i][1])) return false;
        join(edges[i][0], edges[i][1]);
    }
    return true;
}
void getRemoveEdge(vector<vector<int>>& edges) {
    init();
    for (int i = 0; i < n; i++) {
        if (isSame(edges[i][0], edges[i][1])) {
            cout << edges[i][0] << " " << edges[i][1];
            return;
        }
        join(edges[i][0], edges[i][1]);
    }
}
int main() {
    cin >> n;
    vector<vector<int>> edges;
    vector<int> inDegree(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int s, t;
        cin >> s >> t;
        edges.push_back({s, t});
        inDegree[t]++;
    }
    vector<int> vec; // 入度为2的边，要么0要么2
    for (int i = n - 1; i >= 0; i--) {
        if (inDegree[edges[i][1]] == 2) {
            vec.push_back(i);
        }
    }
    if (vec.size() > 0) {
        // 放在vec里的边已经是倒序，所以这里就优先删vec[0]这条边
        if (isTreeAfterRemoveEdge(edges, vec[0])) {
            cout << edges[vec[0]][0] << " " << edges[vec[0]][1];
        } else {
            cout << edges[vec[1]][0] << " " << edges[vec[1]][1];
        }
        return 0;
    } else { // 没有入度为2的边，一定有环，删环里的边
        getRemoveEdge(edges);
    }
}
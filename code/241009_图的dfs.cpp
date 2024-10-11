#include <bits/stdc++.h>
using namespace std;
//有向无环图

//邻接表
vector<vector<int>> result;
vector<int> path;
void dfs(const vector<vector<int>>& graph, int n, int x) {
    if (x == n) {
        result.push_back(path);
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (graph[x][i] == 1) {
            path.push_back(i);
            dfs(graph, n, i);
            path.pop_back();
        }
    }
}
int main() {
    int m, n, s, t;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
    while (m--) {
        cin >> s >> t;
        graph[s][t] = 1;
    }
    path.push_back(1);
    dfs(graph, n, 1);

    if (result.empty()) cout << -1;
    else {
        for (const auto& p : result) {
            for (int i = 0; i < p.size() - 1; i++) cout << p[i] << " ";
            cout << p[p.size() - 1] << endl;
        }
    }
}
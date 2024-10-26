#include <bits/stdc++.h>
using namespace std;
//邻接矩阵
int main1() {
    int n, m, s, t, v;
    cin >> n >> m;
    vector<vector<int>> grid(n + 1, vector<int>(n + 1, INT_MAX));
    for (int i = 0; i < m; i++) {
        cin >> s >> t >> v;
        grid[s][t] = v;
    }
    vector<int> minDist(n + 1, INT_MAX);
    vector<bool> visited(n + 1, false);
    minDist[1] = 0;
    //找n个点
    for (int i = 1; i <= n; i++) {
        int minVal = INT_MAX;
        int cur = -1;
        //找minDist[]中最小且未被访问的点
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && minDist[j] < minVal) {
                minVal = minDist[j];
                cur = j;
            }
        }
        if (cur == -1) break; //初始化为-1，不加会越界

        visited[cur] = true;
        //更新minDist
        for (int j = 1; j <= n; j++) {
            if(!visited[j] && grid[cur][j] != INT_MAX && grid[cur][j] + minDist[cur] < minDist[j]) //grid[cur][j] != INT_MAX 防止溢出
                minDist[j] = grid[cur][j] + minDist[cur];
        }
    }
    if (minDist[n] == INT_MAX) cout << -1;
    else cout << minDist[n];
}
//堆优化，邻接表
class mycomparison {
public:
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second; //小顶堆
    }
};
int main() {
    int n, m, s, t, v;
    cin >> n >> m;
    vector<list<pair<int, int>>> grid(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> s >> t >> v;
        grid[s].push_back({t, v});
    }
    vector<int> minDist(n + 1, INT_MAX);
    vector<bool> visited(n + 1, false);
    minDist[1] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pq;
    pq.push(pair<int, int>(1, 0));

    while (!pq.empty()) {
        //找minDist[]中最小且未被访问的点
        pair<int, int> cur = pq.top(); pq.pop();

        visited[cur.first] = true;
        //更新minDist
        for (const auto& x : grid[cur.first]) {
            if (!visited[x.first] && x.second + cur.second < minDist[x.first]) {
                minDist[x.first] = x.second + cur.second;
                pq.push(pair<int, int>(x.first, minDist[x.first]));
            }
        }
    }
    if (minDist[n] == INT_MAX) cout << -1;
    else cout << minDist[n];
}
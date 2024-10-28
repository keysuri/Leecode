#include <bits/stdc++.h>
using namespace std;
//关键是控制k+1次松弛

int main1() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid;
    int s, t, v;
    for (int i = 0; i < m; i++) {
        cin >> s >> t >> v;
        grid.push_back({s, t, v});
    }
    int src, dst, k;
    cin >> src >> dst >> k;
    //最多经过k个城市=>最多经过k+1条边
    vector<int> minDist(n + 1, INT_MAX);
    vector<int> minDist_copy(n + 1); // 用来记录上一次遍历的结果
    minDist[src] = 0;
    for (int i = 1; i <= k + 1; i++) {
        minDist_copy = minDist; //用上一次的结果松弛
        for (const auto& side : grid) {
            int from = side[0];
            int to = side[1];
            int price = side[2];
            if (minDist_copy[from] != INT_MAX && minDist[to] > minDist_copy[from] + price) {
                minDist[to] = minDist_copy[from] + price;
            }
        }
    }
    if (minDist[dst] == INT_MAX) cout << "unreachable";
    else cout << minDist[dst];
}
int main() {
    int n, m, s, t, v;
    cin >> n >> m;
    vector<list<pair<int, int>>> grid(n + 1);

    for (int i = 0; i < m; i++) {
        cin >> s >> t >> v;
        grid[s].push_back({t, v});
    }
    int src, dst, k;
    cin >> src >> dst >> k;
    queue<int> q; //记录要松弛边的起始点
    vector<int> minDist(n + 1, INT_MAX);
    vector<int> minDist_copy(n + 1); // 用来记录上一次遍历的结果
    minDist[src] = 0;
    q.push(src);

    int que_size;
    k++;
    while (k-- && !q.empty()) {
        minDist_copy = minDist;
        que_size = q.size();
        vector<bool> visited(n + 1, false); // 每一轮松弛中，控制节点不用重复入队列
        while (que_size--) {
            int cur = q.front(); q.pop();
            for (const auto& slide : grid[cur]) {
                int to = slide.first;
                int price = slide.second;
                if (minDist[to] > minDist_copy[cur] + price) {
                    minDist[to] = minDist_copy[cur] + price;
                    if(visited[to]) continue;
                    visited[to] = true;
                    q.push(to);
                }
            }
        }
    }
    if (minDist[dst] == INT_MAX) cout << "unreachable";
    else cout << minDist[dst];
}
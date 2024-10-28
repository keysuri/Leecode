#include <bits/stdc++.h>
using namespace std;
//Bellman_ford
int main1() {
    int n, m, s, t, v;
    cin >> n >> m;
    vector<vector<int>> grid;
    for (int i = 0; i < m; i++) {
        cin >> s >> t >> v;
        grid.push_back({s, t, v});
    }
    vector<int> minDist(n + 1, INT_MAX);
    minDist[1] = 0;

    //松弛一次，minDist可能所有值都会变，但只有与起点1条边相连的节点 的最短距离 是最终值，其实相当于多松弛了
    //对所有边 松弛n-1次 得到 起点到达 与起点n-1条边相连的节点 的最短距离
    for (int i = 1; i < n; i++) {
        for (vector<int>& side : grid) {
            int from = side[0];
            int to = side[1];
            int price = side[2];
            //松弛操作
            if (minDist[from] != INT_MAX && minDist[to] > minDist[from] + price) {
                minDist[to] = minDist[from] + price;
            }
        }
    }

    if (minDist[n] == INT_MAX) cout << "unconnected" << endl; // 不能到达终点
    else cout << minDist[n] << endl; // 到达终点最短路径
}
//Bellman_ford 队列优化算法 SPFA
//每次松弛边时无需松弛所有边
int main() {
    int n, m, s, t, v;
    cin >> n >> m;
    vector<list<pair<int, int>>> grid(n + 1);
    vector<bool> isInQueue(n + 1); // 加入优化，已经在队里里的元素不用重复添加, 也可以不用

    for (int i = 0; i < m; i++) {
        cin >> s >> t >> v;
        grid[s].push_back({t, v});
    }
    queue<int> q; //记录要松弛边的起始点
    vector<int> minDist(n + 1, INT_MAX);
    minDist[1] = 0;
    q.push(1);

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        isInQueue[cur] = false; // 从队列里取出的时候，要取消标记，我们只保证已经在队列里的元素不用重复加入
        for (const auto& slide : grid[cur]) {
            int to = slide.first;
            int price = slide.second;
            if (minDist[to] > minDist[cur] + price) {
                minDist[to] = minDist[cur] + price;
                if (isInQueue[to] == false) {
                    q.push(to);
                    isInQueue[to] = true;
                }
            }
        }
    }

    if (minDist[n] == INT_MAX) cout << "unconnected" << endl; // 不能到达终点
    else cout << minDist[n] << endl; // 到达终点最短路径
}
//判断负权回路
int main11() {
    int n, m, s, t, v;
    cin >> n >> m;
    vector<vector<int>> grid;
    for (int i = 0; i < m; i++) {
        cin >> s >> t >> v;
        grid.push_back({s, t, v});
    }
    vector<int> minDist(n + 1, INT_MAX);
    minDist[1] = 0;

    bool flag = false;
    //对所有边 松弛n次 看最后一次会不会改变最短路径
    for (int i = 1; i <= n; i++) {
        for (vector<int>& side : grid) {
            int from = side[0];
            int to = side[1];
            int price = side[2];
            if (i < n) {
                if (minDist[from] != INT_MAX && minDist[to] > minDist[from] + price)
                    minDist[to] = minDist[from] + price;
            } else {
                if (minDist[from] != INT_MAX && minDist[to] > minDist[from] + price)
                    flag = true;
            }
        }
    }
    if (flag) cout << "circle" << endl;
    else if (minDist[n] == INT_MAX) cout << "unconnected" << endl; // 不能到达终点
    else cout << minDist[n] << endl; // 到达终点最短路径
}
//SPFA最坏情况每个点连接n-1条边，最多加入n-1次，如果超过，则有负权回路
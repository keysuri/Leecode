#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> inDegree(n, 0);
    vector<int> result;
    unordered_map<int, vector<int>> umap;
    int s, t;
    while (m--) {
        cin >> s >> t;
        inDegree[t]++;
        umap[s].push_back(t);
    }
    //入度为0的点不一定唯一
    queue<int> que;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) que.push(i);
    }
    while (que.size()) {
        int cur = que.front();
        que.pop();
        result.push_back(cur);
        //将该节点从图中移除
        for (int x : umap[cur]) {
            inDegree[x]--;
            if (inDegree[x] == 0) que.push(x);
        }
    }
    if (result.size() == n) {
        for (int x : result) cout << x << " ";
    } else { // 一旦有环，size一定小于n
        cout << -1;
    }
}
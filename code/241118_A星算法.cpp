#include <bits/stdc++.h>
using namespace std;

int moves[1001][1001];
int dir[8][2] = {-2, 1, -2, -1, -1, 2, -1, -2, 1, 2, 1, -2, 2, 1, 2, -1};
//广度优先搜索
void bfs(int a1, int a2, int b1, int b2) {
    queue<int> q;
    q.push(a1);
    q.push(a2);
    while (!q.empty()) {
        int m = q.front(); q.pop();
        int n = q.front(); q.pop();
        if (m == b1 && n == b2) break;

        for (int i = 0; i < 8; i++) {
            int mm = m + dir[i][0];
            int nn = n + dir[i][1];
            if (mm < 1 || mm > 1000 || nn < 1 || nn > 1000) continue;
            if (moves[mm][nn] == 0) {
                moves[mm][nn] = moves[m][n] + 1;
                q.push(mm);
                q.push(nn);
            }
        }
    }
}
// A*算法，取决于启发式函数
struct Knight{
    int x, y;
    int g, h, f; // G = 从起点到该节点路径消耗 H = 该节点到终点的预估消耗 F = G + H
    bool operator < (const Knight& k) const {
        return k.f < f;
    }
};
priority_queue<Knight> que;
int Heuristic (const Knight& k, int b1, int b2) { // 欧拉距离
    return (k.x - b1) * (k.x - b1) + (k.y - b2) * (k.y - b2);
}
void a_star(Knight& k, int b1, int b2) {
    Knight cur, next;
    que.push(k);
    while (!que.empty()) {
        cur = que.top(); que.pop();
        if (cur.x == b1 && cur.y == b2) break;
        for (int i = 0; i < 8; i++) {
            next.x = cur.x + dir[i][0];
            next.y = cur.y + dir[i][1];
            if (next.x < 1 || next.x > 1000 || next.y < 1 || next.y > 1000) continue;
            if (moves[next.x][next.y] == 0) {
                moves[next.x][next.y] = moves[cur.x][cur.y] + 1;

                next.g = cur.g + 5; //统一不开根号，可以提高精度
                next.h = Heuristic(next, b1, b2);
                next.f = next.g + next.h;
                que.push(next);
            }
        }
    }
}
int main() {
    int n, a1, a2, b1, b2;
    cin >> n;
    while (n--) {
        cin >> a1 >> a2 >> b1 >> b2;
        memset(moves,0,sizeof(moves));
//        bfs(a1, a2, b1, b2);
        Knight start;
        start.x = a1;
        start.y = a2;
        start.g = 0;
        start.h = Heuristic(start, b1, b2);
        start.f = start.g + start.h;
        a_star(start, b1, b2);

        cout << moves[b1][b2] << endl;
    }
    return 0;
}

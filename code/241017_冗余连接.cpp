#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> parent = vector<int>(n + 1);
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
int main() {
    cin >> n;
    init();
    for (int i = 0; i < n; i++) {
        int s, t;
        cin >> s >> t;
        if (isSame(s, t)) {
            cout << s << " " << t << endl;
            return 0;
        } else {
            join(s, t);
        }
    }
}
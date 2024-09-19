#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, bagWeight;
    cin >> n >> bagWeight;
    vector<int> weight(n);
    vector<int> value(n);
    for (int i = 0; i < n; i ++) {
        cin >> weight[i];
    }
    for (int i = 0; i < n; i ++) {
        cin >> value[i];
    }
    vector<vector<int>> dp(n, vector<int>(bagWeight + 1, 0));
    //dp[i][j]表示空间为j情况下，从0-i物品中取，最大价值

    //初始化第一行
    for (int i = weight[0]; i <= bagWeight; i ++) {
        dp[0][i] = value[0];
    }

    for (int i = 1; i < n; i ++) {
        for (int j = 1; j <= bagWeight; j ++) {
            if (j < weight[i]) dp[i][j] = dp[i - 1][j]; //不选物品i
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);//选物品i
            }
        }
    }
    cout << dp[n - 1][bagWeight];

}
//输入示例：
//6 1
//2 2 3 1 5 4
//2 3 1 5 4 3
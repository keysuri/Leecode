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
    vector<int> dp(bagWeight + 1, 0);
    //dp[i]表示容量为i的背包所背的最大值

    //初始化第一行
    for (int i = weight[0]; i <= bagWeight; i ++) {
        dp[i] = value[0];
    }

    for (int i = 1; i < n; i ++) {
        for (int j = bagWeight; j >= weight[i]; j --) { //倒序遍历，主要防止覆盖，后面的可能用到前面的值，如果已经更新，会不准确
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    cout << dp[bagWeight];
}
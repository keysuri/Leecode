#include <bits/stdc++.h>
using namespace std;

void test(int n, int bagWeight, vector<int>& weight, vector<int>& value);
int main() {
    int n, bagWeight;
//    cin >> n >> bagWeight;
    vector<int> weight(n);
    vector<int> value(n);
//    for (int i = 0; i < n; i ++) {
//        cin >> weight[i] >> value[i];
//    }

    n = 4, bagWeight = 5, weight={1,2,3,4}, value={2,4,4,5};
    test(n, bagWeight, weight, value);
}
void test(int n, int bagWeight, vector<int>& weight, vector<int>& value) {
    vector<vector<int>> dp(n, vector<int>(bagWeight + 1, 0));
    //dp[i][j]表示空间为j情况下，从0-i物品中取，最大价值

    //初始化第一行
    for (int i = weight[0]; i <= bagWeight; i ++) {
        dp[0][i] = dp[0][i - weight[0]] + value[0];
    }

    for (int i = 1; i < n; i ++) {
        for (int j = 1; j <= bagWeight; j ++) {
            if (j < weight[i]) dp[i][j] = dp[i - 1][j]; //不选物品i
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - weight[i]] + value[i]);//选物品i
                //注意max中第二个i，意味着i随便取
            }
        }
    }
    cout << dp[n - 1][bagWeight];
}
//输入示例：
//4 5
//1 2
//2 4
//3 4
//4 5
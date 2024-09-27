//给定一个整数数组
// prices，其中第 prices[i] 表示第 i 天的股票价格 。 
//
// 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）: 
//
// 
// 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。 
// 
//
// 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。 
//
// 
//
// 示例 1: 
//
// 
//输入: prices = [1,2,3,0,2]
//输出: 3 
//解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出] 
//
// 示例 2: 
//
// 
//输入: prices = [1]
//输出: 0
// 
//
// 
//
// 提示： 
//
// 
// 1 <= prices.length <= 5000 
// 0 <= prices[i] <= 1000 
// 
//
// Related Topics 数组 动态规划 👍 1769 👎 0

#include <bits/stdc++.h>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) return 0;
        //持股状态，不持股状态，更好理解
        vector<vector<int>> dp(prices.size(), vector<int>(2));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[1][0] = max(-prices[0], -prices[1]);
        dp[1][1] = max(dp[0][1], dp[0][0] + prices[1]);
        for (int i = 2; i < prices.size(); i ++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 2][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        for (auto& a : dp) {
            for (int b : a) cout << b << " ";
            cout << endl;
        }
        return dp[prices.size() - 1][1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        //保持持股状态，保持卖出股状态，卖出股，冷冻期状态
        vector<vector<int>> dp(prices.size(), vector<int>(4));
        dp[0][0] = -prices[0];
        for (int i = 1; i < prices.size(); i ++) {
            dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][3] - prices[i], dp[i - 1][1] - prices[i]));
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);
            dp[i][2] = dp[i - 1][0] + prices[i];
            dp[i][3] = dp[i - 1][2];
        }
        return max(dp[prices.size() - 1][1], max(dp[prices.size() - 1][2], dp[prices.size() - 1][3]));
    }
};
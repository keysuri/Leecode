//给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。 
//
// 在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。 
//
// 返回 你能获得的 最大 利润 。 
//
// 
//
// 示例 1： 
//
// 
//输入：prices = [7,1,5,3,6,4]
//输出：7
//解释：在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4。
//随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6 - 3 = 3。
//最大总利润为 4 + 3 = 7 。 
//
// 示例 2： 
//
// 
//输入：prices = [1,2,3,4,5]
//输出：4
//解释：在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4。
//最大总利润为 4 。 
//
// 示例 3： 
//
// 
//输入：prices = [7,6,4,3,1]
//输出：0
//解释：在这种情况下, 交易无法获得正利润，所以不参与交易可以获得最大利润，最大利润为 0。 
//
// 
//
// 提示： 
//
// 
// 1 <= prices.length <= 3 * 10⁴ 
// 0 <= prices[i] <= 10⁴ 
// 
//
// Related Topics 贪心 数组 动态规划 👍 2547 👎 0

#include <bits/stdc++.h>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //不考虑区间，只取整利润
        int profit = 0;
        for (int i = 1; i < prices.size(); i ++) {
            profit += max(prices[i] - prices[i - 1], 0);
        }
        return profit;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        //找一个谷点及随后一个峰点
        int cost = -1; //cost可能为0，取一个不可能的数
        for (int i = 0; i < prices.size() - 1; i ++) {
            if (cost == -1 && prices[i + 1] - prices[i] > 0) {
                cost = prices[i];
            }
            if (cost != -1 && prices[i + 1] - prices[i] < 0) {
                profit += prices[i] - cost;
                cost = -1;
            }
        }
        if (cost != -1) profit += prices[prices.size() - 1] - cost; //因为循环只到倒数第二个数，存在最后一个数是峰点情况
        return profit;
    }
};
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
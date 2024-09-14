#include <bits/stdc++.h>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candyVec(ratings.size(), 1);
        //从前往后，考虑后一个比前一个大的情况
        for (int i = 1; i < ratings.size(); i ++) {
            if (ratings[i] > ratings[i - 1]) candyVec[i] = candyVec[i - 1] + 1;
        }
        //从后往前，考虑前一个比后一个大的情况
        for (int i = ratings.size() - 2; i >= 0; i --) {
            if (ratings[i] > ratings[i + 1]) candyVec[i] = max(candyVec[i], candyVec[i + 1] + 1);
        }
        //两次遍历，保证了局部满足：评分高的糖果更多

        int result = 0;
        for (int a : candyVec) {
            result += a;
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

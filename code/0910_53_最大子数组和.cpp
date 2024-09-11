#include <bits/stdc++.h>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = INT32_MIN;
        int sum = 0;
        for (int i = 0; i < nums.size(); i ++) {
            sum += nums[i];
            if (sum > max) max = sum;
            if (sum < 0) sum = 0; //贪心思想，一旦sum<0，只会拖累总和，此时sum=0，从i+1开始计算
        }
        return max;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
// 暴力解法，超时
class Solution1 {
public:
    int maxSubArray(vector<int>& nums) {
        int max = INT32_MIN;
        for (int i = 0; i < nums.size(); i ++) {
            int sum = 0; //if写在for里面，如果先给sum赋值为num[i]会导致if走不到，比如-1 -2 -4 5
            for (int j = i; j < nums.size(); j ++) {
                sum += nums[j];
                if (sum > max) max = sum;
            }
        }
        return max;
    }
};
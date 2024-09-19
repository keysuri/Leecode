//给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,5,11,5]
//输出：true
//解释：数组可以分割成 [1, 5, 5] 和 [11] 。 
//
// 示例 2： 
//
// 
//输入：nums = [1,2,3,5]
//输出：false
//解释：数组不能分割成两个元素和相等的子集。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 200 
// 1 <= nums[i] <= 100 
// 
//
// Related Topics 数组 动态规划 👍 2150 👎 0

#include <bits/stdc++.h>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int a : nums) sum += a;
        if (sum % 2 == 1) return false;
        int target = sum / 2;
        vector<int> dp(target + 1, 0);
        //dp[j]表示 背包总容量是j，放进物品后，背的最大重量
        for (int j = nums[0]; j < target; j ++) dp[j] = nums[0];

        for (int i = 1; i < nums.size(); i ++) {
            for (int j = target; j >= nums[i]; j --) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        if (dp[target] == target) return true;//说明背包装满
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
// 0-1 背包问题求的是最大值，而子集求的是等于某个值，为何会用0-1背包求解？
// 找和为target的子集，可以看做背包总重target，所选物品价值只能<=target，也就是求最大值，最终如果等于，则找到子集
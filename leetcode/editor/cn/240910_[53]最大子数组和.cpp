//给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。 
//
// 子数组 是数组中的一个连续部分。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
//输出：6
//解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
// 
//
// 示例 2： 
//
// 
//输入：nums = [1]
//输出：1
// 
//
// 示例 3： 
//
// 
//输入：nums = [5,4,-1,7,8]
//输出：23
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 10⁵ 
// -10⁴ <= nums[i] <= 10⁴ 
// 
//
// 
//
// 进阶：如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的 分治法 求解。 
//
// Related Topics 数组 分治 动态规划 👍 6776 👎 0

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
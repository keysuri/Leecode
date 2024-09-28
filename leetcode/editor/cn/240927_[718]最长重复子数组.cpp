//给两个整数数组 nums1 和 nums2 ，返回 两个数组中 公共的 、长度最长的子数组的长度 。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
//输出：3
//解释：长度最长的公共子数组是 [3,2,1] 。
// 
//
// 示例 2： 
//
// 
//输入：nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
//输出：5
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums1.length, nums2.length <= 1000 
// 0 <= nums1[i], nums2[i] <= 100 
// 
//
// Related Topics 数组 二分查找 动态规划 滑动窗口 哈希函数 滚动哈希 👍 1120 👎 0

#include <bits/stdc++.h>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), 0));
        //dp[i][j]：以下标i为结尾的A，和以下标j 为结尾的B，最长公共子数组长度
        for (int j = 0; j < nums2.size(); j++) {
            if (nums1[0] == nums2[j]) dp[0][j] = 1;
        }
        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] == nums2[0]) dp[i][0] = 1;
        }
        for (int i = 1; i < nums1.size(); i++) {
            for (int j = 1; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            }
        }
        int max = 0;
        for (int i = 0; i < nums1.size(); i ++) {
            for (int j = 0; j < nums2.size(); j ++) {
                if (dp[i][j] > max) max = dp[i][j];
            }
        }
        return max;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
//暴力
class Solution1 {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int result = 0;
        for (int i = 0; i < nums1.size(); i ++) {
            for (int j = 0; j < nums2.size(); j ++) {
                if (nums1[i] == nums2[j]) {
                    int count = 0;
                    int m = i;
                    int n = j;
                    // (nums1[m] == nums2[n] && m < nums1.size() && n < nums2.size())
                    // 如果m，n已经大于数组长度，会溢出
                    while (m < nums1.size() && n < nums2.size() && nums1[m] == nums2[n]) {
                        count++;
                        m++;
                        n++;
                    }
                    result = max(result, count);
                }
            }
        }
        return result;
    }
};
int main() {
    Solution solution;
    vector<int> nums1 = {1,1,0,0,1,1};
    vector<int> nums2 = {0,0};
    cout << solution.findLength(nums1, nums2);
}
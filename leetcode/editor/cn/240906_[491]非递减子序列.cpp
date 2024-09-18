//给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中 至少有两个元素 。你可以按 任意顺序 返回答案。 
//
// 数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [4,6,7,7]
//输出：[[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [4,4,3,2,1]
//输出：[[4,4]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 15 
// -100 <= nums[i] <= 100 
// 
//
// Related Topics 位运算 数组 哈希表 回溯 👍 806 👎 0
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(int startIndex, vector<int>& nums) {
        if (path.size() >= 2) {
            result.push_back(path);
        }
        if (startIndex >= nums.size()) {
            return;
        }
        unordered_set<int> uset;
        for (int i = startIndex; i < nums.size(); i ++) {
            if (!path.empty() && nums[i] < path.back() || uset.find(nums[i]) != uset.end()) continue;
            path.push_back(nums[i]);
            uset.insert(nums[i]);
            backtracking(i + 1, nums);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(0, nums);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
int main() {
    Solution solution;
    vector<int> nums = {4,6,7,7};
    vector<vector<int>> result = solution.findSubsequences(nums);
    for (const auto& path: result) {
        for (int a : path) {
            cout << a;
        }
        cout << endl;
    }
}
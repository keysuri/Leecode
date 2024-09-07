// 这里用了set并不需要排序，但子集II必须要排序，因为集合内部的无序性，如[1,2] [2,1]在本题是两个排列，却是同一集合
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, vector<bool>& used) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        unordered_set<int> uset;
        for (int i = 0; i < nums.size(); i ++) {
            if (used[i] || uset.find(nums[i]) != uset.end()) continue; //used[i]树枝去重 uset同一层去重
            path.push_back(nums[i]);
            used[i] = true;
            uset.insert(nums[i]);
            backtracking(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
int main() {
    Solution solution;
    vector<int> nums = {1,1,2};
    vector<vector<int>> result = solution.permuteUnique(nums);

    for (const auto& path : result) {
        for (int num : path) {
            cout << num;
        }
        cout << endl;
    }
    return 0;
}
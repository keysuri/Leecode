#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(int startIndex, vector<int>& nums, vector<bool>& used) {
        result.push_back(path);
        if (startIndex >= nums.size()) {
            return;
        }
        for (int i = startIndex; i < nums.size(); i ++) {
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) continue;
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(i + 1, nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        backtracking(0, nums, used);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
int main() {
    Solution solution;
    vector<int> nums = {1,2,2};
    vector<vector<int>> result = solution.subsetsWithDup(nums);
    for (const auto& path: result) {
        for (int a : path) {
            cout << a;
        }
        cout << endl;
    }
}
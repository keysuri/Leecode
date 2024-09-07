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
            if (!path.empty() && nums[i] < path.back() || uset.find(nums[i]) != uset.end()) continue; // != uset.end() 表示遍历到结尾
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
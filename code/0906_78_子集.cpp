#include <iostream>
#include <vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(int startIndex, vector<int>& nums) {
        result.push_back(path);
        if (startIndex >= nums.size()) {
            return;
        }
        for (int i = startIndex; i < nums.size(); i ++) {
            path.push_back(nums[i]);
            backtracking(i + 1, nums);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(0, nums);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution solution;
    vector<int> nums = {1,2,3};
    vector<vector<int>> result = solution.subsets(nums);
    for (const auto& path: result) {
        for (int a : path) {
            cout << a;
        }
        cout << endl;
    }
}
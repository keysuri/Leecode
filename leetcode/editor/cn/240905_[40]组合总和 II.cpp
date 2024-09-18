//给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。 
//
// candidates 中的每个数字在每个组合中只能使用 一次 。 
//
// 注意：解集不能包含重复的组合。 
//
// 
//
// 示例 1: 
//
// 
//输入: candidates = [10,1,2,7,6,1,5], target = 8,
//输出:
//[
//[1,1,6],
//[1,2,5],
//[1,7],
//[2,6]
//] 
//
// 示例 2: 
//
// 
//输入: candidates = [2,5,2,1,2], target = 5,
//输出:
//[
//[1,2,2],
//[5]
//] 
//
// 
//
// 提示: 
//
// 
// 1 <= candidates.length <= 100 
// 1 <= candidates[i] <= 50 
// 1 <= target <= 30 
// 
//
// Related Topics 数组 回溯 👍 1587 👎 0

#include <bits/stdc++.h>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    int sum = 0;
    void backtracking(int startIndex, vector<int>& candidates, int target) {
        if (sum >= target) {
            if (sum == target)  result.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size(); i ++) {
            if (i > startIndex && candidates[i] == candidates[i - 1]) continue;
            path.push_back(candidates[i]);
            sum += candidates[i];
            backtracking(i + 1, candidates, target);
            path.pop_back();
            sum -= candidates[i];
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtracking(0,candidates, target);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
int main() {
    Solution solution;
    vector<int> candidates = {10,1,2,7,6,1,5};
    vector<vector<int>> result = solution.combinationSum2(candidates, 8);
    for (const auto& path : result) {
        for (int num : path) {
            cout << num << " ";
        }
        cout << endl;
    }
}
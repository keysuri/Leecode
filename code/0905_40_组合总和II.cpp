#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(int sum, int startIndex, vector<int>& candidates, int target) {
        if (sum >= target) {
            if (sum == target) {
                result.push_back(path);
            }
            return;
        }
        for (int i = startIndex; i < candidates.size(); i ++) {
            if (i > startIndex && candidates[i] == candidates[i - 1]) continue; //同一层跳过
            path.push_back(candidates[i]);
            sum += candidates[i];
            backtracking(sum, i + 1, candidates, target);
            path.pop_back();
            sum -= candidates[i];
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtracking(0, 0, candidates, target);
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> candidates = {10,1,2,7,6,1,5};
    vector<vector<int>> result = solution.combinationSum(candidates, 8);
    for (const auto& path : result) {
        for (int num : path) {
            cout << num << " ";
        }
        cout << endl;
    }
}
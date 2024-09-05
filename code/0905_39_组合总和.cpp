#include <iostream>
#include <vector>
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
            path.push_back(candidates[i]);
            sum += candidates[i];
            backtracking(sum, i, candidates, target);
            path.pop_back();
            sum -= candidates[i];
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(0, 0, candidates, target);
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> candidates = {2,3,6,7};
    vector<vector<int>> result = solution.combinationSum(candidates, 7);
    for (const auto& path : result) {
        for (int num : path) {
            cout << num;
        }
        cout << endl;
    }
}
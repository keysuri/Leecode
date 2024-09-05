#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(int startIndex, int n, int k) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i <= n - (k - path.size()) + 1; i ++) {
            path.push_back(i);
            backtracking(i + 1, n, k);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        backtracking(1, n, k);
        return result;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> combinations = solution.combine(4, 2);

    for (const auto& combination : combinations) {
        for (int num : combination) {
            cout << num;
        }
        cout << endl;
    }
    return 0;
}

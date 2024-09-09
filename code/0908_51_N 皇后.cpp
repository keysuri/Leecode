#include <bits/stdc++.h>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<vector<string>> result;
    void backtracking(int n, int row, vector<string>& chessboard) {
        if (row == n) {
            result.push_back(chessboard);
            return;
        }
        for (int j = 0; j < n; j ++) {
            if (isValid(row, j, n, chessboard)) {
                chessboard[row][j] = 'Q';
                backtracking(n, row + 1, chessboard);
                chessboard[row][j] = '.';
            }
        }
    }
    bool isValid(int row, int col, int n, vector<string>& chessboard) {
        // 检查列
        for (int i = 0; i < row; i ++) {
            if (chessboard[i][col] == 'Q') return false;
        }
        // 检查45°  只用看左上，因为右下还没有
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i --, j --) {
            if (chessboard[i][j] == 'Q') return false;
        }
        // 检查135°
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i --, j ++) {
            if (chessboard[i][j] == 'Q') return false;
        }
        return true;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> chessboard(n, string (n, '.')); //表示 n 个字符串。每个字符串都是由 n 个字符 '.' 组成的
        backtracking(n, 0, chessboard);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution solution;
    vector<vector<string>> result = solution.solveNQueens(1);
    for (const auto& row : result) {
        for (const string& s : row) {
            cout << s << endl;
        }
        cout << endl;
    }
}
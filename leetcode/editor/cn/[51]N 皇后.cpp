//按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。 
//
// n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。 
//
// 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。 
//
// 
// 
// 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。 
// 
// 
//
// 
//
// 示例 1： 
// 
// 
//输入：n = 4
//输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
//解释：如上图所示，4 皇后问题存在两个不同的解法。
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：[["Q"]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 9 
// 
//
// Related Topics 数组 回溯 👍 2123 👎 0

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
// char 数字也可以++，元素所属三宫格计算
#include <bits/stdc++.h>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    bool backtracking(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i ++) {
            for (int j = 0; j < board[0].size(); j ++) {
                if (board[i][j] != '.') continue;
                for (char k = '1'; k <= '9'; k ++) {
                    if (isValid(k, i, j, board)) {
                        board[i][j] = k;
                        if (backtracking(board)) return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }
    bool isValid(char k, int row, int col, vector<vector<char>>& board) {
        // 同行
        for (int j = 0; j < board[0].size(); j ++) {
            if (board[row][j] == k) return false;
        }
        // 同列
        for (int i = 0; i < board.size(); i ++) {
            if (board[i][col] == k) return false;
        }
        // 同宫格
        int startI = row / 3 * 3;
        int startJ = col / 3 * 3;
        for (int i = startI; i < startI + 3; i ++) {
            for (int j = startJ; j < startJ + 3; j ++) {
                if (board[i][j] == k) return false;
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution solution;
    vector<vector<char>> board = {
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    solution.solveSudoku(board);
    for (int i = 0; i < board.size(); i ++) {
        for (int j = 0; j < board[0].size(); j ++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

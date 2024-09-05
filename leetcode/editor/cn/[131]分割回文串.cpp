//给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "aab"
//输出：[["a","a","b"],["aa","b"]]
// 
//
// 示例 2： 
//
// 
//输入：s = "a"
//输出：[["a"]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 16 
// s 仅由小写英文字母组成 
// 
//
// Related Topics 字符串 动态规划 回溯 👍 1840 👎 0

#include <iostream>
#include <vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<vector<string>> result;
    vector<string> path;
    void backtracking(int startIndex, const string& s) {
        if (startIndex >= s.size()) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < s.size(); i ++) {
            if (isPalindrome(startIndex, i, s)) {
                string temps = s.substr(startIndex, i - startIndex + 1); // 提取从位置x开始的n个字符
                path.push_back(temps);
            } else {
                continue;
            }
            backtracking(i + 1, s);
            path.pop_back();
        }
    }
    bool isPalindrome(int start, int end, const string& s) {
        while (end > start) {
            if (s[end] != s[start])
                return false;
            end --;
            start ++;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        backtracking(0, s);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main () {
    Solution solution;
    string s = "aab";
    vector<vector<string>> result = solution.partition(s);
    for (const auto& path : result) {
        for (const string& ss : path) {
            cout << ss << " ";
        }
        cout << endl;
    }
}
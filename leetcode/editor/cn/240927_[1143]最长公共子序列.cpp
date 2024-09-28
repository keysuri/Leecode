//给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。如果不存在 公共子序列 ，返回 0 。 
//
// 一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。 
//
// 
// 例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。 
// 
//
// 两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。 
//
// 
//
// 示例 1： 
//
// 
//输入：text1 = "abcde", text2 = "ace" 
//输出：3  
//解释：最长公共子序列是 "ace" ，它的长度为 3 。
// 
//
// 示例 2： 
//
// 
//输入：text1 = "abc", text2 = "abc"
//输出：3
//解释：最长公共子序列是 "abc" ，它的长度为 3 。
// 
//
// 示例 3： 
//
// 
//输入：text1 = "abc", text2 = "def"
//输出：0
//解释：两个字符串没有公共子序列，返回 0 。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= text1.length, text2.length <= 1000 
// text1 和 text2 仅由小写英文字符组成。 
// 
//
// Related Topics 字符串 动态规划 👍 1622 👎 0

#include <bits/stdc++.h>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        //dp[i][j] 长度为[0, i - 1]的字符串text1与长度为[0, j - 1]的字符串text2的最长公共子序列为dp[i][j]
        //避免了初始化操作
        for (int i = 1; i <= text1.size(); i ++) {
            for (int j = 1; j <= text2.size(); j ++) {
                if (text1[i - 1] == text2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        return dp[text1.size()][text2.size()];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
// 手动初始化第一行，第一列
class Solution1 {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), 0));
        //dp[i][j] 以下标i为结尾的A，和以下标j 为结尾的B，最长公共子串长度
        for (int j = 0; j < text2.size(); j++) {
            if (text1[0] == text2[j]) {
                while (j < text2.size()) {
                    dp[0][j] = 1;
                    j++;
                }
            }
        }
        for (int i = 0; i < text1.size(); i++) {
            if (text1[i] == text2[0]) {
                while (i < text1.size()) {
                    dp[i][0] = 1;
                    i++;
                }
            }
        }
        for (int i = 1; i < text1.size(); i ++) {
            for (int j = 1; j < text2.size(); j ++) {
                if (text1[i] == text2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        return dp[text1.size() - 1][text2.size() - 1];
    }
};
//给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。 
//
// 回文字符串 是正着读和倒过来读一样的字符串。 
//
// 子字符串 是字符串中的由连续字符组成的一个序列。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "abc"
//输出：3
//解释：三个回文子串: "a", "b", "c"
// 
//
// 示例 2： 
//
// 
//输入：s = "aaa"
//输出：6
//解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa" 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 1000 
// s 由小写英文字母组成 
// 
//
// Related Topics 双指针 字符串 动态规划 👍 1371 👎 0

#include <bits/stdc++.h>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        //dp[i][j] 区间[i,j]字符串是否为回文子串
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j]) { //若不等一定是false
                    if (i == j) dp[i][j] = true;
                    else if (i + 1 == j) dp[i][j] = true;
                    else dp[i][j] = dp[i + 1][j - 1]; //递推公式决定了遍历顺序，下->上，左->右
                }
            }
        }
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            for(int j = 0; j < s.size(); j++) {
                if (dp[i][j] == true) result++;
            }
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
//双指针法
class Solution1 {
public:
    int extend(const string& s, int i, int j, int n) {
        int res = 0;
        while (i >= 0 && j <= n && s[i] == s[j]) {
            res++;
            i--;
            j++;
        }
        return res;
    }
    int countSubstrings(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            result += extend(s, i, i, s.size()); //以i为中心情况
            result += extend(s, i, i + 1, s.size()); //以一个i, i+1为中心
        }
        return result;
    }
};
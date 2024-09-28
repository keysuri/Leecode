//给你两个字符串 s 和 t ，统计并返回在 s 的 子序列 中 t 出现的个数，结果需要对 10⁹ + 7 取模。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "rabbbit", t = "rabbit"
//输出：3
//解释：
//如下所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
//rabbbit
//rabbbit
//rabbbit 
//
// 示例 2： 
//
// 
//输入：s = "babgbag", t = "bag"
//输出：5
//解释：
//如下所示, 有 5 种可以从 s 中得到 "bag" 的方案。 
//babgbag
//babgbag
//babgbag
//babgbag
//babgbag
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length, t.length <= 1000 
// s 和 t 由英文字母组成 
// 
//
// Related Topics 字符串 动态规划 👍 1274 👎 0

#include <bits/stdc++.h>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<uint64_t>> dp(s.size() + 1, vector<uint64_t>(t.size() + 1, 0));
        //dp[i][j] [0, i -1](s的前i个元素）中，有多少个t的[0, j - 1]匹配   （区间内，s不一定以i结尾）
        //初始化列
        for (int i = 0; i <= s.size(); i++) dp[i][0] = 1;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <=t.size(); j++) {
                if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                //用当前元素匹配 + 不用当前元素匹配()
                else dp[i][j] = dp[i - 1][j];//不用当前元素匹配(在s中删除该元素)
            }
        }
        return dp[s.size()][t.size()];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

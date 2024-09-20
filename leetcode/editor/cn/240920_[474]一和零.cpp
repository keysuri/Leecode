//给你一个二进制字符串数组 strs 和两个整数 m 和 n 。 
//
// 
// 请你找出并返回 strs 的最大子集的长度，该子集中 最多 有 m 个 0 和 n 个 1 。 
// 
//
// 如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。 
//
// 
//
// 示例 1： 
//
// 
//输入：strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3
//输出：4
//解释：最多有 5 个 0 和 3 个 1 的最大子集是 {"10","0001","1","0"} ，因此答案是 4 。
//其他满足题意但较小的子集包括 {"0001","1"} 和 {"10","1","0"} 。{"111001"} 不满足题意，因为它含 4 个 1 ，大于 
//n 的值 3 。
// 
//
// 示例 2： 
//
// 
//输入：strs = ["10", "0", "1"], m = 1, n = 1
//输出：2
//解释：最大的子集是 {"0", "1"} ，所以答案是 2 。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= strs.length <= 600 
// 1 <= strs[i].length <= 100 
// strs[i] 仅由 '0' 和 '1' 组成 
// 1 <= m, n <= 100 
// 
//
// Related Topics 数组 字符串 动态规划 👍 1173 👎 0

#include <bits/stdc++.h>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        //dp[i][j][k]表示前i个字符串中，使用j个0和k个1，最多可以得到的字符串数量
        vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
        //计算每个串的01数量
        vector<int> zeros;
        vector<int> ones;
        for (auto& str : strs) {
            int zero = 0;
            int one = 0;
            for (char &c : str) {
                if (c == '0') zero ++;
                else one ++;
            }
            zeros.push_back(zero);
            ones.push_back(one);
        }
        //初始化i = 0
        if (zeros[0] <= m && ones[0] <= n) {
            for (int j = zeros[0]; j <= m; j ++) {
                for (int k = ones[0]; k <= n; k ++)
                    dp[0][j][k] = 1;
            }
        }

        for (int i = 1; i < strs.size(); i ++) {
            int zero = zeros[i], one = ones[i];
            for (int j = 0; j <= m; j ++) {
                for(int k = 0; k <= n; k ++) {
                    if (j < zero || k < one) dp[i][j][k] = dp[i - 1][j][k]; //不选字符串i
                    else dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - zero][k - one] + 1);
                    //选字符串i，则前i-1个字符串在j-zero个0，和k-one个1容量下最大字符串数
                }
            }
        }
        return dp[strs.size() - 1][m][n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

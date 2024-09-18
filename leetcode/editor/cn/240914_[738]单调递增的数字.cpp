//当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。 
//
// 给定一个整数 n ，返回 小于或等于 n 的最大数字，且数字呈 单调递增 。 
//
// 
//
// 示例 1: 
//
// 
//输入: n = 10
//输出: 9
// 
//
// 示例 2: 
//
// 
//输入: n = 1234
//输出: 1234
// 
//
// 示例 3: 
//
// 
//输入: n = 332
//输出: 299
// 
//
// 
//
// 提示: 
//
// 
// 0 <= n <= 10⁹ 
// 
//
// Related Topics 贪心 数学 👍 479 👎 0

#include <bits/stdc++.h>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string strNum = to_string(n); //方便下标索引
        int flag = strNum.size(); // 用来标志从哪里开始往后赋值为9
        for (int i = strNum.size() - 1; i > 0; i --) {
            if (strNum[i] < strNum[i - 1]) {
                flag = i;
                strNum[i - 1] --;
            }
        }
        for (int i = flag; i < strNum.size(); i ++) strNum[i] = '9';
        return stoi(strNum); //string to int
    }
};
//leetcode submit region end(Prohibit modification and deletion)

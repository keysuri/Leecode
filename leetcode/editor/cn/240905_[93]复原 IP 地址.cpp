//有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。 
//
// 
// 例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 
//和 "192.168@1.1" 是 无效 IP 地址。 
// 
//
// 给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。你 不能 重新
//排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "25525511135"
//输出：["255.255.11.135","255.255.111.35"]
// 
//
// 示例 2： 
//
// 
//输入：s = "0000"
//输出：["0.0.0.0"]
// 
//
// 示例 3： 
//
// 
//输入：s = "101023"
//输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 20 
// s 仅由数字组成 
// 
//
// Related Topics 字符串 回溯 👍 1441 👎 0

#include <iostream>
#include <vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<string> result;
    void backtracking(int startIndex, string& s, int pointNum) {
        if (pointNum == 3) {
            if (isValid(startIndex, s.size() - 1, s)) {
                result.push_back(s);
            }
            return;
        }
        for (int i = startIndex; i < s.size(); i ++) {
            if (isValid(startIndex, i, s)) {
                s.insert(s.begin() + i + 1, '.');
                pointNum ++;
                backtracking(i + 2, s, pointNum);
                pointNum --;
                s.erase(s.begin() + i + 1);
            } else {
                break;
            }
        }
    }
    bool isValid(int start, int end, const string& s) {
        if (s[start] == '0' && start != end) return false;
        int num = 0;
        for (int i = start; i <= end; i ++) {
            num = num * 10 + (s[i] - '0');  //计算字符串数字值
        }
        if (num > 255) return false;
        return true;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        backtracking(0, s, 0);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main () {
    Solution solution;
    string s = "25525511135";
    vector<string> result = solution.restoreIpAddresses(s);
    for (const string& ss : result) {
        cout << ss << endl;
    }
}
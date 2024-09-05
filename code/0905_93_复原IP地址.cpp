#include <iostream>
#include <vector>
using namespace std;

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

int main () {
    Solution solution;
    string s = "25525511135";
    vector<string> result = solution.restoreIpAddresses(s);
    for (const string& ss : result) {
        cout << ss << endl;
    }
}
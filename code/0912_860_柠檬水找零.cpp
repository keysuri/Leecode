#include <bits/stdc++.h>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int A = 0, B = 0;
        for (int bill : bills) {
            if (bill == 5) {
                A ++;
            }
            else if (bill == 10) {
                B ++;
                A --;
            } else {
                // 20元也可以用三个5元找回
                if (B - 1 < 0) A -= 3;
                else {
                    A --;
                    B --;
                }
            }
            if (A < 0 || B < 0) return false;
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
//贪心：面对20元找零时，优先用掉10元面额的
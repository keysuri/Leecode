#include <bits/stdc++.h>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int preDiff = 0, curDiff = 0;
        int result = 1; // 峰值个数，最右边有一个峰值
        for (int i = 0; i < nums.size() - 1; i ++) {
            curDiff = nums[i + 1] - nums[i];
            if ((preDiff >= 0 && curDiff < 0) || (preDiff <= 0 && curDiff > 0)) {
                result ++;
                preDiff = curDiff; //只在摆动变化的时候更新preDiff
            }
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
int main() {
    Solution solution;
    vector<int> nums = {1,2,2,2,3,4};
    int result = solution.wiggleMaxLength(nums);
    cout << result;
}
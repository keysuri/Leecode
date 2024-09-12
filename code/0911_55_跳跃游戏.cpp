#include <bits/stdc++.h>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) return true;
        int cover = 0;

//        //错误，并不是所有元素都能达到，要以覆盖范围向后走
//        for (int i = 0; i < nums.size() - 1; i ++) {
//            if (nums[i] >= nums.size() - i - 1) return true;
//        }
//        return false;
        for (int i = 0; i <= cover; i ++) {
            cover = max(cover, i + nums[i]);
            if (cover >= nums.size() - 1) return true;
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

#include <bits/stdc++.h>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int result = 1;
        int cover = nums[0];
        int nextCover = cover;
        //nextCover本身就已覆盖终点了，特殊处理
        if (nextCover >= nums.size() - 1) return result;
        for (int i = 0; i <= cover; i ++) {
            if (i + nums[i] > nextCover) {
                nextCover = i + nums[i];
            }
            if (i == cover) {
                cover = nextCover;
                result ++;
                if (nextCover >= nums.size() - 1) break;
            }
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

#include <bits/stdc++.h>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
static bool cmp(int a, int b) {
        return abs(a) > abs(b);
    }
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), [](int a, int b){return abs(a) > abs(b);});
        for (int i = 0; i < nums.size(); i ++) {
            if (k <= 0) break;
            if (nums[i] < 0) {
                nums[i] = - nums[i];
                k --;
            }
        }
        while (k > 0) {
            nums[nums.size() - 1] = - nums[nums.size() - 1];
            k --;
        }
        int sum = 0;
        for (int a : nums) sum += a;
        return sum;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

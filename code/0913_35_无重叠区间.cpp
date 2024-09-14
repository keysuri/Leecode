#include <bits/stdc++.h>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        else return a[0] < b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int result = 0;
        int end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i ++) {
            if (intervals[i][0] >= end) {
                end = intervals[i][1];
            }
            else {
                end = min(end, intervals[i][1]);
                result ++;
            }
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
// 也可以右区间排序
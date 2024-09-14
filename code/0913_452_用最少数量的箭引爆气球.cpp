#include <bits/stdc++.h>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        else return a[0] < b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int end = points[0][1];
        int result = 1;
        for (int i = 1; i < points.size(); i ++) {
            if (points[i][0] > end) {
                result ++;
                end = points[i][1];
            } else { //考虑重叠情况下，重叠气球中右边边界的最小值 之前的区间一定需要一个弓箭
                end = min(end, points[i][1]);
            }
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
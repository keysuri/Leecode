#include <bits/stdc++.h>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        int num = 0;
        int i = 0, j = 0;
        while (i < s.size() && j < g.size()) {
            if (s[i] >= g[j]) {
                num ++;
                i ++;
                j ++;
            } else {
                i ++;
            }
        }
        return num;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

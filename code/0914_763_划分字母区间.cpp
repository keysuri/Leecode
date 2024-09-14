#include <bits/stdc++.h>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> map;
        for (int i = 0; i < s.size(); i ++) {
            map[s[i]] = i;
        }
        vector<int> result;
        int start = 0;
        int end = 0;
        for (int i = 0; i < s.size(); i ++) {
            end = max(end, map[s[i]]);
            if (i == end) {
                result.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

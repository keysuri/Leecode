#include <bits/stdc++.h>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
//不好想
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int curSum = 0;
        int totalSum = 0;
        int start = 0;
        for (int i = 0; i < n; i ++) {
            curSum += gas[i] - cost[i];
            totalSum += gas[i] - cost[i];

            if (curSum < 0) {
                start = i + 1;
                curSum = 0;
            }
        }
        if (totalSum < 0) return -1;
        return start;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
//暴力超时
class Solution1 {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for (int i = 0; i < n; i ++) {
            int rest = gas[i] - cost[i];
            int index = (i + 1) % n;
            while (rest > 0 && index != i) {
                rest += gas[index] - cost[index];
                index = (index + 1) % n;
            }
            if (rest >= 0 && index == i) return i;
        }
        return -1;
    }
};
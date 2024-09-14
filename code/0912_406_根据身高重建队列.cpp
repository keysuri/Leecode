#include <bits/stdc++.h>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) { //引用传递，避免复制
        if (a[0] == b[0]) return a[1] < b[1]; // 小的数量在前面
        else return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
//        vector<vector<int>> que;
//        for (int i = 0; i < people.size(); i ++) {
//            int position = people[i][1];
//            que.insert(que.begin() + position, people[i]);
//        }
//        return que;
//用链表实现，比vector（动态数组）效率高
        list<vector<int>> que;
        for (int i = 0; i < people.size(); i++) {
            int position = people[i][1];
            list<vector<int>>::iterator it = que.begin();
            while (position--) { // 寻找在插入位置
                it++;
            }
            que.insert(it, people[i]);
        }
        return vector<vector<int>>(que.begin(), que.end());
    }
};
//leetcode submit region end(Prohibit modification and deletion)
//遇到两个维度权衡的时候，一定要先确定一个维度，再确定另一个维度。
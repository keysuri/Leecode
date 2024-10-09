//给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。 
//
// 求在该柱状图中，能够勾勒出来的矩形的最大面积。 
//
// 
//
// 示例 1: 
//
// 
//
// 
//输入：heights = [2,1,5,6,2,3]
//输出：10
//解释：最大的矩形为图中红色区域，面积为 10
// 
//
// 示例 2： 
//
// 
//
// 
//输入： heights = [2,4]
//输出： 4 
//
// 
//
// 提示： 
//
// 
// 1 <= heights.length <=10⁵ 
// 0 <= heights[i] <= 10⁴ 
// 
//
// Related Topics 栈 数组 单调栈 👍 2801 👎 0

#include <bits/stdc++.h>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int result = 0;
        stack<int> st;
        heights.insert(heights.begin(), 0);//防止本身降序时跳过计算结果
        heights.push_back(0);//防止本身升序时跳过计算结果
        st.push(0);

        for (int i = 1; i < heights.size(); i++) {
            if (heights[i] > heights[st.top()]) st.push(i);
            else if (heights[i] == heights[st.top()]) {
                st.pop();
                st.push(i);
            } else {
                while(!st.empty() && heights[i] < heights[st.top()]) {
                    int mid = st.top();
                    st.pop();
                    if (!st.empty()) {
                        int left = st.top();
                        int right = i;
                        int w = right - left - 1;
                        int h = heights[mid];
                        result = max(result, h * w);
                    }
                }
                st.push(i);
            }
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
class Solution1 {
public:
    int largestRectangleArea(vector<int>& heights) {
        //求每个高度的矩形的大小，这次是找左右第一个最小值的下标
        int size = heights.size();
        vector<int> minLeftIndex(size, 0);
        vector<int> minRightIndex(size, 0);
        minLeftIndex[0] = -1; //防止下面死循环
        for (int i = 1; i < size; i++) {
            int t = i - 1;
            while (t >= 0 && heights[t] >= heights[i]) t = minLeftIndex[t];
            minLeftIndex[i] = t;
        }
        minRightIndex[size - 1] = size; //防止下面死循环
        for (int i = size - 2; i >= 0; i--) {
            int t = i + 1;
            while (t < size && heights[t] >= heights[i]) t = minRightIndex[t];
            minRightIndex[i] = t;
        }
        int result = 0;
        for (int i = 0; i < size; i++) {
            int sum = heights[i] * (minRightIndex[i] - minLeftIndex[i] - 1);
            result = max(result, sum);
        }
        return result;
    }
};
//给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
//输出：6
//解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
// 
//
// 示例 2： 
//
// 
//输入：height = [4,2,0,3,2,5]
//输出：9
// 
//
// 
//
// 提示： 
//
// 
// n == height.length 
// 1 <= n <= 2 * 10⁴ 
// 0 <= height[i] <= 10⁵ 
// 
//
// Related Topics 栈 数组 双指针 动态规划 单调栈 👍 5337 👎 0

#include <bits/stdc++.h>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
//单调栈，横着计算
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st; //从小到大
        st.push(0);
        int result = 0;
        for (int i = 1; i < height.size(); i++) {
            if (height[i] < height[st.top()]) st.push(i);
            else if (height[i] == height[st.top()]) { //相同跳过
                st.pop();
                st.push(i);
            } else {
                while (!st.empty() && height[i] > height[st.top()]) {
                    int mid = st.top();
                    st.pop();
                    if (!st.empty()) {
                        int h = min(height[i], height[st.top()]) - height[mid];
                        int w = i - st.top() - 1;
                        result += h * w;
                    }
                }
                st.push(i);
            }
        }
        return result;
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
//暴力解法，竖着计算
class Solution1 {
public:
    int trap(vector<int>& height) {
        int result = 0;
        for (int i = 0; i < height.size(); i++) {
            if (i == 0 || i == height.size() - 1) continue;//第一个和最后一个不接水
            int left = height[i];
            int right = height[i];
            //找左右两边最大值，不需break
            for (int m = i; m >= 0; m--) {
                if (height[m] > left) {
                    left = height[m];
                }
            }
            for (int m = i; m < height.size(); m++) {
                if (height[m] > right) {
                    right = height[m];
                }
            }
            result += min(left, right) - height[i];
        }
        return result;
    }
};
//双指针优化，有点像dp
class Solution2 {
public:
    int trap(vector<int>& height) {
        //记录每个元素左右最大值
        int size = height.size();
        vector<int> leftMax(size, 0);
        vector<int> rightMax(size, 0);
        //记录左边最大值
        leftMax[0] = height[0];
        for (int i = 1; i < size; i++) {
            leftMax[i] = max(height[i], leftMax[i - 1]);
        }
        //记录右边最大值
        rightMax[size - 1] = height[size - 1];
        for (int i = size - 2; i >= 0; i--) {
            rightMax[i] = max(height[i], rightMax[i + 1]);
        }

        int result = 0;
        for (int i = 0; i < height.size(); i++) {
            result += min(leftMax[i], rightMax[i]) - height[i];
        }
        return result;
    }
};
//给定一个循环数组 nums （ nums[nums.length - 1] 的下一个元素是 nums[0] ），返回 nums 中每个元素的 下一个更大元素
// 。 
//
// 数字 x 的 下一个更大的元素 是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1 
//。 
//
// 
//
// 示例 1: 
//
// 
//输入: nums = [1,2,1]
//输出: [2,-1,2]
//解释: 第一个 1 的下一个更大的数是 2；
//数字 2 找不到下一个更大的数； 
//第二个 1 的下一个最大的数需要循环搜索，结果也是 2。
// 
//
// 示例 2: 
//
// 
//输入: nums = [1,2,3,4,3]
//输出: [2,3,4,-1,4]
// 
//
// 
//
// 提示: 
//
// 
// 1 <= nums.length <= 10⁴ 
// -10⁹ <= nums[i] <= 10⁹ 
// 
//
// Related Topics 栈 数组 单调栈 👍 1006 👎 0

#include <bits/stdc++.h>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //将两个nums拼接
        vector<int> nums1(nums.begin(), nums.end());
        nums.insert(nums.end(), nums1.begin(), nums1.end());
        vector<int> result(nums.size(), -1);

        stack<int> st;
        st.push(0);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= nums[st.top()]) st.push(i);
            else {
                while (!st.empty() && nums[i] > nums[st.top()]) {
                    result[st.top()] = nums[i];
                    st.pop();
                }
                st.push(i);
            }
        }
        result.resize(nums.size() / 2);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
int main() {
    Solution solution;
    vector<int> nums = {1,2,3,4,3};
    solution.nextGreaterElements(nums);
}
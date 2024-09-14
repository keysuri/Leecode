#include <bits/stdc++.h>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {

//状态定义，3种
//  0：该节点无覆盖
//  1：本节点有摄像头
//  2：本节点有覆盖
public:
    int result = 0;
    int traversal(TreeNode * cur) {
        if (cur == nullptr) return 2;
        int left = traversal(cur->left);
        int right = traversal(cur->right);
        // 3*3=9种情况，从本节点状态考虑，就只用考虑三种情况
        //情况1：左右均覆盖
        if (left == 2 && right == 2) return 0;
        //情况2：左右至少一个无覆盖        2和3顺序不能反，一旦有个无覆盖，不管另一个是否有摄像头都得返回1
        if (left == 0 || right == 0) {
            result ++;
            return 1;
        }
        //情况3：左右至少一个摄像头
        if (left == 1 || right == 1) return 2;
        //不会走到这里
        return -1;
    }
    int minCameraCover(TreeNode *root) {
        if (traversal(root) ==0) result ++; //第四种情况，根节点未覆盖
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
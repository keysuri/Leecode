//给定一个二叉树，我们在树的节点上安装摄像头。 
//
// 节点上的每个摄影头都可以监视其父对象、自身及其直接子对象。 
//
// 计算监控树的所有节点所需的最小摄像头数量。 
//
// 
//
// 示例 1： 
//
// 
//
// 输入：[0,0,null,0,0]
//输出：1
//解释：如图所示，一台摄像头足以监控所有节点。
// 
//
// 示例 2： 
//
// 
//
// 输入：[0,0,null,0,null,0,null,null,0]
//输出：2
//解释：需要至少两个摄像头来监视树的所有节点。 上图显示了摄像头放置的有效位置之一。
// 
//
// 提示： 
//
// 
// 给定树的节点数的范围是 [1, 1000]。 
// 每个节点的值都是 0。 
// 
//
// Related Topics 树 深度优先搜索 动态规划 二叉树 👍 747 👎 0

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
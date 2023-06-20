/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 *
 * https://leetcode.cn/problems/balanced-binary-tree/description/
 *
 * algorithms
 * Easy (57.53%)
 * Likes:    1308
 * Dislikes: 0
 * Total Accepted:    492.1K
 * Total Submissions: 855.4K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，判断它是否是高度平衡的二叉树。
 * 
 * 本题中，一棵高度平衡二叉树定义为：
 * 
 * 
 * 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [1,2,2,3,3,null,null,4,4]
 * 输出：false
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：root = []
 * 输出：true
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中的节点数在范围 [0, 5000] 内
 * -10^4 
 * 
 * 
 */

// @lc code=start
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


// ----------------------- binary tree --------------------
// 迭代栈入NULL标记每一个孩子，出栈是出两个

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        return dfs(root) == -1 ? false : true;
    }

    int dfs(TreeNode* cur) { // return -1, other numbers (bool 0, 1)
        if (!cur) return 0;
        int h1 = dfs(cur->left);
        int h2 = dfs(cur->right);
        if (h1 == -1 || h2 == -1) return -1; // 防止-1 - -1 类似情况
        cout << cur->val << " " << h1 << " " << h2 << " "<< endl;
        return abs(h1 - h2) > 1 ? -1 : max(h1, h2) + 1; 
    }
};
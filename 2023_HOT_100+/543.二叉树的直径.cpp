/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
class Solution {
public:
    int maxLen = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int a = dfs(root->left);
        int b = dfs(root->right);
        if (a + b > maxLen)
            maxLen = a + b;
        return maxLen;
    }
    int dfs(TreeNode* root) {
        if (!root) return 0;
        int a = dfs(root->left);
        int b = dfs(root->right);
        if (a == 0 && b == 0)
            return 1;
        if (a + b > maxLen) 
            maxLen = a + b;
        return a > b ? a + 1 : b + 1;
    }
};
// @lc code=end


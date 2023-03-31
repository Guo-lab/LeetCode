/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
    TreeNode* convertBST(TreeNode* root) {
        if (!root) return root;
        root->val += dfs(root->right, 0);
        dfs(root->left, root->val);
        return root;
    }
    int dfs(TreeNode* root, int cur) {
        if (!root) return cur;
        root->val += dfs(root->right, cur);
        int b = dfs(root->left, root->val);
        // return value interesting
        return b;
    }
};
// @lc code=end


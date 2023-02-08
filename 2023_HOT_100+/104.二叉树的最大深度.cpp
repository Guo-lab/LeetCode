/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int maxD = 0;
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        else if (root->left == nullptr && root->right == nullptr) return 1;
        else {
            dfs(root->left, 1);
            dfs(root->right, 1);
            return maxD;
        }
    }
    void dfs(TreeNode* root, int depth) {
        if (root == nullptr) {
            maxD = (maxD < depth) ? depth : maxD;
            return;
        }
        else {
            dfs(root->left, depth + 1);
            dfs(root->right, depth + 1);
        }
    }
};
// @lc code=end


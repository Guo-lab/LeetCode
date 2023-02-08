/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;
        else {
            ino_travel(root->left, result);
            result.push_back(root->val);
            ino_travel(root->right, result);
            return result;
        }
    }
    void ino_travel(TreeNode* root, vector<int>& result) {
        if (root == nullptr) return;
        else {
            ino_travel(root->left, result);
            result.push_back(root->val);
            ino_travel(root->right, result);
        }
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isSymmetric(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) return true;
        else if (root->left == nullptr || root->right == nullptr) return false;
        else if (root->left->val != root->right->val) return false;
        else {
            bool isSym = true;
            isSym &= isSymDfs(root->left->left, root->right->right);
            isSym &= isSymDfs(root->right->left, root->left->right);
            return isSym;
        }
    }
    bool isSymDfs(TreeNode* lChild, TreeNode* rChild) {
        if (lChild == nullptr && rChild == nullptr) return true;
        else if (lChild == nullptr || rChild == nullptr) return false; 
        else if (lChild->val != rChild->val) return false;
        else {
            return isSymDfs(lChild->left, rChild->right) & isSymDfs(rChild->left, lChild->right);
        }   
    }
};
// @lc code=end


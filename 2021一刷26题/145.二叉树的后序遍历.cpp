/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==nullptr) return {};
        vector<int> res;
        stack<TreeNode*> parse;
        TreeNode* tmp;
        while (!parse.empty() || root!=nullptr)
        {
            if(root!=nullptr) {
                parse.push(root);
                root = root->left;
            }
            else {
                root = parse.top();
                // tmp: Distinguish First Time Back To Rootnode
                if(root->right!=nullptr && root->right!=tmp) {
                    root = root->right;
                    continue;
                }
                parse.pop();
                res.push_back(root->val);
                tmp = root;
                root = nullptr;
            }
        }
        return res;
        
    }
};
// @lc code=end


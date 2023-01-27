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

        if(root==nullptr) return {};
        
        vector <int> result;
        stack <TreeNode*> parse;

        while(!parse.empty() || root!=nullptr) {
            if(root!=nullptr) {
                parse.push(root);
                root = root->left;
            }
            else {
                root = parse.top();
                parse.pop();
                // root = parse.pop();
                //
                // Line 27: Char 28: error: cannot initialize a variable of type 'TreeNode *' with an rvalue of type 'void'
                // Line 27: Char 28: error: cannot initialize a variable of type 'TreeNode *' with an rvalue of type 'void'
                result.push_back(root->val);
                root = root->right;
            }
        }
        return result;

    }
};
// @lc code=end


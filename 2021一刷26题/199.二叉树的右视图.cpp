/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> parse;
        if(root!=nullptr) parse.push(root);
        while (!parse.empty()) {
            int size = parse.size();
            for(int i=0; i<size; i++) {
                auto tmp = parse.front();
                if(i==size-1)
                    result.push_back(tmp->val);
                parse.pop();
                if(tmp->left) parse.push(tmp->left);
                if(tmp->right) parse.push(tmp->right);
            }
        } 
        return result;
    }
};
// @lc code=end


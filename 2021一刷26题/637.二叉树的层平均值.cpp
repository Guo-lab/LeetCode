/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        queue<TreeNode*> parse;

        if(root!=nullptr) parse.push(root);
        
        while(!parse.empty()) {
            double sum = 0;
            int size = parse.size();

            for(int i=0; i<size; i++) {
                TreeNode* tmp = parse.front();
                sum += tmp->val;
                parse.pop();
                if(tmp->left) parse.push(tmp->left);
                if(tmp->right) parse.push(tmp->right);
            }       
            sum /= size;
            result.push_back(sum);
        }
        return result;
    }
};
// @lc code=end


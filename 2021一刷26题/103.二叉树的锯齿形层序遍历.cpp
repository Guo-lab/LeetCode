/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> parse;

        int l2r = 0;

        if(root!=nullptr) parse.push(root);
        while (!parse.empty())
        {
            vector<int> element;
            TreeNode* tmp; 
            int size = parse.size();

            for(int i=0; i<size; i++) {
                tmp = parse.front();
                element.push_back(tmp->val);
                parse.pop();
                
                if(tmp->left)parse.push(tmp->left);
                if(tmp->right)parse.push(tmp->right);
            }    
            
            if(l2r==1) { 
                reverse(element.begin(), element.end());
            }
            result.push_back(element);             
            l2r = (l2r?0:1);   
        }
        return result;
    }
};
// @lc code=end


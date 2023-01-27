/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> parse;

        if(root!=nullptr) parse.push(root);
        
        while(!parse.empty()) {
            int large = 0x80000000;
            int size = parse.size();

            for(int i=0; i<size; i++) {
                TreeNode* tmp = parse.front();
                if(tmp->val > large)
                    large = tmp->val;
                parse.pop();
                if(tmp->left) parse.push(tmp->left);
                if(tmp->right) parse.push(tmp->right);
            }       
            result.push_back(large);
        }
        return result;
    }
};
// @lc code=end


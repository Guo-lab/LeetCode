/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> parse;

        if(root!=nullptr) parse.push(root);
        
        while(!parse.empty()) {
            vector<int> element;
            int size = parse.size();

            for(int i=0; i<size; i++) {
                TreeNode* tmp = parse.front();
                element.push_back(tmp->val);
                parse.pop();
                if(tmp->left) parse.push(tmp->left);
                if(tmp->right) parse.push(tmp->right);
            }

            result.push_back(element);
        }
        return result;
    }
};
// 34/34 cases passed (4 ms)
// Your runtime beats 72.76 % of cpp submissions
// Your memory usage beats 20.49 % of cpp submissions (12.4 MB)

// @lc code=end


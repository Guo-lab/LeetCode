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
    vector<vector<int>> all;
    queue<TreeNode*> tmp;
    vector<int> layer;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return all;
        } else {
            layer.push_back(root->val);
            all.push_back(layer);
            layer.clear();

            tmp.push(root);
            while (!tmp.empty()) {
                int n = tmp.size(); //! ////////////////////////
                for (int i = 0; i < n; i++) { //! //////////////
                    TreeNode* tmp_a = tmp.front();
                    tmp.pop();
                    if (tmp_a->left != nullptr) {
                        layer.push_back(tmp_a->left->val);
                        tmp.push(tmp_a->left);
                    }
                    if (tmp_a->right != nullptr) {
                        layer.push_back(tmp_a->right->val);
                        tmp.push(tmp_a->right);
                    }
                } // for end      
                if (layer.size() != 0) all.push_back(layer);
                layer.clear();
            } // while end
            return all;
        }
    }
};
// @lc code=end


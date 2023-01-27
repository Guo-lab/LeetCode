/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
    TreeNode* invertTree(TreeNode* root) {
        stack <TreeNode*> st;
        if(root!=nullptr)
            st.push(root);
        while(!st.empty()) {
            TreeNode* tmp = st.top();
            if(tmp!=NULL) {
                st.pop();
                if(tmp->right) {
                    st.push(tmp->right);
                }
                if(tmp->left) {
                    st.push(tmp->left);
                }
                st.push(tmp);
                st.push(nullptr);
            }
            else {
                st.pop();
                tmp = st.top();
                st.pop();
                swap(tmp->left, tmp->right);
            }
        }
        return root;
    }
};
// @lc code=end


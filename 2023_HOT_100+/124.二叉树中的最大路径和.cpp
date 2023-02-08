/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
    int Max = -2000;
    int maxPathSum(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) return root->val;
        int a = dfs(root);
        return Max;
    }
    int dfs (TreeNode* root) {
        ////if (root == nullptr) return 0;
            int l, r;
            if (root->left) l = dfs(root->left);
            if (root->right) r = dfs(root->right);
            if (root->left == nullptr && root->right == nullptr) 
                return root->val;
            else if (root->left == nullptr) {
                Max = max(Max, max(r, max(root->val, r + root->val)));
                return max(r + root->val, root->val);
            } else if (root->right == nullptr) {
                //cout << max(root->val, l + root->val) << endl;
                //cout << max(l, max(root->val, l + root->val)) << endl;
                //cout << Max << endl;
                Max = max(Max, max(l, max(root->val, l + root->val)));
                //cout << Max << endl;
                return max(l + root->val, root->val);
            } else {
                int tmp = max(l, r);
                int ret = max(root->val + tmp, root->val);
                Max = max(Max, max(max(root->val + tmp, max(root->val + l + r, root->val)), tmp));
                return ret;
            }
    }
};
// @lc code=end


/**
 * @brief 
 * case
 * [-10,9,20,null,null,15,7]\n 
 * Answer
 * 42 
 * 
 * case
 * [-3]\n 
 * Answer
 * -3
 * 
 * case
 * [2, -1]\n
 * answer: 
 * 2
 * 
 * [-2,-1]\n
 * -1
 * 
 * [5,4,8,11,null,13,4,7,2,null,null,null,1]\n
 * 48
 */
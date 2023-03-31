/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution { 
//@ https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/solution/er-cha-shu-de-zui-jin-gong-gong-zu-xian-by-leetc-2/
public:
    TreeNode* tmp;

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool leftson  = dfs(root->left, p, q);
        bool rightson = dfs(root->right, p, q);
        ////cout << leftson << rightson << endl;
        if (leftson && rightson) 
            return root;
        if (leftson || rightson) {
            if (root == p || root == q) {
                return root;
            }
        }
        return tmp;
    }

    bool dfs(TreeNode* x, TreeNode* p, TreeNode* q) {
        if (x == nullptr) 
            return false;
        bool leftson  = dfs(x->left, p, q);
        bool rightson = dfs(x->right, p, q);
        if (leftson && rightson) {
            tmp = x;
            return true;
        }
        if (leftson || rightson) {
            if (x == p || x == q) {
                tmp = x;
                return true;
            }
            return true;
        }
        if (x == p || x == q) 
            return true;
        return false;
    }
};
// @lc code=end


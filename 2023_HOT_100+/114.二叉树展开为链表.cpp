/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
    TreeNode* prev;
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        else {
            TreeNode* ans = new TreeNode(root->val);
            prev = ans;
            //root->val = 999;
            dfs(root->left);    // 2, 1
            dfs(root->right);   // 5, 
            root->right = ans->right;
            root->left = nullptr;
            //cout << root->val << " " << root->right->val << ' ' << root->right->right->val << ' ' << root->right->right->right->val << ' ' << root->right->right->right->right->val<< " " << root->right->right->right->right->right->val<< endl;
            //cout << root->val << " " << root->left << ' ' << root->right->left << ' ' << root->right->right->left << ' ' << root->right->right->right->left<< " " << root->right->right->right->right->left<< endl;
            //printDfs(root);
        }
    }
    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        else {
            TreeNode* tmp = new TreeNode(root->val);
            prev->right = tmp;
            prev->left = nullptr;
            prev = tmp;
            //cout << prev->val << endl;
            dfs(root->left);    // 3, 2
            //cout << prev->val << endl;
            dfs(root->right);   // 3,
        }
    }
    void printDfs (TreeNode* root) {
        if (root == nullptr) return;
        cout << root->val << endl;
        printDfs(root->left);
        printDfs(root->right);
    }
};
// @lc code=end


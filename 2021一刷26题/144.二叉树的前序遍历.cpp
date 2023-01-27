/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==nullptr) return {};

        vector<int> result;
        stack<TreeNode*> parse;

        while(!parse.empty() || root!=nullptr) {
            if(root!=nullptr) {
                parse.push(root);
                result.push_back(root->val);
                root = root->left;
            }
            else {
                root = parse.top();
                parse.pop();
                root = root->right;
            }
        }
        return result;
    }
};

// (4 ms)
// (8.2 MB)

// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> result;
//         traversal(root, result);
//         return result;

//     }


//     // 
//     // 1. parameter I/O
//     void traversal(TreeNode* cur, vector<int>& vec) {
//     // 2. ending
//         if(cur == nullptr) return ;
//     // 3. layer logic
//         vec.push_back(cur->val); 
//         traversal(cur->left, vec); 
//         traversal(cur->right, vec); 
//     }
//     // Your runtime beats 43.13 % of cpp submissions      
//     // (4 ms)
//     // Your memory usage beats 75.86 % of cpp submissions 
//     // (8.1 MB)
// };


// @lc code=end


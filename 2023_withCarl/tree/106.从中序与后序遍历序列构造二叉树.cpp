/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 *
 * https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (72.27%)
 * Likes:    1004
 * Dislikes: 0
 * Total Accepted:    276.6K
 * Total Submissions: 383.2K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * 给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder
 * 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入：inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
 * 输出：[3,9,20,null,null,15,7]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入：inorder = [-1], postorder = [-1]
 * 输出：[-1]
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= inorder.length <= 3000
 * postorder.length == inorder.length
 * -3000 <= inorder[i], postorder[i] <= 3000
 * inorder 和 postorder 都由 不同 的值组成
 * postorder 中每一个值都在 inorder 中
 * inorder 保证是树的中序遍历
 * postorder 保证是树的后序遍历
 * 
 * 
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

// --------------------- binary tree ----------------------
// ------------- cut

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0) return nullptr;
        TreeNode* ans = dfs(inorder, postorder);
        return ans;
    }
    TreeNode* dfs(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0) return nullptr;
        
        TreeNode* mid = new TreeNode(postorder[postorder.size() - 1]);
        if (inorder.size() == 1) return mid;

        int middle = 0;
        for (int i = 0; i < inorder.size(); i++) 
            if (inorder[i] == mid->val)
                middle = i;
        vector<int> inorderLeft(inorder.begin(), inorder.begin() + middle);
        vector<int> inorderRight(inorder.begin() + middle + 1, inorder.end());
        vector<int> postorderLeft(postorder.begin(), postorder.begin() + inorderLeft.size());
        vector<int> postorderRight(postorder.begin() + inorderLeft.size(), postorder.end() - 1);
        mid->left = dfs(inorderLeft, postorderLeft);
        mid->right = dfs(inorderRight, postorderRight);
        return mid;
    }
};
// @lc code=end

// 之前做出来的方式是 inorder, inorderLeftIdx, inorderRightIdx, 
//                 postorder, postorderLeftIdx, postorderRightIdx, 
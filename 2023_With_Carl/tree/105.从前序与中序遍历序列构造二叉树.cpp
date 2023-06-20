/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (71.36%)
 * Likes:    1946
 * Dislikes: 0
 * Total Accepted:    488.1K
 * Total Submissions: 684.5K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder
 * 是同一棵树的中序遍历，请构造二叉树并返回其根节点。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * 输出: [3,9,20,null,null,15,7]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: preorder = [-1], inorder = [-1]
 * 输出: [-1]
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= preorder.length <= 3000
 * inorder.length == preorder.length
 * -3000 <= preorder[i], inorder[i] <= 3000
 * preorder 和 inorder 均 无重复 元素
 * inorder 均出现在 preorder
 * preorder 保证 为二叉树的前序遍历序列
 * inorder 保证 为二叉树的中序遍历序列
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return nullptr;
        TreeNode* ans = dfs(preorder, inorder);
        return ans;
    }
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return nullptr;

        TreeNode* mid = new TreeNode(preorder[0]);
        if (preorder.size() == 1) return mid;
        
        int middle;
        for (int i = 0; i < inorder.size(); i++) 
            if (inorder[i] == mid->val)
                middle = i;

        vector<int> inorderLeft(inorder.begin(), inorder.begin() + middle);
        vector<int> inorderRight(inorder.begin() + middle + 1, inorder.end());
        vector<int> preorderLeft(preorder.begin() + 1, preorder.begin() + inorderLeft.size() + 1);
        vector<int> preorderRight(preorder.begin() + inorderLeft.size() + 1, preorder.end());
        mid->left = dfs(preorderLeft, inorderLeft);
        mid->right = dfs(preorderRight, inorderRight);
        return mid;
    }
};
// @lc code=end

// 之前做出来的方式是 inorder,  inorderLeftIdx,  inorderRightIdx, 
//                 preorder, preorderLeftIdx, pretorderRightIdx, 
// 上述方法可重复练习 
// https://www.programmercarl.com/0106.%E4%BB%8E%E4%B8%AD%E5%BA%8F%E4%B8%8E%E5%90%8E%E5%BA%8F%E9%81%8D%E5%8E%86%E5%BA%8F%E5%88%97%E6%9E%84%E9%80%A0%E4%BA%8C%E5%8F%89%E6%A0%91.html#%E6%80%9D%E8%B7%AF
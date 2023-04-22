/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
 *
 * https://leetcode.cn/problems/count-complete-tree-nodes/description/
 *
 * algorithms
 * Medium (80.85%)
 * Likes:    926
 * Dislikes: 0
 * Total Accepted:    278.1K
 * Total Submissions: 343.9K
 * Testcase Example:  '[1,2,3,4,5,6]'
 *
 * 给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。
 * 
 * 完全二叉树
 * 的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h
 * 层，则该层包含 1~ 2^h 个节点。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [1,2,3,4,5,6]
 * 输出：6
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = []
 * 输出：0
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：root = [1]
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点的数目范围是[0, 5 * 10^4]
 * 0 
 * 题目数据保证输入的树是 完全二叉树
 * 
 * 
 * 
 * 
 * 进阶：遍历树来统计节点是一种时间复杂度为 O(n) 的简单解决方案。你可以设计一个更快的算法吗？
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

// ---------------------- binary tree ------------------
// DFS 或者 完全 / 满二叉树做法 

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        
        int leftD = 0, rightD = 0;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        while (left) {
            left = left->left;
            leftD++;
        }
        while (right) {
            right = right->right;
            rightD++;
        }

        if (leftD == rightD) {
            // 满二叉树
            cout << leftD << endl;
            return (2 << leftD) - 1; // priority
        }

        return countNodes(root->left) + countNodes(root->right) + 1;
        // 左非满二叉树 + 右非满二叉树 
    }
};
// @lc code=end

class common_Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int x, y;
        x = countNodes(root->left);
        y = countNodes(root->right);
        return x + y + 1;
    }
};
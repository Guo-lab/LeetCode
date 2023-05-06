/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
 *
 * https://leetcode.cn/problems/binary-tree-cameras/description/
 *
 * algorithms
 * Hard (52.18%)
 * Likes:    591
 * Dislikes: 0
 * Total Accepted:    57.8K
 * Total Submissions: 110.9K
 * Testcase Example:  '[0,0,null,0,0]'
 *
 * 给定一个二叉树，我们在树的节点上安装摄像头。
 * 
 * 节点上的每个摄影头都可以监视其父对象、自身及其直接子对象。
 * 
 * 计算监控树的所有节点所需的最小摄像头数量。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：[0,0,null,0,0]
 * 输出：1
 * 解释：如图所示，一台摄像头足以监控所有节点。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：[0,0,null,0,null,0,null,null,0]
 * 输出：2
 * 解释：需要至少两个摄像头来监视树的所有节点。 上图显示了摄像头放置的有效位置之一。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 给定树的节点数的范围是 [1, 1000]。
 * 每个节点的值都是 0。
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


// ------------------------------ Greedy --------------------------------
// TOP LVL HARD

// 叶子节点剩下的摄像头 >> 头节点剩下的摄像头
class Solution {
public:
// 设定状态值用以分辨遍历情况
// 默认的 0 正好是无覆盖无摄像头
    int sum = 0;
    int minCameraCover(TreeNode* root) {
        //* 可能头结点还有一个无覆盖的情况
        if(dfs(root) == 0) return sum + 1;

        if (!root->left && !root->right) return 1;
        //X if (dfs(root->left) == 2 && dfs(root->right) == 2) return sum + 1;
        return sum;
    }
    int dfs(TreeNode* cur) {
        if (!cur) return 2; // 即为有覆盖
        int x = dfs(cur->left);
        int y = dfs(cur->right);

        if (x == 2 && y == 2) {
            return 0;
        }
        else if (x == 0 || y == 0) {
            if (cur->left)
                cur->left->val = x == 0 ? 2 : x;
            if (cur->right)
                cur->right->val = y == 0 ? 2 : y;
            sum++;
            cur->val = 1;
            return 1;
        }
        else if (x == 1 || y == 1) {
            cur->val = 2;
            return 2;
        }
        return 0;
    }
};
// @lc code=end

====================
[0,0,null,0,0]
---------------
1
====================


========
[0]
-----
1
========

==============================
[0,null,0,null,0,null,0]
------------------------
2
==============================

------------
left |right
2    |2
-----|------
0    |0
0    |1
0    |2
-----|------
1    |2
1    |1
------------
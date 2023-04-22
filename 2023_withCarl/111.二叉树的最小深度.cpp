/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 *
 * https://leetcode.cn/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (51.95%)
 * Likes:    991
 * Dislikes: 0
 * Total Accepted:    542.3K
 * Total Submissions: 1M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最小深度。
 * 
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 * 
 * 说明：叶子节点是指没有子节点的节点。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [2,null,3,null,4,null,5,null,6]
 * 输出：5
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数的范围在 [0, 10^5] 内
 * -1000 
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

// -------------------- binary tree ---------------------
// ------ hierarchy

class Solution {
public:
    int minDepth(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        if (!root) return 0; // unique
        int minDep = 0;
        bool isOver = false;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* tmp = q.front();
                q.pop();
                if(!tmp) {
                    // isOver = true; // 这里结束并非找到了叶子节点，可能只是其中的一支
                    continue;
                }
                if (!tmp->left && !tmp->right) {
                    isOver = true;
                }
                q.push(tmp->left);
                q.push(tmp->right);                
            }
            minDep++;         
            if (isOver) break;
        }
        return minDep;
    }
};
// @lc code=end

-------------------------------------------
[2,null,3,null,4,null,5,null,6]\n
--------------------------------
5
-------------------------------------------


==========================================
[]
-----
0
------------------------------------------
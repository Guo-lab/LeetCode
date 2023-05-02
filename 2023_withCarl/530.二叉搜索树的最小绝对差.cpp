/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
 *
 * https://leetcode.cn/problems/minimum-absolute-difference-in-bst/description/
 *
 * algorithms
 * Easy (63.44%)
 * Likes:    450
 * Dislikes: 0
 * Total Accepted:    172K
 * Total Submissions: 271.2K
 * Testcase Example:  '[4,2,6,1,3]'
 *
 * 给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。
 * 
 * 差值是一个正数，其数值等于两值之差的绝对值。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [4,2,6,1,3]
 * 输出：1
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [1,0,48,null,null,12,49]
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点的数目范围是 [2, 10^4]
 * 0 <= Node.val <= 10^5
 * 
 * 
 * 
 * 
 * 注意：本题与 783
 * https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/ 相同
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

// --------------------------- binary tree ---------------------------
// ---- BST

class Solution {
public:
    TreeNode* pre;
    int minimum = 10000000;
    
    // iteration put root better
    int getMinimumDifference(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while (!s.empty() || cur) { // s is empty at first 
            if (cur) {
                s.push(cur);
                cur = cur->left;
            }
            else {
                cur = s.top();
                s.pop();
                if (pre)
                    minimum = minimum > cur->val - pre->val ? cur->val - pre->val : minimum;
                pre = cur;
                cur = cur->right;
            }
        }
        return minimum;
    }    

    int dfs_getMinimumDifference(TreeNode* root) {
        if (!root) return 0;
        int tmp = 10000000;
        if (root->left) tmp = getMinimumDifference(root->left);
        minimum = min(tmp, minimum);
        if (pre)
            tmp = root->val - pre->val;
        pre = root;
        minimum = min(tmp, minimum);
        if (root->right) tmp = getMinimumDifference(root->right);
        minimum = min(tmp, minimum);
        return minimum;
    }
};
// @lc code=end


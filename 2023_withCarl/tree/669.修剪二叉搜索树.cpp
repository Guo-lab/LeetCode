/*
 * @lc app=leetcode.cn id=669 lang=cpp
 *
 * [669] 修剪二叉搜索树
 *
 * https://leetcode.cn/problems/trim-a-binary-search-tree/description/
 *
 * algorithms
 * Medium (67.78%)
 * Likes:    799
 * Dislikes: 0
 * Total Accepted:    122K
 * Total Submissions: 180.2K
 * Testcase Example:  '[1,0,2]\n1\n2'
 *
 * 给你二叉搜索树的根节点 root ，同时给定最小边界low 和最大边界 high。通过修剪二叉搜索树，使得所有节点的值在[low, high]中。修剪树
 * 不应该 改变保留在树中的元素的相对结构 (即，如果没有被移除，原有的父代子代关系都应当保留)。 可以证明，存在 唯一的答案 。
 * 
 * 所以结果应当返回修剪好的二叉搜索树的新的根节点。注意，根节点可能会根据给定的边界发生改变。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [1,0,2], low = 1, high = 2
 * 输出：[1,null,2]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [3,0,4,null,2,null,null,1], low = 1, high = 3
 * 输出：[3,2,null,1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数在范围 [1, 10^4] 内
 * 0 <= Node.val <= 10^4
 * 树中每个节点的值都是 唯一 的
 * 题目数据保证输入是一棵有效的二叉搜索树
 * 0 <= low <= high <= 10^4
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

// ---------------------- binary tree ----------------------
// BST

class Solution {
public:
    // iteration 需要三次循环，第一次找到范围内的cur， 第二次两层while去掉不符合的左，第三次两层while去掉不符合high的右
    // * https://www.programmercarl.com/0669.%E4%BF%AE%E5%89%AA%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91.html#%E8%BF%AD%E4%BB%A3%E6%B3%95
    // 很有必要学习一下这样的剪枝
    
    // finds a out-of-range number, next level up
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (!root) return root;
        if (root->val < low)
            root = trimBST(root->right, low, high);
        else if (root->val > high) {
            root = trimBST(root->left, low, high);
            //cout << (root == nullptr) << endl;
        }
        else if (root->val == high) { // 不用 else 会访达空
            root->right = NULL;
            root->left = trimBST(root->left, low, high); // key point
        }            
        else if (root->val == low) {
            root->left = NULL;
            root->right = trimBST(root->right, low, high); // key point
        }            
        else if (root->val > low && root->val < high) {
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
        }
        return root;
    }
};
// @lc code=end

            3
        0       4
    ()     2  ()     () 
  ()  () 1  

=================================
[3,0,4,null,2,null,null,1]
1
3
---------------------------
[3,2,null,1]
=================================


===================
[3]
2
2
----
[]
===================

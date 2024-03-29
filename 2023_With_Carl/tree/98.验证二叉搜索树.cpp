/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 *
 * https://leetcode.cn/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (36.90%)
 * Likes:    1996
 * Dislikes: 0
 * Total Accepted:    709.3K
 * Total Submissions: 1.9M
 * Testcase Example:  '[2,1,3]'
 *
 * 给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
 * 
 * 有效 二叉搜索树定义如下：
 * 
 * 
 * 节点的左子树只包含 小于 当前节点的数。
 * 节点的右子树只包含 大于 当前节点的数。
 * 所有左子树和右子树自身必须也是二叉搜索树。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [2,1,3]
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [5,1,4,null,null,3,6]
 * 输出：false
 * 解释：根节点的值是 5 ，但是右子节点的值是 4 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数目范围在[1, 10^4] 内
 * -2^31 <= Node.val <= 2^31 - 1
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

// ------------------------ binary tree -------------------------
// BST

class Solution {
public:
    TreeNode* pre = nullptr;
    // iteration
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> s;
        if (!root) return true;
        s.push(root);
        while (!s.empty()) {
            if (root->left) {
                s.push(root->left);
                root = root->left;
            }
            else {
                root = s.top();
                s.pop();
                if (pre && pre->val >= root->val)
                    return false;
                pre = root;
                if (root->right) {
                    s.push(root->right);
                    root = root->right;
                }
                pre->left = nullptr;
            }    
        }
        return true;
    }

    bool dfs_isValidBST(TreeNode* root) {
        if (!root) return true;
        bool ret = isValidBST(root->left);
        if (!ret) 
            return false;
        if (pre) {
            cout << pre->val << endl;
            if (pre->val >= root->val) 
                return false;
        }
        pre = root;
        ret &= isValidBST(root->right);   
        return ret;
    }
};
// @lc code=end

=====================================
[5,1,4,null,null,3,6]
------------------------
false
=====================================

=====================================
[34,-6,null,-21]
----------------
true
=====================================

=====================================
[5,4,6,null,null,3,7]
----------------------
false
=====================================
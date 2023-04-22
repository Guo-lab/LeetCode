/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
 *
 * https://leetcode.cn/problems/subtree-of-another-tree/description/
 *
 * algorithms
 * Easy (47.58%)
 * Likes:    903
 * Dislikes: 0
 * Total Accepted:    170.4K
 * Total Submissions: 358.2K
 * Testcase Example:  '[3,4,5,1,2]\n[4,1,2]'
 *
 * 
 * 
 * 给你两棵二叉树 root 和 subRoot 。检验 root 中是否包含和 subRoot 具有相同结构和节点值的子树。如果存在，返回 true
 * ；否则，返回 false 。
 * 
 * 二叉树 tree 的一棵子树包括 tree 的某个节点和这个节点的所有后代节点。tree 也可以看做它自身的一棵子树。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [3,4,5,1,2], subRoot = [4,1,2]
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * root 树上的节点数量范围是 [1, 2000]
 * subRoot 树上的节点数量范围是 [1, 1000]
 * -10^4 
 * -10^4 
 * 
 * 
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

// ----------------------- binary tree -----------------------------
// similar as 101

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
        bool ans = isSame(root, subRoot);
        ans |= isSubtree(root->left, subRoot);
        ans |= isSubtree(root->right, subRoot);
        if (ans) return true;
        else
            return false;

    }
    bool isSame(TreeNode* a, TreeNode* b) {
        queue<TreeNode*> s;
        s.push(a);
        s.push(b);
        while (!s.empty()) {
            TreeNode* x = s.front(); s.pop();
            TreeNode* y = s.front(); s.pop();
            if (!x && !y) continue;
            if (!x || !y) return false;

            // if (!y->left && !y->right) continue; // 我还以为是包含子树关系 

            if (x->val != y->val) return false;
            s.push(x->left);
            s.push(y->left);
            s.push(x->right);
            s.push(y->right);
        }
        return true;
    }
};
// @lc code=end


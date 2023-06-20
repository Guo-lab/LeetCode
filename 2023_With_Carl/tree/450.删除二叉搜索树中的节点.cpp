/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
 *
 * https://leetcode.cn/problems/delete-node-in-a-bst/description/
 *
 * algorithms
 * Medium (52.43%)
 * Likes:    1130
 * Dislikes: 0
 * Total Accepted:    200K
 * Total Submissions: 381.8K
 * Testcase Example:  '[5,3,6,2,4,null,7]\n3'
 *
 * 给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key
 * 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。
 * 
 * 一般来说，删除节点可分为两个步骤：
 * 
 * 
 * 首先找到需要删除的节点；
 * 如果找到了，删除它。
 * 
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 
 * 
 * 输入：root = [5,3,6,2,4,null,7], key = 3
 * 输出：[5,4,6,2,null,null,7]
 * 解释：给定需要删除的节点值是 3，所以我们首先找到 3 这个节点，然后删除它。
 * 一个正确的答案是 [5,4,6,2,null,null,7], 如下图所示。
 * 另一个正确答案是 [5,2,6,null,4,null,7]。
 * 
 * 
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: root = [5,3,6,2,4,null,7], key = 0
 * 输出: [5,3,6,2,4,null,7]
 * 解释: 二叉树不包含值为 0 的节点
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: root = [], key = 0
 * 输出: []
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 节点数的范围 [0, 10^4].
 * -10^5 <= Node.val <= 10^5
 * 节点值唯一
 * root 是合法的二叉搜索树
 * -10^5 <= key <= 10^5
 * 
 * 
 * 
 * 
 * 进阶： 要求算法时间复杂度为 O(h)，h 为树的高度。
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

// ------------------------ binary tree ------------------------
// BST

// OK, 这就是3月美团面试我胡扯的那道题

class Solution {
public:
    // iteration 利用 pre 记录前一个
    // 单独删
    // 单独删除节点的部分 与最下面额DFS通用思路有相似之处 

    // DFS
    TreeNode* deleteNode(TreeNode* root, int key) { // Imagine root at first
        // Condition 1: NONE
        if (!root) return root;

        if (root->val == key) {
            // Condition 2: leaf
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            } else if (!root->left) { // Condition 3 & 4: 
                root = root->right;
                return root;
            } else if (!root->right) {
                root = root->left;
                return root;
            } else { // Condition 5: leftson and rightson, left => right's leftmost grandson
                TreeNode* tmp = root->right;
                cout << tmp->val << endl;
                while (tmp->left) {
                    tmp = tmp->left;
                }
                tmp->left = root->left;
                root = root->right;
                return root;
            }
        }
        TreeNode* ret;
        if (root->val < key)
            root->right = deleteNode(root->right, key);
        if (root->val > key)
            root->left = deleteNode(root->left, key);

        return root;
    }
};
// @lc code=end

// DFS 通用思路比较复杂，遇到key了就看有没有右节点，有的话直接把根的值和右孩子的最左节点的值交换，进入迭代
// 直到把右节点卡到没有
// 以后再琢磨
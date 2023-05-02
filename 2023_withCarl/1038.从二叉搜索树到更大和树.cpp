/*
 * @lc app=leetcode.cn id=1038 lang=cpp
 *
 * [1038] 从二叉搜索树到更大和树
 *
 * https://leetcode.cn/problems/binary-search-tree-to-greater-sum-tree/description/
 *
 * algorithms
 * Medium (81.28%)
 * Likes:    206
 * Dislikes: 0
 * Total Accepted:    43.6K
 * Total Submissions: 53.6K
 * Testcase Example:  '[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]'
 *
 * 给定一个二叉搜索树 root (BST)，请将它的每个节点的值替换成树中大于或者等于该节点值的所有节点值之和。
 * 
 * 提醒一下， 二叉搜索树 满足下列约束条件：
 * 
 * 
 * 节点的左子树仅包含键 小于 节点键的节点。
 * 节点的右子树仅包含键 大于 节点键的节点。
 * 左右子树也必须是二叉搜索树。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
 * 输出：[30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [0,null,1]
 * 输出：[1,null,1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中的节点数在 [1, 100] 范围内。
 * 0 <= Node.val <= 100
 * 树中的所有值均 不重复 。
 * 
 * 
 * 
 * 
 * 注意：该题目与 538: https://leetcode-cn.com/problems/convert-bst-to-greater-tree/
 * 相同
 * 
 */


有简单的写法，总不长记性，应该直接放入节点而不是放入孩子节点

        while (cur != NULL || !st.empty()) {
            if (cur != NULL) {
                st.push(cur);
                cur = cur->right;   // 右
            } else {
                cur = st.top();     // 中
                st.pop();
                cur->val += pre;
                pre = cur->val;
                cur = cur->left;    // 左
            }
        }

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
// BST same as 538

class Solution {
public:
// iteration
    TreeNode* pre;
    TreeNode* bstToGst(TreeNode* root) {
        if (!root) return root;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* cur = root;
        while (!s.empty()) {
            while (cur->right) {
                bool out = false;
                if (s.top()->right == cur) break; 
                TreeNode* o = s.top()->right;
                while (o) {
                    if (o->left == cur) {
                        out = true;
                        break;
                    }
                    o = o->left;
                }
                if (out) break;
                s.push(cur->right);
                cur = cur->right;
            }
            cur = s.top();
            s.pop();
            if (pre)
                cur->val += pre->val;
            cout << cur->val << endl;
            pre = cur;
            if (cur->left) {
                s.push(cur->left);
                cur = cur->left;
            }   
        }
        return root;
    }
};
// @lc code=end

=====================================================
[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
                4
            1        6
        0     2    5     7
                3           8

=====================================================
[4,1,7,0,2,5,8,null,null,null,3,null,6,null,9]
                 4
            1           7
        0     2      5     8
               3   ()  6      9             

==============================================================================================================================================================================================================================================================================================================================
[24,11,37,5,17,30,43,2,8,14,20,27,33,40,46,0,3,6,9,12,15,18,22,25,28,31,35,38,41,44,48,null,1,null,4,null,7,null,10,null,13,null,16,null,19,21,23,null,26,null,29,null,32,34,36,null,39,null,42,null,45,47,49]
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
[949,1170,559,1215,1089,790,322,1224,1197,1134,1035,874,697,445,190,1225,1222,1210,1189,1159,1120,1072,994,925,847,760,630,522,405,279,97,null,1225,null,1219,null,1204,null,1180,null,1147,null,1105,null,1054,1015,972,null,900,null,819,null,729,664,595,null,484,null,364,null,235,144,49]
==============================================================================================================================================================================================================================================================================================================================
/*
 * @lc app=leetcode.cn id=1382 lang=cpp
 *
 * [1382] 将二叉搜索树变平衡
 *
 * https://leetcode.cn/problems/balance-a-binary-search-tree/description/
 *
 * algorithms
 * Medium (73.54%)
 * Likes:    175
 * Dislikes: 0
 * Total Accepted:    23.8K
 * Total Submissions: 32.4K
 * Testcase Example:  '[1,null,2,null,3,null,4]'
 *
 * 给你一棵二叉搜索树，请你返回一棵 平衡后 的二叉搜索树，新生成的树应该与原来的树有着相同的节点值。如果有多种构造方法，请你返回任意一种。
 * 
 * 如果一棵二叉搜索树中，每个节点的两棵子树高度差不超过 1 ，我们就称这棵二叉搜索树是 平衡的 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：root = [1,null,2,null,3,null,4,null,null]
 * 输出：[2,1,3,null,null,null,4]
 * 解释：这不是唯一的正确答案，[3,1,4,null,2,null,null] 也是一个可行的构造方案。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入: root = [2,1,3]
 * 输出: [2,1,3]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树节点的数目在 [1, 10^4] 范围内。
 * 1 <= Node.val <= 10^5
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


// ······················· 手撕 AVL 自平衡二叉查找树 ························
// ································ 旋钮 ···································
// https://leetcode.cn/problems/balance-a-binary-search-tree/solution/shou-si-avlshu-wo-bu-guan-wo-jiu-shi-yao-xuan-zhua/
 
 
 // ------------------------- tree ----------------------------

class Solution {
public:
    vector<int> tmp;

    TreeNode* balanceBST(TreeNode* root) {
        // if (abs(heightFor(root->left) - heightFor(root->right)) <= 1)
        //     return root;
        //cout << heightFor(root->left) << " " << heightFor(root->right) << endl;
        convert(root);
        // for (int i = 0; i < tmp.size(); i++) cout << tmp[i] << " ";
        // cout <<  tmp.size() / 2 << endl;
        TreeNode* result = new TreeNode(tmp[tmp.size() / 2]);
        result->left = buildBST(0, tmp.size() / 2 - 1);
        result->right = buildBST(tmp.size() / 2 + 1, tmp.size() - 1);
        return result;
    }

    void convert(TreeNode* cur) {
        if (!cur) return;
        convert(cur->left);
        tmp.push_back(cur->val);
        convert(cur->right);
    }

    TreeNode* buildBST(int left, int right) {
        int rootIdx = (left + right) / 2;
        TreeNode* root = new TreeNode(tmp[rootIdx]);
        if (rootIdx - 1 >= left)
            root->left = buildBST(left, rootIdx - 1);
        if (rootIdx + 1 <= right)
            root->right = buildBST(rootIdx + 1, right);
        return root;
    }

    // 除了可以转换 vector 再化成 binary tree； 求高度可以手撕 AVL 
    // int heightFor(TreeNode* cur) {
    //     if (!cur) return 0;
    //     return max(heightFor(cur->left), heightFor(cur->right)) + 1;
    // }
};
// @lc code=end

================
[2,1,3]
-----------
[2,1,3]
================


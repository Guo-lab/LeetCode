/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
 *
 * https://leetcode.cn/problems/house-robber-iii/description/
 *
 * algorithms
 * Medium (61.00%)
 * Likes:    1605
 * Dislikes: 0
 * Total Accepted:    257.7K
 * Total Submissions: 422.4K
 * Testcase Example:  '[3,2,3,null,3,null,1]'
 *
 * 小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为 root 。
 * 
 * 除了 root 之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果
 * 两个直接相连的房子在同一天晚上被打劫 ，房屋将自动报警。
 * 
 * 给定二叉树的 root 。返回 在不触动警报的情况下 ，小偷能够盗取的最高金额 。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 
 * 
 * 输入: root = [3,2,3,null,3,null,1]
 * 输出: 7 
 * 解释: 小偷一晚能够盗取的最高金额 3 + 3 + 1 = 7
 * 
 * 示例 2:
 * 
 * 
 * 
 * 
 * 输入: root = [3,4,5,1,3,null,1]
 * 输出: 9
 * 解释: 小偷一晚能够盗取的最高金额 4 + 5 = 9
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 
 * 
 * 树的节点数在 [1, 10^4] 范围内
 * 0 <= Node.val <= 10^4
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

// ------------------- Dynamic programming ----------------------

class Solution {
public:
    // 分别记录左节点偷与不偷的值 和 右节点偷与不偷的值

    int rob(TreeNode* root) {
        if (!root) return 0;
        vector<int> ans = dfs(root);
        return max(ans[0], ans[1]);
    }
    vector<int> dfs(TreeNode* root) {
        if (!root) return vector<int>{0, 0};

        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);

        return {
            max(left[1],left[0]) + max(right[1], right[0]), \
            root->val + left[0] + right[0] \
        };
    }
};
// @lc code=end
// 这样想又点难理解，因为即使不偷当前节点，左右节点也不都是必须偷的状态
// 因为左右节点但不被偷，还有可能偷更下层的节点




===================================================================
[79,99,77,null,null,null,69,null,60,53,null,73,11,null,null,null,62,27,62,null,null,98,50,null,null,90,48,82,null,null,null,55,64,null,null,73,56,6,47,null,93,null,null,75,44,30,82,null,null,null,null,null,null,57,36,89,42,null,null,76,10,null,null,null,null,null,32,4,18,null,null,1,7,null,null,42,64,null,null,39,76,null,null,6,null,66,8,96,91,38,38,null,null,null,null,74,42,null,null,null,10,40,5,null,null,null,null,28,8,24,47,null,null,null,17,36,50,19,63,33,89,null,null,null,null,null,null,null,null,94,72,null,null,79,25,null,null,51,null,70,84,43,null,64,35,null,null,null,null,40,78,null,null,35,42,98,96,null,null,82,26,null,null,null,null,48,91,null,null,35,93,86,42,null,null,null,null,0,61,null,null,67,null,53,48,null,null,82,30,null,97,null,null,null,1,null,null]
3038
===================================================================

class Solution {
public:
    unordered_map<TreeNode*, int> tmp; // Memory Search

    int rob(TreeNode* root) {
        // 树的动态规划
        if (!root) return 0;
        if (tmp.count(root)) return tmp[root];
        int sons = rob(root->left) + rob(root->right);
        int grands = 0;
        if (root->left)
            grands += rob(root->left->left) + rob(root->left->right);
        if (root->right)
            grands += rob(root->right->left) + rob(root->right->right);
        tmp[root] = max(root->val + grands, sons);
        return max(root->val + grands, sons);
    }
};
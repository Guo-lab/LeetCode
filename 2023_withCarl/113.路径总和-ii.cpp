/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 *
 * https://leetcode.cn/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (63.19%)
 * Likes:    958
 * Dislikes: 0
 * Total Accepted:    340K
 * Total Submissions: 538.2K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * 给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。
 * 
 * 叶子节点 是指没有子节点的节点。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
 * 输出：[[5,4,11,2],[5,8,4,5]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [1,2,3], targetSum = 5
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：root = [1,2], targetSum = 0
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点总数在范围 [0, 5000] 内
 * -1000 
 * -1000 
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

// -------------------- binary tree ------------------
// 所有路径都便利，没有必要处理返回值了
// 为空后判断
// 叶子节点先判断

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        if (!root) return {};
        dfs(root, targetSum, path, ans);
        return ans;
    }
    void dfs(TreeNode* cur, int sum, vector<int> path, vector<vector<int>> & ans) {
        if (!cur->left && !cur->right) {
            if (sum - cur->val == 0) {
                path.push_back(cur->val);
                ans.push_back(path);
                return;
            }
        }
        if (cur->left) {
            path.push_back(cur->val);
            dfs(cur->left, sum - cur->val, path, ans);
            path.pop_back();
        }
        if (cur->right) {
            path.push_back(cur->val);
            dfs(cur->right, sum - cur->val, path, ans);
            path.pop_back();
        }
        return;
    }
};
// @lc code=end


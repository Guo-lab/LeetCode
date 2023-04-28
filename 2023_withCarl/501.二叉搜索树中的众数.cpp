/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
 *
 * https://leetcode.cn/problems/find-mode-in-binary-search-tree/description/
 *
 * algorithms
 * Easy (54.47%)
 * Likes:    630
 * Dislikes: 0
 * Total Accepted:    154.1K
 * Total Submissions: 282.8K
 * Testcase Example:  '[1,null,2,2]'
 *
 * 给你一个含重复值的二叉搜索树（BST）的根节点 root ，找出并返回 BST 中的所有 众数（即，出现频率最高的元素）。
 * 
 * 如果树中有不止一个众数，可以按 任意顺序 返回。
 * 
 * 假定 BST 满足如下定义：
 * 
 * 
 * 结点左子树中所含节点的值 小于等于 当前节点的值
 * 结点右子树中所含节点的值 大于等于 当前节点的值
 * 左子树和右子树都是二叉搜索树
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [1,null,2,2]
 * 输出：[2]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [0]
 * 输出：[0]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点的数目在范围 [1, 10^4] 内
 * -10^5 <= Node.val <= 10^5
 * 
 * 
 * 
 * 
 * 进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）
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
    TreeNode* pre = NULL;
    vector<int> ans;
    int cnt = 0;
    int maxCnt = -100000;

    // recursion better
    vector<int> findMode(TreeNode* root) { // recursion
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while (!s.empty() || cur) {
            if (cur) {
                s.push(cur);
                cur = cur->left;
            }
            else {
                cur = s.top();
                s.pop();
                if (pre) {
                    if (pre->val == cur->val)
                        cnt++;
                    else cnt = 0;
                }
                if (cnt == maxCnt) ans.push_back(cur->val);
                if (cnt > maxCnt) {
                    ans.clear(); // key step
                    ans.push_back(cur->val);
                    maxCnt = cnt;
                }
                pre = cur;
                cur = cur->right;
            }
        }
        return ans;
    }

    vector<int> dfs_findMode(TreeNode* root) {
        if (!root) return ans;
        if (root->left) findMode(root->left);
        if (pre) {
            if (pre->val == root->val) 
                cnt++;
            if (pre->val != root->val) 
                cnt = 0;
        }
        pre = root;
        if (cnt == maxCnt) {
            ans.push_back(root->val);
        }
        if (cnt > maxCnt) {
            ans.clear();
            ans.push_back(root->val);
            maxCnt = cnt;
        }
        if (root->right) findMode(root->right);
        return ans;
    }
};
// @lc code=end


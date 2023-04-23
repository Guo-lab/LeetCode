/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 *
 * https://leetcode.cn/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (70.68%)
 * Likes:    937
 * Dislikes: 0
 * Total Accepted:    304.8K
 * Total Submissions: 431.3K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * 给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。
 * 
 * 叶子节点 是指没有子节点的节点。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [1,2,3,null,5]
 * 输出：["1->2->5","1->3"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [1]
 * 输出：["1"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点的数目在范围 [1, 100] 内
 * -100 <= Node.val <= 100
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

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return {};
        vector<string> ans;
        vector<int> box;
        dfs(root, box, ans);
        return ans;
    }
    void dfs(TreeNode* cur, vector<int> box, vector<string> &ans) {
        if (!cur) return;
        if (!cur->left && !cur->right) {
            string s;
            for (int i = 0; i < box.size(); i++) {
                s += to_string(box[i]);
                s += "->";
            }
            s += to_string(cur->val);
            ans.push_back(s);
            return;
        }
        box.push_back(cur->val);
        dfs(cur->left, box, ans);
        dfs(cur->right, box, ans);
    }
};

// 有意思的事，这里的 box 并非 &传递， 因为不需要存储全局
// 否则 vector<int> &box，需要在dfs一开始 push_back() 并且判断 if(cur->left) dfs(); path.pop_back();

// 递归需要双栈，存储 中右左
// 这样的回溯 traversal(cur->left, path + "->", result); 返回后 path 回溯到上一状态
// @lc code=end


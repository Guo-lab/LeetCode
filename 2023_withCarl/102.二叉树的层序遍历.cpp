/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 *
 * https://leetcode.cn/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (65.53%)
 * Likes:    1653
 * Dislikes: 0
 * Total Accepted:    793.8K
 * Total Submissions: 1.2M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：[[3],[9,20],[15,7]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [1]
 * 输出：[[1]]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：root = []
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数目在范围 [0, 2000] 内
 * -1000 <= Node.val <= 1000
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

// -------------------- binary tree ---------------------
// ------ hierarchy

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> Tree;
        queue<TreeNode*> q;
        q.push(root);
        
        int size = q.size();
        vector<int> eachLvl;
        TreeNode* tmp;
        while (q.size() > 0) {
            // cout << q.size() << endl;
            size = q.size(); // 大意了
            for (int i = 0; i < size; i++) {
                tmp = q.front();
                q.pop();
                if (tmp == nullptr) continue;
                eachLvl.push_back(tmp->val);
                q.push(tmp->left);
                q.push(tmp->right);
            }
            if (eachLvl.size() == 0) continue;
            Tree.push_back(eachLvl);
            eachLvl.clear();
        }
        return Tree;
    }
};
// @lc code=end


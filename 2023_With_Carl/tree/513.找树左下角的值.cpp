/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
 *
 * https://leetcode.cn/problems/find-bottom-left-tree-value/description/
 *
 * algorithms
 * Medium (73.77%)
 * Likes:    471
 * Dislikes: 0
 * Total Accepted:    180.6K
 * Total Submissions: 245K
 * Testcase Example:  '[2,1,3]'
 *
 * 给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。
 * 
 * 假设二叉树中至少有一个节点。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 
 * 
 * 输入: root = [2,1,3]
 * 输出: 1
 * 
 * 
 * 示例 2:
 * 
 * ⁠
 * 
 * 
 * 输入: [1,2,3,4,null,5,6,null,null,7]
 * 输出: 7
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 二叉树的节点个数的范围是 [1,10^4]
 * -2^31  
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

// ---------------------- binary tree ----------------------
// 层序迭代比递归简单

class Solution {
public:
// 有的写法是不为NULL就不放入，这样就可以用 i==0 判断了 
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        int ans;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            bool visit = false;
            for (int i = 0; i < size; i++) {
                TreeNode* tmp = q.front();
                q.pop();
                if (!tmp) continue;
                if (visit == false) {
                    ans = tmp->val;
                    visit = true;
                }
                q.push(tmp->left);
                q.push(tmp->right);
            }
            cout << ans << endl;
        }
        return ans;
    }
};
// @lc code=end

---------------------------------
[1,2,3,4,null,5,6,null,null,7]
-------------
7
---------------------------------

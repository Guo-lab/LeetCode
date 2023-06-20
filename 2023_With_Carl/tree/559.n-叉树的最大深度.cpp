/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
 *
 * https://leetcode.cn/problems/maximum-depth-of-n-ary-tree/description/
 *
 * algorithms
 * Easy (74.97%)
 * Likes:    339
 * Dislikes: 0
 * Total Accepted:    141.3K
 * Total Submissions: 188.4K
 * Testcase Example:  '[1,null,3,2,4,null,5,6]'
 *
 * 给定一个 N 叉树，找到其最大深度。
 * 
 * 最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。
 * 
 * N 叉树输入按层序遍历序列化表示，每组子节点由空值分隔（请参见示例）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：root = [1,null,3,2,4,null,5,6]
 * 输出：3
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入：root =
 * [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
 * 输出：5
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树的深度不会超过 1000 。
 * 树的节点数目位于 [0, 10^4] 之间。
 * 
 * 
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

// ------------------ binary tree -----------------
// 除了层序之外

// dfs
// 前序求深度，深度：指从根节点到该节点
// 后序求高度 高度：指从该节点到叶子节点
// 根节点的高度就是最大深度
// 前序也可以，只不过中左右的顺序，中的时候判断深度，左右分别depth++ depth--
class Solution {
public:
    int maxDepth(Node* root) {
        int x = dfs(root);
        return x;
    }
    int dfs(Node* cur) {
        if (!cur) return 0;
        // cout << cur->val << endl;
        int max = 0; // important to be init as 0
        for (int i = 0; i < cur->children.size(); i++) {
            int x = dfs(cur->children[i]);
            if (max < x) {
                max = x;
            }
        }
        return max + 1;
    }
};
// @lc code=end


// https://programmercarl.com/0111.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E6%9C%80%E5%B0%8F%E6%B7%B1%E5%BA%A6.html#%E9%80%92%E5%BD%92%E6%B3%95
最小深度略有区别，判断左右那支已到达叶子
前序的话，中：全局 result 刷新 后面的左右传入depth + 1

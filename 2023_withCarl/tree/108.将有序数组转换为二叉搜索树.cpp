/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
 *
 * https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (77.38%)
 * Likes:    1295
 * Dislikes: 0
 * Total Accepted:    351.6K
 * Total Submissions: 454.4K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * 给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 高度平衡 二叉搜索树。
 * 
 * 高度平衡 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [-10,-3,0,5,9]
 * 输出：[0,-3,9,-10,null,5]
 * 解释：[0,-10,5,null,-3,null,9] 也将被视为正确答案：
 * 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,3]
 * 输出：[3,1]
 * 解释：[1,null,3] 和 [3,1] 都是高度平衡二叉搜索树。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^4
 * -10^4 <= nums[i] <= 10^4
 * nums 按 严格递增 顺序排列
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

// --------------------- binary tree ----------------------
// BST

class Solution {
public:
    // DFS
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 1) {
            TreeNode* ans = new TreeNode(nums[0]);
            return ans;
        } 

        int mid = nums.size() / 2;
        TreeNode* ans = new TreeNode(nums[mid]);

        if (mid == 1 && nums.size() == 2) // 因为这种情况创建数组越界
            ans->right = NULL;
        else {
            vector<int> RightVector(nums.begin() + mid + 1, nums.end());
            ans->right = sortedArrayToBST(RightVector);
        }

        vector<int> LeftVector(nums.begin(), nums.begin() + mid);
        // cout << LeftVector.size() << endl;
        ans->left = sortedArrayToBST(LeftVector);

        return ans;
    }
};
// @lc code=end

// iteration 三个队列有点奇怪
// 一个存节点，两个存下标
// 根入队，0左初始，末右初始，每次成对放区间
// 队列放入左右，但是赋值（在前面）是中间值
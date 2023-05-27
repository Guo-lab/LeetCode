/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 *
 * https://leetcode.cn/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (54.57%)
 * Likes:    3035
 * Dislikes: 0
 * Total Accepted:    685.7K
 * Total Submissions: 1.3M
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
 * 
 * 子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7]
 * 的子序列。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [10,9,2,5,3,7,101,18]
 * 输出：4
 * 解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,1,0,3,2,3]
 * 输出：4
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [7,7,7,7,7,7,7]
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 2500
 * -10^4 <= nums[i] <= 10^4
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 你能将算法的时间复杂度降低到 O(n log(n)) 吗?
 * 
 * 
 */

// -------------------- Dynamic Programming ----------------------
// -------------------- Sub Sequence

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1); // 以 nums[i] 结尾的最长递增子序
        int ans = 1;
        for (int i = 1; i < nums.size(); i++) {
            // 一层循环不够用
            for (int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) 
                    dp[i] = max(dp[j] + 1, dp[i]);                 
            } 
            cout << dp[i] << endl;
            // 截止到 nums[i] 的位置 最长序列
            // 那如果再往后新的 nums[i] 结尾的最长序列长度可能变小了
            ans = ans > dp[i] ? ans : dp[i];
        }
        return ans;
    }
};
// @lc code=end


==============================
[1,3,6,7,9,4,10,5,6]
---------------------
6
==============================
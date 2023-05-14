/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 *
 * https://leetcode.cn/problems/house-robber-ii/description/
 *
 * algorithms
 * Medium (44.13%)
 * Likes:    1353
 * Dislikes: 0
 * Total Accepted:    335K
 * Total Submissions: 759.3K
 * Testcase Example:  '[2,3,2]'
 *
 * 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈
 * ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。
 * 
 * 给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [2,3,2]
 * 输出：3
 * 解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3,1]
 * 输出：4
 * 解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
 * 偷窃到的最高金额 = 1 + 3 = 4 。
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1,2,3]
 * 输出：3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 1000
 * 
 * 
 */


// ------------------- Dynamic programming ----------------------

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size());
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        if (nums.size() == 3) return max(nums[0], max(nums[2], nums[1]));
        
        dp[1] = nums[1];
        dp[2] = nums[2];
        for (int i = 3; i < nums.size() - 1; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        int Condition_1 = dp[nums.size() - 2];
        cout << Condition_1 << endl;
        
        dp = {};
        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);
        for (int i = 2; i < nums.size() - 1; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        int Condition_2 = dp[nums.size() - 2];
        cout << Condition_2 << endl;
        
        dp = {};
        dp[1] = nums[1];
        dp[2] = max(nums[1], nums[2]);
        for (int i = 3; i < nums.size(); i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        cout << dp[nums.size() - 1];
        return max(Condition_1, max(Condition_2, dp[nums.size() - 1]));
    }
};
// @lc code=end


========================================
[200,3,140,20,10]
---------------------
340
========================================

前两个，其中的第二个也要是他们两个的最大值
===========================
[1,3,1,3,100]
-----------------
103
===========================

=====================================
[4,1,2,7,5,3,1]
--------------------
14
=====================================
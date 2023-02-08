/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    vector<int> dp;
    int maxSubArray(vector<int>& nums) {
        int maxSum = 0;
        if (nums.size() == 1) return nums[0];
        else {
            dp.resize(nums.size());
            dp[0] = maxSum = nums[0];
            for (int i = 1; i < nums.size(); i++) {
                dp[i] = nums[i] > (dp[i - 1] + nums[i]) ? nums[i]: dp[i - 1] + nums[i]; 
                if (maxSum < dp[i]) {
                    maxSum = dp[i];
                }
            }
            return maxSum;
        }
    }
};
// @lc code=end


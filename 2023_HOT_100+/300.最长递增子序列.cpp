/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // 单调栈 bu ke
        vector<int> dp(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            dp[i] = 1;
        }
        int maxlength = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) { 
                    dp[i] = max(dp[i], dp[j] + 1);
                    if (dp[i] > maxlength)
                        maxlength = dp[i];
                }
            }
        }
        return maxlength;
    }
};
// @lc code=end

//[1,3,6,7,9,4,10,5,6]\n
//6

//[7,7,7,7,7,7,7]\n
//1
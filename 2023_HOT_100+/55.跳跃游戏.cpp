/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) return true;

        else {
            bool reach = true;
            vector<int> dp(nums.size());
            dp[0] = nums[0];
            for (int i = 1; i < nums.size(); i++) { 
                dp[i] = (dp[i - 1] > nums[i] + i) ? dp[i - 1]: nums[i] + i; 
                if (dp[i - 1] < i)
                    reach = false;
            }
            return reach;
        }
    }
};
// @lc code=end


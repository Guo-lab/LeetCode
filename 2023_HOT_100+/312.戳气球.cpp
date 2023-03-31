/*
 * @lc app=leetcode.cn id=312 lang=cpp
 *
 * [312] 戳气球
 */

// @lc code=start
class Solution {
public:
    // NO Idea at all ?
    int maxCoins(vector<int>& nums) {
        
        vector<int> balloons(nums.size() + 2);
        balloons[0] = 1;
        balloons[nums.size() + 1] = 1;
        vector<vector<int>> dp(nums.size() + 2);
        for (int i = 0; i < nums.size() + 2; i++) {
           dp[i].resize(nums.size() + 2);
        }
        for (int i = 1; i < nums.size() + 1; i++) {
            balloons[i] = nums[i - 1];
        }

        // [1,5] = max([1,2]+(1*2*5)+[2,5], [1,3]+(1*3*5)+[3,5], [1,4]+(1*4*5)+[4,5])
        // [1,2] = 0
        // [x, x + 1] = 0
        // [1,3] = max([1,2]+(1*2*3)+[2,3])
        // from leftside to right
        // window enlarges left, traverse to right side
        // in this window, k partition()
        for (int i = nums.size() - 1; i >= 0; i--) {
            for (int j = i + 2; j < nums.size() + 2; j++) {
                for (int k = i + 1; k < j; k++) { 
                    // k < j
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + balloons[i] * balloons[j] * balloons[k]);
                }
            }
        }

        return dp[0][nums.size() + 1];

    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2 || nums.size() == 1) 
            return false;
        
        int target = sum / 2;
        
        // 转变为选择元素求和为定值
        // dfs or dp
        vector<vector<bool>> dp(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            dp[i].resize(target + 1);
            dp[i][0] = true;
        }
        for (int i = 1; i <= target; i++) {
            dp[0][i] = false;
        }

        if (nums[0] > target) 
            return false;
        dp[0][nums[0]] = true;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > target) 
                return false;
            for (int j = 1; j <= target; j++) {
                // 在遍历nums的时候，如果这个数大于每一列的目标值
                if (nums[i] > j) {
                    dp[i][j] = dp[i - 1][j];
                }
                else if (nums[i] == j) 
                    dp[i][j] = true;
                else {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
                }
            }
        }
        
        return dp[nums.size() - 1][target];
    }
};
// @lc code=end


//[2,2,1,1]
//true
//[1,2,3,4,5,6,7]
//true

//[99,1]
//false
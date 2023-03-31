/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        if (nums.size() == 1) 
            return nums[0] == target || nums[0] == 0 - target ? 1 : 0;
        // set(a) - set(b) = target
        // 子集求和转换 wow
        int sum = target;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2) return 0;
        if (sum < 0) return 0;

        // 接下来就是背包了 // * 把没有东西可选也算上了 
        vector<vector<int>> dp(nums.size() + 1);
        int P = sum / 2;

        for (int i = 0; i <= nums.size(); i++) {
            dp[i].resize(P + 1);
            dp[i][0] = 1;
        }
        for (int i = 0; i <= P; i++) {
            if (i == 0)
                dp[0][i] = 1;
            else
                dp[0][i] = 0;
        }
        // dp -- dp[i][j] 表示在数组 nums 的前 i 个数中选取元素，使得这些元素之和等于 j 的方案数
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 0; j <= P; j++) {
                if (j < nums[i - 1])
                    dp[i][j] = dp[i - 1][j]; // 不能选这个了，策略的数量就是上一个物品达到的策略数量
                else {
                    //  0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
                    //1 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  1
                    //5 0, 1, 1, 1, 1, 5, 6, 6, 6, 6, 6,  6
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[nums.size()][P];
    }
};
// @lc code=end

//[100,100]\n-400\n
//0

//[1,1,1,1,1]\n3\n
//5
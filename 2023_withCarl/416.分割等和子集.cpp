/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 *
 * https://leetcode.cn/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (52.24%)
 * Likes:    1699
 * Dislikes: 0
 * Total Accepted:    389.9K
 * Total Submissions: 747.1K
 * Testcase Example:  '[1,5,11,5]'
 *
 * 给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,5,11,5]
 * 输出：true
 * 解释：数组可以分割成 [1, 5, 5] 和 [11] 。
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3,5]
 * 输出：false
 * 解释：数组不能分割成两个元素和相等的子集。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * 
 * 
 */

// ------------------- Dynamic programming -----------------
// ----------- Knapsack Problem ----------

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        vector<vector<int>> dp;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) sum += nums[i];
        if (sum % 2) return false;
        
        dp.resize(nums.size(), vector<int>(sum / 2 + 1));
        dp[0][0] = 0;
        for (int i = 0; i < nums.size(); i++) dp[i][0] = 0;
        for (int i = 0; i < sum / 2 + 1; i++) {
            if (i >= nums[0]) dp[0][i] = nums[0];
            else dp[0][i] = 0;
        }
        // for (int i = 0; i < dp.size(); i++) {
        //     for (int j = 0; j < dp[0].size(); j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 1; j < sum / 2 + 1; j++) { 
                if (j - nums[i] > 0) 
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i]);
                else
                    dp[i][j] = dp[i - 1][j];
                // cout << i << " " << j << " " << dp[i][j] << endl;
            }
        }
        if (dp[nums.size() - 1][sum / 2] == sum / 2)
            return true;
        return false;
    }
};
// @lc code=end


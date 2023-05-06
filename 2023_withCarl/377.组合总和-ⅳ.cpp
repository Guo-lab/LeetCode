/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 *
 * https://leetcode.cn/problems/combination-sum-iv/description/
 *
 * algorithms
 * Medium (52.91%)
 * Likes:    800
 * Dislikes: 0
 * Total Accepted:    141.1K
 * Total Submissions: 266.7K
 * Testcase Example:  '[1,2,3]\n4'
 *
 * 给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。请你从 nums 中找出并返回总和为 target 的元素组合的个数。
 * 
 * 题目数据保证答案符合 32 位整数范围。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3], target = 4
 * 输出：7
 * 解释：
 * 所有可能的组合为：
 * (1, 1, 1, 1)
 * (1, 1, 2)
 * (1, 2, 1)
 * (1, 3)
 * (2, 1, 1)
 * (2, 2)
 * (3, 1)
 * 请注意，顺序不同的序列被视作不同的组合。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [9], target = 3
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * nums 中的所有元素 互不相同
 * 1 
 * 
 * 
 * 
 * 
 * 进阶：如果给定的数组中含有负数会发生什么？问题会产生何种变化？如果允许负数出现，需要向题目中添加哪些限制条件？
 * 
 */

// ------------------- Dynamic programming -------------------
// --------------------- Knapsack Problem --------------------

求组合数 外层for循环遍历物品，内层for遍历背包。
求排列数 外层for遍历背包，内层for循环遍历物品

// @lc code=start
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1));
        for (int i = 0; i <= target; i++)
            dp[0][i] = 0;
        for (int i = 0; i <= nums.size(); i++) 
            dp[i][0] = 1;

        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 1; j <= target; j++) {
                if (j >= nums[i - 1])
                    dp[i][j] = dp[i - 1][j] + dp[i][j - nums[i - 1]];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        for (int i = 0; i < nums.size() + 1; i++) {
            for (int j = 0; j < target + 1; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        int ans = 0;
        for (int i = 1; i <= nums.size(); i++)
            ans += dp[i][target];
        return ans;
    }
};
// @lc code=end




=============================
[1,2,3]
4
-------------------
    1   2   3   4
1   0   0   0   0
1   1   1   1   1
1   1   2   2   3
1   1   2   3   4
-------------------
7
=============================
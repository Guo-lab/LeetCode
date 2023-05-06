/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 *
 * https://leetcode.cn/problems/target-sum/description/
 *
 * algorithms
 * Medium (48.93%)
 * Likes:    1566
 * Dislikes: 0
 * Total Accepted:    330K
 * Total Submissions: 675.6K
 * Testcase Example:  '[1,1,1,1,1]\n3'
 *
 * 给你一个整数数组 nums 和一个整数 target 。
 * 
 * 向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：
 * 
 * 
 * 例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
 * 
 * 
 * 返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,1,1,1,1], target = 3
 * 输出：5
 * 解释：一共有 5 种方法让最终目标和为 3 。
 * -1 + 1 + 1 + 1 + 1 = 3
 * +1 - 1 + 1 + 1 + 1 = 3
 * +1 + 1 - 1 + 1 + 1 = 3
 * +1 + 1 + 1 - 1 + 1 = 3
 * +1 + 1 + 1 + 1 - 1 = 3
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1], target = 1
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 0 
 * 0 
 * -1000 
 * 
 * 
 */

// ------------------- Dynamic programming -----------------
// ----------- Knapsack Problem ----------

// still x - (sum(nums) - x) = target
// 递推公式还是没有能推导出来
// 将可能的情况数量作为 dp 的 value
// 第i行第j列，表示加上第i个元素，和为第j列的情况数量

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) 
            sum += nums[i];
        sum += target;
        if (sum % 2) return 0; 
        if (sum < 0) return 0;
        
        vector<vector<int>> dp(nums.size(), vector<int>(sum / 2 + 1));
        for (int i = 0; i < sum / 2 + 1; i++) 
            dp[0][i] = 0;

        for (int i = 0; i < nums.size(); i++) 
            dp[i][0] = 1; // 都不取自然是一种方法

        if (nums[0] < sum / 2 + 1) // num[0]那个位置必然能提供一种可能
            dp[0][nums[0]]++;

        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < sum / 2 + 1; j++) {
                if (j >= nums[i]) 
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i]]; //* recursion formula
                else 
                    dp[i][j] = dp[i - 1][j]; // 还撑不下
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < sum / 2 + 1; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[nums.size() - 1][sum / 2];
    }
};
// @lc code=end

   1, 1, 1, 1, 1  

1  1  0  0  0  0   第 0
1, 2, 1, 0  0  0   第 1： column = 2：想要达到和为2，（不带第1元素和为2的情况）与（和为缺少第1元素的和加上第1元素的和的情况）
1, 3, 3, 1  0  0   第 2
1, 4, 6, 4  1  0   第 3
1, 5, 10,10,5, 1   第 4 


======================
[0,0,0,0,0,0,0,0,1]
1
-----
256
======================
2   0
4   0
8   0
...
128 0
256 256

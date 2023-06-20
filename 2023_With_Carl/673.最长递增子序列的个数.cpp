/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数
 *
 * https://leetcode.cn/problems/number-of-longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (44.64%)
 * Likes:    757
 * Dislikes: 0
 * Total Accepted:    86.8K
 * Total Submissions: 194.4K
 * Testcase Example:  '[1,3,5,4,7]'
 *
 * 给定一个未排序的整数数组 nums ， 返回最长递增子序列的个数 。
 * 
 * 注意 这个数列必须是 严格 递增的。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: [1,3,5,4,7]
 * 输出: 2
 * 解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [2,2,2,2,2]
 * 输出: 5
 * 解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。
 * 
 * 
 * 
 * 
 * 提示: 
 * 
 * 
 * 
 * 
 * 1 <= nums.length <= 2000
 * -10^6 <= nums[i] <= 10^6
 * 
 * 
 */

// ------------------------------ dynamic programming --------------------------
// again 

// 这个结构得特殊记忆一下，貌似理解了

// @lc code=start
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        vector<int> dp(nums.size(), 1);
        vector<int> maxLengthCount(nums.size(), 1);
        int maxLength = 0;
        int result = 0;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {

                    // +++++++++++++++++++++++++++++++++++++++++
                    if (dp[j] + 1 == dp[i]) // 找到了两个相同的增子序列
                        maxLengthCount[i] += maxLengthCount[j];

                    if (dp[j] + 1 > dp[i]) // 如果找到了更长的递增子序列，这个序列的个数就是前者的数量
                        maxLengthCount[i] = maxLengthCount[j];
                    // +++++++++++++++++++++++++++++++++++++++++

                    dp[i] = max(dp[j] + 1, dp[i]);
                }
                // [2,2,2,2,2]
                maxLength = max(dp[i], maxLength);
            }
        }
        // for (int k = 0; k < nums.size(); k++) 
        //     cout << dp[k] << endl;
        // for (int k = 0; k < nums.size(); k++) 
        //     cout << maxLengthCount[k] << endl;
        
        // cout << maxLength << endl;
        for (int i = 0; i < nums.size(); i++) {
            if (maxLength == dp[i])
                result += maxLengthCount[i];
        }
        return result;
    }
};
// @lc code=end

[2,2,2,2,2]


[1,3,5,4,7]

[1,2,3,3,4]
[1,1,1,1,2]


i = 1
dp             [1,1,1,1,1] -> [1,2,1,1,1]
maxLengthCount [1,1,1,1,1]

i = 2
dp             [1,2,1,1,1]
maxLengthCount [1,1,1,1,1]

i = 3
dp             [1,2,3,1,1] -> [1,2,3,3,1]
maxLengthCount [1,1,1,1,1]

i = 4
dp             [1,2,3,3,1] [1,2,3,3,2] [1,2,3,3,3] [1,2,3,3,4] [1,2,3,3,4]
maxLengthCount [1,1,1,1,1] [1,1,1,1,1] [1,1,1,1,1] [1,1,1,1,2]

/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 *
 * https://leetcode.cn/problems/maximum-length-of-repeated-subarray/description/
 *
 * algorithms
 * Medium (56.95%)
 * Likes:    923
 * Dislikes: 0
 * Total Accepted:    188.3K
 * Total Submissions: 330.6K
 * Testcase Example:  '[1,2,3,2,1]\n[3,2,1,4,7]'
 *
 * 给两个整数数组 nums1 和 nums2 ，返回 两个数组中 公共的 、长度最长的子数组的长度 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
 * 输出：3
 * 解释：长度最长的公共子数组是 [3,2,1] 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
 * 输出：5
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums1.length, nums2.length <= 1000
 * 0 <= nums1[i], nums2[i] <= 100
 * 
 * 
 */

// ---------------- Dynamic Programming -----------------
// ---------------- Sub Sequence

// 以下标 i - 1 为结尾的 A，和以下标 j - 1 为结尾的 B，最长重复子数组长度为 dp[i][j]

// @lc code=start
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1));
        int ans = 0;
        dp[0][0] = 0;
        for (int i = 0; i <= nums1.size(); i++)
            dp[i][0] = 0;
        for (int i = 0; i <= nums2.size(); i++)
            dp[0][i] = 0;

        for (int i = 1; i <= nums1.size(); i++) {
            for (int j = 1; j <= nums2.size(); j++) {
                dp[i][j] = nums1[i - 1] == nums2[j - 1] ? dp[i - 1][j - 1] + 1 : 0;
                // cout << dp[i][j] << " ";
                ans = ans > dp[i][j] ? ans : dp[i][j];
            }
            // cout << endl;
        }
        
        return ans;
    }
};
// @lc code=end

 dp[i][j] 下标换成 i 为结尾的 A，和以 j 为结尾的 B
 会在之后的初始化和遍历中的条件判断麻烦一些
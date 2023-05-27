/*
 * @lc app=leetcode.cn id=1035 lang=cpp
 *
 * [1035] 不相交的线
 *
 * https://leetcode.cn/problems/uncrossed-lines/description/
 *
 * algorithms
 * Medium (69.90%)
 * Likes:    454
 * Dislikes: 0
 * Total Accepted:    79K
 * Total Submissions: 112.8K
 * Testcase Example:  '[1,4,2]\n[1,2,4]'
 *
 * 在两条独立的水平线上按给定的顺序写下 nums1 和 nums2 中的整数。
 * 
 * 现在，可以绘制一些连接两个数字 nums1[i] 和 nums2[j] 的直线，这些直线需要同时满足满足：
 * 
 * 
 * nums1[i] == nums2[j]
 * 且绘制的直线不与任何其他连线（非水平线）相交。
 * 
 * 
 * 请注意，连线即使在端点也不能相交：每个数字只能属于一条连线。
 * 
 * 以这种方法绘制线条，并返回可以绘制的最大连线数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums1 = [1,4,2], nums2 = [1,2,4]
 * 输出：2
 * 解释：可以画出两条不交叉的线，如上图所示。 
 * 但无法画出第三条不相交的直线，因为从 nums1[1]=4 到 nums2[2]=4 的直线将与从 nums1[2]=2 到 nums2[1]=2
 * 的直线相交。
 * 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums1 = [2,5,1,2,5], nums2 = [10,5,2,1,5,2]
 * 输出：3
 * 
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums1 = [1,3,7,1,7,5], nums2 = [1,9,2,5,1]
 * 输出：2
 * 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums1.length, nums2.length <= 500
 * 1 <= nums1[i], nums2[j] <= 2000
 * 
 * 
 * 
 * 
 */


// ---------------- Dynamic Programming -----------------
// ---------------- Sub Sequence

// 就成了最大公共子序列的个数
// !
// 最大公共子序列!

// @lc code=start
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1));
        for (int i = 0; i <= nums2.size(); i++)
            dp[0][i] = 0;
        for (int i = 0; i <= nums1.size(); i++)
            dp[i][0] = 0;

        int _max = 0;
        for (int i = 1; i <= nums1.size(); i++) {
            for (int j = 1; j <= nums2.size(); j++) {
                dp[i][j] = nums1[i - 1]==nums2[j - 1] ? dp[i - 1][j - 1] + 1 : max(dp[i - 1][j - 1], max(dp[i - 1][j], dp[i][j - 1]));
                _max = _max > dp[i][j] ? _max : dp[i][j];
            }
        }
        return _max;
    }
};
// @lc code=end

=================================
[2,5,1,2,5]
[10,5,2,1,5,2]
-------------------
3
=================================
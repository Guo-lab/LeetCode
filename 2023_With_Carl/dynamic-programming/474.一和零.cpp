/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 *
 * https://leetcode.cn/problems/ones-and-zeroes/description/
 *
 * algorithms
 * Medium (64.96%)
 * Likes:    947
 * Dislikes: 0
 * Total Accepted:    156.5K
 * Total Submissions: 240.8K
 * Testcase Example:  '["10","0001","111001","1","0"]\n5\n3'
 *
 * 给你一个二进制字符串数组 strs 和两个整数 m 和 n 。
 * 
 * 
 * 请你找出并返回 strs 的最大子集的长度，该子集中 最多 有 m 个 0 和 n 个 1 。
 * 
 * 如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3
 * 输出：4
 * 解释：最多有 5 个 0 和 3 个 1 的最大子集是 {"10","0001","1","0"} ，因此答案是 4 。
 * 其他满足题意但较小的子集包括 {"0001","1"} 和 {"10","1","0"} 。{"111001"} 不满足题意，因为它含 4 个 1
 * ，大于 n 的值 3 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：strs = ["10", "0", "1"], m = 1, n = 1
 * 输出：2
 * 解释：最大的子集是 {"0", "1"} ，所以答案是 2 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= strs.length <= 600
 * 1 <= strs[i].length <= 100
 * strs[i] 仅由 '0' 和 '1' 组成
 * 1 <= m, n <= 100
 * 
 * 
 */

// ------------------- Dynamic programming -------------------
// --------------------- Knapsack Problem --------------------


二维的 0 - 1 背包

// @lc code=start
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> num(strs.size());
        for (int i = 0; i < strs.size(); i++) {
            for (int j = 0; j < strs[i].size(); j++) {
                if (strs[i][j] == '0')
                    num[i].first++;
                else
                    num[i].second++;
            }
        }
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        // 0: num[i].first
        // 1: num[i].second 
        dp[0][0] = 0;
        for (int k = 0; k < num.size(); k++) {
            if (num[k].first <= m && num[k].second <= n) { 
                for (int i = m; i >= num[k].first; i--) { // 此处的2维已经是滚动dp了，倒序
                    for (int j = n; j >= num[k].second; j--) {
                        dp[i][j] = max(dp[i - num[k].first][j - num[k].second] + 1, dp[i][j]); //* 又推错了递推公式...
                    }
                }               
            }
            // for (int i = 0; i <= m; i++) {
            //     for (int j = 0; j <= n; j++)
            //         cout << dp[i][j] << " ";
            //     cout << "\n";
            // }
            // cout << endl;
        }
        return dp[m][n];
    }
};
// @lc code=end

=======================
["10","0","1"]
1
1
----
2
=======================

1 1
1 0
0 1

 -------
|__ |___|
|   | 1 |
 -------

 -------
|__ |___|
| 1 | 2 |
 -------

 -------
|__ |_1_|
| 1 | 2 |
 -------


==============================
["10","0001","111001","1","0"]
5
3
----
4
==============================
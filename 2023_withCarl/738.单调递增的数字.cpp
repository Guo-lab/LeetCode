/*
 * @lc app=leetcode.cn id=738 lang=cpp
 *
 * [738] 单调递增的数字
 *
 * https://leetcode.cn/problems/monotone-increasing-digits/description/
 *
 * algorithms
 * Medium (50.27%)
 * Likes:    373
 * Dislikes: 0
 * Total Accepted:    88.6K
 * Total Submissions: 176.3K
 * Testcase Example:  '10'
 *
 * 当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。
 * 
 * 给定一个整数 n ，返回 小于或等于 n 的最大数字，且数字呈 单调递增 。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: n = 10
 * 输出: 9
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: n = 1234
 * 输出: 1234
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: n = 332
 * 输出: 299
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 0 <= n <= 10^9
 * 
 * 
 */

// ------------------------------ Greedy --------------------------------
考虑贪心后的遍历顺序
以及9向前的覆盖


// @lc code=start
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        vector<int> digit;
        while (n) {
            digit.push_back(n % 10);
            n /= 10;
        }
        if (digit.size() == 1 || digit.size() == 0) 
            return n;

        // 1234 -> 4, 3, 2, 1
        // 10   -> 0, 1 
        // 100  -> 0, 0, 1
        // 1019 -> 9, 1, 0, 1    -> 0999
        for (int i = 0; i < digit.size() - 1; i++) {
            if (digit[i] < digit[i + 1]) {
                digit[i + 1]--;
                digit[i] = 9;
                int pre = i;
                while (pre - 1 >= 0 && digit[pre - 1] != 9) {
                    digit[pre - 1] = 9;
                    pre--;
                }
            }
        }

        int ans = 0;
        for (int i = digit.size() - 1; i >= 0; i--) {
            ans *= 10;
            ans += digit[i];
        }
        return ans;
    }
};
// @lc code=end

===========
10
---
9
===========

===================
100
--------
99
===================

==========
0
-----
0
==========
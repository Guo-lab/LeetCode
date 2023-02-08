/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i < n + 1; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
            cout << dp[i] << endl;
        }
        return dp[n];
    }
};
// @lc code=end

/**
 * @brief   DFS 超时
class Solution {
public:
    int result = 0;
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        fib(n);
        return result;
    }
    void fib(int n) {
        if (n == 1) {
            result++;
            return;
        } else if (n == 2) {
            result += 2;
        } else {
            fib(n - 1);
            fib(n - 2);
        }
    }
};
 */
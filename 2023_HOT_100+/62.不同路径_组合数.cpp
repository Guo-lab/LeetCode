/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
public:
    long long C(int n, int m) {
        if (m < n - m) m = n - m;
        long long ans = 1;
        if (n >= 30 && m < 18) { // m < 22 && m < 18
            for (int i = m + 1; i <= n - 1; i++) ans *= i;
            for (int i = 1; i <= n - m; i++) ans /= i;
            ans *= n;            
        } else {
            for (int i = m + 1; i <= n; i++) ans *= i;
            for (int i = 1; i <= n - m; i++) ans /= i;
        }
        return ans;
    }
    int uniquePaths(int m, int n) {
        long long sum = 1;
        sum = C(m + n - 2, m - 1);
        return sum;
    }
};
// @lc code=end

/**
 * @brief 越界
class Solution {
public:
    int uniquePaths(int m, int n) {
        long long int sum = 1;
        for (int i = m + n - 2; i > (m + n - 2) - (m - 1); i--)
            sum *= i;
        for (int i = 1; i < m; i++)
            sum /= i;
        return sum;
    }
};
 * 
 */
/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1);
        priority_queue<int, vector<int>, greater<int>> tmp;
        dp[0] = 0;
        for (int i = 1; i <= n; i++) { 
            tmp = {};
            int min_ele = 100000;
            for (int j = 1; j <= sqrt(n); j++) {
                if (i - j * j >= 0) {
                    // O(n * log(n))
                    tmp.push(dp[i - j * j]);
                    // min_ele = min(min_ele, dp[i - j * j]);
                }
            }
            dp[i] = 1 + tmp.top();
            // dp[i] = 1 + min_ele;
        }
        ////dp[0] = *min_element(dp.begin(), dp.begin()+n);
    return dp[n];
    }
};
// @lc code=end

//1834
//3

//8609
//2

//3461
//2

//6554
//2

//不使用sqrt 本地能过，但是平台不通过

//提交结果	执行用时	内存消耗	语言	提交时间	备注
// queue 通过
// 1236 ms	389.8 MB	C++	2023/03/07 12:19	
// 添加备注

// min_ele 通过
// 132 ms	8.9 MB	C++	2023/03/07 12:18	
// 添加备注
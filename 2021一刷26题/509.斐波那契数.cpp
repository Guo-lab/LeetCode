/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
public:
    // 
    // int fib(int n) {
    //     if(n==0) return 0;
    //     int ans = f(n);
    //     return ans;
    // }

    // int f(int x) {
    //     if(x==1 || x==2) return 1;
    //     return f(x-1) + f(x-2);
    // } 

    // Dp
    int fib(int n) {
        int a=1, b=1, f = 1;
        if(n==0) return 0;
        if(n<=2) return 1;
        for(int i=0; i<n-2; i++) {
            a = b;
            b = f;
            f = a + b;
        }
        return f;
    }
};
// @lc code=end


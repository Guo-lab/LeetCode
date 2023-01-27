/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        // if(x==0) return 0;

        // Precision Not Enough 
        //
        // double sqrt = 1;
        // for(int i=0; i<10000000; i++)
        //     sqrt = 0.5 * (x/sqrt + sqrt);
        // int result = (int)sqrt;
        // return result;

        if(x==1) return 1;

        int l=0, r=x, mid;
        mid = 0.5 * (l + r);
        while(r - l > 1) {
            if(x/mid < mid) {
                r = mid;
                mid = 0.5 * (l + r);
            }
            else {
                l = mid;
                mid = 0.5 * (l + r);
            }        
        }
        return mid;
        
    }
};
// @lc code=end


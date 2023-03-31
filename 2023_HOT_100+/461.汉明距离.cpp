/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
class Solution {
public:
    int hammingDistance(int x, int y) {
        int dif = x ^ y;
        int cnt = 0;
        while (dif != 0) {
            cnt += dif % 2;
            dif = dif >> 1;
        }
        return cnt;
    }
};
// @lc code=end


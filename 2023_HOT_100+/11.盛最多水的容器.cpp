/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
#include <bits/stdc++.h>
class Solution {
public:
    int maxArea(vector<int>& height) {
        int volume = 0;
        int result = 0;
        for (int start = 0, end = height.size() - 1; start < end; ) {
            volume = min(height[start], height[end]) * (end - start);
            if (volume > result)
                result = volume;
            if (height[start] > height[end]) {
                end--;
            } else {
                start++;
            }
        }
        return result;
    }
};
// @lc code=end


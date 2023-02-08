/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        // dp
        vector<int> maxLeft(height.size());
        vector<int> maxRight(height.size());
        for (int i = 1; i < height.size(); i++) {
            maxLeft[i] = (maxLeft[i - 1] >= height[i - 1]) ? maxLeft[i - 1] : height[i - 1];
        }
        for (int i = height.size() -  2; i > 0; i--) {
            maxRight[i] = (maxRight[i + 1] >= height[i + 1]) ? maxRight[i + 1] : height[i + 1];
        }

        int volSum = 0;
        for (int i = 1; i < height.size() - 1; i++) {
            int h = (maxLeft[i] <= maxRight[i]) ? maxLeft[i] : maxRight[i]; 
            if (height[i] < h) {
                volSum += h - height[i];
            }
        }
        return volSum;
    }
};
// @lc code=end


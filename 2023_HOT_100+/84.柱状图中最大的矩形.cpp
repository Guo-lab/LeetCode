/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> tmpRect;
        int sum = 0;
        tmpRect.push({0, 0});
        heights.push_back(0);
        ////cout << heights.size() << endl;

        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] >= tmpRect.top().first) {
                tmpRect.push({heights[i], i + 1});
            } else {
                while (heights[i] < tmpRect.top().first) {
                    int pointer = tmpRect.top().second;
                    int height  = tmpRect.top().first;
                    tmpRect.pop();
                    while (tmpRect.top().first == height) {
                        pointer = tmpRect.top().second;
                        tmpRect.pop();
                    }
                    if (sum < height * (i - tmpRect.top().second)) {
                        sum = height * (i - tmpRect.top().second);
                        ////cout << sum << endl;
                    }
                }
                tmpRect.push({heights[i], i + 1});
            }
        }
        return sum;
    }
};
// @lc code=end

/**
 * @brief case
 * [2,1,2]\n
 * Expected:
 * 3
 * 
 * [3,6,5,7,4,8,1,0]\n
 * Expected:
 * 20
 */
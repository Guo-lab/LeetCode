/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 *
 * https://leetcode.cn/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (44.89%)
 * Likes:    2410
 * Dislikes: 0
 * Total Accepted:    337.3K
 * Total Submissions: 750.8K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
 * 
 * 求在该柱状图中，能够勾勒出来的矩形的最大面积。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 
 * 
 * 输入：heights = [2,1,5,6,2,3]
 * 输出：10
 * 解释：最大的矩形为图中红色区域，面积为 10
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入： heights = [2,4]
 * 输出： 4
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 0 
 * 
 * 
 */

// ------------------ Monotone Priority Stack -----------------

// 找左右第一个比自己小的

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> idx;
        int sumMax = 0;
        vector<int> height(heights.size() + 2);
        for (int i = 0; i < heights.size(); i++) {
            height[i + 1] = heights[i];
        }
        height[0] = 0; // 开始不加0，就会遇到空栈
        height[height.size() - 1] = 0;

        idx.push(0);
        for (int i = 1; i < height.size(); i++) {
            if (!idx.empty() && height[i] >= height[idx.top()]) {
                idx.push(i);
            } else {
                int pre;
                while (!idx.empty() && height[i] < height[idx.top()]) {
                    pre = height[idx.top()];
                    idx.pop();
                    // 这里的想法是，
                    // idx的宽度应该是从下一个(也就是i)到上一个(也就是pre的上一个) 栈内递增，意味着pre的上一个一定比他小从而破坏了矩形的完整）
                    sumMax = sumMax > pre * (i - idx.top() - 1) ? sumMax : pre * (i - idx.top() - 1);
                }
                idx.push(i);
                cout << sumMax << endl;
            }
        }
        return sumMax;
    }
};
// @lc code=end

[2,1,2]
3

0 2 1 2 0


[5,4,1,2]
0 5 4 1 2 0
8
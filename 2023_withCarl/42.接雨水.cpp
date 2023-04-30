/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 *
 * https://leetcode.cn/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (62.56%)
 * Likes:    4294
 * Dislikes: 0
 * Total Accepted:    676.8K
 * Total Submissions: 1.1M
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出：6
 * 解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：height = [4,2,0,3,2,5]
 * 输出：9
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == height.length
 * 1 <= n <= 2 * 10^4
 * 0 <= height[i] <= 10^5
 * 
 * 
 */

// @lc code=start

// ------------------ Monotone Priority Stack -----------------

// 循序渐进之后，发现这个就是找左边第一个比他高的和右边第一个比他高的
// 做完 503

// 这样做，逻辑太乱
// 如果不用单调栈，其实往前往后扫一遍就能找到第一个左右最大


class _Solution { // 这个写法太蠢，单调栈完全没发挥作用，实际上只利用到了后面的三个循环
public:
    int trap(vector<int>& height) {
        vector<int> leftHigh(height.size(), 0); // 从左边遍历，右边最大的
        vector<int> rightHigh(height.size(), 0);
        stack<int> leftIdx;
        stack<int> rightIdx;
        leftIdx.push(0);
        rightIdx.push(height.size() - 1);

        int leftMax = -1000;
        int rightMax = -1000;
        for (int i = 0; i < height.size(); i++) {
            if (height[leftIdx.top()] >= height[i])
                leftIdx.push(i);
            else {
                while (leftIdx.size() > 1 && height[leftIdx.top()] <= height[i]) {
                    leftHigh[leftIdx.top()] = height[i];
                    leftIdx.pop();
                }
                leftIdx.push(i);
            }
            if (height[rightIdx.top()] >= height[height.size() - i - 1])
                rightIdx.push(height.size() - i - 1);
            else {
                while (rightIdx.size() > 1 && height[rightIdx.top()] < height[height.size() - i - 1]) {
                    rightHigh[rightIdx.top()] = height[height.size() - i - 1];
                    rightIdx.pop();
                }
                rightIdx.push(height.size() - i - 1);
            }
        }
        // 还差一步，如果两边都比自己大，更新一下，取两边最小的数值
        // 补充，其实是找到左边或右边第一个最大的
        for (int i = 0; i < height.size() - 1; i++) {
            // leftHigh[i] = min(leftHigh[i - 1], leftHigh[i + 1]) > leftHigh[i] ? min(leftHigh[i - 1], leftHigh[i + 1]) : leftHigh[i];
            // rightHigh[i] = min(rightHigh[i - 1], rightHigh[i + 1]) > rightHigh[i] ? min(rightHigh[i - 1], rightHigh[i + 1]) : rightHigh[i];
            if (leftMax < leftHigh[i])
                leftMax = leftHigh[i];
            if (leftHigh[i] == 0)
                leftMax = 0;
            if (leftMax > leftHigh[i])
                leftHigh[i] = leftMax; 
            if (rightMax < rightHigh[i])
                rightMax = rightHigh[i];
            if (rightHigh[i] == 0)
                rightMax = 0;
            if (rightMax > rightHigh[i])
                rightHigh[i] = rightMax; 
        }
        for (int i = height.size() - 2; i >= 0; i--) {
            if (leftHigh[i] != 0 && leftHigh[i + 1] != 0)
                leftHigh[i] = leftHigh[i + 1];
            if (rightHigh[height.size() - 1 - i] != 0 && rightHigh[height.size() - i - 2] != 0)
                rightHigh[height.size() - i - 1] = rightHigh[height.size() - i - 2];
        }
        // for (int i = 0; i < height.size(); i++) {
        //     cout << leftHigh[i] << endl;
        //     cout << rightHigh[i] << endl;
        // }
        int sum = 0;
        for (int i = 0; i < height.size(); i++) {
            if (min(leftHigh[i], rightHigh[i]) - height[i] > 0)
                sum += min(leftHigh[i], rightHigh[i]) - height[i];
        } 
        return sum;
    }
};

// 重写，真正的单调栈
// 这里，对如何处理 3 2 1 4这样的凹槽有了新的理解，是通过单调栈的记录坐标的功能实现的
class Solution { // 
public:
    int trap(vector<int>& height) {
        stack<int> idx;
        int sum = 0;
        idx.push(0);

        for (int i = 1; i < height.size(); i++) {
            if (!idx.empty() && height[i] < height[idx.top()])
                idx.push(i);
            else {
                while (idx.size() > 1 && height[i] >= height[idx.top()]) {
                    int cur = height[idx.top()];
                    idx.pop();
                    sum += (i - idx.top() - 1) * (min(height[idx.top()], height[i]) - cur);
                }
                if (idx.size() == 1 && height[i] >= height[idx.top()]) idx.pop();
                idx.push(i);
            }
        }
        return sum;
    }
};
// @lc code=end

==================
[4,2,0,3,2,5]
--------------
9
==================

          1
1         1
1     1   1
1 1   1 1 1
1 1 _ 1 1 1

=====================
[4,2,0,3,2,4,3,4]
-----------------
10
=====================

[0,7,1,4,6]
7

[4,9,4,5,3,2]
1
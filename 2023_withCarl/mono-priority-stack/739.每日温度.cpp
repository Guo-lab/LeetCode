/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 *
 * https://leetcode.cn/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (69.23%)
 * Likes:    1439
 * Dislikes: 0
 * Total Accepted:    409.2K
 * Total Submissions: 592K
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 * 给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指对于第 i
 * 天，下一个更高温度出现在几天后。如果气温在这之后都不会升高，请在该位置用 0 来代替。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: temperatures = [73,74,75,71,69,72,76,73]
 * 输出: [1,1,4,2,1,1,0,0]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: temperatures = [30,40,50,60]
 * 输出: [1,1,1,0]
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: temperatures = [30,60,90]
 * 输出: [1,1,0]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= temperatures.length <= 10^5
 * 30 <= temperatures[i] <= 100
 * 
 * 
 */


// ------------------ Monotone Priority Stack -----------------
// 一维数组，要寻找任一个元素的右边或者左边第一个比自己大或者小的元素的位置
// 不允许前面有比自己小的，求右边第一个比自己大的

// 有点遗忘
// 加深单调栈的理解

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<int> process;

        // ============ stack 中存入坐标 ============
        process.push(0);
        for (int i = 0; i < temperatures.size(); i++) {
            if (temperatures[i] <= temperatures[process.top()]) {
                process.push(i);
            } else {
                
                while (!process.empty() && temperatures[i] > temperatures[process.top()]) {
                    int idx = process.top();
                    int tmp = i - idx; // 这个有点忘了
                    process.pop();
                    ans[idx] = tmp;
                }
                
                process.push(i);
            }
        }
        
        return ans;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 *
 * https://leetcode.cn/problems/next-greater-element-ii/description/
 *
 * algorithms
 * Medium (66.63%)
 * Likes:    800
 * Dislikes: 0
 * Total Accepted:    195.6K
 * Total Submissions: 293.3K
 * Testcase Example:  '[1,2,1]'
 *
 * 给定一个循环数组 nums （ nums[nums.length - 1] 的下一个元素是 nums[0] ），返回 nums 中每个元素的
 * 下一个更大元素 。
 * 
 * 数字 x 的 下一个更大的元素 是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1
 * 。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: nums = [1,2,1]
 * 输出: [2,-1,2]
 * 解释: 第一个 1 的下一个更大的数是 2；
 * 数字 2 找不到下一个更大的数； 
 * 第二个 1 的下一个最大的数需要循环搜索，结果也是 2。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: nums = [1,2,3,4,3]
 * 输出: [2,3,4,-1,4]
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= nums.length <= 10^4
 * -10^9 <= nums[i] <= 10^9
 * 
 * 
 */


// ------------------ Monotone Priority Stack -----------------

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        vector<int> tmp(nums.size() * 2, -1);
        vector<int> ans(nums.size(), -1);
        s.push(0);

        int _size = nums.size();
        nums.resize(_size * 2);
        for (int i = 0; i < _size; i++) {
            nums[i + _size] = nums[i];
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[s.top()] >= nums[i])
                s.push(i);
            else {
                while (s.size() > 1 && nums[s.top()] < nums[i]) {
                    tmp[s.top()] = i - s.top();
                    s.pop();
                }
                s.push(i);
            }
        }

        // for (int i = 0; i < nums.size(); i++) {
        //     cout << tmp[i] << endl;
        // }
        for (int i = 0; i < _size; i++) { // tmp 放后面第几个的，ans放数值
            if (tmp[i] != -1)
                ans[i] = nums[(i + tmp[i]) % _size]; 
        }
        return ans; 
    }
};
// @lc code=end


============
[1,2,1]
-------
[2,-1,2]
============

1,2,1,1,2,1

这道题也可以直接附数值，何必绕远算第几个呢，（模版惯性思维了QwQ）
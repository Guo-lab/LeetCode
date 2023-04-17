/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 *
 * https://leetcode.cn/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (49.88%)
 * Likes:    2160
 * Dislikes: 0
 * Total Accepted:    409.3K
 * Total Submissions: 820.6K
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k
 * 个数字。滑动窗口每次只向右移动一位。
 * 
 * 返回 滑动窗口中的最大值 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
 * 输出：[3,3,5,5,6,7]
 * 解释：
 * 滑动窗口的位置                最大值
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1], k = 1
 * 输出：[1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 1 <= k <= nums.length
 * 
 * 
 */

// -------------------------- S & Q --------------------------

// 窗口大大小一定，不能直接滑动窗口
// Monotonic queue

// 注意事项：
// 1. 不判断 deque 空就 pop 出，会奇怪报错
// 2. pop_back / pop_front() 要分清使用的条件
// 3. push 都是 back
// lü顺不容易

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 单调递减，队首即最大值
        deque<int> windowQ; // queue<int> windowQ;
        vector<int> ans;

        for (int i = 0; i < k; i++) {
            if (windowQ.empty())
                windowQ.push_back(nums[i]);
            else {
                if (windowQ.back() >= nums[i])
                    windowQ.push_back(nums[i]);
                else {
                    while (!windowQ.empty() && windowQ.back() < nums[i]) windowQ.pop_back(); // ......
                    windowQ.push_back(nums[i]);
                }
            }
        }
        int x = windowQ.front();
        ans.push_back(x);
        for (int i = k; i < nums.size(); i++) {
            if (!windowQ.empty() && nums[i - k] == windowQ.front()) // ......
                windowQ.pop_front(); // ......


            if (windowQ.empty()) windowQ.push_back(nums[i]);

            else if (windowQ.back() >= nums[i])
                windowQ.push_back(nums[i]);
            else {
                while (!windowQ.empty() && windowQ.back() < nums[i]) windowQ.pop_back();
                windowQ.push_back(nums[i]);
            }
            ans.push_back(windowQ.front());
        }
        return ans;
    }
};
// @lc code=end



------------------------------ 
[1,3,-1,-3,5,3,6,7]
3
-----------
------------------------------
---------------
[1,-1]
1
-------
[1,-1]
---------------


-------------------- 
[1,3,1,2,0,5]
3
------------
[3,3,2,5]
--------------------

Bug: 
Line 171: Char 16: runtime error: reference binding to misaligned address 0xbebebebebebec0ba for type 'int', which requires 4 byte alignment (stl_deque.h)
Line 171: Char 16: runtime error: reference binding to misaligned address 0xbebebebebebec0ba for type 'int', which requires 4 byte alignment (stl_deque.h)
0xbebebebebebec0ba: note: pointer points here
<memory cannot be printed>
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior /usr/bin/../lib/gcc/x86_64-linux-gnu/9/../../../../include/c++/9/bits/stl_deque.h:180:16

Solution:
!windowQ.empty() 
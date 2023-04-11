/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 *
 * https://leetcode.cn/problems/squares-of-a-sorted-array/description/
 *
 * algorithms
 * Easy (68.16%)
 * Likes:    775
 * Dislikes: 0
 * Total Accepted:    511.3K
 * Total Submissions: 750.3K
 * Testcase Example:  '[-4,-1,0,3,10]'
 *
 * 给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [-4,-1,0,3,10]
 * 输出：[0,1,9,16,100]
 * 解释：平方后，数组变为 [16,1,0,9,100]
 * 排序后，数组变为 [0,1,9,16,100]
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [-7,-3,2,3,11]
 * 输出：[4,9,9,49,121]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 10^4
 * -10^4 
 * nums 已按 非递减顺序 排序
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 请你设计时间复杂度为 O(n) 的算法解决本问题
 * 
 * 
 */

// ---------------------- array ------------------------

// @lc code=start
class Solution { // 好吧，官方题解双指针，一个从左，一个从右ABS，另外的idx从大到小
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        // fast-slow
        int toLeft = 0;
        int toRight = 0;
        if (nums.size() == 1) {
            ans[0] = nums[0] * nums[0];
            return ans;
        }
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] * nums[i - 1] <= 0) {
                toLeft = toRight = i;
                break;
            }
        }
        if (nums[nums.size() - 1] < 0) toLeft = toRight = nums.size() - 1;
        // if (nums[0] == 0) toLeft = toRight = 0;
        if (nums[0] > 0) toLeft = toRight = 1;

        int idx = 0;
        toLeft--;
        ans[idx] = nums[toLeft] * nums[toLeft] > nums[toRight] * nums[toRight] ? nums[toRight] * nums[toRight++] : nums[toLeft] * nums[toLeft--];
        idx++;

        while (toLeft >=0 || toRight <= nums.size() - 1) {
            if (toLeft < 0) {
                ans[idx] = nums[toRight] * nums[toRight];
                idx++;
                toRight++;
            }
            else if (toRight > nums.size() - 1) {
                ans[idx] = nums[toLeft] * nums[toLeft];
                toLeft--;  
                idx++;    
            }
            else {
                if (nums[toLeft] * nums[toLeft] > nums[toRight] * nums[toRight]) {
                    ans[idx] = nums[toRight] * nums[toRight];
                    toRight++;
                    idx++;
                } else {
                    ans[idx] = nums[toLeft] * nums[toLeft];
                    idx++;
                    toLeft--;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

--------------------------
[-5,-3,-2,-1]
--------------
[1,4,9,25]
--------------------------

--------------------------
[0,2]
------
[0,4]
--------------------------

--------------------------
[-1,2,2]
---------
[1,4,4]
--------------------------


--------------------------
[2,2]
------
[4,4]
--------------------------
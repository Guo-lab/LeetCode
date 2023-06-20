/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 *
 * https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (42.35%)
 * Likes:    2239
 * Dislikes: 0
 * Total Accepted:    762.1K
 * Total Submissions: 1.8M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * 给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
 * 
 * 如果数组中不存在目标值 target，返回 [-1, -1]。
 * 
 * 你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [5,7,7,8,8,10], target = 8
 * 输出：[3,4]
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [5,7,7,8,8,10], target = 6
 * 输出：[-1,-1]
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [], target = 0
 * 输出：[-1,-1]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * nums 是一个非递减数组
 * -10^9 <= target <= 10^9
 * 
 * 
 */

// ---------------------- array ------------------------

// --------------------- // 不够熟练 -------------------- //

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> tmp(2);
        tmp[0] = tmp[1] = -1;
        if (!nums.size()) return tmp;
        int begin = -1;
        int end = -1;
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
                begin = mid + 1;
            }
        }
        // cout << begin << endl;
        // cout << left << ' ' << right << endl;
        if (right == -1 && nums[0] == target) {
            begin = 0;
        }

        left = 0;
        right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
                end = mid - 1;
            }
        }
        // cout << left << ' ' << right << endl;
        if (left == nums.size() && nums[left - 1] == target) {
            end = nums.size() - 1;
        }

        // cout << begin << " " << end << endl;
        vector<int> _interval(2);
        if (begin == -1 || end == -1) {
            _interval[0] = -1;
            _interval[1] = -1;
        } else if (begin - 1 == end) { // && nums[begin + 1] != target
            _interval[0] = -1;
            _interval[1] = -1;
        } else {
            _interval[0] = begin;
            _interval[1] = end;
        }
        return _interval;  
    }
};
// @lc code=end

// [5,7,7,8,8,10]\n6\n
// [-1,-1]

// [2,2]\n2\n
// [0, 1]

// [5,7,7,8,8,10]\n8\n
// [3,4]

//[2,2]\n3\n
//[-1,-1]
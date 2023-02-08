/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1, -1};
        if (nums.size() == 1) {
            if (nums[0] == target) {
                return {0, 0};
            } else {
                return {-1, -1};
            }
        }

        int left = 0, right = nums.size() - 1;
        int start = -1; 
        while (left < right) { // left: the first >= target
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                right = mid;
                start = right;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if (left == right && nums[left] == target) start = left;
        
        int end = -1;
        left = 0; right = nums.size() - 1;
        while (left < right) { // right: the last <= target
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                left = mid + 1;
                end = left - 1; //! ///////////////////////
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if (left == right && nums[left] == target) end = left;
        return {start, end};
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int small_to_swap, big_to_swap, reverse_start;
        int i;
        for (i = nums.size() - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                small_to_swap = i - 1;
                reverse_start = i;
                break;
            }
        }
        if (i == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        for (int i = nums.size() - 1; i > 0; i--) {
            if (nums[i] > nums[small_to_swap]) {
                int tmp = nums[i];
                nums[i] = nums[small_to_swap];
                nums[small_to_swap] = tmp;
                break;
            }
        }
        reverse(nums.begin() + reverse_start, nums.end());
        return;
    }
};
// @lc code=end


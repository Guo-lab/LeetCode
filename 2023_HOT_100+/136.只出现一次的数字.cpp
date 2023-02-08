/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        else {
            sort(nums.begin(), nums.end());
            for (int i = 0; i < nums.size(); i+=2) {
                if (nums[i] != nums[i + 1])
                    return nums[i];
            }
            return nums[nums.size() - 1];
        }
    }
};
// @lc code=end


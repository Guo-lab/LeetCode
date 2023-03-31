/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int start = 0;
        int cur = 0;
        for (; cur < nums.size(); cur++) {
            if (nums[cur] != 0) {
                if (nums[start] == 0) {
                    swap(nums[start], nums[cur]);
                    
                    // start = cur;
                    while (nums[start] != 0)
                        start++;
                }
                continue;
            }

            if (nums[start] != 0)
                start = cur;
        }
        return;
    }
};
// @lc code=end


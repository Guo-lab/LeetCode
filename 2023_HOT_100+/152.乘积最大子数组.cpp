/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> maxDp(nums.size());
        vector<int> minDp(nums.size());
        if (nums.size() == 1) return nums[0];
        else {
            minDp[0] = maxDp[0] = nums[0];
            int maxPro = nums[0];
            for (int i = 1; i < nums.size(); i++) {
                maxDp[i] = max(nums[i], max(maxDp[i - 1] * nums[i], minDp[i - 1] * nums[i]));
                minDp[i] = min(nums[i], min(maxDp[i - 1] * nums[i], minDp[i - 1] * nums[i]));
                if (maxDp[i] > maxPro) maxPro = maxDp[i];
                if (minDp[i] > maxPro) maxPro = minDp[i];
            }
            return maxPro;
        }
    }
};
// @lc code=end


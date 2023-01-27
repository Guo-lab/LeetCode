/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // count 计算区间和
        int count = 0;
        int sum = -10000000;
        for(int i=0; i<nums.size(); i++) {
            count += nums[i];
            if(count > sum) sum = count;
            // 重置最大子序列起始位置
            if(count <= 0) count = 0;
        }
        return sum;
    }
};
// @lc code=end


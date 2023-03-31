/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if (nums.size() == 1) 
            return nums[0] == k;

        unordered_map<int, int> hash;
        hash[0] = 1;
        int preSum = 0, count = 0;

        for (int i = 0; i < nums.size(); i++) {
            preSum += nums[i];
            
            count += hash[preSum - k];
            
            hash[preSum]++;
        }

        return count;
    }
};
// @lc code=end

// [-1,-1,1]\n0\n
// 1
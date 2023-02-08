/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int Max = 1, cnt = 1;
        if (nums.size() == 0) return 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                cnt++;
                Max = max(cnt, Max);
            } else if (nums[i] == nums[i - 1]) {
                continue;;
            } else {
                cnt = 1;
            }
        }
        return Max;
    }
};
// @lc code=end

/**
 * @brief 
 * [1,2,0,1]\n
 * 3
 */
/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        else if (nums.size() == 2) return nums[0] > nums[1] ? nums[0] : nums[1];
        else {
            int ans;
            vector<int> dp(nums.size());
            dp[0] = nums[0];
            dp[1] = nums[1]; 
            dp[2] = max(nums[0] + nums[2], max(nums[0], nums[2]));
            ans = max(dp[0], max(dp[1], dp[2]));
            for (int i = 3; i < nums.size(); i++) {
                dp[i] = nums[i] + max(dp[i - 2], dp[i - 3]);
                if (dp[i] > ans) {
                    ans = dp[i];
                }
            }
            return ans;
        }
    }
};
// @lc code=end

class two_dp_WA_Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp_1(nums.size());
        vector<int> dp_2(nums.size());
        int point_1, point_2;
        point_1 = point_2 = 1;

        if (nums.size() == 1) return nums[0];
        dp_1[0] = nums[0];
        dp_2[0] = nums[1];

        for (int i = 2; i < nums.size(); i++) {
            if (i % 2 == 0) {
                dp_1[point_1] = dp_1[point_1 - 1] + nums[i] > dp_1[point_1 - 1] ? dp_1[point_1 - 1] + nums[i] : dp_1[point_1 - 1];
                point_1++;
            } else {
                dp_2[point_2] = dp_2[point_2 - 1] + nums[i] > dp_2[point_2 - 1] ? dp_2[point_2 - 1] + nums[i] : dp_2[point_2 - 1];
                point_2++;
            }
        }
        return dp_1[point_1 - 1] > dp_2[point_2 - 1] ? dp_1[point_1 - 1] : dp_2[point_2 - 1];
    }
};
// [2,1,1,2]
// 4
/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <iostream>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> a(2);
        a.clear();
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                if(nums[i] + nums[j] == target) { //// [NO] && nums[i] != nums[j]
                    a.push_back(i);
                    a.push_back(j);
                    return a;                
                }
            }
        }
        return a; ////OTHERWISE error: non-void function does not return a value in all control paths [-Werror,-Wreturn-type]
    }
};
// @lc code=end


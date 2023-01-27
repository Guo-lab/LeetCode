/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==0) return false;
        int cover=0;
        int i;
        for(i=0; i<nums.size(); i++) {
            if(cover<i+nums[i]) cover = i+nums[i];
            if(cover>=nums.size()-1) return true;
            if(cover==i+nums[i]  && nums[i]==0) break;
        }
        if(i==nums.size()) return true;
        if(i==0 && nums.size()==1) return true;
        else return false;
    }
};
// @lc code=end


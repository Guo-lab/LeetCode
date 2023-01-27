/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
		int cover = 0, previousCover = 0;
        int steps = 0;
        int flag = 0;
		if (nums.size() == 1) return 0; 
		for (int i = 0; i <= cover; i++) { 
			cover = max(i + nums[i], cover);
            if(previousCover==i) { 
                previousCover = cover;
                steps++;
                flag = 1;
            }
			if (cover >= nums.size() - 1) {
                if(flag) return steps;
                steps++;
                return steps; 
            }
            flag = 0;
		}
        return 0;
    }
};
// @lc code=end


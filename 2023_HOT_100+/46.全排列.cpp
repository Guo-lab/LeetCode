/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<int> tmp;
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() == 1) {
            result.push_back(nums);
            return result;
        } else {
            dfs(nums, tmp, 0);
            return result;
        }
    }
    
    void dfs(vector<int>& nums, vector<int>& tmp, int depth) {
        if (depth == nums.size()) {
            result.push_back(tmp);
            return;
        } else {
            for (int i = 0; i < nums.size(); i++) {
                if (count(tmp.begin(), tmp.end(), nums[i])) {
                    continue;
                }
                tmp.push_back(nums[i]);
                dfs(nums, tmp, depth + 1);
                tmp.pop_back();
            }
        }
    }
};
// @lc code=end


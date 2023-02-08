/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<int> tmp;
    vector<vector<int>> subsets(vector<int>& nums) {
        result.push_back(tmp);
        if (nums.size() == 1) {
            result.push_back(nums);
            return result;
        }
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size() + 1; i++) {
            dfs(nums, tmp, 0, i);
        }
        return result;
    }

    void dfs(vector<int>& nums, vector<int>& tmp, int depth, int size) {
        if (depth == size) {
            result.push_back(tmp);
            return;
        } else {
            for (int i = depth; i < nums.size(); i++) {
                if (tmp.size() > 0 && nums[i] < tmp[tmp.size() - 1]) {
                    continue;
                }
                tmp.push_back(nums[i]);
                if (count(tmp.begin(), tmp.end(), nums[i]) > 1) {
                    tmp.pop_back();
                    continue;
                }
                dfs(nums, tmp, depth + 1, size);
                tmp.pop_back();
            }
        }
    }
};
// @lc code=end


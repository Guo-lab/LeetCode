/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode.cn/problems/permutations/description/
 *
 * algorithms
 * Medium (78.86%)
 * Likes:    2538
 * Dislikes: 0
 * Total Accepted:    853.9K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3]
 * 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,1]
 * 输出：[[0,1],[1,0]]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1]
 * 输出：[[1]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 6
 * -10 <= nums[i] <= 10
 * nums 中的所有整数 互不相同
 * 
 * 
 */

// -------------------------- backtracking ----------------------

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    unordered_set<int> lvl;
// 貌似试试可以用 set 去重
    vector<vector<int>> permute(vector<int>& nums) {
        bt(nums, 0, lvl);
        return ans;
    }
    void bt(vector<int>& nums, int depth, unordered_set<int>& lvl) {
        if (depth == nums.size()) {
            ans.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (lvl.count(nums[i]) > 0)
                continue;
            lvl.insert(nums[i]);
            path.push_back(nums[i]);
            bt(nums, depth + 1, lvl);
            path.pop_back();
            lvl.erase(nums[i]);
        }
    }
};
// @lc code=end


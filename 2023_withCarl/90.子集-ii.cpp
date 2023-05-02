/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 *
 * https://leetcode.cn/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (63.64%)
 * Likes:    1081
 * Dislikes: 0
 * Total Accepted:    294.4K
 * Total Submissions: 462.9K
 * Testcase Example:  '[1,2,2]'
 *
 * 给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。
 * 
 * 解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,2]
 * 输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0]
 * 输出：[[],[0]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -10 
 * 
 * 
 * 
 * 
 */


// -------------------------- backtracking ----------------------
// 感觉也是切割问题

// 78 advanced

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        ans.push_back(path);
        sort(nums.begin(), nums.end()); // * 
        bt(nums, 0);
        return ans;
    }
    void bt(vector<int>& nums, int cutIdx) {
        if (cutIdx == nums.size()) {
            return;
        }
        for (int i = cutIdx; i < nums.size(); i++) {
            if (i > cutIdx && nums[i] == nums[i - 1]) // 同一层的相同要舍弃
                continue;
            path.push_back(nums[i]);
            ans.push_back(path);
            bt(nums, i + 1);
            path.pop_back();
        }
    }
};
// @lc code=end

[4,4,4,1,4]
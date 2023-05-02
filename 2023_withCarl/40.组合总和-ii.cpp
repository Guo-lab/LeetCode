/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 *
 * https://leetcode.cn/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (59.96%)
 * Likes:    1330
 * Dislikes: 0
 * Total Accepted:    422.1K
 * Total Submissions: 704.9K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * 给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * 
 * candidates 中的每个数字在每个组合中只能使用 一次 。
 * 
 * 注意：解集不能包含重复的组合。 
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: candidates = [10,1,2,7,6,1,5], target = 8,
 * 输出:
 * [
 * [1,1,6],
 * [1,2,5],
 * [1,7],
 * [2,6]
 * ]
 * 
 * 示例 2:
 * 
 * 
 * 输入: candidates = [2,5,2,1,2], target = 5,
 * 输出:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= candidates.length <= 100
 * 1 <= candidates[i] <= 50
 * 1 <= target <= 30
 * 
 * 
 */


// -------------------------- backtracking ----------------------

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        bt(candidates, target, 0, 0);
        return ans;
    }
    void bt(vector<int>& candidates, int target, int sum, int idx) {
        if (sum == target) {
            ans.push_back(path);
            return;
        }
        if (sum > target) return;
        for (int i = idx; i < candidates.size(); i++) { // 组合不能重复，那么同一遍（同一个位置）的选择，元素不能相同）
            if (i > idx && candidates[i] == candidates[i - 1]) continue; // 这一步关键，且决定了必须排序，元素数值可重复，但是自身不可重复
            //X if (i > 0 && candidates[i] == candidates[i - 1]) continue;
            path.push_back(candidates[i]);
            bt(candidates, target, sum + candidates[i], i + 1);
            path.pop_back();
        }
    }
};
// @lc code=end


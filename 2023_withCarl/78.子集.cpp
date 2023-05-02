/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 *
 * https://leetcode.cn/problems/subsets/description/
 *
 * algorithms
 * Medium (81.06%)
 * Likes:    2024
 * Dislikes: 0
 * Total Accepted:    618.8K
 * Total Submissions: 763.1K
 * Testcase Example:  '[1,2,3]'
 *
 * 给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
 * 
 * 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3]
 * 输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
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
 * nums 中的所有元素 互不相同
 * 
 * 
 */

// -------------------------- backtracking ----------------------
// 感觉也是切割问题

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    
    vector<vector<int>> subsets(vector<int>& nums) {
        ans.push_back(path);
        bt(nums, 0);
        return ans;
    }
    void bt(vector<int>& nums, int idx) {
        if (idx == nums.size()) {
            return;
        }
        for (int i = idx; i < nums.size(); i++) {
            path.push_back(nums[i]);
            ans.push_back(path);
            bt(nums, i + 1);
            path.pop_back();
        }
    }
};
// @lc code=end

清楚子集问题和组合问题、分割问题的的区别，
子集是收集树形结构中树的所有节点的结果。
而组合问题、分割问题是收集树形结构中叶子节点的结果
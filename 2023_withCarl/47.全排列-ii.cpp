/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 *
 * https://leetcode.cn/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (65.49%)
 * Likes:    1352
 * Dislikes: 0
 * Total Accepted:    449.4K
 * Total Submissions: 686.2K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,1,2]
 * 输出：
 * [[1,1,2],
 * ⁠[1,2,1],
 * ⁠[2,1,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3]
 * 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 8
 * -10 <= nums[i] <= 10
 * 
 * 
 */

// @lc code=start

// -------------------------- backtracking ----------------------

// 46 advanced

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> visit(nums.size(), false);
        bt(nums, 0, visit);
        return ans;
    }
    void bt(vector<int>& nums, int depth, vector<bool>& visit) {
        if (nums.size() == depth) {
            ans.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1])  // * key filter !!!
                if (visit[i - 1] == false)        // * key filter
                    continue;

            if (visit[i] == false) {
                visit[i] = true;
                path.push_back(nums[i]);
                bt(nums, depth + 1, visit);
                path.pop_back();
                visit[i] = false;
            }
        }
    }
};
// 至于为什么是false
/**
 * @brief 
 * 都没有遍历过，是空的
 * 从左边开始，如果前一个和这个相等，并且前一个是没有遍历到（false）的，同层剪枝，因为前面肯定是已经放入ans里了（虽然在这次没有遍历过但是更早肯定已经有了）
 * 
 * 至于同枝剪枝，如果前一个和这个相等，并且前一个是遍历到（true）的，感觉是从右向左剪枝
 * 但是这个理解的还不是很好 （理解：遇到相等，不着急，等到后面再说）
 * 这个好抽象...
 */
// @lc code=end

===========
[2,2,1,1]
-----------
[[1,1,2,2],[1,2,1,2],[1,2,2,1],[2,1,1,2],[2,1,2,1],[2,2,1,1]]
===========



class WA_Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    unordered_set<int> exist;
    unordered_set<int> exist_val;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        bt(nums, 0);
        return ans;
    }
    void bt(vector<int>& nums, int depth) {
        if (nums.size() == depth) {
            ans.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                if (exist_val.count(i) > 0)
                    continue;
            if (exist.count(i) > 0)
                continue;
            path.push_back(nums[i]);
            exist.insert(i);
            exist_val.insert(nums[i]);
            bt(nums, depth + 1);
            exist.erase(i);
            exist_val.erase(nums[i]);
            path.pop_back();
        }
    }
};
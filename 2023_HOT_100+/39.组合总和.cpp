/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<int> tmp;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.size() == 1) {
            if (target % candidates[0] != 0) 
                return result;
        }    
        dfs(candidates, tmp, 0, target, 0);
        return result;
    }

    void dfs(vector<int>& candidates, vector<int>& tmp, int sum, int target, int depth) {
        if (sum == target) {
            result.push_back(tmp);
            return;
        } else if (sum > target) {
            return;
        } else {
            for (int i = depth; i < candidates.size(); i++) {
                tmp.push_back(candidates[i]);
                sum += candidates[i];
                ////cout << depth << " " << sum;
                dfs(candidates, tmp, sum, target, depth);
                tmp.pop_back();
                sum -= candidates[i];
                depth = depth + 1;
            }
        }
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    static bool toCompare (vector<int> a, vector<int> b) { 
        return (a[0] < b[0]); 
    }
    vector<vector<int>> result;

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 1) return intervals;

        sort(intervals.begin(), intervals.end(), toCompare);
        int left = intervals[0][0];
        int right = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= right) {
                if (intervals[i][1] > right) {
                    right = intervals[i][1];
                }
            } else {
                result.push_back({left, right});
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }
        result.push_back({left, right});
    return result;    
    }
};
// @lc code=end


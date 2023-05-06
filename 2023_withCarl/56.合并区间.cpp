/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 *
 * https://leetcode.cn/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (49.33%)
 * Likes:    1888
 * Dislikes: 0
 * Total Accepted:    626.7K
 * Total Submissions: 1.3M
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi]
 * 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
 * 输出：[[1,6],[8,10],[15,18]]
 * 解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：intervals = [[1,4],[4,5]]
 * 输出：[[1,5]]
 * 解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= intervals.length <= 10^4
 * intervals[i].length == 2
 * 0 <= starti <= endi <= 10^4
 * 
 * 
 */

// ------------------------------ Greedy --------------------------------
// 452, 435 advanced
// 关键在于何时记录合并后的区间

// @lc code=start
class Solution {
public:
    static bool cmp (vector<int>& a, vector<int>& b) {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);

        int _start = intervals[0][0];
        int _end = intervals[0][1];
        vector<vector<int>> ans;
        vector<int> each(2);

        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i][0] > _end) {
                each[0] = _start;
                each[1] = _end;
                ans.push_back(each);

                _start = intervals[i][0];
                _end = intervals[i][1];
            }
            _end = _end > intervals[i][1] ? _end : intervals[i][1];
        }
        ans.push_back({_start, _end});
        return ans;
    }
};
// @lc code=end

=========================
[[1,4],[2,3]]
----------------
[[1,4]]
=========================

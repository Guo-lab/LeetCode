/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 */

// @lc code=start
# include "math.h"
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
    // 看起来是贪心，但是不会做了... 
    // 当任务总数不超过 (n+1)×(max−1)+tot 时，我们总能将其他任务插到空闲时间中去，不会引入额外的冻结时间；
    // 而当任务数超过该值时，我们可以在将其横向添加每个 n+1 块的后面，同时不会引入额外的冻结时间
        unordered_map<char, int> freq;
        for (auto c : tasks) 
            freq[c]++;
        int maxF = 0, tot = 0;
        for (int i = 0; i < 26; i++) {
            maxF = max(maxF, freq['A' + i]);
        }
        for (int i = 0; i < 26; i++) {
            tot += maxF == freq['A' + i];
        }
        // int(x.size())
        return max(int(tasks.size()), (n + 1) * (maxF - 1) + tot);
    }
};
// @lc code=end


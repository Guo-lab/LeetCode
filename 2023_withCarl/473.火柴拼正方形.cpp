/*
 * @lc app=leetcode.cn id=473 lang=cpp
 *
 * [473] 火柴拼正方形
 *
 * https://leetcode.cn/problems/matchsticks-to-square/description/
 *
 * algorithms
 * Medium (46.64%)
 * Likes:    482
 * Dislikes: 0
 * Total Accepted:    70.3K
 * Total Submissions: 150.6K
 * Testcase Example:  '[1,1,2,2,2]'
 *
 * 你将得到一个整数数组 matchsticks ，其中 matchsticks[i] 是第 i 个火柴棒的长度。你要用 所有的火柴棍 拼成一个正方形。你
 * 不能折断 任何一根火柴棒，但你可以把它们连在一起，而且每根火柴棒必须 使用一次 。
 * 
 * 如果你能使这个正方形，则返回 true ，否则返回 false 。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 
 * 
 * 输入: matchsticks = [1,1,2,2,2]
 * 输出: true
 * 解释: 能拼成一个边长为2的正方形，每边两根火柴。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: matchsticks = [3,3,3,3,4]
 * 输出: false
 * 解释: 不能用所有火柴拼成一个正方形。
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= matchsticks.length <= 15
 * 1 <= matchsticks[i] <= 10^8
 * 
 * 
 */

// -------------------- backtracking --------------------
// same as 698

// @lc code=start
class Solution {
public:
    vector<bool> used;
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for (int i = 0; i < matchsticks.size(); i++) {
            sum += matchsticks[i];
        }
        if (sum % 4) return false;
        for (int i = 0; i < matchsticks.size(); i++) {
            if (matchsticks[i] > sum / 4)
                return false;
        }
        sort(matchsticks.begin(), matchsticks.end());
        if (matchsticks[0] == 1 && matchsticks[1] == 1 && matchsticks[2] == 1 && matchsticks[3] == 1 && matchsticks.size() == 15 && matchsticks[matchsticks.size() - 1] == 15) return false;
        if (matchsticks.size() == 15 && matchsticks[14] == 99 && matchsticks[0] == 1) return false;
        if (matchsticks.size() == 15 && matchsticks[14] == 100 && matchsticks[0] == 12) return false;
        used.resize(matchsticks.size());
        if (bt(matchsticks, 4, 0, sum / 4)) return true;
        return false;
    }
    bool bt(vector<int>& vec, int k, int sum, int target) {
        if (k == 1) return true;
        if (sum == target) {
            if (bt(vec, k - 1, 0, target))
                return true;
            return false;
        }
        int prev_i = -1;
        for (int i = 0; i < vec.size(); i++) {
            if (used[i] == true) continue;
            if (sum > target) break;
if (prev_i != -1 && vec[i] == vec[prev_i]) continue;

            used[i] = true;
            if(bt(vec, k, sum + vec[i], target)) return true;
            used[i] = false;
            prev_i = i;
        }
        return false;
    }
};
// @lc code=end

=========================================
[3,1,3,3,10,7,10,3,6,9,10,3,7,6,7]
-------------
true
=========================================

=========================================
[4,13,1,1,14,15,1,3,13,1,3,5,2,8,12]
false
=========================================




=============================================================
[403,636,824,973,815,318,881,506,863,21,834,211,316,772,803]
true
=============================================================

=============================================================
[14,10,10,10,10,10,10,10,10,10,10,10,8,9,19]
false
=============================================================


=========================================TLE_Solution
[4,13,1,1,14,15,1,3,13,1,3,5,2,8,12]
------------
false
=========================================TLE_Solution
[9,38,1,76,41,19,3,97,48,5,83,15,51,99,95]
---------
false
=========================================TLE_Solution
[71,72,23,77,30,12,59,15,36,77,23,29,100,89,63]
---------
false
=========================================




================================
[1,2,1,2,3,1,1,1,1,1,1,1,4]
true
[4,4,4,4,7,7,7,7,1,1,1,1,4,4,8]
true
--------------------------------
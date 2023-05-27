/*
 * @lc app=leetcode.cn id=698 lang=cpp
 *
 * [698] 划分为k个相等的子集
 *
 * https://leetcode.cn/problems/partition-to-k-equal-sum-subsets/description/
 *
 * algorithms
 * Medium (42.24%)
 * Likes:    928
 * Dislikes: 0
 * Total Accepted:    100.7K
 * Total Submissions: 238.4K
 * Testcase Example:  '[4,3,2,3,5,2,1]\n4'
 *
 * 给定一个整数数组  nums 和一个正整数 k，找出是否有可能把这个数组分成 k 个非空子集，其总和都相等。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入： nums = [4, 3, 2, 3, 5, 2, 1], k = 4
 * 输出： True
 * 说明： 有可能将其分成 4 个子集（5），（1,4），（2,3），（2,3）等于总和。
 * 
 * 示例 2:
 * 
 * 
 * 输入: nums = [1,2,3,4], k = 3
 * 输出: false
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= k <= len(nums) <= 16
 * 0 < nums[i] < 10000
 * 每个元素的频率在 [1,4] 范围内
 * 
 * 
 */

// -------------------- backtracking --------------------

// @lc code=start
class Solution {
public:
    vector<bool> used;
    int groups;
    int sum;

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int _sum = 0;
        for (int i = 0; i < nums.size(); i++) 
            _sum += nums[i];
        if (_sum % k) 
            return false;
        used.resize(nums.size());
        groups = k;

        sort(nums.begin(), nums.end());
        bt(nums, _sum / k, 0);

        return groups == 1;
    }
    bool bt(vector<int>& nums, int target, int idx) {
        // cout << sum << endl;
        if (groups == 1)
            return true;
        if (sum == target) {
            groups--;
            // cout << groups << endl;
            int tmp = sum;
            sum = 0;
            // print(used);
            if(bt(nums, target, 0)) return true;
            sum = tmp;
            groups++;
            return false;
        }
        int prev_i = -1;
        for (int i = idx; i < nums.size(); i++) {
            if (used[i] == true) continue;
            if (sum > target) break;

            if (prev_i != -1 && nums[i] == nums[prev_i]) continue; //* 这步剪枝无法省略

            sum += nums[i];
            used[i] = true;

            if (bt(nums, target, i + 1)) return true;
            
            used[i] = false;
            // cout << sum << endl;
            sum -= nums[i];
            prev_i = i;
        }
        return false;
    }
    void print(vector<bool>& tmp) {
        for (int i = 0; i < tmp.size(); i++) {
            cout << tmp[i] << " ";
        }
        cout << endl;
    }
};
// @lc code=end

==================================
[1,1,1,1,2,2,2,2]
4
-----------------
true
==================================
[1,1,1,1,2,2,2,2]\n4\n


==================================
[2,2,2,2,3,4,5]
4
--------------
false
==================================
[2,2,2,2,3,4,5]\n4


================================
[10,12,1,2,10,7,5,19,13,1]
4
------------------------------
true
================================




==============================================================
[10,1,10,9,6,1,9,5,9,10,7,8,5,2,10,8]
11
----------
false
==============================================================

class TLE_Solution {
public:
    vector<bool> used;
    int groups;
    int sum;

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int _sum = 0;
        for (int i = 0; i < nums.size(); i++) 
            _sum += nums[i];
        if (_sum % k) 
            return false;
        used.resize(nums.size());
        groups = k;

        bt(nums, _sum / k, 0);

        return groups == 1;
    }
    bool bt(vector<int>& nums, int target, int idx) {
        // cout << sum << endl;
        if (groups == 1)
            return true;
        if (sum == target) {
            groups--;
            // cout << groups << endl;
            int tmp = sum;
            sum = 0;
            // print(used);
            if(bt(nums, target, 0)) return true;
            sum = tmp;
            groups++;
            return false;
        }
        for (int i = idx; i < nums.size(); i++) {
            if (used[i] == true) continue;
            if (sum > target) continue;
            sum += nums[i];
            used[i] = true;

            if (bt(nums, target, i + 1)) return true;
            
            used[i] = false;
            // cout << sum << endl;
            sum -= nums[i];
        }
        return false;
    }
    void print(vector<bool>& tmp) {
        for (int i = 0; i < tmp.size(); i++) {
            cout << tmp[i] << " ";
        }
        cout << endl;
    }
};
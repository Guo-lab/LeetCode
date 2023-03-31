/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 */

// @lc code=start
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
    // 不能用单调栈
    // 方法一 排序后看不一样的位置，复杂度较高
    // 方法二，一遍遍历，
    // 从左往右，比最大值还小是右边，从右往左，比最小值还大是左边
    // 有空练习：
    // TODO: 
        vector<int> num_tmp(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            num_tmp[i] = nums[i];
        } 
        sort(num_tmp.begin(), num_tmp.end());

        int left, right;
        for (int i = 0; i < num_tmp.size(); i++) {
            if (num_tmp[i] != nums[i]) {
                left = i;
                break;
            }
        }
        for (int i = num_tmp.size() - 1; i >= 0; i--) {
            if (num_tmp[i] != nums[i]) {
                right = i;
                break;
            }
        }
        return right - left + 1 > 0 ? right - left + 1 : 0;
    }
};
// @lc code=end

// [2,6,4,8,10,9,15]
// 5

// [1,2,3,4]
// 0


class Diff_O__N_log_N_Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
    // 不能用单调栈
    // 方法一 排序后看不一样的位置，复杂度较高
        vector<int> num_tmp(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            num_tmp[i] = nums[i];
        } 
        sort(num_tmp.begin(), num_tmp.end());

        int left, right;
        for (int i = 0; i < num_tmp.size(); i++) {
            if (num_tmp[i] != nums[i]) {
                left = i;
                break;
            }
        }
        for (int i = num_tmp.size() - 1; i >= 0; i--) {
            if (num_tmp[i] != nums[i]) {
                right = i;
                break;
            }
        }
        return right - left + 1 > 0 ? right - left + 1 : 0;
    }
};

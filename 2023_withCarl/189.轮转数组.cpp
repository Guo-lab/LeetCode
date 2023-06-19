/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 *
 * https://leetcode.cn/problems/rotate-array/description/
 *
 * algorithms
 * Medium (44.15%)
 * Likes:    1861
 * Dislikes: 0
 * Total Accepted:    660.7K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,2,3,4,5,6,7]\n3'
 *
 * 给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: nums = [1,2,3,4,5,6,7], k = 3
 * 输出: [5,6,7,1,2,3,4]
 * 解释:
 * 向右轮转 1 步: [7,1,2,3,4,5,6]
 * 向右轮转 2 步: [6,7,1,2,3,4,5]
 * 向右轮转 3 步: [5,6,7,1,2,3,4]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入：nums = [-1,-100,3,99], k = 2
 * 输出：[3,99,-1,-100]
 * 解释: 
 * 向右轮转 1 步: [99,-1,-100,3]
 * 向右轮转 2 步: [3,99,-1,-100]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -2^31 <= nums[i] <= 2^31 - 1
 * 0 <= k <= 10^5
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 尽可能想出更多的解决方案，至少有 三种 不同的方法可以解决这个问题。
 * 你可以使用空间复杂度为 O(1) 的 原地 算法解决这个问题吗？
 * 
 * 
 */

// ------------------------ array --------------------------
//
// Related: 541, 151, 剑指Offer58-II
//
// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // <1> vector keeps k nums
        // <2> k layers, move one int each time
        // <3> reverse
        k %= nums.size();

        reverse(nums.begin(), nums.end());
        reverse(nums.begin() + k, nums.end());
        reverse(nums.begin(), nums.begin() + k);
    }
};
// @lc code=end


class AC_Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // <1> vector keeps k nums 
        // 
        while (k > nums.size()) {
            k -= nums.size();
        }
        if (k == nums.size()) 
            return;
            
        vector<int> tmp(k);
        for (int i = 0; i < k; i++) {
            tmp[i] = nums[nums.size() - k + i];
        }
        for (int i = 0; i < nums.size() - k; i++) {
            nums[nums.size() - 1 - i] = nums[nums.size() - 1 - i - k];
        }
        for (int i = 0; i < k; i++) {
            nums[i] = tmp[i];
        }
    }
};


class TLE_Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // <2> k layers, move one int each time
        for (int i = 0; i < k; i++) {
            int tmp = nums[nums.size() - 1];
            for (int j = nums.size() - 2; j >= 0; j--) {
                nums[j + 1] = nums[j];
            }
            nums[0] = tmp;
            // for (int k = 0; k < nums.size() - 1; k++) {
            //     cout << nums[k] << " ";
            // }
            // cout << nums[nums.size() - 1] << endl;
        }
    }
};
/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 *
 * https://leetcode.cn/problems/binary-search/description/
 *
 * algorithms
 * Easy (54.48%)
 * Likes:    1258
 * Dislikes: 0
 * Total Accepted:    946.4K
 * Total Submissions: 1.7M
 * Testcase Example:  '[-1,0,3,5,9,12]\n9'
 *
 * 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的
 * target，如果目标值存在返回下标，否则返回 -1。
 * 
 * 
 * 示例 1:
 * 
 * 输入: nums = [-1,0,3,5,9,12], target = 9
 * 输出: 4
 * 解释: 9 出现在 nums 中并且下标为 4
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums = [-1,0,3,5,9,12], target = 2
 * 输出: -1
 * 解释: 2 不存在 nums 中因此返回 -1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 你可以假设 nums 中的所有元素是不重复的。
 * n 将在 [1, 10000]之间。
 * nums 的每个元素都将在 [-9999, 9999]之间。
 * 
 * 
 */

// ---------------------- array ------------------------

// @lc code=start
class Solution { // left_closed_right_closed
// 其实想明白并不是奇数偶数个影响了mid的移动
// 实际上最关键的时间节点就是说三个节点的时候，也就是考虑往左走往右走都是只有两个相邻的数
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1; // [left, right]
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] < target) {
                // 想明白加一是因为 [1,2,3] 这种情路需要到达 break 条件
                left = mid + 1; // [mid + 1, right]
            }
            else {
                right = mid - 1; // [left, mid - 1]
            }
        } 
        return -1;
    }
};
// @lc code=end

// [-1,0,3,5,9,12]\n2\n
// -1

class left_closed_right_open_Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size(); // [left, right)
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] < target) {
                left = mid + 1; // [mid + 1, right)
            }
            else {
                right = mid; // [left, mid)
            }
        } 
        return -1;
    }
};

class my_Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] < target) {
                // 想明白加一是因为 [1,2,3] 这种情路需要到达 break 条件
                left = mid + 1;
            }
            else {
                right = mid;
            }
        } 
        if (left == right && nums[left] == target)
            return right;
        return -1;
    }
};
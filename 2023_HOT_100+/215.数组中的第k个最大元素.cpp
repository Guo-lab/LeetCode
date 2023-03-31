/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
    int qiuckSort(vector<int>& nums, int l, int r, int idx) {
        int pos = partition(nums, l, r);
        if (pos == idx) {
            return nums[pos];
        }
        // !
        if (pos < idx) {
            return qiuckSort(nums, pos + 1, r, idx);
        }
        return qiuckSort(nums, l, pos - 1, idx);
    }
    int partition(vector<int>& nums, int l, int r) {
        int x = nums[r];
        int smaller = l - 1;
        for (int i = l; i < r; i++) {
            if (nums[i] < x) {
                swap(nums[++smaller], nums[i]);
            }
        }
        // 出循环的时候 smaller 及其左边都是更小的
        swap(nums[smaller + 1], nums[r]);
        return smaller + 1;
    }
    int findKthLargest(vector<int>& nums, int k) {
        return qiuckSort(nums, 0, nums.size() - 1, nums.size() - k);
    }
};
// @lc code=end

class easy_Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        int top = 0;
        for (; k > 1; k--) {
            top++;
        }
        return nums[top];
    }
};
class _第k大元素_Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        int top = 0;
        for (; k > 1; k--) {
            top++;
            while (nums[top] == nums[top - 1])
            {
                top++;
            }
        }
        return nums[top];
    }
};
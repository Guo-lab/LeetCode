/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 *
 * https://leetcode.cn/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (74.25%)
 * Likes:    748
 * Dislikes: 0
 * Total Accepted:    426.9K
 * Total Submissions: 575K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * 给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums1 = [1,2,2,1], nums2 = [2,2]
 * 输出：[2]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * 输出：[9,4]
 * 解释：[4,9] 也是可通过的
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums1.length, nums2.length <= 1000
 * 0 <= nums1[i], nums2[i] <= 1000
 * 
 * 
 */

// ------------------ hash table -----------------

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // array
        unordered_set<int> ans;
        int exist_1[1003] = {0};
        for (auto num : nums1) 
            exist_1[num] = 1;
        for (auto num : nums2)
            if (exist_1[num] == 1) 
                ans.insert(num);
        return vector<int>(ans.begin(), ans.end()); // vector<int> v; v.assign(st.begin(), st.end());
    }
};
// @lc code=end


class set_Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> exist_1;
        unordered_set<int> exist_2;
        for (auto a : nums1) {
            exist_1.insert(a);
        }
        for (auto a : nums2) {
            exist_2.insert(a);
        }
        vector<int> ans;
        for (auto a : exist_1) {
            // set<int>::iterator it;
            if (exist_2.find(a) == exist_2.end())
                continue;
            ans.push_back(a);
        }
        return ans;
    }
};

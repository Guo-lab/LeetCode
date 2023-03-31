/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */

// @lc code=start
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> disappear;
        sort(nums.begin(), nums.end());
        int cur = 1;

        for (int i = 0; i < nums.size(); i++) {
            if (cur == nums[i]) {
                cur++;
                if (i == nums.size() - 1)
                    if (nums.size() != nums[i])
                        disappear.push_back(cur);
                continue;
            }
            if (nums[i] < cur) {
                if (i == nums.size() - 1) {
                    // cout << cur << endl;
                    while (cur <= nums.size()) {
                        disappear.push_back(cur);
                        cur++;
                    }
                }
                continue;
            }
            if (nums[i] > cur) {
                // cout << cur << endl;
                while (nums[i] > cur) {
                    disappear.push_back(cur);
                    cur++;
                }
                cur++;
            }
        }
        return disappear;
    }
};
// @lc code=end

// [4,3,2,7,8,2,3,1]
// [5,6]

// [1,1]
// [2]

//[4,3,2,7,7,2,3,1]
//[5,6,8]

// [27,40,6,21,14,36,10,19,44,10,41,26,39,20,25,19,14,7,29,27,40,38,11,44,4,6,48,39,9,13,7,45,41,23,31,8,24,1,3,5,28,11,49,29,18,4,38,32,24,15]
// [2,12,16,17,22,30,33,34,35,37,42,43,46,47,50]
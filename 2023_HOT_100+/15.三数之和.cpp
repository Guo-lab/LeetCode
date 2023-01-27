/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> tmp;
        vector<vector<int>> res;
        vector<int> each;
        int left = 0, right = nums.size() - 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (left = i + 1, right = nums.size() - 1; left < right;) { 
                //* 除了set去重，还可以在这里对b去重
                each.clear();           
                if (nums[i] + nums[left] + nums[right] < 0) {
                    left++;
                } else if (nums[i] + nums[left] + nums[right] > 0) {
                    right--;
                } else if (nums[i] + nums[left] + nums[right] == 0) {
                    each.push_back(nums[i]);
                    each.push_back(nums[left]);
                    each.push_back(nums[right]); 
                    tmp.insert(each);               
                    left++; right--;
                }
            }
        }
        res.assign(tmp.begin(), tmp.end());
    return res;
    }
};
// @lc code=end

/**
 * @brief Time Limit Exceeded
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int>> result;
    vector<vector<int>> res;
    vector<int> each;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            for (int k = j + 1; k < nums.size(); k++) {
                each.clear();
                if (nums[i] + nums[j] + nums[k] == 0) {
                    each.push_back(nums[i]);
                    each.push_back(nums[j]);
                    each.push_back(nums[k]);
                    sort(each.begin(), each.end());
                    result.insert(each);
                }
            }
        }
    }
    res.assign(result.begin(), result.end());
    return res;
    }
};
 */
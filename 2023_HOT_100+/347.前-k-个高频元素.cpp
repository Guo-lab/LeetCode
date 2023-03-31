/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        vector<pair<int, int>> vec(freq.begin(), freq.end());
        sort(vec.begin(), vec.end(), cmp);

        int i = 0;
        for (auto it = vec.begin(); i < k; i++, it++) {
            ans.push_back(it->first);
        }
        return ans;
    }
};
// @lc code=end


// [1,1,1,2,2,3]\n2\n
// [1,2]

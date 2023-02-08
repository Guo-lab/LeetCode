/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    map<string, vector<string>> mapping;
    vector<vector<string>> result;
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() == 0) 
            return result;
        if (strs.size() == 1) {
            result.push_back(strs);
            return result;
        } else {
            for (int i = 0; i < strs.size(); i++) {
                string map_s = strs[i];
                sort(map_s.begin(), map_s.end());
                mapping[map_s].push_back(strs[i]);
            }
            map<string, vector<string>>::iterator it = mapping.begin();
            while(it != mapping.end()) {
                result.push_back(it->second);
                it++;
            }
            return result;
        }
    }
};
// @lc code=end


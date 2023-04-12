/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 *
 * https://leetcode.cn/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (67.82%)
 * Likes:    1447
 * Dislikes: 0
 * Total Accepted:    446.6K
 * Total Submissions: 658.5K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
 * 
 * 字母异位词 是由重新排列源单词的字母得到的一个新单词，所有源单词中的字母通常恰好只用一次。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
 * 输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
 * 
 * 示例 2:
 * 
 * 
 * 输入: strs = [""]
 * 输出: [[""]]
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: strs = ["a"]
 * 输出: [["a"]]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= strs.length <= 10^4
 * 0 <= strs[i].length <= 100
 * strs[i] 仅包含小写字母
 * 
 * 
 */

// ----------------- hash table ------------------

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // map<vector<int>, int> -> hash table
        map<vector<int>, int> cnt;
        vector<vector<string>> ans;
        vector<int> tmp(26);
        int idx = 1;

        for (int j = 0; j < strs.size(); j++) {
            for (int i = 0; i < 26; i++) tmp[i] = 0;
            for (int i = 0; i < strs[j].size(); i++) {
                tmp[strs[j][i] - 'a']++;
                // cout << strs[j][i] << " " << tmp[strs[j][i] - 'a'] << endl;
            }
            if (cnt[tmp] == 0) { // 遇到没有遇到过的才会赋予其 idx
                cnt[tmp] = idx;
                idx++;
            } // 1,2,3
            cout << cnt[tmp] << endl;
            if (cnt[tmp] > ans.size()) ans.resize(cnt[tmp]); // 因为一开始ans下标是空的
            ans[cnt[tmp] - 1].push_back(strs[j]);
        }
        return ans;
    }
};
// @lc code=end


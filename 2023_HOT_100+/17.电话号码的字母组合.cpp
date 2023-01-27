/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
#include <bits/stdc++.h>
class Solution {
public:
    vector<string> result;
    vector<string> mapping = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" 
    };

    vector<string> letterCombinations(string digits) {
        if (digits == "")
            return result;
        dfs(digits, "", digits.size());
        return result;
    }

    void dfs(string digits, string tmp_string, int lvl) {
        if (lvl == 0) {
            result.push_back(tmp_string);
            return;
        }
        // NOT atoi()
        int key_of_mapping = digits[digits.size() - lvl] - '0';
        string val_mapping = mapping[key_of_mapping];
        for (int i = 0; i < val_mapping.size(); i++) {
            dfs(digits, tmp_string + val_mapping[i], lvl - 1);
        }
    }
};
// @lc code=end


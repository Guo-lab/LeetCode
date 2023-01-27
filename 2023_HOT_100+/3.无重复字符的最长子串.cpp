/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include<iostream>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int length = 0;
        int start, end;
        if (s.length() == 0) return 0;
        map<char, int> next_no_repeat; //! ///////////////////////////////// character
        for (start = 0, end = 0; end < s.length() - 1; end++) {
            int repeat = 0;
            char repeat_char;
            int repeat_index;
            for (int i = start; i <= end; i++) {
                if (s[i] == s[end + 1]) {
                    repeat = 1;
                    repeat_char = s[i];
                    repeat_index = i;
                    break;
                }
            }
            if (repeat == 0) {
                next_no_repeat[s[end]] = end + 1;
                length = end + 1 - start;
                ans = ans >= length ? ans : length;
                continue;
            } else {
                next_no_repeat[s[end]] = end + 1; //! ////////////////////// update
                //cout << repeat_char << " " << next_no_repeat[repeat_char] << endl;
                start = next_no_repeat[repeat_char] > start ? next_no_repeat[repeat_char] : end + 1;
            }
        } 

    ans++;
    return ans;
    }
};
// @lc code=end


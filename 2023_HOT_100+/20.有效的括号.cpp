/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
#include <iostream>
class Solution {
public:
    bool isValid(string s) {
        bool result = true;
        stack<char> pairs;

        for (int i = 0; i < s.length(); i++) {
            if(pairs.empty()) {
                pairs.push(s[i]);
                continue;
            }
            switch (s[i]) {
            case ')':
                result = (pairs.top() == '(');
                pairs.pop();
                break;
            case ']':
                result = (pairs.top() == '[');
                pairs.pop();
                break;
            case '}':
                result = (pairs.top() == '{');
                pairs.pop();
                break;
            default:
                pairs.push(s[i]);
                break;
            } // switch end
        if  (result == false) break;
        } // for end
        if (!pairs.empty()) {
            result = false;
        }

        return result;
    }
};
// @lc code=end


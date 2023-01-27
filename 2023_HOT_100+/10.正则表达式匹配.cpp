/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution { //analysis: https://leetcode.cn/problems/regular-expression-matching/solution/by-flix-musv/
public:
    bool isMatch(string s, string p) {
        vector<vector<bool> > match(s.length() + 1);

        for (int i = 0; i <= s.length(); i++) {
            match[i].resize(p.length() + 1);
            match[i][0] = false;
        }
        // s empty
        match[0][0] = true;
        match[0][1] = false;
        if (p[1] == '*') {
            match[0][2] = true;
        } else {
            match[0][2] = false;
        }
        for (int i = 3; i <= p.length(); i++) { 
            if (p[i - 1] != '*') {
                match[0][i] = false;
            } else {
                match[0][i] = match[0][i - 2];
            }
        }
        // dynamic-programming
        for (int i = 1; i <= s.length(); i++) {
            for (int j = 1; j <= p.length(); j++) {
                if ((s[i - 1] == p[j - 1]) || (p[j - 1] == '.')) {
                    match[i][j] = match[i - 1][j - 1];   
                } else if (p[j - 1] == '*') {
                    if (s[i - 1] != p[j - 2] && p[j - 2] != '.') {
                        match[i][j] = match[i][j - 2];
                    } else {
                        match[i][j] = match[i][j - 2] || match[i - 1][j];
                    }
                } // else if end
            }
        } // for both end

        return match[s.length()][p.length()];
    }
};
// @lc code=end


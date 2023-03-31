/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        // stack<int>  k;
        // stack<char> tmp;

        int idx = 0;
        int rightBracket = 0;

        return dfs(s, idx, rightBracket);
    }
    string dfs(string s, int curIdx, int &rightBracket) {
        if (curIdx >= s.size())
            return "";

        int k = 0;
        string tmp = "";

        for (int i = curIdx; i < s.size(); i++) {
            if (0 <= s[i] - '0' && s[i] - '0' <= 9) { // && 我只想说 python 很干
                // cout << s[i] - '0' << endl;
                k = k * 10 + (s[i] - '0');
                curIdx = i;
                // cout << s[i] << endl;
                // cout << i << endl;
                // cout << k << endl;
            } else {
                if (s[i] == '[') {
                    // cout << i << endl;
                    curIdx = i;
                    string fromDFS = "";
                    
                    // cout << rightBracket << endl;
                    fromDFS = dfs(s, curIdx + 1, rightBracket);
                    // cout << rightBracket << endl << endl;
                    
                    // cout << fromDFS << endl;
                    for (int cnt = 0; cnt < k; cnt++)
                        tmp += fromDFS;
                    k = 0;

                    i = rightBracket;
                    curIdx = i;
                }

                else if (s[i] == ']') {
                    curIdx = i;
                    rightBracket = i;
                    return tmp;
                }

                else {
                    curIdx = i;
                    tmp += s[i];
                }
            }

        }

        return tmp;
    }
};
// @lc code=end

// "3[a]2[bc]"
// aaabcbc

// "100[leetcode]"
// "leetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcode"




class DFS_Solution {
public:
    string decodeString(string s) {
        // stack<int>  k;
        // stack<char> tmp;

        int idx = 0;
        int rightBracket = 0;

        return dfs(s, idx, rightBracket);
    }
    string dfs(string s, int curIdx, int &rightBracket) {
        if (curIdx >= s.size())
            return "";

        int k = 0;
        string tmp = "";

        for (int i = curIdx; i < s.size(); i++) {
            if (0 <= s[i] - '0' && s[i] - '0' <= 9) { // && 我只想说 python 很干
                // cout << s[i] - '0' << endl;
                k = k * 10 + (s[i] - '0');
                curIdx = i;
                // cout << s[i] << endl;
                // cout << i << endl;
                // cout << k << endl;
            } else {
                if (s[i] == '[') {
                    // cout << i << endl;
                    curIdx = i;
                    string fromDFS = "";
                    
                    // cout << rightBracket << endl;
                    fromDFS = dfs(s, curIdx + 1, rightBracket);
                    // cout << rightBracket << endl << endl;
                    
                    // cout << fromDFS << endl;
                    for (int cnt = 0; cnt < k; cnt++)
                        tmp += fromDFS;
                    k = 0;

                    i = rightBracket;
                    curIdx = i;
                }

                else if (s[i] == ']') {
                    curIdx = i;
                    rightBracket = i;
                    return tmp;
                }

                else {
                    curIdx = i;
                    tmp += s[i];
                }
            }

        }

        return tmp;
    }
};
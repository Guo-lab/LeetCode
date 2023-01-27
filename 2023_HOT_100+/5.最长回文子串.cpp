/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include <bits/stdc++.h> // https://alchemist-al.com/algorithms/longest-palindromic-substring
class Solution {
public:
    string longestPalindrome(string s) { //! /////// dp
        if (s == "") 
            return "";
        int biggest = 1;
        vector<vector<bool> > dp(s.length());
        for (int i = 0; i < s.length(); i++) {
            dp[i].resize(s.length());
            dp[i][i] = true;
        }

        int pointer = 0;
        for (int length = 2; length - 1 <= s.length() - 1; length++) {
            for (int row = 0; row < s.length(); row++) {
                int col = row + length - 1;
                if (col >= s.length())
                    break; //! ///////////////////// OTHERWISE ✘ Error: AddressSanitizer: stack-buffer-overflow on address
                if (s[row] != s[col]) {
                    dp[row][col] = false;
                } else {
                    if (col-1 - (row+1) <= 0) {
                        dp[row][col] = true;
                    } else {
                        dp[row][col] = dp[row + 1][col - 1]; // bottom-left
                    }
                    if (dp[row][col] == true) { // ! update condition 
                        biggest = length;
                        pointer = col - length + 1;
                    }
                } // else end
            }
        }
        string result;
        result = s.substr(pointer, biggest);
        return result;
    }
};
// @lc code=end



/**
 * @brief 最长公共子串
#include <bits/stdc++.h>
class Solution {
public:
    string longestPalindrome(string s) {
        string reverse_s;
        reverse_s = s;
        reverse(reverse_s.begin(), reverse_s.end());

        if (s == "") 
            return "";
        vector<vector<int> > both(s.length() + 1);
        for (int i = 0; i <= s.length(); i++) {
            both[i].resize(s.length() + 1, 0);
        }
        for (int j = 0; j <= reverse_s.length(); j++) {
            both[0][j] = 0;
        }

        int biggest = 0;
        int x = 0, y = 0;
        for (int i = 1; i <= s.length(); i++) {
            for (int j = 1; j <= reverse_s.length(); j++) {
                if (s[i - 1] == reverse_s[j - 1]) {
                    both[i][j] = both[i - 1][j - 1] + 1;
                    if (biggest < both[i][j]) {
                        biggest = both[i][j];
                        x = i;
                        y = j;
                    }
                } else {
                    both[i][j] = 0;
                }
            }
        }

        string result;
        while (both[x][y] != 0) {
            result += s[x - 1];
            x--;
            y--; 
        }
        return result;
    }
};
 * 
 */
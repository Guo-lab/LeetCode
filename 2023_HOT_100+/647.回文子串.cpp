/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        // 第二种方法： Manacher 后续有时间到官网看学习此解法  
        if (s.size() == 1) return 1;
        int count = s.size();
        vector<vector<bool>> dp(s.size());
        for (int i = 0; i < s.size(); i++) {
            dp[i].resize(s.size());
            dp[i][i] = true;
        }
        // cout << " OK " << endl;
        for (int i = 1; i < s.size(); i++) {
            dp[i - 1][i] = s[i] == s[i - 1];
            if (dp[i - 1][i] == true)
                count++;
        }
        for (int i = 2; i < s.size(); i++)
            for (int m = 0; m < s.size() - i; m++) {
                int j = m + i;
                dp[m][j] = dp[m + 1][j - 1] && s[m] == s[j];
                if (dp[m][j] == true)
                    count++;
            }
        return count;
    }
};
// @lc code=end

//"abc"
//3
//"aaa"
//6

//"a"
//1

//"aaaaa"\n
//15


class DP_Solution {
public:
    int countSubstrings(string s) {        
        if (s.size() == 1) return 1;
        int count = s.size();
        vector<vector<bool>> dp(s.size());
        for (int i = 0; i < s.size(); i++) {
            dp[i].resize(s.size());
            dp[i][i] = true;
        }
        // cout << " OK " << endl;
        for (int i = 1; i < s.size(); i++) {
            dp[i - 1][i] = s[i] == s[i - 1];
            if (dp[i - 1][i] == true)
                count++;
        }
        // cout << count << endl;
        // for (int i = 0; i < s.size() - 2; i++) {
        //     for (int j = i + 2; j < s.size(); j++) {
        //         dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
        //         cout << i << " " << s[i] << " " << j << " " << s[j] << endl;
        //         if (dp[i][j] == true)
        //             count++;
        //     }
        // }
        // https://blog.csdn.net/miyagiSimple/article/details/110561865
        for (int i = 2; i < s.size(); i++) {
            for (int m = 0; m < s.size() - i; m++) {
                int j = m + i;
                dp[m][j] = dp[m + 1][j - 1] && s[m] == s[j];
                // cout << i << " " << s[i] << " " << j << " " << s[j] << endl;
                if (dp[m][j] == true)
                    count++;
            }
        }
        return count;
    }
};
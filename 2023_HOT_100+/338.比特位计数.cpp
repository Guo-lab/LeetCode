/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        ans[0] = 0;
        if (n == 0) 
            return ans;

        for (int i = 1; i <= n; i++) {
            cout << i << endl;
            int cnt = 0;
            
            // qwq
            int j = i; 
            
            while (j != 1) {
                cnt += (j % 2);
                j *= 0.5;
            }
            if (j == 1) 
                cnt++;

            ans[i] = cnt;
        }
        return ans;
    }
};
// @lc code=end


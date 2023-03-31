/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        int n = 0;
        cin >> n;
        vector<int> l(n);
        vector<int> r(n);
        for (int i = 0; i < n; i++) {
            cin >> l[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> r[i];
        }
        int max_ = 0;
        int num = 0;
        
        vector<int> time(r[max_element(r.begin(), r.end()) - r.begin()]);
        cout << time.size() ;
        
        
        cout << max_ << " " << num << endl;
        return 0;
    }
};
// @lc code=end


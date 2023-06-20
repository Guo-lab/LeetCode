/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 *
 * https://leetcode.cn/problems/backspace-string-compare/description/
 *
 * algorithms
 * Easy (47.93%)
 * Likes:    641
 * Dislikes: 0
 * Total Accepted:    203.4K
 * Total Submissions: 424.5K
 * Testcase Example:  '"ab#c"\n"ad#c"'
 *
 * 给定 s 和 t 两个字符串，当它们分别被输入到空白的文本编辑器后，如果两者相等，返回 true 。# 代表退格字符。
 * 
 * 注意：如果对空文本输入退格字符，文本继续为空。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "ab#c", t = "ad#c"
 * 输出：true
 * 解释：s 和 t 都会变成 "ac"。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "ab##", t = "c#d#"
 * 输出：true
 * 解释：s 和 t 都会变成 ""。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "a#c", t = "b"
 * 输出：false
 * 解释：s 会变成 "c"，但 t 仍然是 "b"。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length, t.length <= 200
 * s 和 t 只含有小写字母以及字符 '#'
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 你可以用 O(n) 的时间复杂度和 O(1) 的空间复杂度解决该问题吗？
 * 
 * 
 */

// -------------------------- string --------------------------

// 空间复杂度可由 O(n + m) 降至 O(1)
// 通过同时消除 # 的操作 => https://programmercarl.com/0844.%E6%AF%94%E8%BE%83%E5%90%AB%E9%80%80%E6%A0%BC%E7%9A%84%E5%AD%97%E7%AC%A6%E4%B8%B2.html#%E4%BC%98%E5%8C%96%E6%96%B9%E6%B3%95-%E4%BB%8E%E5%90%8E%E5%90%91%E5%89%8D%E5%8F%8C%E6%8C%87%E9%92%88

// @lc code=start

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> tmp;
        string s_processed;
        string t_processed;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '#') {
                if (!tmp.empty())
                    tmp.pop();
            }
            else {
                tmp.push(s[i]);
            }
        }
        while (!tmp.empty()) {
            s_processed += tmp.top();
            tmp.pop();
        }
        for (int i = 0; i < t.size(); i++) {
            if (t[i] == '#') {
                if (!tmp.empty())
                    tmp.pop();
            }
            else {
                tmp.push(t[i]);
            }
        }
        while (!tmp.empty()) {
            t_processed += tmp.top();
            tmp.pop();
        }
        // cout << s_processed << " " << t_processed << endl;
        return s_processed == t_processed;
    }
};
// @lc code=end


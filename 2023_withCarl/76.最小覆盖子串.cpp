/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 *
 * https://leetcode.cn/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (45.15%)
 * Likes:    2437
 * Dislikes: 0
 * Total Accepted:    408.5K
 * Total Submissions: 904.8K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 ""
 * 。
 * 
 * 
 * 
 * 注意：
 * 
 * 
 * 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
 * 如果 s 中存在这样的子串，我们保证它是唯一的答案。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "ADOBECODEBANC", t = "ABC"
 * 输出："BANC"
 * 解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "a", t = "a"
 * 输出："a"
 * 解释：整个字符串 s 是最小覆盖子串。
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: s = "a", t = "aa"
 * 输出: ""
 * 解释: t 中两个字符 'a' 均应包含在 s 的子串中，
 * 因此没有符合条件的子字符串，返回空字符串。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * ^m == s.length
 * ^n == t.length
 * 1 <= m, n <= 10^5
 * s 和 t 由英文字母组成
 * 
 * 
 * 
 * 进阶：你能设计一个在 o(m+n) 时间内解决此问题的算法吗？
 */

// ---------------------- array ------------------------

// @lc code=start
class Solution { // 2.2 旧版答案，有所遗忘
public:
    string minWindow(string s, string t) {
    int left, right;
    int isFind = 0;
    vector<int> WindowFreq(128);
    vector<int> t_Freq(128);
    for (int i = 0; i < t.size(); i++) {
        t_Freq[t[i]]++;
    }
    int s_cover_t = 0;
    string result = s;
        
    int end = 0;
    for (left = 0, right = 0; right < s.size() + 1;) {
        if (s_cover_t == t.size()) {
            if (WindowFreq[s[left]] == t_Freq[s[left]]) {
                s_cover_t--;
            }
            WindowFreq[s[left]]--;
            left++;
            if (s_cover_t == t.size() && right-1 - left + 1 < result.size()) { 
                result = s.substr(left, right-1 - left + 1);
            }
            ////cout << s_cover_t << " " << s.substr(left, right-1 - left + 1) << endl;
            continue;
        }
        if (right == s.size()) {
            break;
        }
        if (t_Freq[s[right]] == 0 || WindowFreq[s[right]] >= t_Freq[s[right]]) {
            WindowFreq[s[right]]++;
            right++;
            if (WindowFreq[s[right]] > 32000) {
                left = left + 32000;
                WindowFreq[s[left]] -= 32000;
            }
        } else if (WindowFreq[s[right]] < t_Freq[s[right]]) {
            s_cover_t++;
            if (s_cover_t == t.size()) {
                isFind = 1;
                ////cout << s.substr(left, right - left + 1) << endl;
                if (right - left + 1 < result.size()) {
                    result = s.substr(left, right - left + 1);
                }
            }
            WindowFreq[s[right]]++;
            right++;
        }
        ////cout << s_cover_t << " " << s.substr(left, right-1 - left + 1) << endl;
    }

    if (isFind == 0) return "";
    return result;
    }
};
// @lc code=end

-------------------------------
"ab"\n"a"\n
----
"a"
-------------------------------


-------------------------------
"bba"\n"ab"\n
-------
"ba"
-------------------------------

-------------------------------
"abcabdebac"\n"cda"\n
-----------
"cabd"
-------------------------------


class TLE_windows_Solution { // 266/267 cases passed (N/A)
public:
    string minWindow(string s, string t) {
        string result = "";
        int length = 1000000;
        unordered_map<char, int> t_map; 
        unordered_map<char, int> s_map;
        for (int i = 0; i < t.size(); i++) {
            t_map[t[i]]++;
        }
        for (int i = 0; i < s.size(); i++) {
            s_map[s[i]] = 0;
            // cout << s[i] << " " << s_map[s[i]] << endl;
        }
        int left = 0;
        int inactive = t_map.size();
        if (t.size() > s.size()) return result;
        
        for (int i = 0; i < s.size(); i++) {
            s_map[s[i]]++;
            // cout << s[i] << " " << s_map[s[i]] << endl;

            if (t_map.find(s[i]) != t_map.end()) {
                // cout << "t_map has s[i]" << endl;
                if (s_map[s[i]] == t_map[s[i]]) {
                    inactive--;
                    // cout << inactive << endl;
                    if (inactive == 0) {
                        result = length < i - left + 1 ? result : s.substr(left, i - left + 1);
                        length = result.size();
                    }
                }
            }
            while (inactive == 0 || t_map.find(s[left]) == t_map.end()) {
                if (left > i) {
                    left--;
                    break;
                }
                s_map[s[left]]--;
                // 先判断能不能找到
                if (t_map.find(s[left]) != t_map.end()) {
                    if (s_map[s[left]] < t_map[s[left]]) {
                        inactive++;
                    }
                }
                left++;
                if (inactive == 0) {
                    result = length < i - left + 1 ? result : s.substr(left, i - left + 1);
                    length = result.size();
                }
                if (left == s.size())
                    break;
            }
        }
        return result;
    }
};








---------------------------------------------------------------------------------
class Ref_Solution { // 正确而简洁的滑动窗口
public:
    string minWindow(string s, string t) {
        vector<int> need(128,0);
        int count = 0;  
        for(char c : t)
        {
            need[c]++;
        }
        count = t.length();
        int l=0, r=0, start=0, size = INT_MAX;
        while(r<s.length())
        {
            char c = s[r];
            if(need[c]>0)
                count--;
            need[c]--;  //先把右边的字符加入窗口
            if(count==0)    //窗口中已经包含所需的全部字符
            {
                while(l<r && need[s[l]]<0) //缩减窗口
                {
                    need[s[l++]]++;
                }   //此时窗口符合要求
                if(r-l+1 < size)    //更新答案
                {
                    size = r-l+1;
                    start = l;
                }
                // 现在正好覆盖
                // ------------
                need[s[l]]++;   //左边界右移之前需要释放need[s[l]]
                l++;
                count++;
            }

            r++;
        }
        return size==INT_MAX ? "" : s.substr(start, size);
    }
};
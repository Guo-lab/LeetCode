/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 *
 * https://leetcode.cn/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (65.83%)
 * Likes:    759
 * Dislikes: 0
 * Total Accepted:    587.3K
 * Total Submissions: 892.2K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
 * 
 * 注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: s = "anagram", t = "nagaram"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s = "rat", t = "car"
 * 输出: false
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 
 * s 和 t 仅包含小写字母
 * 
 * 
 * 
 * 
 * 进阶: 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
 * 
 */

// ---------------------- hash table ----------------------

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        // hash table
        int record[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            record[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            record[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (record[i] != 0)
                return false;
        }
        return true;
    }
};
// @lc code=end

------------ "a"\n"ab"\n
"a"
"ab"
----
false
-------------


class map_Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> s_;
        unordered_map<char, int> t_;
        if (s.size() != t.size()) return false;
        for (int i = 0; i < s.size(); i++) {
            s_[s[i]]++;
        }
        for (int i = 0; i < s.size(); i++) {
            t_[t[i]]++;
        }
        for (auto c: s_) {
            // cout << c.first << c.second << endl;
            if (t_[c.first] != c.second)
                return false;
        }
        for (auto c: t_) {
            if (s_[c.first] != c.second)
                return false;
        }
        return true;
    }
};
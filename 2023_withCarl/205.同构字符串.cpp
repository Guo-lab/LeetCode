/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 *
 * https://leetcode.cn/problems/isomorphic-strings/description/
 *
 * algorithms
 * Easy (49.60%)
 * Likes:    610
 * Dislikes: 0
 * Total Accepted:    205K
 * Total Submissions: 413.3K
 * Testcase Example:  '"egg"\n"add"'
 *
 * 给定两个字符串 s 和 t ，判断它们是否是同构的。
 * 
 * 如果 s 中的字符可以按某种映射关系替换得到 t ，那么这两个字符串是同构的。
 * 
 * 
 * 每个出现的字符都应当映射到另一个字符，同时不改变字符的顺序。不同字符不能映射到同一个字符上，相同字符只能映射到同一个字符上，字符可以映射到自己本身。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入：s = "egg", t = "add"
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "foo", t = "bar"
 * 输出：false
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "paper", t = "title"
 * 输出：true
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 
 * 
 * 1 <= s.length <= 5 * 10^4
 * t.length == s.length
 * s 和 t 由任意有效的 ASCII 字符组成
 * 
 * 
 */

// ------------------------ hash table ---------------------------

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) 
            return false;

        unordered_map<char, char> map_1;
        unordered_map<char, char> map_2;

        for (int i = 0; i < s.size(); i++) {
            if (map_1.find(s[i]) == map_1.end())
                map_1[s[i]] = t[i];
            if (map_2.find(t[i]) == map_2.end())
                map_2[t[i]] = s[i];
            
            // mapping from s to t and mapping from t to s both exist
            if (map_1[s[i]] != t[i] || map_2[t[i]] != s[i])
                return false;
        }
        return true;
    }
};
// @lc code=end


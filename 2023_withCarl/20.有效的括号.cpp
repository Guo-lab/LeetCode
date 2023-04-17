/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode.cn/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (44.16%)
 * Likes:    3872
 * Dislikes: 0
 * Total Accepted:    1.5M
 * Total Submissions: 3.3M
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 每个右括号都有一个对应的相同类型的左括号。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "()"
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "()[]{}"
 * 输出：true
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "(]"
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^4
 * s 仅由括号 '()[]{}' 组成
 * 
 * 
 */

// -------------------- S & Q -------------------

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        // 竟是把它相对的另一半压入栈就可以
        stack<char> theOther;
        while (theOther.size() != 0) theOther.pop();
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                theOther.push(')');
            else if (s[i] == '[')
                theOther.push(']');
            else if (s[i] == '{')
                theOther.push('}');
            else if (s[i] == ')') {
                if (theOther.size() == 0) return false;
                if (theOther.top() != ')') return false;
                theOther.pop();
            }
            else if (s[i] == ']') {
                if (theOther.size() == 0) return false;
                if (theOther.top() != ']') return false;
                theOther.pop();
            }
            else if (s[i] == '}') {
                if (theOther.size() == 0) return false;
                if (theOther.top() != '}') return false;
                theOther.pop();
            }
        }
        if (!theOther.empty()) return false;
        return true;
    }
};
// @lc code=end


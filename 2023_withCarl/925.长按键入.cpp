/*
 * @lc app=leetcode.cn id=925 lang=cpp
 *
 * [925] 长按键入
 *
 * https://leetcode.cn/problems/long-pressed-name/description/
 *
 * algorithms
 * Easy (37.49%)
 * Likes:    276
 * Dislikes: 0
 * Total Accepted:    66.5K
 * Total Submissions: 177.3K
 * Testcase Example:  '"alex"\n"aaleex"'
 *
 * 你的朋友正在使用键盘输入他的名字 name。偶尔，在键入字符 c 时，按键可能会被长按，而字符可能被输入 1 次或多次。
 * 
 * 你将会检查键盘输入的字符 typed。如果它对应的可能是你的朋友的名字（其中一些字符可能被长按），那么就返回 True。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：name = "alex", typed = "aaleex"
 * 输出：true
 * 解释：'alex' 中的 'a' 和 'e' 被长按。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：name = "saeed", typed = "ssaaedd"
 * 输出：false
 * 解释：'e' 一定需要被键入两次，但在 typed 的输出中不是这样。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= name.length, typed.length <= 1000
 * name 和 typed 的字符都是小写字母
 * 
 * 
 */

// ------------------------ string -------------------------

// @lc code=start
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if (name[0] != typed[0])
            return false;
        int name_cur = 0; 
        int type_cur = 0;
        for (; name_cur < name.size(); name_cur++) {
            if (name[name_cur] == typed[type_cur]) {
                type_cur++;
            } else {
                if (typed[type_cur] != name[name_cur - 1])
                    return false;
                    
                while (typed[type_cur] == name[name_cur - 1]) // typed[j] == typed[j - 1]
                    type_cur++;
                name_cur--;
            }
        }
        if (type_cur != typed.size()) { 
            if (typed[type_cur] != name[name.size() - 1])
                return false;
            while (typed[type_cur] == name[name.size() - 1] && type_cur < typed.size())
                type_cur++;
            if (type_cur != typed.size())
                return false;            
        }
        return true;
    }
};
// @lc code=end

=======================
"alex"
"aaleexa"
-------------
false
=======================
"alex"\n"aaleexa"\n
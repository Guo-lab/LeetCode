/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (58.05%)
 * Likes:    2442
 * Dislikes: 0
 * Total Accepted:    684.3K
 * Total Submissions: 1.2M
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：digits = "23"
 * 输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：digits = ""
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：digits = "2"
 * 输出：["a","b","c"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= digits.length <= 4
 * digits[i] 是范围 ['2', '9'] 的一个数字。
 * 
 * 
 */


// -------------------------- backtracking ----------------------

// @lc code=start
class Solution {
public:
    vector<string> ans;
    string each = "";
    // vector<int> mapping(10); // Line 5: Char 25: error: expected parameter declarator
    vector<vector<char>> mapping = vector<vector<char>>(10);

    vector<string> letterCombinations(string digits) {
        mapping[2] = {'a', 'b', 'c'};
        mapping[3] = {'d', 'e', 'f'};
        mapping[4] = {'g', 'h', 'i'};
        mapping[5] = {'j', 'k', 'l'};
        mapping[6] = {'m', 'n', 'o'};
        mapping[7] = {'p', 'q', 'r', 's'};
        mapping[8] = {'t', 'u', 'v'};
        mapping[9] = {'w', 'x', 'y', 'z'};
        if (digits == "") return {};
        bt(digits, 1);
        return ans;
    }
    void bt(string digits, int x) {
        if (x > digits.size()) {
            ans.push_back(each);
            return;
        }
        for (int i = 0; i < mapping[digits[x - 1] - '0'].size(); i++) {
            each += mapping[digits[x - 1] - '0'][i];
            bt(digits, x + 1);
            each = each.substr(0, each.size() - 1);
        }
    }
};
// @lc code=end


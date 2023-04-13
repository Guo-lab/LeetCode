/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 *
 * https://leetcode.cn/problems/reverse-string-ii/description/
 *
 * algorithms
 * Easy (58.34%)
 * Likes:    453
 * Dislikes: 0
 * Total Accepted:    191.5K
 * Total Submissions: 328.2K
 * Testcase Example:  '"abcdefg"\n2'
 *
 * 给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。
 * 
 * 
 * 如果剩余字符少于 k 个，则将剩余字符全部反转。
 * 如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "abcdefg", k = 2
 * 输出："bacdfeg"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "abcd", k = 2
 * 输出："bacd"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^4
 * s 仅由小写英文组成
 * 1 <= k <= 10^4
 * 
 * 
 */

// ----------------- String --------------------

// @lc code=start
class Solution {
public:
    string reverseStr(string s, int k) {
        // no need to count 2 * k
        int left = 0, right = s.size() - 1;
        for (int i = 2 * k; i < s.size(); i += 2 * k) {
            right = i - k - 1;
            while (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
            left = i;
        }
        if (left + k <= s.size()) {
            right = left + k - 1;
            while (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        else {
            right = s.size() - 1;
            while (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            } 
        }
        return s;
    }
};
// @lc code=end


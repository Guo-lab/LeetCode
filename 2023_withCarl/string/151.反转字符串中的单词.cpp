/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 *
 * https://leetcode.cn/problems/reverse-words-in-a-string/description/
 *
 * algorithms
 * Medium (51.56%)
 * Likes:    830
 * Dislikes: 0
 * Total Accepted:    371.8K
 * Total Submissions: 720.9K
 * Testcase Example:  '"the sky is blue"'
 *
 * 给你一个字符串 s ，请你反转字符串中 单词 的顺序。
 * 
 * 单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。
 * 
 * 返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。
 * 
 * 注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "the sky is blue"
 * 输出："blue is sky the"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "  hello world  "
 * 输出："world hello"
 * 解释：反转后的字符串中不能存在前导空格和尾随空格。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "a good   example"
 * 输出："example good a"
 * 解释：如果两个单词间有多余的空格，反转后的字符串需要将单词间的空格减少到仅有一个。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^4
 * s 包含英文大小写字母、数字和空格 ' '
 * s 中 至少存在一个 单词
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 进阶：如果字符串在你使用的编程语言中是一种可变数据类型，请尝试使用 O(1) 额外空间复杂度的 原地 解法。
 * 
 */

// ---------------------------------- String --------------------------------

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        // s = "the  sky  is  blue";
        // 反转的思路是，先去空格，全部颠倒，再逐个单词翻就能满足，把单词整体顺序倒置的目的
        // s = "  hello world  ";

        // slow - fast // 去空格写的有点绕，可以slow单独加空格，然后fast找到非空格再处理
        int left, right;
        int slow = 0, fast = 0;
        while (fast <= s.size() - 1) {
            if (s[fast] == ' ' && fast == 0) fast++;
            if (s[fast] != ' ' || (s[fast] == ' ' && fast > 0 && s[fast - 1] != ' '))
                s[slow++] = s[fast++];
            else fast++;
        }
        s.resize(slow);
        if (s[s.size() - 1] == ' ') s.resize(slow - 1);


        // left - right
        left = 0, right = s.size() - 1;
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }

        left = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') continue;
            right = i - 1;
            while (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
            left = i + 1;
        }
        right = s.size() - 1;
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
        return s;
    }
};
// @lc code=end

--------------------------
"  hello world  "
-----------------
"world hello"
--------------------------
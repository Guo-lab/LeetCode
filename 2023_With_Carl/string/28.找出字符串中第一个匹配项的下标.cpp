/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 *
 * https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
 *
 * algorithms
 * Medium (42.23%)
 * Likes:    1833
 * Dislikes: 0
 * Total Accepted:    829.7K
 * Total Submissions: 2M
 * Testcase Example:  '"sadbutsad"\n"sad"'
 *
 * 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0
 * 开始）。如果 needle 不是 haystack 的一部分，则返回  -1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：haystack = "sadbutsad", needle = "sad"
 * 输出：0
 * 解释："sad" 在下标 0 和 6 处匹配。
 * 第一个匹配项的下标是 0 ，所以返回 0 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：haystack = "leetcode", needle = "leeto"
 * 输出：-1
 * 解释："leeto" 没有在 "leetcode" 中出现，所以返回 -1 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= haystack.length, needle.length <= 10^4
 * haystack 和 needle 仅由小写英文字符组成
 * 
 * 
 */

// ------------------ String  ------------------

// KMP
//  https://programmercarl.com/0028.%E5%AE%9E%E7%8E%B0strStr.html

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        // KMP 
        vector<int> next(needle.size());
        // 前缀表初始化
        next[0] = 0;
        int j = 0;
        // i 后缀末尾
        for (int i = 1; i < needle.size(); i++) { // aabaaf
            // 前后缀不相等的时候 回退
            while (needle[i] != needle[j] && j > 0)
                j = next[j - 1]; // aa -> af if match
            // 前后缀相等的时候
            if (needle[i] == needle[j])
                j++;
            next[i] = j;
        }
        // for (int i = 0; i < next.size(); i++)
        //     cout << next[i] << endl;
        // ------------------------------
        // a a b a a b a a f
        // a a b a a f
        // 0 1 0 1 2 0
        // ------------------------------
        j = 0;
        for (int i = 0; i < haystack.size(); i++) {
            while (j > 0 && haystack[i] != needle[j])
                j = next[j - 1];
            if (haystack[i] == needle[j])
                j++;
            // 结束搜索的条件
            if (j == needle.size()) // j 已经加到长度了
                return i - j + 1;
        }
        // Fail
        return -1;
    }
};
// @lc code=end


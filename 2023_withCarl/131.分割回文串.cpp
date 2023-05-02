/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 *
 * https://leetcode.cn/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (73.38%)
 * Likes:    1483
 * Dislikes: 0
 * Total Accepted:    286.4K
 * Total Submissions: 390.2K
 * Testcase Example:  '"aab"'
 *
 * 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
 * 
 * 回文串 是正着读和反着读都一样的字符串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "aab"
 * 输出：[["a","a","b"],["aa","b"]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "a"
 * 输出：[["a"]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 仅由小写英文字母组成
 * 
 * 
 */


// -------------------------- backtracking ----------------------
// 待重做
//

// @lc code=start
class Solution {
public:
    vector<vector<string>> ans;
    vector<string> path;

    vector<vector<string>> partition(string s) {
        bt(s, 0); 
        return ans;
    }
    void bt(string s, int cutIdx) {
        // 终止条件
        if (cutIdx == s.size()) {
            ans.push_back(path);
            return;
        }
        // * 切割位置传入参数是起始位置，循环便利每一次切割的长度，如果克切，就接着切
        for (int i = cutIdx; i < s.size(); i++) { // 切割边界有点乱
            string tmp = s.substr(cutIdx, i - cutIdx + 1); // [cutIdx, i]
            cout << tmp << endl;
            if (isP(tmp)) {
                path.push_back(tmp); // 先压入其中         
            }
            else {
                continue;
            }
            bt(s, i + 1); // 在进入bt之前符合回文。并且在这个循环里也是回文，可以接着往后看
            path.pop_back();
        }
    }
    bool isP(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
// @lc code=end


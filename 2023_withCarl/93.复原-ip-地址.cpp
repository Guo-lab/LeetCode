/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 *
 * https://leetcode.cn/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (57.96%)
 * Likes:    1223
 * Dislikes: 0
 * Total Accepted:    330K
 * Total Submissions: 568.9K
 * Testcase Example:  '"25525511135"'
 *
 * 有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。
 * 
 * 
 * 例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312"
 * 和 "192.168@1.1" 是 无效 IP 地址。
 * 
 * 
 * 给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。你 不能
 * 重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "25525511135"
 * 输出：["255.255.11.135","255.255.111.35"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "0000"
 * 输出：["0.0.0.0"]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "101023"
 * 输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 20
 * s 仅由数字组成
 * 
 * 
 */

// -------------------------- backtracking ----------------------
// 131 advanced

// @lc code=start
class Solution {
public:
    vector<string> ans;
    string path = "";
    vector<string> restoreIpAddresses(string s) {
        bt(s, 0, 0);
        return ans;
    } 
    void bt (string s, int cutIdx, int x) {
        if (x == 4 && cutIdx == s.size()) {
            path = path.substr(0, path.size() - 1);
            ans.push_back(path);
            path += '.';
            return;
        }
        if (x == 4 && cutIdx != s.size()) 
            return;
        if (cutIdx == s.size() && x < 4) 
            return;
        for (int i = cutIdx; i < s.size(); i++) {
            string tmp = s.substr(cutIdx, i - cutIdx + 1);
            int curSize = tmp.size();
            if (isValid(tmp)) {
                // cout << tmp << " " << x << endl;
                path += tmp;
                path += '.';
            } 
            else 
                continue;
            bt(s, i + 1, x + 1);
            // cout << path.size( ) <<" " << tmp.size() << endl;
            path = path.substr(0, path.size() - tmp.size() - 1);
        }
    }
    bool isValid(string s) {
        if (s.size() == 0 || s.size() > 3) return false;
        if (s[0] - '0' == 0 && s.size() > 1) return false; 
        int ip = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] - '0' < 0 || s[i] - '0' > 9) return false;
            ip = ip * 10 + (s[i] - '0');
        }
        return ip <= 255;
    }
};
// @lc code=end


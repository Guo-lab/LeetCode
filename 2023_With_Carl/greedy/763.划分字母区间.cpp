/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 *
 * https://leetcode.cn/problems/partition-labels/description/
 *
 * algorithms
 * Medium (76.74%)
 * Likes:    943
 * Dislikes: 0
 * Total Accepted:    162.3K
 * Total Submissions: 211.5K
 * Testcase Example:  '"ababcbacadefegdehijhklij"'
 *
 * 给你一个字符串 s 。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。
 * 
 * 注意，划分结果需要满足：将所有划分结果按顺序连接，得到的字符串仍然是 s 。
 * 
 * 返回一个表示每个字符串片段的长度的列表。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "ababcbacadefegdehijhklij"
 * 输出：[9,7,8]
 * 解释：
 * 划分结果为 "ababcbaca"、"defegde"、"hijhklij" 。
 * 每个字母最多出现在一个片段中。
 * 像 "ababcbacadefegde", "hijhklij" 这样的划分是错误的，因为划分的片段数较少。 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "eccbbbbdec"
 * 输出：[10]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 500
 * s 仅由小写英文字母组成
 * 
 * 
 */

// ------------------------------ Greedy --------------------------------
找到边界，截止最远边界与当前下标相等的位置并且之前的元素都已经找到这样的位置

之前的所有元素都找到“这样的”位置通过每次刷新的最大值来判断

// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> far(s.size());
        unordered_map<char, int> idx;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (idx[s[i]] == 0)
                idx[s[i]] = i + 1;
            far[i] = idx[s[i]];
        }
        // cout << far[0] << far[1] << far[2] << far[3] << endl;

        vector<int> length;
        int scanIdx = 0;
        int pre = 1;
        for (int i = 0; i < s.size(); i++) {
            scanIdx = max(scanIdx, far[i]); // 这样保证了之前的都满足了条件 // * key step
            if (scanIdx == i + 1) {
                length.push_back(i + 1 - pre + 1);
                pre = scanIdx + 1;
            }
        }
        return length;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=1002 lang=cpp
 *
 * [1002] 查找共用字符
 *
 * https://leetcode.cn/problems/find-common-characters/description/
 *
 * algorithms
 * Easy (70.69%)
 * Likes:    337
 * Dislikes: 0
 * Total Accepted:    85.5K
 * Total Submissions: 120.9K
 * Testcase Example:  '["bella","label","roller"]'
 *
 * 给你一个字符串数组 words ，请你找出所有在 words 的每个字符串中都出现的共用字符（ 包括重复字符），并以数组形式返回。你可以按 任意顺序
 * 返回答案。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：words = ["bella","label","roller"]
 * 输出：["e","l","l"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：words = ["cool","lock","cook"]
 * 输出：["c","o"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= words.length <= 100
 * 1 <= words[i].length <= 100
 * words[i] 由小写英文字母组成
 * 
 * 
 */

// --------------------- hash table --------------------------

// @lc code=start
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> result;
        unordered_map<char, int> countChar;
        for (int i = 0; i < words[0].size(); i++) {
            countChar[words[0][i]]++;
        }
        for (int i = 1; i < words.size(); i++) {
            for (auto x : countChar)
                if (count(words[i].begin(), words[i].end(), x.first) < x.second)
                {
                    countChar[x.first] = count(words[i].begin(), words[i].end(), x.first);
                    // cout << x.first << " " << x.second << endl;
                }
        }
        for (auto x : countChar) {
            while (x.second > 0) {
                // ----------------
                char tmp[1];
                tmp[0] = x.first;
                string str(tmp, 1);
                // ----------------
                result.push_back(str);

                x.second--;
            }
        }
        return result;
    }
};
// @lc code=end


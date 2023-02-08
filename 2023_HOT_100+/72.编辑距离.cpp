/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> modify;
    int minDistance(string word1, string word2) {
        modify.resize(word1.size() + 1);
        for (int i = 0; i < word1.size() + 1; i++) {
            modify[i].resize(word2.size() + 1);
            modify[i][0] = i;
        }
        for (int i = 0; i < word2.size() + 1; i++) {
            modify[0][i] = i;
        }
        for (int i = 1; i < word1.size() + 1; i++) {
            for (int j = 1; j < word2.size() + 1; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    modify[i][j] = modify[i - 1][j - 1];                        
                } else {
                    modify[i][j] = 1 + min(min(modify[i - 1][j], modify[i][j - 1]), modify[i - 1][j - 1]);
                }
            }
        }
        return modify[word1.size()][word2.size()];
    }
};
// @lc code=end


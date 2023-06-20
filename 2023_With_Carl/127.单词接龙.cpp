/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 *
 * https://leetcode.cn/problems/word-ladder/description/
 *
 * algorithms
 * Hard (48.24%)
 * Likes:    1252
 * Dislikes: 0
 * Total Accepted:    186.1K
 * Total Submissions: 385.8K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * 字典 wordList 中从单词 beginWord 和 endWord 的 转换序列 是一个按下述规格形成的序列 beginWord -> s1 ->
 * s2 -> ... -> sk：
 * 
 * 
 * 每一对相邻的单词只差一个字母。
 * 对于 1 <= i <= k 时，每个 si 都在 wordList 中。注意， beginWord 不需要在 wordList 中。
 * sk == endWord
 * 
 * 
 * 给你两个单词 beginWord 和 endWord 和一个字典 wordList ，返回 从 beginWord 到 endWord 的 最短转换序列
 * 中的 单词数目 。如果不存在这样的转换序列，返回 0 。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：beginWord = "hit", endWord = "cog", wordList =
 * ["hot","dot","dog","lot","log","cog"]
 * 输出：5
 * 解释：一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog", 返回它的长度 5。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：beginWord = "hit", endWord = "cog", wordList =
 * ["hot","dot","dog","lot","log"]
 * 输出：0
 * 解释：endWord "cog" 不在字典中，所以无法进行转换。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= beginWord.length <= 10
 * endWord.length == beginWord.length
 * 1 <= wordList.length <= 5000
 * wordList[i].length == beginWord.length
 * beginWord、endWord 和 wordList[i] 由小写英文字母组成
 * beginWord != endWord
 * wordList 中的所有字符串 互不相同
 * 
 * 
 */

// ------------------------------ Graph BFS ----------------------------------
// @lc code=start
class Solution { // Bi_BFS
public:
    // 只能说，我的脑子不行了，理解了背吧
    // ============================= 双向 BFS 优化 ==========================
// Accepted
// 50/50 cases passed (88 ms)
// Your runtime beats 79.99 % of cpp submissions
// Your memory usage beats 54.89 % of cpp submissions (15.3 MB)

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) 
            return 0;

        queue<string> positivePathQueue;
        queue<string> negativePathQueue;
        positivePathQueue.push(beginWord);
        negativePathQueue.push(endWord);

        unordered_map<string, int> posPathDistance;
        unordered_map<string, int> negPathDistance;
        posPathDistance[beginWord] = 1;
        negPathDistance[endWord] = 1;

        int small = INT_MAX;
        while (!positivePathQueue.empty() && !negativePathQueue.empty()) {
            int reach = -1;
            // cout << positivePathQueue.size() << " " << negativePathQueue.size() << endl;
            if (positivePathQueue.size() <= negativePathQueue.size()) {
                reach = update(positivePathQueue, posPathDistance, negPathDistance, wordSet);
            } else {
                reach = update(negativePathQueue, negPathDistance, posPathDistance, wordSet);
            }
            if (reach != -1) {
                // for (auto it : posPathDistance) cout << it.first << " " << it.second << endl;
                // cout << endl;
                // for (auto it : negPathDistance) cout << it.first << " " << it.second << endl;
                // return reach;
                small = small < reach ? small : reach;
            }
        }
        
        // https://leetcode.cn/problems/word-ladder/solution/gong-shui-san-xie-ru-he-shi-yong-shuang-magjd/
        // 为什么这样写 BFS 不能一开始就找到最小值
        if (small > 0 && small < INT_MAX)
            return small;
        else
            return 0;
    }
    int update(queue<string>& q, unordered_map<string, int>& self, unordered_map<string, int>& theOther, unordered_set<string>& set) {
        string current = q.front();
        q.pop();
        for (int i = 0; i < current.size(); i++) {
            string newWord = current;
            for (int j = 0; j < 26; j++) {
                newWord[i] = 'a' + j;
                if (set.find(newWord) != set.end()) {
                    // cout << newWord << endl;
                    if (self.find(newWord) != self.end()) {
                        continue;
                    }
                    // cout << newWord << " " << self[newWord] << endl;
                    if (theOther.find(newWord) != theOther.end()) {
                        // cout << newWord << " " << self[current] << " " << theOther[newWord] << endl;
                        return self[current] + theOther[newWord];
                    }
                    if (self.find(newWord) == self.end()) { // 既不在记录过的队列拓展的路径中，也不在对面的路径中
                        self[newWord] = self[current] + 1;
                        q.push(newWord);
                    }
                    // cout << newWord << " " << self[newWord] << endl;
                }
            }
        }
        return -1;
    }
};
// @lc code=end


=======================================================================================
"hbo"\n"qbx"\n["abo","hco","hbw","ado","abq","hcd","hcj","hww","qbq","qby","qbz","qbx","qbw"]
---------------------------------------------------------------------------------------
hbo -> abo -> abq <- qbq <- qbx
hbo -> hbw -> qbw -> qbx
4
=======================================================================================
qbq 4
hww 3
hcj 3
qbx 4
qbw 3
hcd 3
ado 3
hbw 2
abq 3
hco 2
abo 2
hbo 1

==============================
"hog"\n"cog"\n["cog"]
------------------------------
2
==============================





---------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------
Accepted
50/50 cases passed (132 ms)
Your runtime beats 44.59 % of cpp submissions
Your memory usage beats 40.53 % of cpp submissions (15.5 MB)

class Solution {
public:
    // 只能说，我的脑子不行了，理解了背吧
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // ---- Accelerate with unordered set
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        //
        queue<string> pathCurrentWord;
        pathCurrentWord.push(beginWord);

        unordered_map<string, int> pathDistance; // Record both path and visited word
        pathDistance[beginWord] = 1;

        if (wordSet.find(endWord) == wordSet.end())
            return 0;
        
        while (!pathCurrentWord.empty()) {
            string current = pathCurrentWord.front();

            pathCurrentWord.pop();
            for (int i = 0; i < current.size(); i++) {
                // ------- <!> CANNOT CHANGE THE CURRENT WORD -------- 
                string newWord = current;

                for (int j = 0; j < 26; j++) {
                    newWord[i] = 'a' + j;

                    if (wordSet.find(newWord) != wordSet.end() && pathDistance.find(newWord) == pathDistance.end()) {
                        pathCurrentWord.push(newWord);
                        pathDistance[newWord] = pathDistance[current] + 1;
                    }

                    if (endWord == newWord) {
                        for (auto it : pathDistance) cout << it.first << " " << it.second << endl;
                        return pathDistance[newWord];
                    }
                }
            }
        }
        return 0;
    }
};


// 还有 A star 的做法

// https://leetcode.cn/problems/word-ladder/solution/gong-shui-san-xie-ru-he-shi-yong-shuang-magjd/

// https://www.redblobgames.com/pathfinding/a-star/introduction.html
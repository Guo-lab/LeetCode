/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int len = p.size();
        vector<int> ansIdx;

        unordered_map<char, int> need, window;
        unordered_set<char> tmp;
        for (char c : p) {
            need[c]++;
            tmp.insert(c);
        }

        int left = 0, right = 0, valid = 0;
        while (right < s.size()) {
            char c = s[right];
            right++;
            window[c]++;
            if (window[c] == need[c])
                valid++;

            ////printf("window: [%d, %d)\n", left, right);

            while (right - left >= len) {
                if (valid == tmp.size()) { // ----> need.size()
                    ansIdx.push_back(left);
                }
                // cba
                // abc
                char d = s[left];
                left++;
                if (window[d] == need[d]) {
                    if (need[d] != 0)
                        valid--;
                }
                window[d]--;
            }
        }
        return ansIdx;
    }
};
// @lc code=end


/* 滑动窗口算法框架 */
void slidingWindow(string s, string t) {
    unordered_map<char, int> need, window;
    for (char c : t) need[c]++;
    
    int left = 0, right = 0;
    int valid = 0; 
    while (right < s.size()) {
        // c 是将移入窗口的字符
        char c = s[right];
        // 右移窗口
        right++;
        // 进行窗口内数据的一系列更新
        // ...

        /*** debug 输出的位置 ***/
        printf("window: [%d, %d)\n", left, right);
        /********************/
        
        // 判断左侧窗口是否要收缩
        while (window needs shrink) {
            // d 是将移出窗口的字符
            char d = s[left];
            // 左移窗口
            left++;
            // 进行窗口内数据的一系列更新
            // ...
        }
    }
}
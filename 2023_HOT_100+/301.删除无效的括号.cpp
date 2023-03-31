/*
 * @lc app=leetcode.cn id=301 lang=cpp
 *
 * [301] 删除无效的括号
 */

// @lc code=start
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        unordered_set<string> string_to_verify;
        string_to_verify.insert(s);
        
        while (!string_to_verify.empty()) {
            // 一直在循环，直到找到删减的最少括号
            for (auto & str: string_to_verify) {
                if (isValid(str)) {
                    ans.emplace_back(str); // push_back -> 
                }
            }
            if (ans.size() != 0) 
                return ans;
            
            unordered_set<string> string_to_verify_tmp;
            // 判断暂时还没有找到合适的解的情况下
            for (auto & tmp: string_to_verify) {
                for (int j = 0; j < tmp.size(); j++) {
                    // 如果括号两个连着一样，删除没有意义，只去考虑 )(
                    if (j > 0 && tmp[j] == tmp[j - 1])
                        continue;
                    if (tmp[j] == ')' || tmp[j] == '(') {
                        if (j + 1 < tmp.size()) {
                            string_to_verify_tmp.insert(tmp.substr(0, j) + tmp.substr(j + 1, tmp.size() - j - 1));
                            ////cout << tmp.substr(0, j) + tmp.substr(j + 1, tmp.size() - j - 1) << endl;
                        }
                        else {
                            string_to_verify_tmp.insert(tmp.substr(0, j));
                            ////cout << tmp.substr(0, j) << endl;
                        }
                    }
                }
            }  
            // queue tmp 已经更新
            string_to_verify = string_to_verify_tmp;
        }
        return ans;
    }
    bool isValid(string s) {
        //Xif (s == "") return false;
        //Xif (s.find('(') == string::npos && s.find(')') == string::npos) return false;
        int cntLeft = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                cntLeft++;
            else if (s[i] == ')') { // 这个逻辑开始的时候 if else if else 写错了...
                cntLeft--;
                if (cntLeft < 0)
                    return false;
            }
        }
        if (cntLeft == 0)
            return true;
        return false; 
    }
};
// @lc code=end

//"(a)())()"\n
//["(a())()","(a)()()"]

//")("\n
//[""]

//")(f"\n
//["f"]


class TLE_Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        queue<string> string_to_verify;
        // 必须去重 
        //unordered_set<string> string_to_verify;
        string_to_verify.push(s);
        
        while (!string_to_verify.empty()) {
            // 一直在循环，直到找到删减的最少括号
            int string_size = string_to_verify.size();
            ////cout << string_size << endl;
            for (int i = 0; i < string_size; i++) {
                if (isValid(string_to_verify.front())) {
                    ans.push_back(string_to_verify.front());
                    set<string> s(ans.begin(), ans.end());
                    ans.assign(s.begin(), s.end());
                }
                string_to_verify.push(string_to_verify.front());
                string_to_verify.pop();
            }
            if (ans.size() != 0) 
                return ans;
            
            // 判断暂时还没有找到合适的解的情况下
            for (int i = 0; i < string_size; i++) {
                string tmp = string_to_verify.front();

                for (int j = 0; j < tmp.size(); j++) {
                    // 如果括号两个连着一样，删除没有意义，只去考虑 )(
                    if (j > 0 && tmp[j] == tmp[j - 1])
                        continue;
                    if (tmp[j] == ')' || tmp[j] == '(') {
                        if (j + 1 < tmp.size()) {
                            string_to_verify.push(tmp.substr(0, j) + tmp.substr(j + 1, tmp.size() - j - 1));
                            ////cout << tmp.substr(0, j) + tmp.substr(j + 1, tmp.size() - j - 1) << endl;
                        }
                        else {
                            string_to_verify.push(tmp.substr(0, j));
                            ////cout << tmp.substr(0, j) << endl;
                        }
                    }
                }
                // queue tmp 已经更新
                string_to_verify.pop();
            }  
        }
        return ans;
    }
    bool isValid(string s) {
        //Xif (s == "") return false;
        //Xif (s.find('(') == string::npos && s.find(')') == string::npos) return false;
        int cntLeft = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                cntLeft++;
            else if (s[i] == ')') { // 这个逻辑开始的时候 if else if else 写错了...
                cntLeft--;
                if (cntLeft < 0)
                    return false;
            }
        }
        if (cntLeft == 0)
            return true;
        return false; 
    }
};
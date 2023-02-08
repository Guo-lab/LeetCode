/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> result;
    vector<vector<string>> all_group;
    vector<string> group;

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() == 0) return result;
        else if (strs.size() == 1) {
            result.push_back(strs);
            return result;
        } else {
            int isFind = 0;
            for (int i = 0; i < strs.size(); i++) {
                isFind = 0;
                ////cout << "####### 1 #######" << endl;
                if (all_group.size()) {
                    ////cout << all_group.size() << endl;
                    for (int j = 0; j < all_group.size(); j++) {
                        if (count(all_group[j].begin(), all_group[j].end(), strs[i])) {
                            isFind = 1;
                            break;
                        }
                    }
                    if (isFind == 1) continue;
                }
                ////cout << "###### 2 ########" << endl;
                ////cout << strs[i] << endl;
                findGroup(strs[i]);
            }

            ////cout << "Bug: null?" << endl;
            // put item into result
            for (int i = 0; i < strs.size(); i++) {
                int pos = 0;
                if (all_group.size() == 0) return result;
                ////cout << all_group.size() << endl;
                for (int j = 0; j < all_group.size(); j++) {
                    if (count(all_group[j].begin(), all_group[j].end(), strs[i])) {
                        pos = j;
                        ////cout << "pos is " << pos << endl;
                        break;
                    }
                }
                result.resize(all_group.size());
                result[pos].push_back(strs[i]);
            }
            return result;
        }
    }

    void findGroup(string str) {
        if (str.size() == 1) {
            group.push_back(str);
            all_group.push_back(group);
            group.clear();
        } else {
            ////cout << "#### 3 ######" <<endl;
            dfs(str, "", group, 0);
            all_group.push_back(group);
            /* for (int num = 0; num < all_group[all_group.size() - 1].size(); num++)
                cout << all_group[all_group.size() - 1][num] << endl; */
            group.clear();
        }
    }

    void dfs(string str, string tmp, vector<string>& group, int depth) {
        if (depth == str.size()) {
            group.push_back(tmp);
            ////cout << group[group.size() - 1] << endl;
            return;
        } else {
            for (int i = 0; i < str.size(); i++) {
                ////cout << "######## 4 #######" << endl;
                ////cout << str[i] << endl;
                if (tmp.size()) {
                    if (count(tmp.begin(), tmp.end(), str[i]) == count(str.begin(), str.end(), str[i])) {
                        continue;
                    }
                }
                dfs(str, tmp + str[i], group, depth + 1);
            }
        }
    }

};
// @lc code=end

/**
 * @brief 
 * ["hhhhu","tttti","tttit","hhhuh","hhuhh","tittt"]
 */
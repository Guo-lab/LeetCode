/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool isFind = false;
        if (board.size() == 1 && board[0].size() == 1) {
            if (word.size() > 1) return false;
            if (word[0] == board[0][0]) return true;
            return false;
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    ////cout << "pos: " << i << " " << j << endl;
                    isFind = dfs(board, word, i, j, 0);
                    if (isFind) return isFind;
                    ////cout << endl;
                }
            }
        }
        return isFind;
    }

    bool dfs(vector<vector<char>>& board, string word, int row, int col, int depth) {
        if (board[row][col] != word[depth]) { 
            ////cout << depth + 1 << " " << board[row][col] << endl;
            return false;
        } else if (depth == word.size() - 1)  {
            return true;
        } else {
            char tmp = board[row][col];
            board[row][col] = '#';
            bool tmpIsFind;
            if (board[0].size() == 1) {
                if (row == 0) {
                    tmpIsFind = dfs(board, word, row + 1, col, depth + 1); 
                } else if (row == board.size() - 1) {
                    tmpIsFind = dfs(board, word, row - 1, col, depth + 1);
                } else {
                    tmpIsFind = dfs(board, word, row + 1, col, depth + 1) | dfs(board, word, row - 1, col, depth + 1);
                }
                board[row][col] = tmp;
                return tmpIsFind;
            }
            if (board.size() == 1) {
                if (col == 0) {
                    tmpIsFind = dfs(board, word, row, col + 1, depth + 1);
                } else if (col == board[0].size() - 1) {
                    tmpIsFind = dfs(board, word, row, col - 1, depth + 1);
                } else {
                    tmpIsFind = dfs(board, word, row, col + 1, depth + 1) | dfs(board, word, row, col - 1, depth + 1); 
                } 
                board[row][col] = tmp;
                return tmpIsFind;          
            } 
            if (row == 0 && col == 0) {
                tmpIsFind = dfs(board, word, row + 1, col, depth + 1) | dfs(board, word, row, col + 1, depth + 1);
            } else if (row == board.size() - 1 && col == 0) {
                tmpIsFind = dfs(board, word, row - 1, col, depth + 1) | dfs(board, word, row, col + 1, depth + 1);
            } else if (col == board[0].size() - 1 && row == 0) {
                tmpIsFind = dfs(board, word, row, col - 1, depth + 1) | dfs(board, word, row + 1, col, depth + 1);
            } else if (col == board[0].size() - 1 && row == board.size() - 1) {
                tmpIsFind = dfs(board, word, row, col - 1, depth + 1) | dfs(board, word, row - 1, col, depth + 1);
            } else if (col == board[0].size() - 1) {
                tmpIsFind = dfs(board, word, row, col - 1, depth + 1) | (dfs(board, word, row - 1, col, depth + 1) | dfs(board, word, row + 1, col, depth + 1));
            } else if (col == 0) {
                tmpIsFind = dfs(board, word, row, col + 1, depth + 1) | (dfs(board, word, row - 1, col, depth + 1) | dfs(board, word, row + 1, col, depth + 1));
            } else if (row == board.size() - 1) {
                tmpIsFind = dfs(board, word, row, col - 1, depth + 1) | (dfs(board, word, row - 1, col, depth + 1) | dfs(board, word, row, col + 1, depth + 1));
            } else if (row == 0) {
                tmpIsFind = dfs(board, word, row, col - 1, depth + 1) | (dfs(board, word, row, col + 1, depth + 1) | dfs(board, word, row + 1, col, depth + 1));
            } else {
                tmpIsFind = dfs(board, word, row, col - 1, depth + 1) | (dfs(board, word, row, col + 1, depth + 1) | (dfs(board, word, row - 1, col, depth + 1) | dfs(board, word, row + 1, col, depth + 1)));
            }
            board[row][col] = tmp;
            return tmpIsFind;
        }
    }
};
// @lc code=end

/**
 * @brief case
[["C","A","A"],["A","A","A"],["B","C","D"]]\n"AAB"\n
 *
true
 * 
 *
Answer
 *
class Solution {
public:
    bool check(vector<vector<char>>& board, vector<vector<int>>& visited, int i, int j, string& s, int k) {
        if (board[i][j] != s[k]) {
            return false;
        } else if (k == s.length() - 1) {
            return true;
        }
        visited[i][j] = true;
        vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        bool result = false;
        for (const auto& dir: directions) {
            int newi = i + dir.first, newj = j + dir.second;
            if (newi >= 0 && newi < board.size() && newj >= 0 && newj < board[0].size()) {
                if (!visited[newi][newj]) {
                    bool flag = check(board, visited, newi, newj, s, k + 1);
                    if (flag) {
                        result = true;
                        break;
                    }
                }
            }
        }
        visited[i][j] = false;
        return result;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int h = board.size(), w = board[0].size();
        vector<vector<int>> visited(h, vector<int>(w));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                bool flag = check(board, visited, i, j, word, 0);
                if (flag) {
                    return true;
                }
            }
        }
        return false;
    }
};
 */
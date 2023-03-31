/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
    int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    dfs(i, j, grid);
                    ans++;
                }
            }
        }
        return ans;
    }
    void dfs(int m, int n, vector<vector<char>>& grid) {
        if (m < 0 || m >  grid.size() - 1 || n < 0 || n > grid[0].size() - 1) { return; }
        else if (grid[m][n] == '0') {
            return;
        }
        else {
            grid[m][n] = '0';
            dfs(m + 1, n, grid);
            dfs(m - 1, n, grid);
            dfs(m, n + 1, grid);
            dfs(m, n - 1, grid);
        }
    }
};
// @lc code=end


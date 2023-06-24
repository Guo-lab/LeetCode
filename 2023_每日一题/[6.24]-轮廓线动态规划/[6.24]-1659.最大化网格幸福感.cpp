// You are given four integers, m, n, introvertsCount, and extrovertsCount. 
// You have an m x n grid, and there are two types of people: introverts and extroverts. 
// There are introvertsCount introverts and extrovertsCount extroverts.

// You should decide how many people you want to live in the grid and assign each of them one grid cell. 
// Note that you do not have to have all the people living in the grid.

// The happiness of each person is calculated as follows:

// Introverts start with 120 happiness and lose 30 happiness for each neighbor (introvert or extrovert).
// Extroverts start with 40 happiness and gain 20 happiness for each neighbor (introvert or extrovert).
// Neighbors live in the directly adjacent cells north, east, south, and west of a person's cell.

// The grid happiness is the sum of each person's happiness. Return the maximum possible grid happiness.


// 

// Input: m = 2, n = 3, introvertsCount = 1, extrovertsCount = 2
// Output: 240

// Explanation: Assume the grid is 1-indexed with coordinates (row, column).

// We can put the introvert in cell (1,1) and put the extroverts in cells (1,3) and (2,3).

// - Introvert at (1,1) happiness: 120 (starting happiness) - (0 * 30) (0 neighbors) = 120
// - Extrovert at (1,3) happiness: 40 (starting happiness) + (1 * 20) (1 neighbor) = 60
// - Extrovert at (2,3) happiness: 40 (starting happiness) + (1 * 20) (1 neighbor) = 60

// The grid happiness is 120 + 60 + 60 = 240.








// Reference:  https://leetcode.cn/problems/maximize-grid-happiness/solution/you-yi-chong-zhuang-ya-jiao-zuo-hua-dong-chuang-ko/
//
//
//
//
// ----------------------- Dynamic Programming -------------------------------
// 
//
// 轮廓线动态规划
//
//
//
class Solution {
public:
    int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) { // m -> row; n -> col;
        if (m < n) swap(m, n);

        int triCompressed     = pow(3, n); // [3^n], [3^(n-1)], ..., [3^0]
        int power_3_n_minus_1 = triCompressed / 3;

        int dp[m * n + 1][introvertsCount + 1][extrovertsCount + 1][triCompressed];
        memset(dp, 0x80, sizeof(dp));
        dp[0][0][0][0] = 0;

        int cross[3][3] = {{0,0,0}, {0,-60,-10}, {0,-10,40}};
        // none int ext
        // 0.   0.   0
        // 0. -60. -10
        // 0. -10.  40

        for (int position = 0; position < m * n; position++) {
            for (int mask = 0; mask < triCompressed; mask++) {
                int left = mask % 3;                 // status % 3
                int up   = mask / power_3_n_minus_1; // status / pow(3, n - 1) 
                if (position % n == 0) left = 0;

                for (int i = 0; i <= introvertsCount; i++) {
                    for (int j = 0; j <= extrovertsCount; j++) {
                        if (i < introvertsCount) // put an intro
                            dp[position + 1][i + 1][j][(mask * 3 + 1) % triCompressed] = max(
                                dp[position + 1][i + 1][j][(mask * 3 + 1) % triCompressed],
                                dp[position][i][j][mask] + 120 + cross[left][1] + cross[up][1]
                            );
                        if (j < extrovertsCount) // put an extro
                            dp[position + 1][i][j + 1][(mask * 3 + 2) % triCompressed] = max(
                                dp[position + 1][i][j + 1][(mask * 3 + 2) % triCompressed],
                                dp[position][i][j][mask] + 40 + cross[left][2] + cross[up][2]
                            );
                        // put none
                        dp[position + 1][i][j][(mask * 3) % triCompressed] = max(
                            dp[position + 1][i][j][(mask * 3) % triCompressed],
                            dp[position][i][j][mask]
                        );
                    }
                }

            }
        }
        // 在遍历过 m * n 所有网格的情况下，选取放入特定数量 intro 和 extro 之后的最大值
        int res = 0;
        for(int i = 0; i <= introvertsCount; i++) {
            for(int j = 0; j <= extrovertsCount; j++) {
                for(int mask = 0; mask < triCompressed; mask++) {
                    res = max(res, dp[m * n][i][j][mask]);
                }
            }
        }
        return res;
    }
};
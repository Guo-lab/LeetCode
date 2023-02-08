/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
    /**
     * @brief https://leetcode.cn/problems/unique-binary-search-trees/solution/bu-tong-de-er-cha-sou-suo-shu-by-leetcode-solution/
     * F(i, n) = G(i - 1) * G(n - i)
     * G(n)    = sum_i->n_ (F(i, n)) 
     */
public:
    int numTrees(int n) {
        if (n == 1) return 1;
        else if (n == 2) return 2;
        else {
            int G[n + 1];
            G[0] = 1;
            G[1] = 1;
            G[2] = 2;
            int sum;
            for (int i = 3; i <= n; i++) {
                sum = 0;
                for (int j = 1; j <= i; j++) {
                    int tmp = G[j - 1] * G[i - j];
                    sum += tmp;
                }
                G[i] = sum;
            }
            return G[n];
        }
    }
};
// @lc code=end


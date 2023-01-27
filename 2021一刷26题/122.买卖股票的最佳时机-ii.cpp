/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start

// 贪心
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> profits;
        int sum = 0;
        if(prices.size()==1) return 0;
        for(int i=1; i<prices.size(); i++) {
            // profits.push_back(prices[i] - prices[i-1]);
            sum += (prices[i] - prices[i-1]>0) ? prices[i] - prices[i-1] : 0;
        }
        return sum;
    }
};
// @lc code=end


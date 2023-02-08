/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro = 0;
        stack<int> trade;
        trade.push(0);
        trade.push(prices[0]);
        prices.push_back(0);
        int minPrice = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            while (prices[i] < trade.top()) {
                maxPro = maxPro > trade.top() - minPrice ? maxPro : trade.top() - minPrice;
                trade.pop();
            }
            minPrice = minPrice < prices[i] ? minPrice : prices[i];
            trade.push(prices[i]);
        }
        return maxPro;
    }
};
// @lc code=end


/**
 * @brief 超时
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro = 0;
        vector<vector<int>> trade(prices.size(), vector<int>(prices.size()));
        for (int i = 0; i < prices.size() - 1; i++) {
            for (int j = i + 1; j < prices.size(); j++) {
                trade[i][j] = prices[j] - prices[i];
                maxPro = maxPro > trade[i][j] ? maxPro : trade[i][j]; 
            }
        }
        return maxPro;
    }
};
 */
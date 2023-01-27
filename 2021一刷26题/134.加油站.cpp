/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> rest(gas.size());
        int sum = 0;
        for(int i=0; i<gas.size(); i++) {
            rest[i] = gas[i] - cost[i];   
            sum += rest[i];         
        }
        if(sum < 0) return -1;
        int curSum = 0;
        int result = 0;
        for(int i=0; i<rest.size(); i++) {
            curSum += rest[i];
            if(curSum<0) {
                result = i+1;
                curSum = 0;
                continue;
            }
        }
        return result;
    }
};
// @lc code=end


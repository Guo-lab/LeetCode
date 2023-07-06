给你一个整数 finalSum 。请你将它拆分成若干个 互不相同 的正偶数之和，且拆分出来的正偶数数目 最多 。

比方说，给你 finalSum = 12 ，那么这些拆分是 符合要求 的（互不相同的正偶数且和为 finalSum）：(2 + 10) ，(2 + 4 + 6) 和 (4 + 8) 。
它们中，(2 + 4 + 6) 包含最多数目的整数。注意 finalSum 不能拆分成 (2 + 2 + 4 + 4) ，因为拆分出来的整数必须互不相同。
请你返回一个整数数组，表示将整数拆分成 最多 数目的正偶数数组。如果没有办法将 finalSum 进行拆分，请你返回一个 空 数组。
你可以按 任意 顺序返回这些整数。


You are given an integer finalSum. Split it into a sum of a maximum number of unique positive even integers.

For example, given finalSum = 12, the following splits are valid (unique positive even integers summing up to finalSum): (12),
(2 + 10), (2 + 4 + 6), and (4 + 8). Among them, (2 + 4 + 6) contains the maximum number of integers.
Note that finalSum cannot be split into (2 + 2 + 4 + 4) as all the numbers should be unique.
Return a list of integers that represent a valid split containing a maximum number of integers. 
If no valid split exists for finalSum, return an empty list. You may return the integers in any order.




class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if ((finalSum & 1) == 1) 
            return {};
        vector<long long> result;
        // 看能不能够再次拆分出
        long long peel = 2;
        while (finalSum) {
            if (peel * 2 + 2 <= finalSum) {
                result.push_back(peel);
                finalSum -= peel;
                peel += 2;
            } else {
                result.push_back(finalSum);
                break;
            }
        }
        return result;
    }
};


class another_short_Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if ((finalSum & 1) == 1) 
            return {};
        // vector<long long> dp;
        // 原来只是贪心
        vector<long long> result;
        for (int i = 2; i <= finalSum; i += 2) {
            result.push_back(i);
            finalSum -= i;
        }
        // 加不动了，收个尾
        result.back() += finalSum;
        return result;
    }
};
// 给你一个正整数 n ，找出满足下述条件的 中枢整数 x ：

// 1 和 x 之间的所有元素之和等于 x 和 n 之间所有元素之和。
// 返回中枢整数 x 。如果不存在中枢整数，则返回 -1 。题目保证对于给定的输入，至多存在一个中枢整数。


// Given a positive integer n, find the pivot integer x such that:

// The sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively.
// Return the pivot integer x. If no such integer exists, return -1. 
// It is guaranteed that there will be at most one pivot index for the given input.


class Solution {
public:
    int pivotInteger(int n) {
        if (n == 1) return 1;
        vector<int> prefix(n + 1);
        vector<int> suffix(n + 1);
        prefix[0] = 0;
        suffix[n] = n;
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + i; 
            suffix[n - i] = suffix[n - i + 1] + n - i; 
        }
        for (int i = 0; i <= n; i++)
            if (prefix[i] == suffix[i])
                return i;
        
        // for (int i = 0; i <= n; i++)
        //     cout << prefix[i] << " ";
        // cout << endl;
        // for (int i = 0; i <= n; i++)
        //     cout << suffix[i] << " ";
        return -1;
    }
};
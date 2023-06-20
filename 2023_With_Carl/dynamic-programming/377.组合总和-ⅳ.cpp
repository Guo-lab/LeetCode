/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 *
 * https://leetcode.cn/problems/combination-sum-iv/description/
 *
 * algorithms
 * Medium (52.91%)
 * Likes:    800
 * Dislikes: 0
 * Total Accepted:    141.1K
 * Total Submissions: 266.7K
 * Testcase Example:  '[1,2,3]\n4'
 *
 * 给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。请你从 nums 中找出并返回总和为 target 的元素组合的个数。
 * 
 * 题目数据保证答案符合 32 位整数范围。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3], target = 4
 * 输出：7
 * 解释：
 * 所有可能的组合为：
 * (1, 1, 1, 1)
 * (1, 1, 2)
 * (1, 2, 1)
 * (1, 3)
 * (2, 1, 1)
 * (2, 2)
 * (3, 1)
 * 请注意，顺序不同的序列被视作不同的组合。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [9], target = 3
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * nums 中的所有元素 互不相同
 * 1 
 * 
 * 
 * 
 * 
 * 进阶：如果给定的数组中含有负数会发生什么？问题会产生何种变化？如果允许负数出现，需要向题目中添加哪些限制条件？
 * 
 */

// ------------------- Dynamic programming ---------------------- 本题与 70 advanced 任意阶楼梯相同
// --------------------- Knapsack Problem -----------------------

求组合数 外层for循环遍历物品，内层for遍历背包。 // 因为没有同一元素不同次序的重复放入
求排列数 外层for遍历背包，内层for循环遍历物品

// @lc code=start
class Solution { // 实际上求排列

//! 求排列数还是 1 维数组好理解

// 排列数组合数的区别对于1维dp在于 https://programmercarl.com/0518.%E9%9B%B6%E9%92%B1%E5%85%91%E6%8D%A2II.html#%E6%80%9D%E8%B7%AF

public:
    int combinationSum4(vector<int>& nums, int target) {
        // =============== size_t >> long long ===============
        vector<size_t> dp(target + 1);

        // 求排列背包放在外层，就一层了
        // 想了半天，dp[0] = 1确实没有意义，但是他填充了(1, target - 1), (target - 1, 1)
        dp[0] = 1;
        for (int j = 1; j <= target; j++) {
            for (int i = 1; i <= nums.size(); i++) {
                if (j >= nums[i - 1])
                    dp[j] += dp[j - nums[i - 1]]; 
                cout << dp[j] << " ";
            }
            cout << endl;
        }
        // for (int j = 0; j <= target; j++) {
        //         cout << dp[j] << " ";
        // }
        int ans = dp[target];
        return ans;
    }

    int _combinationSum4(vector<int>& nums, int target) {
        // =============== size_t >> long long ===============
        vector<vector<size_t>> dp(nums.size() + 1, vector<size_t>(target + 1));
        for (int i = 0; i <= nums.size(); i++)
            dp[i][0] = 1;
        // for (int j = 0; j <= target; j++)
        //     dp[0][j] = 1;
        

        for (int j = 1; j <= target; j++) {
            for (int i = 1; i <= nums.size(); i++) {
                if (j >= nums[i - 1]) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - nums[i - 1]]; 
                } else
                    dp[i][j] = dp[i - 1][j];
                
                // 这样像下面写相当于还是得更新前面的每一个位置，因此更需要外层来循环背包了
                int tmp = i;
                while (tmp >= 2) {
                    dp[tmp - 1][j] = dp[tmp][j];
                    tmp--;
                }
            }
        }
        
        for (int j = 0; j <= nums.size(); j++) {
            for (int i = 0; i <= target; i++)
                cout << dp[j][i] << " ";
            cout << endl;
        }
        int ans = dp[nums.size()][target];
        return ans;
    }
};
// @lc code=end








===================
[10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300,310,320,330,340,350,360,370,380,390,400,410,420,430,440,450,460,470,480,490,500,510,520,530,540,550,560,570,580,590,600,610,620,630,640,650,660,670,680,690,700,710,720,730,740,750,760,770,780,790,800,810,820,830,840,850,860,870,880,890,900,910,920,930,940,950,960,970,980,990,111]
999
------
1
===================







=============================
[1,2,3]
4
-------------------
    1   2   3   4                排列
1   0   0   0   0                1  0  0  0  0  
1   1   1   1   1                1  1  1  2  4(0 加上第三列上一状态的nums[i - 1])
1   1   2   2   3                1  1  2  3  6(4 加上第三列上一状态的NUMS[2])
1   1   2   3   4 (4种组合)是吧   1  1  2  4  7(6 加上第三列上衣状态的nums[1])
-------------------
7
=============================

class Solution { // 这样求的真的是纯纯的组合数量
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1));
        for (int i = 0; i <= target; i++)
            dp[0][i] = 0;
        for (int i = 0; i <= nums.size(); i++) 
            dp[i][0] = 1;

        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 1; j <= target; j++) {
                if (j >= nums[i - 1])
                    dp[i][j] = dp[i - 1][j] + dp[i][j - nums[i - 1]];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        for (int i = 0; i < nums.size() + 1; i++) {
            for (int j = 0; j < target + 1; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        int ans = 0;
        return ans;
    }
};
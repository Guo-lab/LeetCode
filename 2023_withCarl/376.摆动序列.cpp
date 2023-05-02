/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 *
 * https://leetcode.cn/problems/wiggle-subsequence/description/
 *
 * algorithms
 * Medium (46.98%)
 * Likes:    932
 * Dislikes: 0
 * Total Accepted:    177.7K
 * Total Submissions: 378.5K
 * Testcase Example:  '[1,7,4,9,2,5]'
 *
 * 如果连续数字之间的差严格地在正数和负数之间交替，则数字序列称为 摆动序列
 * 。第一个差（如果存在的话）可能是正数或负数。仅有一个元素或者含两个不等元素的序列也视作摆动序列。
 * 
 * 
 * 
 * 例如， [1, 7, 4, 9, 2, 5] 是一个 摆动序列 ，因为差值 (6, -3, 5, -7, 3) 是正负交替出现的。
 * 
 * 相反，[1, 4, 7, 2, 5] 和 [1, 7, 4, 5, 5]
 * 不是摆动序列，第一个序列是因为它的前两个差值都是正数，第二个序列是因为它的最后一个差值为零。
 * 
 * 
 * 子序列 可以通过从原始序列中删除一些（也可以不删除）元素来获得，剩下的元素保持其原始顺序。
 * 
 * 给你一个整数数组 nums ，返回 nums 中作为 摆动序列 的 最长子序列的长度 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,7,4,9,2,5]
 * 输出：6
 * 解释：整个序列均为摆动序列，各元素之间的差值为 (6, -3, 5, -7, 3) 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,17,5,10,13,15,10,5,16,8]
 * 输出：7
 * 解释：这个序列包含几个长度为 7 摆动序列。
 * 其中一个是 [1, 17, 10, 13, 10, 16, 8] ，各元素之间的差值为 (16, -7, 3, -3, 6, -8) 。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1,2,3,4,5,6,7,8,9]
 * 输出：2
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 0 
 * 
 * 
 * 
 * 
 * 进阶：你能否用 O(n) 时间复杂度完成此题?
 * 
 */


// ------------------------------ Greedy --------------------------------

// @lc code=start
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
// 这么写也可以处理 0 2 2 2 2 2 0 的情况

        if (nums.size() == 1) return 1;
        if (nums.size() == 2 && nums[0] != nums[1]) return 2;
        if (nums.size() == 2 && nums[0] == nums[1]) return 1;

        vector<int> diff(nums.size());
        int leng = 2;
        for (int i = 1; i < nums.size(); i++) {
            diff[i - 1] = nums[i] - nums[i - 1]; 
        }
        // b - a, c - b, d - c
        if (diff[0] == 0) leng = 1;
        for (int i = 1; i < nums.size() - 1; i++) {
            if (diff[i] == 0) {
                continue;
            }            
            if (i > 1 && diff[i] * diff[i - 1] == 0 && diff[i - 1] * diff[i - 2] == 0)
                if (diff[i] * diff[i - 2] > 0) 
                    continue;
            if (diff[i] * diff[i - 1] > 0)
                continue;
            else
                leng++;
        }
        return leng;
    }
};
// @lc code=end

===========
[0,0]
------
1
===========


=============
[0,0,0]
---------
1
=============


=============
[3,3,3,2,5]
-----------
3
=============

===============
[0,2,2,2,2,2,2,2,0]
2,0,0,0,0,0,0,-2
--------------------
3
===============

==================================
[372,492,288,399,81,2,320,94,416,469,427,117,265,357,399,456,496,337,355,219,475,295,457,350,490,470,281,127,131,36,430,412,442,174,128,253,1,56,306,295,340,73,253,130,259,223,14,79,409,384,209,151,317,441,156,275,140,224,128,250,290,191,161,472,477,125,470,230,321,5,311,23,27,248,138,284,215,356,320,194,434,136,221,273,450,440,28,179,36,386,482,203,24,8,391,21,500,484,135,348,292,396,145,443,406,61,212,480,455,78,309,318,84,474,209,225,177,356,227,263,181,476,478,151,494,395,23,114,395,429,450,247,245,150,354,230,100,172,454,155,189,33,290,187,443,123,59,358,241,141,39,196,491,381,157,157,134,431,295,20,123,118,207,199,317,188,267,335,315,308,115,321,56,52,253,492,97,374,398,272,74,206,109,172,471,55,452,452,329,367,372,252,99,62,122,287,320,325,307,481,316,378,87,97,457,21,312,249,354,286,196,43,170,500,265,253,19,480,438,113,473,247,257,33,395,456,246,310,469,408,112,385,53,449,117,122,210,286,149,20,364,372,71,26,155,292,16,72,384,160,79,241,346,230,15,427,96,95,59,151,325,490,223,131,81,294,18,70,171,339,14,40,463,421,355,123,408,357,202,235,390,344,198,98,361,434,174,216,197,274,231,85,494,57,136,258,134,441,477,456,318,155,138,461,65,426,162,90,342,284,374,204,464,9,280,391,491,231,298,284,82,417,355,356,207,367,262,244,283,489,477,143,495,472,372,447,322,399,239,450,168,202,89,333,276,199,416,490,494,488,137,327,113,189,430,320,197,120,71,262,31,295,218,74,238,169,489,308,300,260,397,308,328,267,419,84,357,486,289,312,230,64,468,227,268,28,243,267,254,153,407,399,346,385,77,297,273,484,366,482,491,368,221,423,107,272,98,309,426,181,320,77,185,382,478,398,476,22,328,450,299,211,285,62,344,484,395,466,291,487,301,407,28,295,36,429,99,462,240,124,261,387,30,362,161,156,184,188,99,377,392,442,300,98,285,312,312,365,415,367,105,81,378,413,43,326,490,320,266,390,53,327,75,332,454,29,370,392,360,1,335,355,344,120,417,455,93,60,256,451,188,161,388,338,238,26,275,340,109,185]
----------------------------------
334
==================================



[372,492,288,399,81,2,320,94,416,469,427,117,265,357,399,456,496,337,355,219,475,295,457,350,490,470,281,127,131,36,430,412,442,174,128,253,1,56,306,295,340,73,253,130,259,223,14,79,409,384,209,151,317,441,156,275,140,224,128,250,290,191,161,472,477,125,470,230,321,5,311,23,27,248,138,284,215,356,320,194,434,136,221,273,450,440,28,179,36,386,482,203,24,8,391,21,500,484,135,348,292,396,145,443,406,61,212,480,455,                          
  78,309,318,84,474,209,225,177,356,227,263,181,476,478,151,494,395,23,114,395,429,450,247,245,150,354,230,100,172,454,155,189,33,290,187,443,123,59,358,241,141,39,196,
  
  491,381,157,157,134,431,295,20,123,118,207,199,317,188,267,
  335,315,308,115,321,56,52,253,492,97,374,
  
  398,272,74,206,109,172,471,55,452,452,329,367,372,252,99,62,122,287,320,325,307,481,316,378,87,97,457,21,312,249,354,286,196,43,170,500,265,253,19,480,438,113,473,247,257,33,395,
  456,246,310,469,408,112,385,53,449,117,122,210,286,149,20,364,372,71,26,155,292,16,72,384,160,79,241,346,230,15,427,96,95,59,151,325,490,223,131,81,294,18,70,171,339,14,40,463,421,355,123,408,357,202,235,390,344,198,98,361,434,174,216,197,274,231,85,494,57,136,258,134,441,477,456,318,155,            
        138,461,65,426,162,90,342,284,374,204,464,9,280,391,491,231,298,284,82,417,355,356,207,367,262,244,283,489,477,143,495,472,372,447,322,399,239,450,168,202,89,333,276,199,416,490,494,488,137,327,113,189,430,320,197,120,71,262,31,295,218,74,238,169,489,308,300,260,397,308,328,267,419,84,357,486,289,312,230,64,468,227,268,28,243,267,254,153,407,399,346,385,77,297,273,484,366,482,491,368,221,423,107,272,98,309,426,181,320,77,185,382,478,398,476,22,328,450,299,211,285,62,344,484,395,466,291,487,301,407,28,295,36,429,99,462,240,124,261,387,30,362,161,156,184,188,99,377,392,442,300,98,285,312,312,365,415,367,105,81,378,413,43,326,490,320,266,390,53,327,75,332,454,29,370,392,360,1,335,355,344,120,417,455,93,60,256,451,188,161,388,338,238,26,275,340,109,185]
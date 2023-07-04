//给你一个下标从 0 开始的二维整数数组 nums 。一开始你的分数为 0 。

//你需要执行以下操作直到矩阵变为空：

//矩阵中每一行选取最大的一个数，并删除它。如果一行中有多个最大的数，选择任意一个并删除。
//在步骤 1 删除的所有数字中找到最大的一个数字，将它添加到你的 分数 中。
//请你返回最后的 分数 。




//You are given a 0-indexed 2D integer array nums. Initially, your score is 0. 

//Perform the following operations until the matrix becomes empty:

//From each row in the matrix, select the largest number and remove it. In the case of a tie, it does not matter which number is chosen.
//Identify the highest number amongst all those removed in step 1. Add that number to your score.
//Return the final score.



//Input: nums = [[7,2,1],[6,4,2],[6,5,3],[3,2,1]]
//Output: 15
//Explanation: In the first operation, we remove 7, 6, 6, and 3. 
//We then add 7 to our score. Next, we remove 2, 4, 5, and 2. 
//We add 5 to our score. Lastly, we remove 1, 2, 3, and 1. We add 3 to our score. 
//Thus, our final score is 7 + 5 + 3 = 15.




class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int row = nums.size();
        int col = nums[0].size();
        int score = 0;
        for (int i = 0; i < row; i++) {
            sort(nums[i].begin(), nums[i].end());
        }
        int maxInCol = 0;
        for (int j = 0; j < col; j++) {
            for (int i = 0; i < row; i++) {
                maxInCol = max(maxInCol, nums[i][j]);
            }
            score += maxInCol;
        }
        return score;
    }
};
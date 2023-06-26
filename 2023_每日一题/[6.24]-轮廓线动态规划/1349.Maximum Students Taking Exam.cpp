// Given a m * n matrix seats  that represent seats distributions in a classroom. 
// If a seat is broken, it is denoted by '#' character otherwise it is denoted by a '.' character.

// Students can see the answers of those sitting next to the left, right, upper left and upper right, 
// but he cannot see the answers of the student sitting directly in front or behind him. 

// Return the maximum number of students that can take the exam together without any cheating being possible..

// Students must be placed in seats in good condition.


// 给你一个 m * n 的矩阵 seats 表示教室中的座位分布。
// 如果座位是坏的（不可用），就用 '#' 表示；否则，用 '.' 表示。
// 学生可以看到左侧、右侧、左上、右上这四个方向上紧邻他的学生的答卷，但是看不到直接坐在他前面或者后面的学生的答卷。
// 请你计算并返回该考场可以容纳的一起参加考试且无法作弊的最大学生人数。
// 学生必须坐在状况良好的座位上。



// Input: seats = [["#",".","#","#",".","#"],
//                 [".","#","#","#","#","."],
//                 ["#",".","#","#",".","#"]]
// Output: 4
// Explanation: Teacher can place 4 students in available seats so they don't cheat on the exam. 




class Solution {
public:
    // ------------------------ 学习 ----------------------------
    // ----------------------- 再  写 ---------------------------
    // ---------------------- 轮廓化 dp --------------------------
    int dp[8][1 << 8];
    int row;
    int col;
    vector<int> maskState;

    int maxStudents(vector<vector<char>>& seats) {
        row = seats.size();
        col = seats[0].size();
        memset(dp, -1, sizeof(dp));

//    [["#",".","#","#",".","#"],
//     [".","#","#","#","#","."],
//     ["#",".","#","#",".","#"]]
//      0  1  0  0  1  0  = 18  
//      1  0  0  0  0  1  = 33
//      0  1  0  0  1  0  = 18  
        for (auto arr : seats) {
            int mask = 0;
            for (int bit = 0; bit < col; bit++) {
                mask <<= 1;
                mask |= (arr[bit] == '.');
            }
            maskState.push_back(mask);
        }
        int maxStudentsCount = dfs(maskState[0], 0);
        return maxStudentsCount;
    }

    int dfs(int current, int idx) {
        if (dp[idx][current] != -1) // 不记忆化搜索会TLE
            return dp[idx][current];

        int MASK = 1 << col; // 1 0 0 0 0 0 0 0 0
        int ans  = 0;
        for (int mask = 0; mask < MASK; mask++) {
            if (mask & (~current)) // 不能坐的位置"1" 被坐了 1 0 1 1 0 1 
                continue;
            if (mask & (mask << 1))
                continue;

            int cnt = 0;
            for (int i = 0; i < col; i++) {
                if (mask & (1 << i)) {
                    // 1 左移 i 位 （1左移5位）1 0 0 0 0 0 每个位置是否可以坐人
                    cnt++;
                }
            }
            
            if (idx + 1 == row) 
                ans = max(ans, cnt); // 最后一行已经影响不到更后面了
            else {
                int nextState = maskState[idx + 1];
                // 对角消除，除了坏的椅子还要消除坐了人的位置
                nextState &= ~(mask << 1); //0 1 1 0 1 0 // mask 本身就在枚举已经坐好人之后的状态
                nextState &= ~(mask >> 1); //0 1 0 1 1 0
                
                ans = max(ans, cnt + dfs(nextState, idx + 1));
            }
        }

        dp[idx][current] = ans;
        // 每一层idx处，当前的 mask 对应的值，每一nextState 在之后 current 都有一个最大值
        return ans;
    }
};



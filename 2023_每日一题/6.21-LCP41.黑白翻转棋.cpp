//在 n*m 大小的棋盘中，有黑白两种棋子，黑棋记作字母 "X", 白棋记作字母 "O"，空余位置记作 "."。
//当落下的棋子与其他相同颜色的棋子在行、列或对角线完全包围（中间不存在空白位置）另一种颜色的棋子，则可以翻转这些棋子的颜色。

//黑白翻转棋项目中，将提供给选手一个未形成可翻转棋子的棋盘残局，其状态记作 chessboard。若下一步可放置一枚黑棋，请问选手最多能翻转多少枚白棋。

//注意：
//1. 若翻转白棋成黑棋后，棋盘上仍存在可以翻转的白棋，将可以 继续 翻转白棋
//2. 输入数据保证初始棋盘状态无可以翻转的棋子且存在空余位置

//==========
//[".......",".......",".......","X......",".O.....","..O....","....OOX"]
//4
//==========

//==========
//[".X.",".O.","XO."]
//2
//==========

//==========
//["....X.","....X.","XOOO..","......","......"]
//3
//==========

class Solution {
public:
    int flipChess(vector<string>& chessboard) {
        int row = chessboard.size();
        int col = chessboard[0].size();
        int result = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (chessboard[i][j] == '.')
                    result = max(result, fill(chessboard, i, j));
            }
        }
        return result;
    }

    // 一共有 8 个方向
    const int dir[8][2] = {
        {0, 1}, {0, -1}, {1,  0}, {-1,  0},
        {1, 1}, {1, -1}, {-1, 1}, {-1, -1},
    };

    // 判断能否顺着一个方向翻到最后
    bool isValidFlip(vector<string>& chessboard, int x, int y, int moveX, int moveY) {
        x += moveX;
        y += moveY;
        while (x >= 0 && y >= 0 && x <= chessboard.size() - 1 && y <= chessboard[0].size() - 1) {
            if (chessboard[x][y] == 'X')
                return true;
            if (chessboard[x][y] == '.')
                return false;
            x += moveX;
            y += moveY;
        }
        return false;
    }
    
    // BFS 进行翻转的实际操作，但是不能动真的棋盘
    int fill(vector<string> chessboard, int row, int col) { // do not change the real chessboard
        int white = 0;
        queue<pair<int, int>> q;
        q.emplace(row, col);
        chessboard[row][col] = 'X';

        while (!q.empty()) {
            pair<int, int> current = q.front();
            q.pop();
            // 8 种操作
            for (int i = 0; i < 8; i++) {
                if (isValidFlip(chessboard, current.first, current.second, dir[i][0], dir[i][1])) {
                    int actualX = current.first + dir[i][0];
                    int actualY = current.second + dir[i][1];
                    while (chessboard[actualX][actualY] != 'X') {
                        q.emplace(actualX, actualY);
                        chessboard[actualX][actualY] = 'X';
                        actualX += dir[i][0];
                        actualY += dir[i][1];
                        white++;
                    }
                }
            }
        }
        return white;
    }

};
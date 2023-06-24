//�� n*m ��С�������У��кڰ��������ӣ����������ĸ "X", ���������ĸ "O"������λ�ü��� "."��
//�����µ�������������ͬ��ɫ���������С��л�Խ�����ȫ��Χ���м䲻���ڿհ�λ�ã���һ����ɫ�����ӣ�����Է�ת��Щ���ӵ���ɫ��

//�ڰ׷�ת����Ŀ�У����ṩ��ѡ��һ��δ�γɿɷ�ת���ӵ����̲о֣���״̬���� chessboard������һ���ɷ���һö���壬����ѡ������ܷ�ת����ö���塣

//ע�⣺
//1. ����ת����ɺ�����������Դ��ڿ��Է�ת�İ��壬������ ���� ��ת����
//2. �������ݱ�֤��ʼ����״̬�޿��Է�ת�������Ҵ��ڿ���λ��

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



// ---------------------------------------- BFS ------------------------------------------


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

    // һ���� 8 ������
    const int dir[8][2] = {
        {0, 1}, {0, -1}, {1,  0}, {-1,  0},
        {1, 1}, {1, -1}, {-1, 1}, {-1, -1},
    };

    // �ж��ܷ�˳��һ�����򷭵����
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
    
    // BFS ���з�ת��ʵ�ʲ��������ǲ��ܶ��������
    int fill(vector<string> chessboard, int row, int col) { // do not change the real chessboard
        int white = 0;
        queue<pair<int, int>> q;
        q.emplace(row, col);
        chessboard[row][col] = 'X';

        while (!q.empty()) {
            pair<int, int> current = q.front();
            q.pop();
            // 8 �ֲ���
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
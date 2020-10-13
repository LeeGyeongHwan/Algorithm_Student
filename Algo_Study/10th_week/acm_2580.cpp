/* 
ACMICPC
Study Group
10th Week
문제 번호 : 2580
문제 제목 : 스도쿠 
풀이 날짜 : 2020-10-13
Solved By Reamer 
*/

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

vector<pair<int, int>> holeVec;
int sudoku[9][9];
int row[9], col[9];
int box[3][3];
int endNum;

void doSudoku(int cnt)
{

    if (cnt == endNum)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
                cout << sudoku[i][j] << " ";
            cout << endl;
        }
        exit(0);
    }
    int x, y;
    tie(x, y) = holeVec[cnt];

    int dx = x / 3;
    int dy = y / 3;

    for (int i = 1; i <= 9; i++)
    {
        if ((row[x] & (1 << i)) == 0 && (col[y] & (1 << i)) == 0 && (box[dx][dy] & (1 << i)) == 0)
        {
            sudoku[x][y] = i;
            row[x] |= (1 << i);
            col[y] |= (1 << i);
            box[dx][dy] |= (1 << i);
            doSudoku(cnt + 1);
            row[x] ^= (1 << i);
            col[y] ^= (1 << i);
            box[dx][dy] ^= (1 << i);
        }
    }
}

int main()
{
    int tmp;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> tmp;
            sudoku[i][j] = tmp;
            if (tmp == 0)
            {
                holeVec.push_back({i, j});
                continue;
            }
            row[i] |= (1 << tmp);
            col[j] |= (1 << tmp);
            box[i / 3][j / 3] |= (1 << tmp);
        }
    }

    endNum = holeVec.size();
    doSudoku(0);

    return 0;
}
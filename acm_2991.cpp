/* 
ACMICPC 
문제 번호 : 2991
문제 제목 : 사나운 개
풀이 날짜 : 2020-05-20
*/

#include <iostream>

using namespace std;

int main()
{
    int A, B, C, D;
    int P, M, N;
    cin >> A >> B >> C >> D;
    cin >> P >> M >> N;

    int countP = 0, countM = 0, countN = 0;
    int tmp = P % (A + B);
    if (tmp != 0 && tmp <= A)
        countP++;
    tmp = P % (C + D);
    if (tmp != 0 && tmp <= C)
        countP++;

    tmp = M % (A + B);
    if (tmp != 0 && tmp <= A)
        countM++;
    tmp = M % (C + D);
    if (tmp != 0 && tmp <= C)
        countM++;

    tmp = N % (A + B);
    if (tmp != 0 && tmp <= A)
        countN++;
    tmp = N % (C + D);
    if (tmp != 0 && tmp <= C)
        countN++;

    cout << countP << "\n"
         << countM << "\n"
         << countN << endl;

    return 0;
}
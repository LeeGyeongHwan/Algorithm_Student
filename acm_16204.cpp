/* 
ACMICPC 
문제 번호 : 16204
문제 제목 : 카드 뽑기
풀이 날짜 : 2020-05-20
*/

#include <iostream>

using namespace std;

int main()
{
    int N, M, K;

    cin >> N >> M >> K;

    int maxNum = M > K ? M : K;
    int minNum = M > K ? K : M;

    cout << minNum + (N - maxNum) << endl;

    return 0;
}
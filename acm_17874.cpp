/* 
ACMICPC 
문제 번호 : 17874
문제 제목 : Piece of Cake!
풀이 날짜 : 2020-05-26
*/

#include <iostream>

using namespace std;

int main()
{
    int n, h, v;
    int result;
    cin >> n >> h >> v;

    result = n - h > h ? n - h : h;
    result = n - v > v ? (n - v) * result : v * result;

    cout << result * 4 << endl;

    return 0;
}
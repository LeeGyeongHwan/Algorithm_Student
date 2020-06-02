/* 
ACMICPC 
문제 번호 : 2535
문제 제목 : 아시아 정보올림피아드
풀이 날짜 : 2020-06-02
Solved By Reamer 
*/

#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

bool func(tuple<int, int, int> A, tuple<int, int, int> B)
{
    int A1, A2, A3, B1, B2, B3;
    tie(A1, A2, A3) = A;
    tie(B1, B2, B3) = B;
    if (A3 > B3)
        return true;
    else
        return false;
}

int main()
{
    int N;
    int country, number, score;
    int graph[100] = {0};
    int count = 0;
    vector<tuple<int, int, int>> tVec;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> country >> number >> score;
        tVec.push_back(make_tuple(country, number, score));
    }

    sort(tVec.begin(), tVec.end(), func);

    for (int i = 0; i < N; i++)
    {
        tie(country, number, score) = tVec[i];
        if (count == 3)
            break;
        if (graph[country] < 2)
        {
            cout << country << " " << number << endl;
            graph[country]++;
            count++;
        }
    }

    return 0;
}
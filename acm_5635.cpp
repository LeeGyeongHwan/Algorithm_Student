/*
ACMICPC
문제 번호 : 5635
문제 제목 : 생일
풀이 날짜 : 2020-11-10
Solved By Reamer
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <tuple>
using namespace std;

bool compare(tuple<string, int, int, int> A, tuple<string, int, int, int> B)
{
    string aname, bname;
    int ad, am, ay, bd, bm, by;
    tie(aname, ad, am, ay) = A;
    tie(bname, bd, bm, by) = B;

    if (ay == by)
    {
        if (am == bm)
            return ad < bd;
        return am < bm;
    }
    return ay < by;
}

int main()
{
    int N, day, month, year;
    vector<tuple<string, int, int, int>> tupleVec;
    string name;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> name >> day >> month >> year;
        tupleVec.push_back({name, day, month, year});
    }
    sort(tupleVec.begin(), tupleVec.end(), compare);

    tie(name, day, month, year) = tupleVec.back();
    cout << name << "\n";
    tie(name, day, month, year) = tupleVec.front();
    cout << name << "\n";
    return 0;
}
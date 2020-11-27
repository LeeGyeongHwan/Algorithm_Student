/* 
ACMICPC 
문제 번호 : 16499 
문제 제목 : 동일한 단어 그룹화하기
풀이 날짜 : 2020-11-27
Solved By Reamer 
*/

#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    set<string> strSet;
    string str;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> str;
        sort(str.begin(), str.end());
        strSet.insert(str);
    }

    cout << strSet.size() << "\n";

    return 0;
}
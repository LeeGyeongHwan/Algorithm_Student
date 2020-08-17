/* 
ACMICPC
Study Group
2nd Week
문제 번호 : 9251
문제 제목 : LCS
풀이 날짜 : 2020-08-09
Solved By Reamer 
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int lcs[1001][1001];
int main()
{
    string str1, str2;

    cin >> str1;
    cin >> str2;
    //문자열 앞에 빈칸을 삽입한다.
    str1 = " " + str1;
    str2 = " " + str2;
    for (int i = 1; i < str1.length(); i++)
    {
        for (int j = 1; j < str2.length(); j++)
        {
            if (str1[i] == str2[j]) //글자가 같다면 이전까지의 최장 길이보다 증가시킨다.
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            else //글자가 다르다면 이전글자 까지의 최장 길이 중 최댓값을 적용시킨다.
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
        }
    }

    cout << lcs[str1.length() - 1][str2.length() - 1] << endl;
    return 0;
}
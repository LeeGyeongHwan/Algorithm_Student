/* 
ACMICPC
Study Group
3rd Week
문제 번호 : 2661
문제 제목 : 좋은수열
풀이 날짜 : 2020-08-17
Solved By Reamer 
*/

#include <iostream>
#include <string>
using namespace std;

int N;

string subseq;
bool isFind = false;
void findGoodSequence(int cnt, string sequence)
{
    bool isBad = false;
    int length = sequence.length();
    for (int i = 0; i < length / 2; i++)
    {
        string subStr = sequence.substr(length - (i + 1), i + 1);
        string comStr = sequence.substr(length - (i + 1) * 2, i + 1);
        if (!subStr.compare(comStr))
        {
            isBad = true;
            break;
        }
    }
    if (isBad)
        return;
    if (cnt == N)
    {
        subseq = sequence;
        isFind = true;
        return;
    }

    for (int i = 1; i <= 3; i++)
    {
        string newS = sequence + to_string(i);
        findGoodSequence(cnt + 1, newS);
        if (isFind)
            break;
    }
}

int main()
{
    cin >> N;
    findGoodSequence(0, "");
    cout << subseq << endl;
    return 0;
}
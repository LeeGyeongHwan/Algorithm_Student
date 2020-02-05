/*
난이도 : D2
문제 번호 : 1983
문제 제목 : 조교의 성적 매기기
풀이 날짜 : 2020-02-05
Solved By Reamer
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

bool compare(pair<float, int> A, pair<float, int> B)
{
    return A.first > B.first;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int testCase, student, num;
    int middleTest, endTest, assignment;

    vector<pair<float, int>> pairVec;
    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        cin >> student >> num;
        for (int j = 0; j < student; j++)
        {
            cin >> middleTest >> endTest >> assignment;
            float finalScore = middleTest * 0.35 + endTest * 0.45 + assignment * 0.2;
            pairVec.push_back(make_pair(finalScore, j + 1));
        }

        sort(pairVec.begin(), pairVec.end(), compare);

        int grade;
        for (int j = 0; j < pairVec.size(); j++)
        {
            if (pairVec[j].second == num)
            {
                grade = j + 1;
            }
        }
        string mark = "";
        if (grade % (student / 10) == 0)
            grade = grade / (student / 10);
        else
            grade = grade / (student / 10) + 1;

        switch (grade)
        {
        case 1:
            mark = "A+";
            break;
        case 2:
            mark = "A0";
            break;
        case 3:
            mark = "A-";
            break;
        case 4:
            mark = "B+";
            break;
        case 5:
            mark = "B0";
            break;
        case 6:
            mark = "B-";
            break;
        case 7:
            mark = "C+";
            break;
        case 8:
            mark = "C0";
            break;
        case 9:
            mark = "C-";
            break;
        case 10:
            mark = "D0";
            break;
        default:
            mark = "error";
            break;
        }
        cout << "#" << (i + 1) << " " << mark << endl;
        pairVec.clear();
    }

    return 0;
}
/* 
ACMICPC 
문제 번호 : 5800
문제 제목 : 성적 통계
풀이 날짜 : 2020-08-02
Solved By Reamer 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int K, student, tmp;
    vector<int> score;
    cin >> K;

    for (int i = 0; i < K; i++)
    {
        cin >> student;
        int largeGap = 0;

        for (int j = 0; j < student; j++)
        {
            cin >> tmp;
            score.push_back(tmp);
        }

        sort(score.begin(), score.end());

        for (int j = 1; j < score.size(); j++)
        {
            int gap = score[j] - score[j - 1];
            if (gap > largeGap)
                largeGap = gap;
        }

        cout << "Class " << i + 1 << endl;
        cout << "Max " << score.back() << ", Min " << score.front() << ", Largest gap " << largeGap << endl;
        score.clear();
    }

    return 0;
}
/*
난이도 : D2
문제 번호 : 1979
문제 제목 : 어디에 단어가 들어갈 수 있을까
풀이 날짜 : 2020-02-17
Solved By Reamer
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int testCase, N, K, tmp;
    vector<vector<int>> intVV;
    vector<int> tmpVec;

    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        bool isRight = false;
        bool isDown = false;
        int answer = 0;
        cin >> N >> K;
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                cin >> tmp;
                tmpVec.push_back(tmp);
            }
            intVV.push_back(tmpVec);
            tmpVec.clear();
        }
        
        for (int j = 0; j < N; j++)
        {
            int wordLength = 0;
            for (int k = 0; k < N; k++)
            {
                if(intVV[j].at(k)==1)
                {
                    if(isRight)
                    {
                        wordLength++;
                    }
                    else
                    {
                        isRight=true;
                        wordLength++;
                    }
                }
                else
                {
                    if(wordLength==K)
                        answer++;
                    isRight=false;
                    wordLength=0;
                }    
            }
            if(wordLength==K)
                answer++;
        }

        for (int j = 0; j < N; j++)
        {
            int wordLength = 0;
            for (int k = 0; k < N; k++)
            {
                if(intVV[k].at(j)==1)
                {
                    if(isDown)
                    {
                        wordLength++;
                    }
                    else
                    {
                        isDown=true;
                        wordLength++;
                    }
                }
                else
                {
                    if(wordLength==K)
                        answer++;
                    isDown=false;
                    wordLength=0;
                }
               
            }
             if(wordLength==K)
                answer++;
        }
        cout << "#" << (i + 1) << " " << answer << endl;
        intVV.clear();
    }

    return 0;
}
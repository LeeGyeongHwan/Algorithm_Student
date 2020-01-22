#include <iostream>

using namespace std;

int main()
{
    int N;
    string testCase;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> testCase;
        int ttt = 0, tth = 0, tht = 0, thh = 0, htt = 0, hth = 0, hht = 0, hhh = 0;
        for (int j = 2; j < testCase.length(); j++)
        {
            string compareStr = testCase.substr(j - 2, 3);
            if (compareStr == "TTT")
                ttt++;
            else if (compareStr == "TTH")
                tth++;
            else if (compareStr == "THT")
                tht++;
            else if (compareStr == "THH")
                thh++;
            else if (compareStr == "HTT")
                htt++;
            else if (compareStr == "HTH")
                hth++;
            else if (compareStr == "HHT")
                hht++;
            else if (compareStr == "HHH")
                hhh++;
        }
        cout << ttt << " " << tth << " " << tht << " " << thh << 
        " " << htt << " " << hth << " " << hht << " " << hhh << endl;
    }

    return 0;
}
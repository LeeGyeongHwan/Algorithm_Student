/*
난이도 : D2
문제 번호 : 1928
문제 제목 : Base64 Decoder
풀이 날짜 : 2020-02-03
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    int testCase;
    string str;
    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        cin >> str;
        string answer = "";
        //48 - 0
        //65 - A
        //97 - a
        int byte4 = 0;
        for (int j = 0; j < str.length(); j++)
        {
            int num;
            if (str[j] >= 'A' && str[j] <= 'Z')
                num = str[j] - 'A';
            else if (str[j] >= 'a' && str[j] <= 'z')
                num = str[j] - 'a' + 26;
            else if (str[j] >= '0' && str[j] <= '9')
                num = str[j] - '0' + 52;
            else if (str[j] == '+')
                num = 62;
            else
                num = 63;
                
            switch (j % 4)
            {
            case 0:
                byte4 += (num << 18);
                break;
            case 1:
                byte4 += (num << 12);
                break;
            case 2:
                byte4 += (num << 6);
                break;
            case 3:
                byte4 += num;
                answer += char(byte4 >> 16);
                answer += char((byte4 >> 8) & 0xff);
                answer += char(byte4 & 0xff);
                byte4 = 0;
            }
        }

        cout << "#" << (i + 1) << " " << answer << endl;
    }
    return 0;
}
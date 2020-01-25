#include <iostream>

using namespace std;

int main()
{
    int N;
    string str;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        string resultStr = "";
        for (int j = 0; j < str.length(); j++)
        {
            if (str[j] < 90)
                resultStr += char(str[j] + 1);
            else
                resultStr += char(str[j] - 25);
        }

        cout << "String #" << (i + 1) << endl;
        cout << resultStr << endl
             << endl;
    }

    return 0;
}
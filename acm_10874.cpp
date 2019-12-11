#include <iostream>

using namespace std;

int main()
{
    int numOfStudent, tmp;

    cin >> numOfStudent;
    for (int i = 0; i < numOfStudent; i++)
    {
        int count = 0;
        for (int j = 0; j < 10; j++)
        {
            cin >> tmp;
            int answer = j % 5 + 1;
            if (tmp == answer)
                count++;
        }
        if (count == 10)
            cout << i + 1 << endl;
    }

    return 0;
}
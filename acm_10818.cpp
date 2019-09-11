#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int numMin = 1000000;
    int numMax = -1000000;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        if (tmp < numMin)
            numMin = tmp;
        if (tmp > numMax)
            numMax = tmp;
    }
    cout << numMin << " " << numMax << endl;
}
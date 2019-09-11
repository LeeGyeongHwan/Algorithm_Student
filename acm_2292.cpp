#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int count = 0;
    while (N > 0)
    {
        if (count == 0)
        {
            N--;
            count++;
            continue;
        }
        N = N - 6 * count;
        count++;
    }
    cout << count << endl;
}
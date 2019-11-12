#include <iostream>

using namespace std;

int main()
{
    int N, K;
    bool check[1001] = {false};
    cin >> N >> K;
    int count = 0;
    int num;
    for (int i = 2; i <= N; i++)
    {
        if (check[i] == false)
        {

            count++;
            //cout << "i : " << i << ", count: " << count << endl;
            if (count == K)
            {
                num = i;
                break;
            }
            for (int j = i + i; j <= N; j += i)
            {
                if (check[j] == false)
                {
                    check[j] = true;
                    count++;
                    //cout << "j : " << j << ", count: " << count << endl;
                    if (count == K)
                    {
                        num = j;
                        break;
                    }
                }
            }
            if (count >= K)
                break;
        }
    }
    cout << num << endl;
    return 0;
}
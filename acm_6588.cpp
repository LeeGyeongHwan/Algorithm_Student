#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(NULL); // <----원인
    ios::sync_with_stdio(false);
    int N;
    vector<int> primeVec;
    bool isChecked[1000001];

    for (int i = 2; i <= 1000000; i++)
    {
        if (isChecked[i] == false)
        {
            primeVec.push_back(i);
            for (int j = i + i; j <= 1000000; j += i)
            {
                isChecked[j] = true;
            }
        }
    }

    cin >> N;

    while (N != 0)
    {
        bool noExist = false;
        for (int i = 0; i < primeVec.size() / 2; i++)
        {
            int num = N - primeVec[i];
            if (isChecked[num] == false)
            {
                noExist = true;
                cout << N << " = " << primeVec[i] << " + " << num << "\n";
                break;
            }
        }
        if (!noExist)
            cout << "Goldbach's conjecture is wrong.\n";
        cin >> N;
    }

    return 0;
}

/*#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N;
    int pn=0;
    int prime[80000];
    bool check[1000001];

    for(int i=2;i<=1000000;i++)
    {
        if(check[i]==false)
        {
            prime[pn++]=i;
            for(int j=i+i;j<=1000000;j+=i)
            {
                check[j]=true;
            }
        }
    }




    cin >> N;

    while(N!=0)
    {
        bool noExist = false;
        for (int i = 0; i * i <= N; i++)
        {
            int num = N - prime[i];
            if (check[num] == false)
            {
                noExist = true;
                cout << N << " = " << prime[i] << " + " << num << "\n";
                break;
            }
        }
        if (!noExist)
            cout << "Goldbach's conjecture is wrong.\n";




        cin >> N;
    }
    return 0;
}
*/
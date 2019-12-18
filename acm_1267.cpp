#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int num, tmp;
    vector<int> intVec;
    cin >> num;
    int Ymon = 0, Mmon = 0;
    for (int i = 0; i < num; i++)
    {
        cin >> tmp;
        Ymon += (tmp / 30) + 1;
        Mmon += (tmp / 60) + 1;
    }
    Ymon = (Ymon)*10;
    Mmon = (Mmon)*15;
    if (Ymon > Mmon)
    {
        cout << "M " << Mmon << endl;
    }
    else if (Ymon < Mmon)
    {
        cout << "Y " << Ymon << endl;
    }
    else
    {
        cout << "Y M " << Ymon << endl;
    }

    return 0;
}
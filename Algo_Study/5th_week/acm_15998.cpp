/* 
ACMICPC
Study Group
5th Week
문제 번호 : 15998
문제 제목 : 카카오머니
풀이 날짜 : 2020-08-31
Solved By Reamer 
*/

#include <iostream>
#include <set>
#include <climits>

using namespace std;

long long gcd(long long A, long long B)
{
    if (B == 0)
        return A;
    return gcd(B, A % B);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    long long A, B, tmpSum, chargedMoney;
    long long curMoney = 0;
    pair<long long, long long> prevInfo = {0, 1};
    bool noAnswer = false, firstWithdraw = true;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A >> B;
        tmpSum = curMoney + A;
        if (A > 0 || tmpSum >= 0 || noAnswer) //단순입금이거나 출금이 가능할 때 답이없을경우 입력을 다처리
        {
            if (tmpSum != B)
                noAnswer = true;
            curMoney = tmpSum;
            continue;
        }
        chargedMoney = B - tmpSum;
        curMoney = B;
        //이거의 약수중에 B원 초과하는것들

        if (firstWithdraw)
        {
            prevInfo = {B, chargedMoney};
            firstWithdraw = false;
            continue;
        }
        else
        {
            tmpSum = gcd(prevInfo.second, chargedMoney);
            int large = prevInfo.first > B ? prevInfo.first : B;
            if (tmpSum > large)
                prevInfo = {large, tmpSum};
            else
                noAnswer = true;
        }
    }

    if (noAnswer)
        cout << "-1\n";
    else
        cout << prevInfo.second << "\n";

    return 0;
}
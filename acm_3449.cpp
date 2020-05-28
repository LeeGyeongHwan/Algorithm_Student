/* 
ACMICPC 
문제 번호 : 3449
문제 제목 : 해밍 거리
풀이 날짜 : 2020-05-28
*/

#include <iostream>

using namespace std;

int main()
{
    int N;
    string A, B;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> A >> B;
        int count = 0;
        for (int j = 0; j < A.length(); j++)
        {
            if (A[j] != B[j])
                count++;
        }
        cout << "Hamming distance is " << count << "." << endl;
    }
    return 0;
}
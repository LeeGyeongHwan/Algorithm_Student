#include <iostream>

using namespace std;

int main()
{
    int test, leg, chicken;
    cin >> test;
    for (int i = 0; i < test; i++)
    {
        cin >> leg >> chicken;
        int num = chicken * 2 - leg;
        cout << num << " " << chicken - num << endl;
    }
}
#include <iostream>

using namespace std;

int main()
{
    int num, student, apple;
    int sumApple = 0;

    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> student >> apple;
        sumApple += (apple % student);
    }
    cout << sumApple;
    return 0;
}
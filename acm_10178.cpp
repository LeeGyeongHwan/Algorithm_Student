#include <iostream>

using namespace std;

int main()
{
    int num, A, B;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cin >> A >> B;
        cout << "You get " << A / B << " piece(s) and your dad gets " << A % B << " piece(s)." << endl;
    }
    return 0;
}
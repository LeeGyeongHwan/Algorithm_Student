#include <iostream>

using namespace std;

int main()
{
    int N;

    cin >> N;
    int count = 0;
    int i = 1;
    for (;count!=N; i++)
    {
        string abc = to_string(i);
        size_t found = abc.find("666");
        if (found != string::npos)
            count++;    
   }
   cout << i-1 <<endl;
}
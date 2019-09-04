#include<iostream>
#include<vector>

using namespace std;



int main()
{
    int num;
    
    cin>>num;
    vector<int> vec={0,1};
    for(int i=1;i<num;i++)
    {
        vec.push_back(vec.at(i)+vec.at(i-1));
    }

    cout<<vec.back()<<endl;

    return 0;
}
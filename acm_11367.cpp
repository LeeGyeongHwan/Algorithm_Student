#include<iostream>

using namespace std;

int main()
{
    int N,score;
    string hobby;
    
    cin>>N;

    for(int i=0;i<N;i++)
    {
        cin>>hobby>>score;

        cout<<hobby<<" ";

        if(score>=97)
            cout<<"A+"<<endl;
        else if(score>=90)
            cout<<"A"<<endl;
        else if(score>=87)
            cout<<"B+"<<endl;
        else if(score>=80)
            cout<<"B"<<endl;
        else if(score>=77)
            cout<<"C+"<<endl;
        else if(score>=70)
            cout<<"C"<<endl;
        else if(score>=67)
            cout<<"D+"<<endl;
        else if(score>=60)
            cout<<"D"<<endl;
        else
            cout<<"F"<<endl;
    }

    return 0;
}
#include<iostream>
using namespace std;

int main()
{
    int a,b,i,d,s;
    cin>>a>>b;
    for(i=a; i<=b;i++)
    {
        s=1;
        for (d=2;d<=i/2;d++)
            if(i%d==0)
            s+=d;
        if(s==i)
            cout<<i<<'\n';
    }

}


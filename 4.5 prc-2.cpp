#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int ara[n];
    int sum=1;
    for (int i=1;i<n;i++)
    {
        cin>>ara[i];
    }
    for (int i=1;i<n;i++)
    {
        if(i%2==0)
        {
            sum*=ara[i];
        }
    }
    cout<<sum;


    return 0;
}


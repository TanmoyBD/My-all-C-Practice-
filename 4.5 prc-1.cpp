#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int ara[n];
    int sum=0;
    for (int i=0;i<n;i++)
    {
        cin>>ara[i];
    }
    for (int i=0;i<n;i++)
    {
        sum+=ara[i];
    }
    cout<<sum;


    return 0;
}

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int m;
    cin>>m;
    int ara[m];
    int i,j;
    for ( i=0;i<m;i++)
    {
        cin>>ara[i];
    }
    int n;
    cin>>n;
    int arb[n];
    for (j=0;j<m;j++)
    {
        cin>>arb[j];
    }

    if (m<n)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(ara[i]==arb[j])
                {
                    cout<<ara[i]<<" ";
                }
            }
        }
    }
    else if(n<m)
    {
        for(i=0;i<m;i++)
        {
            for(j=0;j<m;j++)
            {
                if(ara[i]==arb[j])
                {
                    cout<<ara[i]<<" ";
                }
            }
        }
    }
    return 0;
}

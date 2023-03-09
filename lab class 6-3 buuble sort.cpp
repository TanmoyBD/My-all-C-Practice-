#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter The Size Of Array->>";
    int n;
    cin>>n;
    vector<int>ara(n);
    for(int i=0;i<n;i++)
    {
        cin>>ara[i];
    }
    //N at pass cholbe
    for (int pass=0;pass<n;pass++)
    {
        int last =n-1-pass;
        for(int j=0;j<last;j++)
        {
            if (ara[j]>=ara[j+1])
            {
                swap(ara[j],ara[j+1]);
            }
        }
        cout<<"After Pass"" "<<pass<<": ""\n";
        for (int i=0;i<n;i++)
        {
            cout<<ara[i]<<" ";
            cout<<"\n";
        }

    }
    cout<<"After Sorting"<<"\n";
    for (int i=0;i<n;i++)
    {
        cout<<ara[i]<<" ";
        cout<<"\n";
    }

}

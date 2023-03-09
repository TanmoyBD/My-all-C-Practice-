#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for{int i=0;i<n;i++}
    {
        int idx=1
        while(idx >=1)
        {
            if(a[idx-1] > a[idex])
            {
                swap(a[idx-1],a[idx]);
                idx--;
            }
        }
    }
    cout<<"After";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}

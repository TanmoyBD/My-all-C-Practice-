#include<bits/stdc++.h>

using namespace std;

int main()
{
    string st;
    getline(cin,st);

    for (int i=0;i<st.length();i++)
    {
        if (st[i]=='z')
        {
            st[i]='a';
            continue;
        }
        if (i%2==0)
        {
            st[i]=st[i]+1;
        }
    }
    cout<<st;

    return 0;
}


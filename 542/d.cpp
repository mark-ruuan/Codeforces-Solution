#include<bits/stdc++.h>
using namespace std;
int M=1e9+7;
int dsu[150009];

int findfn(int x)
{
    if(dsu[x]!=x)
        dsu[x]=findfn(dsu[x]);
    return dsu[x];
}

int main()
{
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);

    int n;
    cin>>n;

    vector< vector<int> > arr(n+1);
    for(int i=1;i<=n;i++)
        arr[i].push_back(i);

    for(int i=1;i<=n;i++)
        dsu[i]=i;
    int ans=1;

    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;

        int a=findfn(x);
        int b=findfn(y);
        dsu[a]=b;
        for(int j=0;j<arr[a].size();j++)
            arr[b].emplace_back(arr[a][j]);
        // arr[a].clear();
        ans=b;
    }

    for(int i=0;i<n;i++)
        cout<<arr[ans][i]<<" ";
    return 0;
}
//This is basically Bipartite check Problem
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mk make_pair
#define pll pair<ll,ll>
#define pii pair<int,int>
#define mod 1000000007
#define wi while
#define vtrl vector<ll>
#define vtri vector<int>
#define endl "\n"
#define mp map<char, int>
#define min_heap priority_queue<int,vtr,greater<int>> 
#define max_heap priority_queue<int>
vtri ar[100001];
int visited[100001];
int n,m,a,b;
int colour[100001];
bool dfs(int node,int color)
{
    visited[node] = 1;
    colour[node] = color;
    for(auto child:ar[node])
    {
        if(visited[child]==0)
        {
            if(dfs(child,color^1)==false)
                return false;
        }
        else if(colour[node]==colour[child])//check whether the parent and child are in same team
            return false;
    }
    return true;
}
int main()
{
    cin>>n>>m;
    while(m--)
    {
        cin>>a>>b;
        ar[a].pb(b);
        ar[b].pb(a);
    }
    bool ans = true;
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            ans = dfs(i,1);
            if(!ans)
                break;
        }
    }
    if(!ans)
        cout<<"IMPOSSIBLE"<<endl;
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(colour[i]==0)
            {
                cout<<2<<" ";
            }
            else
                cout<<1<<" ";
        }
        cout<<endl;
    }

    return 0;

}
//it is basically a disjoint set problem
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mk make_pair
#define pii pair<int,int>
#define mod 1000000007
#define wi while
#define vtr vector<ll>
#define endl "\n"
#define mp map<char, int>
#define min_heap priority_queue<int,vtr,greater<int>> 
#define max_heap priority_queue<int>
vector<int> ar[100001];
int visited[100001];
int n,m,a,b;
void dfs(int node)
{
    visited[node] = 1;
    for(int child:ar[node])
    {
        if(visited[child]==0)
            dfs(child);
    }
}

int main()
{
    
    cin>>n>>m;
    for(int i=1;i<=n;i++) visited[i] = 0;
    while(m--)
    {
        cin>>a>>b;
        ar[a].pb(b);
        ar[b].pb(a);
    }
    int cc = 0;//to count the number of connected components
    int lst = 1;//this variable is for merging two connected components
    dfs(1);
    cc++;
    vector<pii> v;
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            cc++;
            v.pb({lst,i});
            lst = i;
            dfs(i);  
        }
    }
    cout<<cc-1<<endl;
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
    return 0;

}
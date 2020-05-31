//author:-Adarsh Kumar Singh
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
const int INF = 100001;
vector<pair<int,int>> ar[100001];
int parent[100001];
vector<int> path;
int n,m,a,b;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)parent[i] = -1;
    while(m--)
    {
        cin>>a>>b;
        ar[a].pb({b,1});
        ar[b].pb({a,1});
    }
    parent[1] = 1;
    //Dijstra algorithm for minimum path
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>>> pq;
    vector<int> dist(n+1,INF);
    pq.push({0,1});
    dist[1] = 0;
    while(!pq.empty())
    {
        int curr = pq.top().second;
        int curr_d = pq.top().first;
        pq.pop();
        for(auto edge: ar[curr])
        {
         if(curr_d + edge.second < dist[edge.first])
         {
             dist[edge.first] = curr_d + edge.second;
             pq.push({dist[edge.first], edge.first});
             parent[edge.first] = curr;

         }
        }
    }
    //whether the both graph lie in same connected components or not
    if(dist[n]==INF)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        cout<<dist[n]+1<<endl;
   for(int i=n; i!= 1;i = parent[i])
   {
        path.pb(i);
   }
   path.pb(1);
   reverse(path.begin(),path.end());
   for(int i=0;i<path.size();i++)
   {
    cout<<path[i]<<" ";
   }
}
    return 0;

}
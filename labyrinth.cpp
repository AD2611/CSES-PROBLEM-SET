//Labyrinth Solution
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
const int INF = 1000001;
int n,m;
int distt[1001][1001];
char mat[1001][1001];
bool vis[1001][1001];
int ans = 0;
int sx,sy;
int ex,ey;
//function to check move is possible or not
bool isValid(int x,int y)
{
    if((x < 1) || (x>n) || (y < 1) || (y > m))
        return false;
    if(mat[x][y]=='#')
        return false;
    return true;
}
int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    //     freopen("error.txt","w",stderr);
    // #endif
    cin>>n>>m;
    ans = 0;
    pair<int,int> parent[1001][1001];
    for(int i=0;i<1001;i++)
    {
        for(int j=0;j<1001;j++)
        {
            distt[i][j] = INF;
            parent[i][j] = {-1,-1};
        }
    }
    for(int i=1;i<=n;i++)
    {
       for(int j = 1;j<=m;j++)
       {
        cin>>mat[i][j];
        
        if(mat[i][j]=='A')
        {
            sx = i;
            sy = j;
        }
        if(mat[i][j]=='B')
        {
            ex = i;
            ey = j;
        }
       }
       
    }
    
    //dijstra algorithm for shortest path
    priority_queue<pair<int,pair<int,int>>,
    vector<pair<int,pair<int,int>> >,
    greater<pair<int,pair<int,int>>>> pq;
    
    pq.push({0,make_pair(sx,sy)});
    distt[sx][sy] = 1;
    while(!pq.empty())
    {
        auto curr = pq.top().second;
        int curr_d = pq.top().first;
        pq.pop();
        int x = curr.first;
        int y = curr.second;
        if(isValid(x-1,y))
        {
            v.pb('U');

            if(curr_d + 1 < distt[x-1][y])
            {
                distt[x-1][y] = curr_d + 1;
                pq.push({distt[x-1][y],{x-1,y}});
                parent[x-1][y] = {x,y};

            }
            
        }
        if(isValid(x,y+1))
        {
            v.pb('R');
            if(curr_d + 1 < distt[x][y+1])
            {
                distt[x][y+1] = curr_d + 1;
                pq.push({distt[x][y+1],{x,y+1}});
                parent[x][y+1] = {x,y};
            }
            
        }
        if(isValid(x+1,y))
        {
            v.pb('D');
            if(curr_d + 1 < distt[x+1][y])
            {
                distt[x+1][y] = curr_d + 1;
                pq.push({distt[x+1][y],{x+1,y}});
                parent[x+1][y] = {x,y};
            }
            
        }
        if(isValid(x,y-1))
        {
            v.pb('L');
            if(curr_d + 1 < distt[x][y-1])
            {
                distt[x][y-1] = curr_d + 1;
                pq.push({distt[x][y-1],{x,y-1}});
                parent[x][y-1] = {x,y};
            }
            
        }
    }
    if(distt[ex][ey]==INF)
    {
    cout<<"NO"<<endl;
    }
    else{
    pair<int,int> t = {ex,ey};
    pair<int,int> s = {sx,sy};
    vector<pair<int,int>> path;
    for(pair<int,int> f = t; f != s ; f = parent[f.first][f.second])
    {
        path.pb(f);
    
    }
    reverse(path.begin(), path.end());
    int dx = sx;
    int dy = sy;
    vector<char> ar;
    for(int i=0;i<path.size();i++)
    {
        int tx = path[i].first;
        int ty = path[i].second;
        if(tx==(dx-1) && ty==(dy))
        {
            ar.pb('U');
        }
        if(tx==(dx+1) && ty==(dy))
        {
            ar.pb('D');
        }
        if(tx==(dx) && ty==(dy-1))
        {
            ar.pb('L');
        }
        if(tx==(dx) && ty==(dy+1))
        {
            ar.pb('R');
        }
        dx = tx;
        dy = ty;
        
    }
    cout<<"YES"<<endl;
    cout<<distt[ex][ey]<<endl;
    for(int i=0;i<ar.size();i++)
    {
        cout<<ar[i];
    }
    }

    return 0;
}
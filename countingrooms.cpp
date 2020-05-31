//connected components on 2d grid
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mk make_pair
#define pii pair<ll,ll>
#define mod 1000000007
#define wi while
#define vtr vector<ll>
#define endl "\n"
#define mp map<char, int>
#define min_heap priority_queue<int,vtr,greater<int>> 
#define max_heap priority_queue<int>
int n,m;
char mat[1001][1001];
bool vis[1001][1001];
bool isValid(int x,int y)
{
    if((x < 1) || (x>n) || (y < 1) || (y > m))
        return false;
    if(vis[x][y]==true || mat[x][y]=='#')
        return false;
    return true;
}
// int dx[] = {-1,0,1,0};
// int dy[] = {0,1,0,-1};
void dfs(int x, int y)
{

    vis[x][y] = true;
    // for(int i=0;i<3;i++)
    // {
    //     if(isValid(x + dx[i],y + dy[i]))
    //         dfs(x+dx[i],y+dy[i]);
        
    // }
    if(isValid(x-1,y))
     dfs(x-1,y);//up
    if(isValid(x,y+1))
     dfs(x,y+1);//down
    if(isValid(x+1,y))
     dfs(x+1,y);//right
    if(isValid(x,y-1))
     dfs(x, y-1);//left
    
    
    
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
       for(int j = 1;j<=m;j++)
       {
        cin>>mat[i][j];
       }
    }
    int count = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            
            if(mat[i][j]=='.' && vis[i][j]==false)
            {
                
                dfs(i,j);
                count++;
            }
        }
       
    }
    cout<<count;
    return 0;

}
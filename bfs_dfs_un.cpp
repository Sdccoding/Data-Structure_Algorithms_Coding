//Copyright@Souhardya
//Question : BFS&&DFS(Unweighed)
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mk make_pair
#define f first
#define se second
#define ll long long int
#define ld long double
#define MOD 1000000007

void bfs(ll n,vector<vector<ll>> &v,ll src,vector<ll>&ans)
{
      queue<ll>q;
      q.push(src);
      //vector<ll>ans;
      vector<ll>vis(n,0);
      while(q.size())
      {
            src=q.front();
            vis[src]=1;
            ans.pb(src);
            q.pop();
            for(ll i=0;i<v[src].size();i++)
            {
                  ll tar=v[src][i];
                  if(vis[tar]==0)
                  {
                     vis[tar]=1;
                     q.push(tar);
                  }
            }
      }
      
}

void dfs(ll n,vector<vector<ll>> &v,ll src,vector<ll>&ans,ll *vis)
{          
           vis[src]=1; 
           ans.pb(src);  
           for(ll i=0;i<v[src].size();i++)
           {
                   ll tar=v[src][i];
                   if(vis[tar]==0)
                   {
                       vis[tar]=1;
                       dfs(n,v,tar,ans,vis);
                   }
           }
}
int main() 
{    
      
      ll n,e;
      cin>>n>>e;
      ll src;
      cin>>src;

    vector<vector<ll>>v(n);
    for(ll i=0;i<e;i++)
     {
           ll x,y;
           cin>>x>>y;
           v[x].pb(y);
           v[y].pb(x);
     }
    vector<ll>ans;
    cout<<"For BFS:"<<endl;
     bfs(n,v,src,ans);
     for(ll i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
      cout<<endl;

     ans.clear();

     ll vis[n]={0};
     dfs(n,v,src,ans,vis);
    cout<<"For DFS:"<<endl;
     for(ll i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
      cout<<endl;


     

  return 0;
              
}
      



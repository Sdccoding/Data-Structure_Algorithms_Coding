//Copyright@Souhardya
//Question : Djikstra
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mk make_pair
#define f first
#define se second
#define ll long long int
#define ld long double
#define MOD 1000000007

//Same aprroach works for directed||undirected
ll mindist(ll *dist,ll *vis,ll n)
{      
      ll mn=INT_MAX; ll ind=-1;
      for(ll i=0;i<n;i++)
      {
           if(vis[i]==0&&dist[i]<mn)
           {
                mn=dist[i];
                ind=i;
           }
      }
      return ind;
}
void dijkmat(ll n,ll src,vector<vector<ll>>&v)
{
    ll vis[n]={0};  ll dist[n]; 
    for(ll i=0;i<n;i++)
      dist[i]=INT_MAX;
    dist[src]=0;
    for(ll cnt=0;cnt<n-1;cnt++)
    {
         ll u=mindist(dist,vis,n);
         vis[u]=1;
         for(ll i=0;i<n;i++)
         {     
              if(v[u][i]&&(dist[u]!=INT_MAX)&&(dist[u]+v[u][i]<dist[i])&&(vis[i]==0))
              {
                     dist[i]=dist[u]+v[u][i];
              }
         }
    }
    for(ll i=0;i<n;i++)
      cout<<i<<" : "<<dist[i]<<endl;
}


void dijklist(ll n,ll src,vector<vector<pair<ll,ll>>> &v)
{
      ll vis[n]={0};  ll dist[n]; 
    for(ll i=0;i<n;i++)
      dist[i]=INT_MAX;
    dist[src]=0;
    //First one distance and second one id
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q;
    q.push(mk(0,src));
    while(!q.empty())
    {
         ll id=(q.top()).se;
         q.pop();
         vis[id]=1;
         for(ll i=0;i<v[id].size();i++)
         {
                ll tar=v[id][i].f;
                ll ds=v[id][i].se;
                if((vis[tar]==0)&&(dist[id]!=INT_MAX)&&dist[tar]>dist[id]+ds)
                {
                    dist[tar]=dist[id]+ds;
                    q.push(mk(dist[tar],tar));
                }
         }
    }
    for(ll i=0;i<n;i++)
      cout<<i<<" : "<<dist[i]<<endl;


}
int main() 
{    
      
      ll n,e;
      cin>>n>>e;
      ll src;
      cin>>src;
//Adjacent Matrix approach's vector
     vector<vector<ll>>v(n,vector<ll>(n,0));

//Adjacent list approach's vector
    vector<vector<pair<ll,ll>>>v2(n);
     


     for(ll i=0;i<e;i++)
     {
           ll x,y,w;
           cin>>x>>y>>w;
           //Vector matrix
           v[x][y]=w;
           v[y][x]=w;

           //List matrix
          v2[x].pb(mk(y,w));
          v2[y].pb(mk(x,w));
     }

     //Adjacent vector approach
     cout<<"Adjacent Matrix Form:"<<endl;
     dijkmat(n,src,v);

//Adjacent list approach
     cout<<"Adjacent List Form:"<<endl;
     dijklist(n,src,v2);

     

  return 0;
              
}
      



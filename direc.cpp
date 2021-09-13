/*Minimum time taken by each job to be completed given by a Directed Acyclic Graph*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
ll times[101];
ll vis[101];
void dfs(ll src,vector<ll>* adj,ll cp)
{
	vis[src]=1;
	times[src]=min(times[src],cp);
	for(auto x:adj[src])
	{
		if(vis[x]==0)
		{   
			dfs(x,adj,cp+1);
		}
	}


}
int main()
{
    
    ll t;
    cin>>t;
    while(t--)
    {
    	ll n,e;
    	cin>>n>>e;
    	vector<ll>adj[n+1];
        memset(vis,0,sizeof(vis));
    	for(ll i=0;i<e;i++)
    	{
    		ll u,v;
    		cin>>u>>v;
    		adj[u].pb(v);
    		vis[v]++;
    	}
    	for(ll i=1;i<=n;i++) times[i]=INT_MAX;
    	queue<int>q;
    	for(ll i=1;i<=n;i++)
    	{
    		if(!vis[i])
    			q.push(i);
    	}
    	memset(vis,0,sizeof(vis));

    	while(q.size())
    	{
    		ll t=q.front();
    		q.pop();
    		if(vis[t]==0)
    		{
    			
    			dfs(t,adj,1);
    		}
    	}

    	for(ll i=1;i<=n;i++)
    	{
    		cout<<times[i]<<" ";
    	}
    	cout<<endl;





    }
}


      
 

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int lc(int a,int b)
{
    int hcf=__gcd(a,b);
    int lc=(a*b)/hcf;

    return lc;
}
// int ans(char* binstr)
// {
//     int n=strlen(binstr);
//     int ans=0; int tans=0;
//     for(int i=0;i<n;i++)
//     {
//         if(binstr[i]=='1')
//         {
//             tans++;
//         }
//         else
//         {
//             ans=max(ans,tans);
//             tans=0;
//         }
//     }
//     ans=max(ans,tans);

//     return ans;
// }
int vis[100];
vector<int>adj[101];
int st=-1; int en=-1; int cp=0;
int dfs(int src,int par)
{
    vis[src]=1;
    for(auto i:adj[src])
    {
        if(vis[i]==0)
        {    
            if(dfs(i,src))
                return 1;        
        }

        else if(i!=par)
        {   
            st=i; en=src;
            return 1;
        }
    }

    return 0;
}
vector<int>paths; int fl=0;
vector<vector<int>>ans;
void pth(int src,int par)
{
    vis[src]=1;
    paths.pb(src);
    if(src == en)
    {    
        ans.pb(paths);
        paths.pop_back();
        vis[src]=0;
        return;
    }
    for(int i:adj[src])
    {
        // if(src == st && i == en)
        //     continue;
        if(vis[i]==0 && i!=par)
        {
            pth(i,src);  
        }
    }
        
        vis[src]=0;
        paths.pop_back();

}
int main()
{
     int n,e;
     cin>>n>>e;
     
     for(int i=0;i<e;i++)
     {
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
     }
     
     // for(int i=0;i<n;i++)
     // {
     //    for(int j : adj[i])
     //        cout<<j<<" ";
     //    cout<<endl;
     // }

     memset(vis,0,sizeof(vis));
     int cy=0;
    for(int i=0;i<n;i++)
    {
        if(vis[i]==0)
        {
            if(dfs(i,-1))
            {   
                cy=1;
                break;
            }
        }
    }
    if(cy ==0) 
    {
        cout<<"No cycles present"<<endl;
        return 0;
    }
     
    cout<<st<<" "<<en<<endl;

    memset(vis,0,sizeof(vis));
    en=7;
    st=0;
    pth(st,-1);



    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    // for(int i=0;i<paths.size();i++)
    //     cout<<paths[i]<<" ";









}

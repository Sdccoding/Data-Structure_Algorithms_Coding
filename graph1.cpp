//Finding cycle in a directed graph
//dfs till you meet a visited node.
//Also maintain a inrecursion array.


#define pb push_back
int find(int src,vector<vector<int>>&v,int *vis,int *st)
{
        vis[src]=1;     st[src]=1;
        for(int i=0;i<v[src].size();i++)
        {
              int tar=v[src][i];
              if(vis[tar]==0)
              {
                    if(find(tar,v,vis,st))
                    {
                        return 1;
                    }
              }
              else
              {
                    if(st[tar]==1)
                      return 1;
              }
        }
        st[src]=0;
        return 0;
}
int Solution::solve(int A, vector<vector<int> > &B)
{
    vector<vector<int>>dp(A);
    if(A<=2)
     return 0;
    int n=B.size();
    for(int i=0;i<n;i++)
    {
          dp[B[i][0]-1].pb(B[i][1]-1);
    }
    int vis[A]={0};  
    int st[A]={0};
    for(int i=1;i<=A;i++)
    {
        if(vis[i]==0)
        {
            if(find(i,dp,vis,st))
               return 1;
        }
    }
  
    return 0;
     
}

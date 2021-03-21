//Finding cycle in undirected graph.
//Maintain a parent 
//if vis[i]==0 ,answer will be what is returned from next step
//else check if the pre checked node is not the parent
#define pb push_back
bool find_cycle(vector<vector<int>> &graph,int s,vector<int> &visited,int par)
{
    visited[s] = 1;
    
    for (int i = 0;i < graph[s].size();i++)
    {
        if (visited[graph[s][i]] == 0)
        {
            if (find_cycle(graph,graph[s][i],visited,s) == true)
            {   
                
                return true;
            }
        } 
        else 
        {
            if (graph[s][i] != par)
            {    
                
                return true;
            }
        }
    }
    
    return false;
}

int Solution::solve(int n, vector<vector<int> > &A) {
    
    int m=A.size();
    vector<vector<int>>v(n);
    for(int i=0;i<n;i++)
    {
           v[A[i][0]-1].pb(A[i][1]-1);
           v[A[i][1]-1].pb(A[i][0]-1);
    }
    vector<int>visited(n,0);
    for(int i=0;i<n;i++)
    {
           if(visited[i]==0)
           {
               return find_cycle(v,i,visited,-1);
           }
    }
    
    return 0;
}

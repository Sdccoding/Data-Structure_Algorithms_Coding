//Reverse DFS
void topo(int src,vector<int>* &v,int* vis,vector<int> &ans)
{
       vis[src]=1;
       for(int i=0;i<v[src].size();i++)
       {
           int cp=v[src][i];
           if(vis[cp]==0)
           {
               topo(cp,v,vis,ans);
           }
       }
       ans.push_back(src);
}
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int n, vector<int> v[]) 
	{
	    
	    //To exist if a topo cycle exits 
	    //Atfirst find if its a directed acyclic graph.
	    
	    
	    //Then,move here
	    int vis[n]={0}; vector<int>ans;
	    for(int i=0;i<n;i++)
	    {
	        if(vis[i]==0)
	        {
	            topo(i,v,vis,ans);
	        }
	    }
	    reverse(ans.begin(),ans.end());
	    return ans;
	    
	    
	    
	}
};

//Longest Arithmetic Progression

int Solution::solve(const vector<int> &A) {
    int n=A.size();
    if(n<3)
    return n;
    int ans=1;
    
    //Runs at O(n3) complexity
    // for(int i=0;i<n-1;i++)
    // {
    //     for(int j=i+1;j<n;j++)
    //     {
    //         int dif=A[j]-A[i];  int ls=A[j];  int cp=2;
    //         for(int k=j+1;k<n;k++)
    //         {
    //             if(A[k]-ls==dif)
    //             {
    //                 cp++;
    //                 ls=A[k];
    //             }
    //         }
    //         ans=max(ans,cp);
    //     }
    // }
    vector<unordered_map<int,int>>v(n);
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
                int dif=A[j]-A[i]; 
                if(v[i].find(dif)!=v[i].end())
                {
                      v[j][dif]=v[i][dif]+1;
                }
                else
                    v[j][dif]=2;
                ans=max(ans,v[j][dif]);
        }
    }
    
    return ans;
    
            
    
    
}

string smallestWindow (string s, string p)
    {
        int dp[256]={0};
        int n=s.size();
        int m=p.size();
        int cnt=0;
        for(int i=0;i<m;i++)
        {  
            if(dp[p[i]]==0)
            {
                cnt++;
            }
            dp[p[i]]++;
            
        }
        int i=0; int j=0; int ans=INT_MAX;int start;
        while(j<n)
        {
            dp[s[j]]--;
            if(dp[s[j]]==0)
              cnt--;
            if(cnt==0)
            {  
                while(cnt==0)
                {
                    if(j-i+1<ans)  
                    {
                        ans=j-i+1; start=i;
                    }
                    
                    dp[s[i]]++;
                    if(dp[s[i]]>0)
                    {
                        cnt++;
                    }
                    i++;
                    
                }
            }
            j++;
        }
        if(ans==INT_MAX)
          return "-1";
        else
          return s.substr(start,ans);
    }

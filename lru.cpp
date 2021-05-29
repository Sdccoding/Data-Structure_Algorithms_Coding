int pageFaults(int n, int C, int pages[]){
        // code here
        unordered_map<int,int>mp;
        map<int,int>cnt;
        int ans=0;
        for(int i=0;i<n;i++)
        {
             if(mp.find(pages[i])!=mp.end())
             {
                   int cp=mp[pages[i]];
                   cnt.erase(cp);
                   mp[pages[i]]=i;
                   cnt[i]=pages[i];
             }
             else
             {
                   if(C>0)
                   {
                       mp[pages[i]]=i;
                       cnt[i]=pages[i];
                       C--;
                   }
                   else
                   {   
                       int ind=(cnt.begin())->first;
                       int bc=(cnt.begin())->second;
                       mp.erase(bc);
                       cnt.erase(ind);
                       cnt[i]=pages[i];
                       mp[pages[i]]=i;
                   }
                   ans++;
             }

        }
        return ans;

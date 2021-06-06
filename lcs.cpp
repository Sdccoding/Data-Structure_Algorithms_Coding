//Find LCS in terms of LIS,when 1 array has unique elemnts
//Find LIS in O(nlogn) 

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ll long long int
#define ld long double
#define MOD 1000000007
#define endl "\n"
#define pi pair<int,int>
#define JALDI ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
void so(vector<ll> &v)
{
    sort(v.begin(),v.end());
}

int main() 
{    
    JALDI;
    ll n,m;
    cin>>n>>m;
    vector<ll>s(n),t(m);
    for(ll i=0;i<n;i++)
      cin>>s[i];
    unordered_map<int,int>mp;
    for(ll i=0;i<m;i++)
    {
      cin>>t[i];
      mp[t[i]]=i;
    }
    for(ll i=0;i<n;i++)
    {
      if(mp.find(s[i])!=mp.end())
      {
        s[i]=mp[s[i]];
      }
      else
        s[i]=-1;
    }
    vector<ll>tail;
    for(ll i=0;i<n;i++)
    {
      if(s[i]==-1)  continue;
      else if(tail.size()==0)
      {
        tail.pb(s[i]);
      }
      else if(s[i]>=tail.back())
      {
        tail.pb(s[i]);
      }
      else if(s[i]<tail[0])
      {
        tail[0]=s[i];
      }
      else
      {
        auto it=lower_bound(tail.begin(),tail.end(),s[i]);
        *it=s[i];

      }
    }
    cout<<tail.size()<<endl;


    

        

         
        


    
       
    
  
      

    
            
    


  return 0;
              
}
      

 

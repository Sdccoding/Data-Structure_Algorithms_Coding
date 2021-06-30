//Xor value of x=[1,pow(2,31)].Find the minimum such that sigma xor of x and individual element is minimum
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
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll hash[32]={0};
        for(ll i=0;i<n;i++)
        {
            ll x;
            cin>>x;
            ll cp=0;
            while(x!=0)
            {   
                ll rem=x%2;
                hash[cp]+=rem;
                x=x/2;
                cp++;
            }
        }
        vector<pair<ll,ll>>v;
        for(ll i=0;i<=31;i++)
        {
              ll h2[33]={0}; ll c=i; ll cp=0;
              while(c!=0)
              {
                   h2[cp++]+=(c%2);
                   c=c/2;
              }
             
              ll cr=0;
             vector<ll>ans(33,0);
              for(ll j=0;j<32;j++)
              {    

                   if(h2[j]==0)
                   {
                          ll on=hash[j]+cr;
                          if(on%2==0)
                          {
                            ans[j]=0;
                          }
                          else
                            ans[j]=1;
                          if(on>=2)
                          {
                            cr=1;
                          }
                   }
                   else if(h2[j]==1)
                   {   
                        ll on=(n-hash[j]);
                        if(on%2==0)
                          {
                            ans[j]=0;
                          }
                        else
                            ans[j]=1;
                        if(on>=2)
                          {
                            cr=1;
                          }
                   }
              }
              if(cr==1)
              {
                ans[32]=1;
              }
              reverse(ans.begin(),ans.end());
              ll sum=0;
              for(ll j=0;j<33;j++)
                sum=(ll)sum*2+ans[j];
              //v.pb(sum);
              
              v.pb(mk(sum,i));
              //v[i].fi=sum; v[i].se=i;
              
        }
        sort(v.begin(),v.end());
        cout<<v[0].fi<<" ";
        ll cnt=0;
        for(ll i=0;i<32;i++)
        {
           if(v[0].fi==v[i].fi)
           {
               cnt++;
           }
        }
        cout<<cnt<<endl;


        

        
        



    }
  return 0;
              
}
      

 
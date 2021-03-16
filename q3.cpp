//Copyright@Souhardya
//Ways to reach n if k jumps are allowed
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mk make_pair
#define f first
#define se second
#define ll long long int
#define ld long double
#define MOD 1000000007
#define Fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int main() 
{   
    Fast
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        ll dp[n+1]={0};

        //O(n*k) implemantation
        dp[1]=1;
        for(ll i=2;i<=n;i++)
        {
             for(ll j=i-1;j>=max((ll)1,i-k);j--)
             {
                    dp[i]+=dp[j];
             }
        }
        cout<<dp[n]<<endl;


        //O(n) implementation
        for(ll i=0;i<=n;i++)
          dp[i]=0;
        dp[1]=1;
        if(n>=2)  dp[2]=1;
        for(ll i=3;i<=n;i++)
        {      
              if(i-k>=1)
                dp[i]=2*dp[i-1]-dp[i-k-1];
              else 
                dp[i]=2*dp[i-1];

             
        }
        cout<<dp[n]<<endl;


          



          
        
    }


  return 0;
              
}
      



//2*(x|A[i])-(x^A[i]) => x+A[i]
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

ll bin(ll lo,ll hi,vector<ll> &v,ll key)
{
	ll ans=0;
	while(lo<=hi)
	{
		ll mid=(lo+hi)/2;
		if(v[mid]>=key)
		{
             ans=(ll)v.size()-mid;
             hi=mid-1;
		}
		else
		{
			lo=mid+1;
		}
	}
	return ans;
}
int main() 
{    
    JALDI;
    ll t;
    //cin>>t;
    t=1;
    while(t--)
    {
    	
    	ll n;
    	cin>>n;
    	vector<ll>v(n);
    	for(ll i=0;i<n;i++)
    	{
    		cin>>v[i];

    	}
    	so(v);

     ll q;
     cin>>q;
     while(q--)
     {
     	ll x,m;
     	cin>>x>>m;
     	ll z=m-x;
     	//cout<<"Key is "<<z<<endl;
     	cout<<bin(0,n-1,v,z)<<endl;
     }




    } 
  return 0;
              
}
      

 
//Reversing words of a string

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mk make_pair
#define f first
#define se second
#define ll long long int
#define ld long double
#define MOD 1000000007
int main() 
{    
     
  string s;
  getline(cin,s);
  //cout<<s<<endl;
  int n=s.size(); //cout<<n<<endl;
  string ans; string temp;
  for(int i=n-1;i>=0;i--)
  {
      if(temp.size()==0&&s[i]==' ')
      {
           continue;
      }
      else if(s[i]==' ')
      {
             
             //cout<<i<<endl;
            reverse(temp.begin(),temp.end());
            temp.pb(s[i]);
            //cout<<temp.back()<<endl;
            ans.append(temp);
            temp.clear();
      }
      else
        temp.pb(s[i]);
  }
  if(temp.size())
  {
        reverse(temp.begin(),temp.end());
        ans.append(temp);
  }
  if(ans.size()&&ans.back()==' ')
      ans.pop_back();
  cout<<ans<<endl;
  //cout<<ans.size()<<endl;

  return 0;
              
}
      

 

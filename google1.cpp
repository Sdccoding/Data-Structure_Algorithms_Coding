//Find the number of non-overlapping palindromic triplet substrings of a string. Note: These triplets when combined may or mayn't be equal to the length of the string
//Example: abbccd => a,b,d is also possible {a,b,d are 3 palindromic substrings,they are non overlapping}


int ispal(int lo,int hi,string s)
{
    while(lo<hi)
    {
        if(s[lo]!=s[hi])
            return 0;
        lo++;
        hi--;
    }
    return 1;
}

vector<string>temp;
int google=0;
void rec(int i,int j,string s)
{   
     if(i >j )
     {   
        return;
     }
    for(int k=i;k<=j;k++)
    {
        if(ispal(i,k,s))
        {
            temp.push_back(s.substr(i,k-i+1));
            if(temp.size()==3)
                google++;
            rec(k+1,j,s);
            temp.pop_back();
        }
    }
}

class Solution {
public:
    long long partition(string s) {
           
           google =0;
           rec(0,s.size()-1,s);
    
           return google;
        
        
    }
};

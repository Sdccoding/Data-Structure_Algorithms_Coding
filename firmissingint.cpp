// Given an unsorted integer array, find the first missing positive integer.

// Example:

// Given [1,2,0] return 3,

// [3,4,-1,1] return 2,

// [-8, -7, -6] returns 1

// Your algorithm should run in O(n) time and use constant space.


int Solution::firstMissingPositive(vector<int> &A) {
    int n=A.size();
    int cp=0;
    for(int i=0;i<n;i++)
    {
         if(A[i]>n||A[i]<=0)
        {
            A[i]=n+1;
        }
        else if(A[i]==n)
            cp=1;
           
        
    }
    for(int i=0;i<n;i++)
    {
        if(abs(A[i])>=n)
        {
            continue;
        }
        
        else
        {   
            A[abs(A[i])]=-1*abs(A[abs(A[i])]);
        }
    }
  
    for(int i=1;i<n;i++)
    {
        if(A[i]>0)
             return i;
    }
    if(cp==1)
       return n+1;
    else
        return n;
        
        
        
//Had said 1st Missing Non Negative Integer
//   int n=A.size();
//   for(int i=0;i<n;i++)
//   {
//       if(A[i]<0||A[i]>=n)
//          A[i]=n;
//   }
//   for(int i=0;i<n;i++)
//   {
//       if(abs(A[i])>=n)
//           continue;
//       else
//       {
//              if(A(abs(A[i]))==0)
//              {
//                  A[abs(A[i])]=-1*n;
//                  A[0]=-1*n;
//              }
                
//              else
//              A[abs(A[i])]=-1*abs(A[abs(A[i])]);
//       }
//   }
//   for(int i=0;i<n;i++)
//   {
//       if(A[i]>=0)
//          return i;
//   }
//   return n;


    
    
}

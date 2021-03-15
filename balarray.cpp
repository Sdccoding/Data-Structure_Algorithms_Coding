// Given an integer array A of size N. You need to count the number of special elements in the given array.

// A element is special if removal of that element make the array balanced.

// Array will be balanced if sum of even index element equal to sum of odd index element.



int Solution::solve(vector<int> &A) {
    int n=A.size();
    int od[n]={0}; int ev[n]={0};
    od[0]=A[0];   if(n>=2)   od[1]=od[0];
    for(int i=2;i<n;i=i+2)
    {
          od[i]=od[i-2]+A[i];
          if(i+1<n)
           od[i+1]=od[i];
    }
    ev[0]=0;
    if(n>=2)  ev[1]=A[1];
    if(n>=3)  ev[2]=ev[1];
    for(int i=3;i<n;i=i+2)
    {
        ev[i]=ev[i-2]+A[i];
        if(i+1<n)
        ev[i+1]=ev[i];
    }
    // for(int i=0;i<n;i++)
    //   cout<<od[i]<<" ";
    //   cout<<endl;
    // for(int i=0;i<n;i++)
    //   cout<<ev[i]<<" ";
    //   cout<<endl;
     
    int cp=0;
    for(int i=0;i<n;i++)
    {     
        int odd=0,even=0;
         if(i%2==0)
         {
               odd=od[i]-A[i];
               odd+=ev[n-1]-ev[i];
               
               even=ev[i]+od[n-1]-od[i];
               
         }
         else
         {
             even=ev[i]-A[i];
             even+=od[n-1]-od[i];
             
             odd=od[i]+ev[n-1]-ev[i];
         }
         if(odd==even)
         cp++;
    }
    return cp;
}

// This function wants you to modify the given input
    // array and no need to return anything
    // arr: input array
    // n: size of array
    //Function to rearrange  the array elements alternately.
    /*Given a sorted array of positive integers. Your task is to rearrange  the array elements alternatively
    i.e first element should be max value, second should be min value, third should be second max, fourth 
    should be second min and so on.*/
    
    void rearrange(long long *arr, int n) 
    { 
    	
    	// Your code here
    	int l=0; int r=n-1;
    	int mx=arr[n-1]+1;
    	for(int i=0;i<n;i++)
    	{
    	    if(i%2==0)
    	    {   
    	        int a=(arr[r]%mx);
    	        arr[i]=mx*a+arr[i];
    	        r--;
    	    }
    	    else
    	    {
    	        int a=(arr[l]%mx);
    	        arr[i]=a*mx+arr[i];
    	        l++;
    	    }
    	}
    	for(int i=0;i<n;i++)
    	{
    	    arr[i]=arr[i]/mx;
    	}
    	 

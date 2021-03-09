/* Determine whether an integer is a palindrome. Do this without extra space.

A palindrome integer is an integer x for which reverse(x) = x where reverse(x) is x with its digit reversed.
Negative numbers are not palindromic.*/
int Solution::isPalindrome(int A) 
{  
    if(A<0)  return 0;
    //if(A==0)  return 0;
    int cp=0;  int x=A;
    while(x!=0)
    {
        cp++;
        x=x/10;
    }
    x=A; int i=0;  int tot=cp;  cp--;
    while(i<tot/2)
    {
          int a1=x/(pow(10,cp));
          int a2=A%10;
          A=A/10;
          int t=pow(10,cp);
          cp--;
          x=x%t;
          if(a1!=a2)
            return 0;
          i++;
          
    }
    return 1;
}

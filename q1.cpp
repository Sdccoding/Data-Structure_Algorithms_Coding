//Copyright@Souhardya

//Question: Given singly linked list with every node having an additional “arbitrary” pointer that currently points to NULL. Need to make the “arbitrary” pointer point to the next higher value node
//Both version solved
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mk make_pair
#define f first
#define se second
#define ll long long int
#define ld long double
#define MOD 1000000007

//Declaring linked list with arbitrary pointer
struct node{
    int val;
    node* next;
    node*  arb;
};

//creating the linked list
void create(int val,node* &head,node* &A)
{       
        node* temp=new node();
        temp->val=val;   temp->next=NULL;   temp->arb=NULL;
        if(head==NULL)
        {
                 head=temp;
                 A=temp;

        }
        else
        {     
          head->next=temp;
          head=head->next;
        }
}

//printing the linked list
void prin(node* A)
{
       while(A)
       {
          cout<<A->val<<" ";
          if(A->arb==NULL)
            cout<<"NULL ";
          else
            cout<<A->arb->val<<" ";
          A=A->next;
       }
       cout<<endl;
       return;
}

//Reversing the linked list
void rev(node* &A)
{
     node* prev=NULL;
     node* head=A;
     while(head)
     {
          node* temp=head;
          head=head->next;
          temp->next=prev;
          prev=temp;
     }
     A=prev;
}

//Conditional Sorting 
static bool compare(node* A,node* B)
{
   return A->val<B->val;
}

//Main Function
int main() 
{    
      
      node* head=NULL;
      node* A=NULL;
      ll n;
      cin>>n;
      
      //Taking input
      for(ll i=0;i<n;i++)
      {
        ll x;
        cin>>x;
        create(x,head,A);
      }
  

  prin(A);

  //Start: If for any element,right greater is not found,answer is NULL
  rev(A);
  head=A;
  stack<node*>st;
  st.push(head);
  head=head->next;
  while(head)
  {
        while(!st.empty())
        {
             node* temp=st.top();
             if(temp->val>head->val)
             {
                   head->arb=temp;
                   break;
             }
             else
              st.pop();
        }
        st.push(head);
        head=head->next;
  }
  rev(A);
  prin(A);
  //End: If for any element,right greater is not found,answer is NULL


  //Start : In case circular type is considered.Means,for any element if right greater is not found,then look into left side.
  head=A;
  vector<node*>v;
  while(head)
  {
          v.pb(head);
          head=head->next;  
  }
  
  sort(v.begin(),v.end(),compare);
  for(int i=0;i<v.size()-1;i++)
  {
      node* pr=v[i];
      node* nx=v[i+1];
      pr->arb=nx;
  }
  prin(A);
  //Start : In case circular type is considered.Means,for any element if right greater is not found,then look into left side.



        
   
     

  return 0;
              
}
      



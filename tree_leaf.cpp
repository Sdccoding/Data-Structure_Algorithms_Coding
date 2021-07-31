/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// int rec(TreeNode* A,int &B)
// {
//     if(A==NULL)
//      return 0 ;
//     rec(A->left,B,res);
//     if(B==0)
//     return A->val;
//     B--;
//     rec(A->right,B,res);

// }


int dist=INT_MAX; int aq=-1;
void ans(TreeNode* A,map<TreeNode*,TreeNode*> &mp,int dis,set<TreeNode*> &st)
{
     if(A==NULL)
       return ;
     
    //  cout<<A->val<<endl;
      st.insert(A);
     
     if(A->left==NULL && A->right==NULL)
     {
          if(dis<=dist)
          {
              aq=A->val;
              dist=dis;
          }
     }
     if(A->left && st.find(A->left)==st.end())
     {           
             st.insert(A->left);
             ans(A->left,mp,dis+1,st);
     }
     if(A->right && st.find(A->right)==st.end())
     {      
            st.insert(A->right);
            ans(A->right,mp,dis+1,st);
     }
     
     
     if(mp[A]!=NULL && st.find(mp[A]) == st.end())
       ans(mp[A],mp,dis+1,st);
     
     
}

void fi(int B,map<TreeNode*,TreeNode*> &mp,TreeNode* A,TreeNode* par,TreeNode* &value)
{
     if(A==NULL)
      return ;
      mp[A]=par;
      if(A->val == B)
      {
          value = A;
      }
      fi(B,mp,A->left,A,value);
      fi(B,mp,A->right,A,value);
    
}
int Solution::kthsmallest(TreeNode* A, int B) {
    
    TreeNode* value=NULL;
    aq=-1;
    map<TreeNode*,TreeNode*>mp;
    set<TreeNode*>st;
    
     fi(B,mp,A,NULL,value);
     //pre(A);
    cout<<"Value is "<<value->val<<endl;
     
     ans(value,mp,0,st);
     return aq;
     
     
    
}

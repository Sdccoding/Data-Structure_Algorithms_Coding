//Sorted linked list to BST
#define pb push_back
void find(int x,TreeNode* &ans)
{
    if(ans==NULL)
    {
        ans=new TreeNode(x);
        return ;
    }
    if(x>ans->val)
    {
        find(x,ans->right);
    }
    if(x<ans->val)
    {
        find(x,ans->left);
    }
    
}
void rec(vector<int>&v,int lo,int hi,TreeNode* &ans)
{
     if(lo>hi)
      return;
     int mid=(lo+hi)/2;
     find(v[mid],ans);
     rec(v,lo,mid-1,ans);
     rec(v,mid+1,hi,ans);
}
TreeNode* Solution::sortedListToBST(ListNode* A) {
         vector<int>v;
         TreeNode* ans=NULL;
         while(A)
         {
          v.push_back(A->val);
          A=A->next;
         }
         rec(v,0,v.size()-1,ans);
         return ans;
}

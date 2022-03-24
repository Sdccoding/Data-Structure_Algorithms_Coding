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
#define pi pair<ll,ll>
#define JALDI ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
void so(vector<ll> &v)
{
    sort(v.begin(),v.end());
}
ll powb(ll a, ll b) 
{
    ll res = 1;
    while (b > 0) 
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
struct node {
    int val;
    node* next;
    node* prev;

};
void prin(node* h)
{
    if(h == NULL)
        return;
    cout<<h->val<<" ";
    h=h->next;
    prin(h);
}
map<int,node*>mp;
node* head=NULL; node* tail=NULL;
int pg_fault=0;
void lru(int x,int n)
{   
    if(mp.find(x)!=mp.end())
    {
        node* temp = mp[x];
        if(temp == head)
        {
            prin(head);
            return ;
        }
        if(temp == tail)
            tail=tail->prev;
        temp->prev->next = temp->next;
        if(temp->next)
            temp->next->prev = temp->prev;
        temp->prev = NULL;
        temp->next = head;
        if(head)
            head->prev=temp;
        head=temp;
    }
    else
    {  
        pg_fault++;
        node* temp= new node();
        temp->val = x;
        temp->next = temp->prev = NULL;
        if(mp.size() < n)
        {
            temp->next=head;
            if(head)
                head->prev = temp;
            else
                tail=temp;
            head=temp;
        }
        else
        {   
            temp->next = head;
            if(head)
                head->prev=temp;
            head=temp;
            mp.erase(tail->val);
            tail=tail->prev;
            tail->next = NULL;

        }

    }
    mp[x] = head;
    prin(head);
    cout<<endl;
}
int main() 
{    
    JALDI
    //n => No. of frames available.
    //f => no. of pages to be placed.
    int n;
    cin>>n;
    int f;
    cin>>f;
    for(int i=0;i<f;i++)
    {   

        int x;
        cin>>x;
        cout<<"After Step "<<i+1<<": "<<endl;
        lru(x,n);
    }
    cout<<"Total PageFaults: "<<pg_fault<<endl;

    return 0;
}

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node *reverse(Node *head)
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        Node *ans=reverse(head->next);
        Node *temp=head->next;
        temp->next=head;
        head->next=NULL;
        return ans;
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        Node *revNode=reverse(head);
        Node *temp=revNode;
        int sum=0,c=1;
        while(temp!=NULL)
        {
            sum=temp->data+c;
            temp->data=sum%10;
            c=sum/10;
            if(c>0 && temp->next==NULL)
            {
                Node *newNode=new Node(c);
                temp->next=newNode;
                newNode->next=NULL;
                break;
            }
            temp=temp->next;
        }
        head=reverse(revNode);
        return head;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void print(Node* root) {
    Node* temp = root;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node *reverse(Node *head)
    {
        if(!head || !head->next)
        {
            return head;
        }
        Node *ans=reverse(head->next);
        Node *temp=head->next;
        temp->next=head;
        head->next=NULL;
        return ans;
    }
    Node *compute(Node *head) {
        // your code goes here
        if(!head || !head->next)
        {
            return head;
        }
        
        head=reverse(head);
        Node *maxNode=head;
        Node *curr=head;
        while(curr && curr->next)
        {
            if(curr->next->data<maxNode->data)
            {
                curr->next=curr->next->next;
            }
            else{
                curr=curr->next;
                maxNode=curr;
            }
            
        }
        head=reverse(head);
        return head;
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }
        Solution ob;
        int data = arr[0];
        Node* head = new Node(data);
        Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Node* result = ob.compute(head);
        print(result);
        cout << endl;
    }
}

// } Driver Code Ends
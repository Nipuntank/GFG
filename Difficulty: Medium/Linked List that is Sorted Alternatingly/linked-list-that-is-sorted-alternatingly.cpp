//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}


// } Driver Code Ends

/*
struct Node
{
    int data;
    struct Node *next;

    Node(int x){
        data =x;
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
    Node* sort(Node* head) {
        // Code here
        Node *h1=head;
        Node *h2=head->next;
        Node *t=h2;
        while(h1 && h2 && h1->next && h2->next)
        {
            h1->next=h2->next;
            h2->next=h1->next->next;
            if(h1->next)
            {
                h1=h1->next;
            }
            if(h2->next)
            {
                h2=h2->next;
            }
        }
        t=reverse(t);
        h1->next=t;
        return head;
        
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = new Node(x);
            tail = head;

            while (ss >> x) {
                tail->next = new Node(x);
                tail = tail->next;
            }
        }

        Solution ob;
        Node* newHead = ob.sort(head);
        printList(newHead);
        freeList(newHead);
    }

    return 0;
}

// } Driver Code Ends
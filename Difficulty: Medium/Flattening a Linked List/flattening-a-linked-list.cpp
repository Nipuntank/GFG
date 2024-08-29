//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

void printList(Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
    printf("\n");
}


// } Driver Code Ends
/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
        
        void insert(Node* prev, Node* l2){
            l2->bottom= prev->bottom;
            prev->bottom=l2;
        }
        
        // void merge(Node* l1, Node* l2){
        //     Node *prev = l1;
        //     Node *temp;
        //     while(l1 && l2){
        //         if(l1->data <= l2->data){
        //             prev=l1;
        //             l1=l1->bottom;
        //         }
        //         else if(l2->data < l1->data){
        //             temp=l2->bottom;
        //             insert(prev, l2);
        //             prev=l2;
        //             l2=temp;
        //         }
        //     }
        //     if(l1!=nullptr){
        //         return;
        //     }
        //     else if(l2!=nullptr){
        //         prev->bottom=l2;
        //     }
        // }
        void merge(Node*& l1, Node* l2){
    Node *dummy = new Node(0); // Dummy node to simplify edge cases
    Node *prev = dummy;
    
    while (l1 && l2) {
        if (l1->data <= l2->data) {
            prev->bottom = l1;
            l1 = l1->bottom;
        } else {
            prev->bottom = l2;
            l2 = l2->bottom;
        }
        prev = prev->bottom;
    }

    if (l1) prev->bottom = l1;
    if (l2) prev->bottom = l2;

    l1 = dummy->bottom; 
    delete dummy; 
}
    // Node *flatten(Node *root) {
    //     // Your code here
    //     Node *l1= root;
    //     Node *l2= root->next;
    //     Node *nex= l2;
    //     while(l2 && nex){
    //     nex=l2->next;
    //     merge(l1, l2);
    //     l2=nex;
    //     }
    //     return l1;
    // }
    Node* flatten(Node *root) {
    if (!root || !root->next) return root;

    // Recursively flatten the next nodes first
    root->next = flatten(root->next);

    
    merge(root, root->next);

    return root;
}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        vector<int> work;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            work.push_back(number);
        }
        n = work.size();

        Node *head = NULL;
        Node *pre = NULL;

        for (int i = 0; i < n; i++) {
            int m = work[i] - 1;
            int data;
            cin >> data;
            Node *temp = new Node(data);
            if (head == NULL) {
                head = temp;
                pre = temp;
            } else {
                pre->next = temp;
                pre = temp;
            }

            Node *preB = temp;
            for (int j = 0; j < m; j++) {
                int temp_data;
                cin >> temp_data;
                Node *tempB = new Node(temp_data);
                preB->bottom = tempB;
                preB = tempB;
            }
        }

        Solution ob;
        Node *root = ob.flatten(head);
        printList(root);
    }
    return 0;
}

// } Driver Code Ends
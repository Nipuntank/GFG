//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    int precedence(char c)
    {
        if(c=='^')
        {
            return 3;
        }
        if(c=='/' || c=='*')
        {
            return 2;
        }
        if(c=='+' || c=='-')
        {
            return 1;
        }
        return 0;
    }
    string infixToPostfix(string s) {
        // Your code here
        string post="";
        stack<char>st;
        for(int i=0;i<s.size();i++)
        {
            char c=s[i];
            if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9'))
            {
                post+=c;
            }
            else if(c=='(')
            {
                st.push(c);
            }
            else if(c==')')
            {
                while(st.top()!='(')
                {
                    post+=st.top();
                    st.pop();
                }
                st.pop();
            }
            else{
                while(!st.empty() && precedence(c)<=precedence(st.top()) )
                {
                    post+=st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
        while(!st.empty())
        {
            post+=st.top();
            st.pop();
        }
        return post;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends
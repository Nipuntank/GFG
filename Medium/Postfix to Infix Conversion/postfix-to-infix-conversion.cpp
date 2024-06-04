//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  bool isOperator(char c)
  {
      if(c=='/' || c=='+'|| c=='*' || c=='-'|| c=='^')
      {
          return true;
      }
      return false;
  }
    string postToInfix(string exp) {
        // Write your code here
        stack<string>st;
        for(int i=0;i<exp.size();i++)
        {
            if(isOperator(exp[i]))
            {
                string c1=st.top();
                st.pop();
                string c2=st.top();
                st.pop();
                st.push('('+c2+exp[i]+c1+')');
            }
            else{
                st.push(string(1,exp[i]));
            }
        }
        return st.top();
        
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string postfix;
        cin >> postfix;
        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToInfix(postfix) << endl;

        // cout << "~\n";
    }
    fclose(stdout);

    return 0;
}

// } Driver Code Ends
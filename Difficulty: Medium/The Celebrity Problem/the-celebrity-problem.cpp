//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int m=mat.size();
        vector<int>knowMe(m+1,0);
        vector<int>iKnow(m+1,0);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==j)
                {
                    continue;
                }
                if(mat[i][j])
                {
                    knowMe[j]+=1;
                    iKnow[i]+=1;
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            if(iKnow[i]==0 && knowMe[i]==m-1)
            {
                return i;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends
//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSquares(int N, int M, vector<vector<int>> &matrix) {
        // code here
        vector<vector<int>>dp(N,vector<int>(M,0));
        int ans=0;
        for(int i=0;i<N;i++)
        {
            dp[i][0]=matrix[i][0];
            ans+=dp[i][0];
        }
        for(int j=1;j<M;j++)
        {
            dp[0][j]=matrix[0][j];
            ans+=dp[0][j];
        }
        for(int i=1;i<N;i++)
        {
            for(int j=1;j<M;j++)
            {
                if(matrix[i][j])
                {
                    dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});;
                    ans+=dp[i][j];
                }
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;

        vector<vector<int>> matrix(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        cout << obj.countSquares(N, M, matrix) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int mod=1e9+7;
    int helper(int i,int j,string s1,string s2,vector<vector<int>>&dp)
    {
        
        if(j==0)
        {
            return 1;
        }
        if(i==0)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int a=0;
        if(s1[i-1]==s2[j-1])
        {
            a=helper(i-1,j-1,s1,s2,dp);
        }
        int b=helper(i-1,j,s1,s2,dp);
        return dp[i][j]=(a+b)%mod;
    }
    int countWays(string s1, string s2) {
        // code here
        int m=s1.size();
        int n=s2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return helper(m,n,s1,s2,dp);
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        Solution obj;
        int res = obj.countWays(s1, s2);

        cout << res << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends
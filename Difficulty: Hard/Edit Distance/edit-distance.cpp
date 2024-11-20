//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to compute the edit distance between two strings
    int helper(string s1,string s2,vector<vector<int>>&dp)
    {
        int m=s1.size();
        int n=s2.size();
        if(m==0 || n==0)
        {
            return max(m,n);
        }
        if(dp[m][n]!=-1)
        {
            return dp[m][n];
        }
        int ans=1e9;
        if(s1[0]==s2[0])
        {
            ans=helper(s1.substr(1),s2.substr(1),dp);
        }
        else{
            int a=1+helper(s1.substr(1),s2.substr(1),dp);
            int b=1+helper(s1.substr(1),s2,dp);
            int c=1+helper(s1,s2.substr(1),dp);
            ans=min(a,min(b,c));
        }
        return dp[m][n]=ans;
    }
    int editDistance(string s1, string s2) {
        // code here
        int m=s1.size();
        int n=s2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return helper(s1,s2,dp);
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
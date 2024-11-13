//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int mod=1e9+7;
    long long helper(int n,vector<int>&dp)
    {
        if(n==1 || n==2)
        {
            return 1;
        }
        if(n==3)
        {
            return 2;
        }
        if(n==4)
        {
            return 4;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        long long a=helper(n-1,dp);
        long long b=helper(n-3,dp);
        long long c=helper(n-4,dp);
        return dp[n]=(a+b+c)%mod;
    }
    long long countWays(int N) {
        // code here
        vector<int>dp(N+1,-1);
        return helper(N,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.countWays(N) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends
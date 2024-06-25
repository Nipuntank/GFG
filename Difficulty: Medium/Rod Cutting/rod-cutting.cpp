//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int helper(int *price,vector<vector<int>>&dp,int i,int n)
    {
        if(i==0)
        {
            return n*price[0];
        }
        if(dp[i][n]!=-1)
        {
            return dp[i][n];
        }
        int a=helper(price,dp,i-1,n);
        int len=i+1;
        int b=-1e9;
        if(len<=n)
        {
            b=price[i]+helper(price,dp,i,n-len);
        }
        return dp[i][n]=max(a,b);
    }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return helper(price,dp,n-1,n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int helper(int i,int k,vector<int>&height,vector<int>&dp)
    {
        int n=height.size();
        if(i==0)
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int mini=1e9;
        for(int j=1;j<=k;j++)
        {
            if(i-j>=0)
            {
                int jump=abs(height[i]-height[i-j])+helper(i-j,k,height,dp);
                mini=min(mini,jump);
            }
        }
        return dp[i]=mini;
    }
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        vector<int>dp(n,-1);
        return helper(n-1,k,height,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends
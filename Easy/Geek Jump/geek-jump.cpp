//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int helper(int i,vector<int>&height,vector<int>&dp)
    {
        if(i==0)
        {
            return 0;
        }
        if(i==1)
        {
            return abs(height[1]-height[0]);
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int a=helper(i-1,height,dp)+abs(height[i]-height[i-1]);
        int b=1e9;
        if(b>1)
        {
            b=helper(i-2,height,dp)+abs(height[i]-height[i-2]);
        }
        return dp[i]=min(a,b);
    }
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int>dp(n,-1);
        return helper(n-1,height,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int mod=1e9+7;
    int helper(int i,int sum,vector<int>&arr,vector<vector<int>>&dp)
    {
        if(i==0)
        {
            if(arr[i]==0 && sum==0)
                return 2;
            if(arr[i]==sum || sum==0)
                return 1;
            return 0;
        }
        if(dp[i][sum]!=-1)
            return dp[i][sum];
        int p=0;
        if(arr[i]<=sum)
            p=helper(i-1,sum-arr[i],arr,dp);
        int np=helper(i-1,sum,arr,dp);
        return dp[i][sum]=(p+np)%mod;
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return helper(n-1,target,arr,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int target;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> target;
        cin.ignore(); // Ignore newline character after target input

        Solution solution;
        cout << solution.perfectSum(arr, target);
        cout << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends
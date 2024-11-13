//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int helper(int i,int sum,vector<int>&coins,vector<vector<int>>&dp)
    {
        if(sum==0)
        {
            return 1;
        }
        if(i<0 || sum<0)
        {
            return 0;
        }
        if(dp[i][sum]!=-1)
        {
            return dp[i][sum];
        }
        int take=helper(i-1,sum,coins,dp);
        int notake=helper(i,sum-coins[i],coins,dp);
        return dp[i][sum]=take+notake;
    }
    int count(vector<int>& coins, int sum) {
        // code here.
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return helper(n-1,sum,coins,dp);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
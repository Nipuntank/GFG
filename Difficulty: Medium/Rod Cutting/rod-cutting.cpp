//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int helper(int i,int len,vector<int>&price,vector<vector<int>>&dp)
    {
        if(i==0)
            return price[0]*len;
        if(dp[i][len]!=-1)
            return dp[i][len];
        int a=INT_MIN;
        if(i+1<=len)
        {
            a=price[i]+helper(i,len-i-1,price,dp);
        }
        int b=helper(i-1,len,price,dp);
        return dp[i][len]=max(a,b);
    }
    int cutRod(vector<int> &price) {
        // code here
        int n=price.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return helper(n-1,n,price,dp);
    }
    
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;

        cout << ob.cutRod(a) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
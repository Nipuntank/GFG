//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int helper(int val[],int wt[],vector<vector<int>>&dp,int i,int w)
    {
        if(i==0)
        {
            if(wt[i]<=w)
            {
                return (w/wt[i])*val[i];
            }
            return 0;
        }
        if(dp[i][w]!=-1)
        {
            return dp[i][w];
        }
        int a=helper(val,wt,dp,i-1,w);
        int b=-1e9;
        if(wt[i]<=w)
        {
            b=val[i]+helper(val,wt,dp,i,w-wt[i]);
        }
        return dp[i][w]=max(a,b);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>>dp(N,vector<int>(W+1,-1));
        return helper(val,wt,dp,N-1,W);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends
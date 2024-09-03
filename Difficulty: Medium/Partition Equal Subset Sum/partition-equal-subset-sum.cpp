//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int helper(int i,int sum,int arr[],vector<vector<int>>&dp)
    {
        if(i<0)
        {
            return 0;
        }
        if(sum==0)
        {
            return 1;
        }
        if(dp[i][sum]!=-1)
        {
            return dp[i][sum];
        }
        int a=0;
        if(arr[i]<=sum)
        {
            a=helper(i-1,sum-arr[i],arr,dp);
        }
        int b=helper(i-1,sum,arr,dp);
        return dp[i][sum]=a||b;
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++)
        {
            sum+=arr[i];
        }
        if(sum%2!=0)
        {
            return 0;
        }
        sum=sum/2;
        vector<vector<int>>dp(N+1,vector<int>(sum+1,-1));
        return helper(N-1,sum,arr,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends
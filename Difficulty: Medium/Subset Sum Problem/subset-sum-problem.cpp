//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool helper(vector<int>&arr,vector<vector<int>>&dp,int sum,int i)
    {
        if(sum==0)
        {
            return true;
        }
        if(i==0)
        {
            return arr[0]==sum;
        }
        if(dp[i][sum]!=-1)
        {
            return dp[i][sum];
        }
        int notpick=helper(arr,dp,sum,i-1);
        int pick=0;
        if(arr[i]<=sum)
        {
            pick=helper(arr,dp,sum-arr[i],i-1);
        }
        return dp[i][sum]=pick || notpick;
    }

    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return helper(arr,dp,sum,n-1);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends
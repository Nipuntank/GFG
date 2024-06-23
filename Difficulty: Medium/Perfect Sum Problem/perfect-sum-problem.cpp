//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod=1e9+7;
	int helper(int arr[],vector<vector<int>>&dp,int i,int sum)
	{
	    // base case
	    
	    if(i==0)
	    {
	        if(arr[i]==0 && sum==0)
	        {
	            return 2;
	        }
	        if(arr[i]==sum || sum==0)
	        {
	            return 1;
	        }
	        return 0;
	    }
	    
	    if(dp[i][sum]!=-1)
	    {
	        return dp[i][sum];
	    }
	    int a=helper(arr,dp,i-1,sum);
	    int b=0;
	    if(arr[i]<=sum)
	    {
	        b=helper(arr,dp,i-1,sum-arr[i]);
	    }
	    return dp[i][sum]=(a+b)%mod;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return helper(arr,dp,n-1,sum);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
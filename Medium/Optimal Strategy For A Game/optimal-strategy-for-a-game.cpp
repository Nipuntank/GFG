//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    long long helper(int arr[],vector<vector<long long>>&dp,int l,int r)
    {
        if(l>r)
        {
            return 0;
        }
        if(l==r)
        {
            return arr[l];
        }
        if(dp[l][r]!=-1)
        {
            return dp[l][r];
        }
        long long leftans=arr[l]+min(helper(arr,dp,l+2,r),helper(arr,dp,l+1,r-1));
        long long rightans=arr[r]+min(helper(arr,dp,l,r-2),helper(arr,dp,l+1,r-1));
        return dp[l][r]=max(leftans,rightans);
    }
    long long maximumAmount(int n, int arr[]){
        // Your code here
        vector<vector<long long>>dp(n+1,vector<long long>(n+1,-1));
        long long ans=helper(arr,dp,0,n-1);
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(n,a)<<endl;
	}
	return 0;
}
// } Driver Code Ends
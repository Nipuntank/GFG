//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int helper(int i,int j,string &str1,string &str2,vector<vector<int>>&dp)
	{
	    if(i<0 || j<0)
	    {
	        return 0;
	    }
	    if(dp[i][j]!=-1)
	    {
	        return dp[i][j];
	    }
	    if(str1[i]==str2[j])
	    {
	        return dp[i][j]=1+helper(i-1,j-1,str1,str2,dp);
	    }
	    else{
	        int a=helper(i-1,j,str1,str2,dp);
	        int b=helper(i,j-1,str1,str2,dp);
	        return dp[i][j]=max(a,b);
	    }
	}
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int m=str1.size();
	    int n=str2.size();
	    vector<vector<int>>dp(m,vector<int>(n,-1));
	    int a=helper(m-1,n-1,str1,str2,dp);
	    return m+n-2*a;
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends
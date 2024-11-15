//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int helper(int i,int j,string S,vector<vector<int>>&dp)
    {
        if(i>=j)
        {
            return 1;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(S[i]==S[j])
        {
            return dp[i][j]= helper(i+1,j-1,S,dp);
        }
        return dp[i][j]=0;
    }
    string longestPalindrome(string S){
        // code here 
        int n=S.size();
        if(n<=1)
        {
            return S;
        }
        int max_len=INT_MIN;
        int si=0;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(helper(i,j,S,dp))
                {
                    if(max_len<j-i+1)
                    {
                        max_len=j-i+1;
                        si=i;
                    }
                }
            }
        }
        return S.substr(si,max_len);
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends
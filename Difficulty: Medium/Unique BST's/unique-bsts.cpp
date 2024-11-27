//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the total number of possible unique BST. 
    int numTrees(int N) 
    {
        // Your code here
        vector<int>dp(N+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=N;i++)
        {
            int l=0;
            int r=i-1;
            while(l<=i-1)
            {
                dp[i]+=dp[l]*dp[r];
                l++;
                r--;
            }
        }
        return dp[N];
    }
};

//{ Driver Code Starts.
#define mod (int)(1e9+7)
int main(){
    
    //taking total testcases
    int t;
    cin>>t;
    while(t--){
        
        //taking total number of elements
        int n;
        cin>>n;
        Solution ob;
        //calling function numTrees()
        cout<<ob.numTrees(n)<<"\n";
    
cout << "~" << "\n";
}
}	
// } Driver Code Ends
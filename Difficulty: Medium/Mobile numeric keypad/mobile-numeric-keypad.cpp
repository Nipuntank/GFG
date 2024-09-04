//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>>arr={{0,8},{1,2,4},{1,2,3,5},{2,3,6},{1,4,5,7},{2,4,5,6,8},{3,5,6,9},{4,7,8},{0,5,7,8,9},{6,8,9}};
    long long getCount(int n) {
        // Your code goes here
        vector<long long>dp(10,1);
        for(int i=2;i<=n;i++)
        {
            vector<long long>temp(10,0);
            for(int j=0;j<10;j++)
            {
                for(auto it:arr[j])
                {
                    temp[j]=temp[j]+dp[it];
                }
            }
            dp=temp;
        }
        long long ans=0;
        for(auto it:dp)
        {
            ans=ans+it;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends
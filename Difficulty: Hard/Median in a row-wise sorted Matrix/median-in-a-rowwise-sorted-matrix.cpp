//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int helper(int mid,vector<vector<int>> &mat,int m,int n)
    {
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            cnt+=upper_bound(mat[i].begin(),mat[i].end(),mid)-mat[i].begin();
        }
        return cnt;
    }
    int median(vector<vector<int>> &mat) {
        // code here
        int l=INT_MAX,h=INT_MIN;
        int m=mat.size();
        int n=mat[0].size();
        for(int i=0;i<m;i++)
        {
            l=min(l,mat[i][0]);
            h=max(h,mat[i][n-1]);
        }
        int req=(m*n)/2;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            int a=helper(mid,mat,m,n);
            if(a<=req)
                l=mid+1;
            else
                h=mid-1;
        }
        return l;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cin >> matrix[i][j];
        Solution obj;
        int ans = -1;
        ans = obj.median(matrix);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void helper(vector<int>&arr,int i,int sum,vector<int>&temp)
    {
        if(i==arr.size())
        {
            temp.push_back(sum);
            return ;
        }
        helper(arr,i+1,sum+arr[i],temp);
        helper(arr,i+1,sum,temp);
    }
    vector<int> subsetSums(vector<int> arr, int n) {
        // Write Your Code here
        sort(arr.begin(),arr.end());
        vector<int>temp;
        helper(arr,0,0,temp);
        return temp;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
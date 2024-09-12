//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        if(n==1)
        {
            return 0;
        }
        sort(arr.begin(),arr.end());
        int diff=arr[n-1]-arr[0];
        
        int largest=arr[n-1]-k;
        int smallest=arr[0]+k;
        
        for(int i=0;i<n-1;i++)
        {
            int a=max(largest,arr[i]+k);
            int b=min(smallest,arr[i+1]-k);
            if(b<0)
            {
                continue;
            }
            diff=min(diff,a-b);
        }
        return diff;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, k;
        cin >> k;
        cin.ignore();
        vector<int> a, b, c, d;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution ob;
        auto ans = ob.getMinDiff(a, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
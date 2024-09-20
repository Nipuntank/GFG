//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int characterReplacement(string& s, int k) {
        // code here
        unordered_map<char,int>mp;
        int l=0,r=0;
        int maxi=0,ans=0;
        int n=s.size();
        while(r<n)
        {
            mp[s[r]]++;
            maxi=max(maxi,mp[s[r]]);
            if((r-l+1)-maxi>k)
            {
                mp[s[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;

        Solution obj;
        cout << obj.characterReplacement(S, K) << endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // your code here
        if(s.size()==0 || k==0)
            return -1;
        unordered_map<char,int>mp;
        int i=0,ans=-1;
        for(int j=0;j<s.size();j++)
        {
            mp[s[j]]++;
            while(mp.size()>k)
            {
                mp[s[i]]--;
                if(mp[s[i]]==0)
                    mp.erase(s[i]);
                i++;
            }
            if(mp.size()==k)
                ans=max(ans,j-i+1);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends
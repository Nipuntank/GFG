//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    set<string>s;
    void helper(string &str,int i)
    {
        if(i==str.size())
        {
            s.insert(str);
            return ;
        }
        for(int j=i;j<str.size();j++)
        {
            swap(str[i],str[j]);
            helper(str,i+1);
            swap(str[i],str[j]);
        }
    }
    vector<string> find_permutation(string str) {
        // Code here there
        s.clear();
        helper(str,0);
        return vector<string>(s.begin(),s.end());
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.find_permutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
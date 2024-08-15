//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<vector<string>>ans;
    bool isPlaindrome(string S)
    {
        int i=0,j=S.size()-1;
        while(i<j)
        {
            if(S[i++]!=S[j--])
            {
                return false;
            }
        }
        return true;
    }
    void helper(string S,vector<string>temp,int i)
    {
        if(i==S.size())
        {
            ans.push_back(temp);
            return;
        }
        for(int j=i;j<S.size();j++)
        {
            if(isPlaindrome(S.substr(i,j-i+1)))
            {
                temp.push_back(S.substr(i,j-i+1));
                helper(S,temp,j+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> allPalindromicPerms(string S) {
        // code here
        vector<string>temp;
        helper(S,temp,0);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends
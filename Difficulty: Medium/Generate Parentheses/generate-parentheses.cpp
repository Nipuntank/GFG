//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    vector<string>s;
    void helper(int n,string temp,int l,int r)
    {
        if(l==n && r==n)
        {
            s.push_back(temp);
            return ;
        }
        if(l<n)
        {
            temp.push_back('(');
            helper(n,temp,l+1,r);
            temp.pop_back();
        }
        if(r<l)
        {
            temp.push_back(')');
            helper(n,temp,l,r+1);
            temp.pop_back();
        }
    }
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        string temp="";
        int r=0,l=0;
        helper(n,temp,l,r);
        return s;
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends
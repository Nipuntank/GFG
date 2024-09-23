//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    bool isEmpty(int grid[N][N],int &row,int &col)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(grid[i][j]==0)
                {
                    row=i;
                    col=j;
                    return true;
                }
            }
        }
        return false;
    }
    bool isSafe(int grid[N][N],int row,int col,int val)
    {
        for(int i=0;i<9;i++)
        {
            if(grid[i][col]==val)
            {
                return false;
            }
        }
        for(int i=0;i<9;i++)
        {
            if(grid[row][i]==val)
            {
                return false;
            }
        }
        int rowF=row-row%3;
        int colF=col-col%3;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(grid[i+rowF][j+colF]==val)
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        int row=0,col=0;
        if(!isEmpty(grid,row,col))
        {
            return true;
        }
        for(int i=1;i<=9;i++)
        {
            
            if(isSafe(grid,row,col,i))
            {
                grid[row][col]=i;
                if(SolveSudoku(grid))
                {
                    return true;
                }
                grid[row][col]=0;
            }
        }
        return false;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                cout<<grid[i][j]<<" ";
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends
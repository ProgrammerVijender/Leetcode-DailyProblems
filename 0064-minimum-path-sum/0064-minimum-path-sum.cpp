class Solution {
public:
    // recursion solution
    // int sol(vector<vector<int>>& grid , int i , int j  )
    // {
    //     int m = grid.size();
    //     int n = grid[0].size();

    //     if( i >= m || j >= n)
    //     {
    //         return INT_MAX;
    //     }

    //     if( i == m-1 && j == n-1)
    //     {
    //         return grid[i][j];
    //     }

    //     int inc = sol(grid , i , j+1 );
    //     int exc = sol(grid , i+1 , j );

    //     return grid[i][j] + min(inc , exc);
        
    // }

    // recursion + memoisation solution
    int sol(vector<vector<int>>& grid , int i , int j ,vector<vector<int>>& dp  )
    {
            int m = grid.size();
        int n = grid[0].size();

        if( i >= m || j >= n)
        {
            return INT_MAX;
        }

        if( i == m-1 && j == n-1)
        {
            return grid[i][j];
        }

        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }

       int inc = sol(grid , i , j+1 ,dp );
        int exc = sol(grid , i+1 , j , dp);

        dp[i][j] = grid[i][j] + min(inc , exc);
        return dp[i][j] ;
     
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m , vector<int> (n,-1));
        int i = 0 , j = 0;
       return sol(grid , i , j , dp);



    }
};
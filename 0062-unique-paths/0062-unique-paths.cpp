class Solution {
public:

    // recursion + memoisation
    // int sol(int& m , int& n , int i , int j , vector< vector<int > > & dp)
    // {
    //     if( i >= m || j >= n)
    //     {
    //         return 0;
    //     }

    //     if( i == m-1 && j == n-1)
    //     {
    //         return 1;
    //     }

    //     if(dp[i][j] != -1)
    //     {
    //         return dp[i][j];
    //     }

    //     dp[i][j] =  sol(m,n,i+1,j,dp) + sol(m,n,i,j+1,dp);

    //     return dp[i][j];
    // }


    int uniquePaths(int m, int n) {
        // int ans = 0 ;

        // int i = 0; 
        // int j = 0; 
        // vector< vector<int > > dp(m , vector<int> (n,-1));

        // return sol(m , n  , i , j , dp);
    
    // tabulation method
        vector< vector<int > > dp(m , vector<int> (n,0));

        dp[m-1][n-1] = 1;
    for(int i=m-1; i>=0; i--)
    {
        for(int j=n-1; j >=0; j--)
        {
             if (i == m-1 && j == n-1) continue;
            int down = ( i+1 <m) ? dp[i+1][j] : 0;
            int right = ( j+1 <n) ? dp[i][j+1] : 0;
            dp[i][j] = down + right;
        }
    }
    
        return dp[0][0];
    }
};
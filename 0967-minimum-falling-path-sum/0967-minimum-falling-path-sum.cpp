class Solution {
public:
    // recursion soltuion 
    // int sol(vector<vector<int>>& matrix , int i , int j  )
    // {
    //     int m = matrix.size();
    //     int n = matrix[0].size();

    //     if(m <= i ||  j < 0||  n <= j)
    //     {
    //         return INT_MAX;
    //     }

    //     // sum = matrix[i][j];

    //     if(i == m-1)
    //     {
    //          return matrix[i][j];
    //     }

    //     int nextRowLeft = sol(matrix , i +1,j-1 );
    //     int nextRowBott = sol(matrix , i +1,j );
    //     int nextRowRight = sol(matrix , i +1,j+1);

    //     int mini = min({nextRowLeft, nextRowBott, nextRowRight});

    //     return mini + matrix[i][j];

    // }


    
    
    // Recursion + memoisation method , isme baadme TLE marta h 
    
// class Solution {
// public:
    // int sol(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp) {
    //     int m = matrix.size();
    //     int n = matrix[0].size();

    //     if (i >= m || j < 0 || j >= n) {
    //         return INT_MAX;
    //     }

    //     if (i == m - 1) {
    //         return matrix[i][j];
    //     }

    //     if (dp[i][j] != -1) {
    //         return dp[i][j];
    //     }

    //     int nextRowLeft = sol(matrix, i + 1, j - 1, dp);
    //     int nextRowBott = sol(matrix, i + 1, j, dp);
    //     int nextRowRight = sol(matrix, i + 1, j + 1, dp);

    //     dp[i][j] = matrix[i][j] + min({nextRowLeft, nextRowBott, nextRowRight});
    //     return dp[i][j];
    // }

    // Tabulation Method 


    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        // vector<vector<int> > dp(m, vector<int>(n, -1));

        // int minAns = INT_MAX;

        // for (int j = 0; j < n; ++j) {
        //     minAns = min(minAns, sol(matrix, 0, j, dp));
        // }


        // Tabulation method

        vector<vector<int> > dp(m, vector<int>(n, -1));
        dp = matrix;
        // int minAns = INT_MAX;
        for(int i = m-2; i>=0; i--)
        {
            for(int j=0; j<n; j++)
            {
                int lefty = (j > 0) ? dp[i+1][j-1] : INT_MAX;
                int m =  dp[i + 1][j ] ;
                int r = (j < n-1) ? dp[i+1][j+1] : INT_MAX;
                dp[i][j] = matrix[i][j] + min({lefty , m , r});
                // minAns = min(dp[i][j] , minAns);
            }
        }
 int minAns = INT_MAX;
    for (int j = 0; j < n; j++) {
        minAns = min(minAns, dp[0][j]);
    }


        return minAns;
    }
};
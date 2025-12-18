class Solution {
public:

    // recursion wala method 
    // int sol(int start , int end)
    // {
    //     // base case

    //     if(start >= end)
    //     {
    //         return 0;
    //     }

    //     int ans = INT_MAX;

    //     for(int i=start; i<=end; i++ )
    //     {
    //         ans = min(ans , i+ max( sol(start , i-1) , sol(i+1 , end)));
    //     }
    //     return ans;
    // }

    // recursion + memoisation 
    // int solUsingMemoisation(int start , int end , vector<vector<int>> &dp)
    // {
    //     // base case
    //     if(start >= end)
    //     {
    //         return 0;
    //     }
    //     if(dp[start][end] != -1)
    //     {
    //         return dp[start][end];
    //     }

        // int ans = INT_MAX;

        // for(int i=start; i<=end; i++ )
        // {
        //     ans = min(ans , i+ max( solUsingMemoisation(start , i-1 , dp) , solUsingMemoisation(i+1 , end ,dp)));
        // }
    //     dp[start][end] = ans;
    //     return dp[start][end];
    // }


    // Solve usinng Tabulation Method
    int solvingUsingTabulation(int n)
    {
        vector<vector<int> >  dp(n+2, vector<int>(n+2, 0));
        
        for(int start=n; start >=1; start--)
        {
            for(int end=1; end<=n; end++ )
            {
                if (start >= end) {
    dp[start][end] = 0;
    continue;
}
                int ans = INT_MAX;

        for(int i=start; i<=end; i++ )
        {
            ans = min(ans , i+ max( dp[start][ i-1 ] , dp[i+1 ][end]));
        }
        
        dp[start][end] = ans;
            }

        }

    return dp[1][n];
    }

    int getMoneyAmount(int n) {
        // int start = 1;
        // int end  = n;

        // memoisation :--
        // vector<vector<int>> dp(n+1 , vector<int>(n+1 , -1));

        // int ans = solUsingMemoisation(start , end , dp);

        // Tabulation method :--
        return solvingUsingTabulation(n);

    }
};
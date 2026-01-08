class Solution {
public:
    
    // rec + memo 
    int sol(vector<int>& nums1, vector<int>& nums2 , vector<vector<int>>& dp , int m , int n)
    {
        // base case
        if(nums1.size() == m || nums2.size() == n) {
            return INT_MIN;
        }

        if(dp[m][n] != -1)
        {
            return dp[m][n];
        }

        // take 
        int take = nums1[m] * nums2[n];

        // next Take 
        int next = sol(nums1 , nums2, dp ,m+1 , n+1);

        // if next value positive h to take me add karlenge max ans ke liye
        if(next > 0 )
        {
            take += next;
        }

        // skip 1 element
        int SkipNum1 = sol(nums1 , nums2, dp ,m+1 , n);
        int SkipNum2 = sol(nums1 , nums2, dp ,m , n+1);


        // max lenge teeno kaa
        int maxi = max({ take, SkipNum1,  SkipNum2 });

        return dp[m][n] = maxi;
    }
  int sol2(vector<int>& nums1, vector<int>& nums2)
    {
        int m = nums1.size();
        int n = nums2.size();

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i=m-1; i>=0; i--)
        {
            for(int j=n-1; j>=0; j--)
            {
                 // take 
        int take = nums1[i] * nums2[j];

        // if next value positive h to take me add karlenge max ans ke liye
        if(dp[i+1 ][j+1] > 0 )
        {
            take += dp[i+1 ][j+1];
        }

        // skip 1 element
        int SkipNum1 = dp[i+1][ j];
        int SkipNum2 = dp[i] [j+1];


        // max lenge teeno kaa
        dp[i][j] = max({ take, SkipNum1,  SkipNum2 });
            }
        }

        return dp[0][0];
    }

    // Tabulation Space optimized;
      int sol3(vector<int>& nums1, vector<int>& nums2 )
    {
        int m = nums1.size();
        int n = nums2.size();

        vector<int> next(n + 1, INT_MIN);
        vector<int> curr(n + 1, INT_MIN);

        for(int i=m-1; i>=0; i--)
        {
            for(int j=n-1; j>=0; j--)
            {
                 // take 
        int take = nums1[i] * nums2[j];

        // if next value positive h to take me add karlenge max ans ke liye
        if(next[j+1] > 0 )
        {
            take += next[j+1];
        }

        // skip 1 element
        int SkipNum1 = next[j];
        int SkipNum2 = curr[j+1];


        // max lenge teeno kaa
        curr[j] = max({ take, SkipNum1,  SkipNum2 });
            }
            next = curr;
        }


        return next[0];
    }


    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        
        // vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), -1));
        // return  sol(nums1, nums2 , dp,  0 , 0);


            // return  sol2(nums1, nums2 );

            return sol3(nums1,nums2 );
    }
};
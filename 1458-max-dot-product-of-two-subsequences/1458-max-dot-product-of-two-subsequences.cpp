class Solution {
public:
    
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
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        
        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), -1));
        return  sol(nums1, nums2 , dp,  0 , 0);

    }
};
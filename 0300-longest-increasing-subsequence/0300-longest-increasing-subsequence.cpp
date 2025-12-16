class Solution {
public:
    // recursion solution
    // int sol(vector<int>& nums , int curr , int prev)
    // {
    //     int n = nums.size();

    //     if(curr >= n)
    //     {
    //         return 0;
    //     }

    //     int inc = 0;
    //     if(prev == -1 || nums[curr] > nums[prev])
    //     {
    //         inc = 1 + sol(nums , curr + 1 , curr);
    //     }
    //     int exc = 0 + sol(nums , curr+1, prev);

    //     int ans = max(exc , inc);

    //     return ans;
    // }

    // recursion + Memoisation
    // int sol(vector<int>& nums , int curr , int prev , vector<vector<int>>
    // &dp)
    // {
    //     int n = nums.size();

    //     if(curr >= n)
    //     {
    //         return 0;
    //     }

    //     if(dp[curr][prev +1] != -1)
    //     {
    //         return dp[curr][prev +1];
    //     }

    //     int inc = 0;
    //     if(prev == -1 || nums[curr] > nums[prev])
    //     {
    //         inc = 1 + sol(nums , curr + 1 , curr ,dp);
    //     }
    //     int exc = 0 + sol(nums , curr+1, prev ,dp);

    //     dp[curr][prev +1] = max(exc , inc);

    //     return dp[curr][prev +1];
    // }

    // Using Tabulation method
    // int sol(vector<int>& nums, vector<vector<int>>& dp) {
    //     int n = nums.size();

    //     for (int curr = n - 1; curr >= 0; curr--) {
    //         for (int prev = curr - 1; prev >= -1; prev--) {
    //             int inc = 0;
    //             if (prev == -1 || nums[curr] > nums[prev]) {
    //                 inc = 1 + dp[curr + 1][curr + 1];
    //             }
    //             int exc = dp[curr + 1][prev + 1];

    //             dp[curr][prev + 1] = max(exc, inc);
    //         }
    //     }

    //     return dp[0][0];
    // }

    // Using Tabulation method with Space optimize
    // int solTab_with_SpaceOptimized(vector<int>& nums   ) {

        
    //     int n = nums.size();
    //     vector <int> cur(n+1 , 0);
    //     vector <int> next(n+1 , 0);

    //     for (int curr = n - 1; curr >= 0; curr--) {
    //         for (int prev = curr - 1; prev >= -1; prev--) {
    //             int inc = 0;
    //             if (prev == -1 || nums[curr] > nums[prev]) {
    //                 inc = 1 + next[curr + 1];
    //             }
    //             int exc = next[prev + 1];

    //             cur[prev + 1] = max(exc, inc);
                
    //         }
    //         next = cur;
    //     }

    //     return cur[0];
    // }

    // using Binary Easy Method
    int UsingBinarySearch(vector<int> &num)
    {
        vector<int> ans;

        // initial state
        ans.push_back(num[0]);

        for(int i=1; i<num.size(); i++)
        {
            if(num[i] > ans.back())
            {
                ans.push_back(num[i]);
            }
            else
            {
                // nums[i] ka first occurence index lake dega , 
                // , otherwise usse just bade ka first occurence index dega
                int index = lower_bound(ans.begin() , ans.end() , num[i]) - ans.begin();
                // replace
                ans[index] = num[i];
            }
        }
        return ans.size();
    }


    int lengthOfLIS(vector<int>& nums) {
        
        // vector<vector<int>> dp(nums.size() + 1,vector<int>(nums.size() + 1, 0));
        // return sol(nums, dp);


        // Tabulation space optimized
        // return solTab_with_SpaceOptimized(nums);

        // using Binary Easy Method
        int curr = 0;
        int prev = -1;
        int n = nums.size();

        return UsingBinarySearch(nums);
    }
};
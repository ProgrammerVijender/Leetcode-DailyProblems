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
    int sol(vector<int>& nums , int curr , int prev , vector<vector<int>> &dp)
    {
        int n = nums.size();

        if(curr >= n)
        {
            return 0;
        }

        if(dp[curr][prev +1] != -1)
        {
            return dp[curr][prev +1];
        }


        int inc = 0;
        if(prev == -1 || nums[curr] > nums[prev])
        {
            inc = 1 + sol(nums , curr + 1 , curr ,dp);
        }
        int exc = 0 + sol(nums , curr+1, prev ,dp);
        
        dp[curr][prev +1] = max(exc , inc);

        return dp[curr][prev +1];
    }



    int lengthOfLIS(vector<int>& nums) {
        vector < vector <int> > dp(nums.size() +1 , vector<int> (nums.size() +1, -1));
        return sol(nums, 0 , -1 , dp);
    }
};
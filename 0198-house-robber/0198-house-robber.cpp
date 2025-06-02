class Solution {
public:

    int usingMem(vector <int> & nums , int index , vector <int> & dp)
    {
        if(index >= nums.size())
        {
            return 0;
        }
        if(dp[index] != -1)
        {
            return dp[index];
        }

        int inc = nums[index] + usingMem(nums,index+2,dp);
        int exc = 0 + usingMem(nums,index+1,dp);

        dp[index] = max(inc, exc);

        return dp[index];
    }
    int rob(vector<int>& nums) {
        vector<int> ans(nums.size() +1,-1);

        return usingMem(nums ,0,ans);
    }
};
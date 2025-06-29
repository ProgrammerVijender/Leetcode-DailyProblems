class Solution {
public:

    bool sol(vector <int>& nums , int i , int sum , int target ,  vector < vector <int > > &dp)
    {  
        if(sum == target)
        {
            return 1;
        }
        if(sum > target )
        {
            return 0;
        }
        if(i >= nums.size())
        {
            return 0;
        }

        if(dp[i][sum] != -1)
        {
            return dp[i][sum];
        }

        bool inc = sol(nums , i+1 , sum + nums[i] , target ,dp);
        bool exc = sol(nums , i+1 , sum , target ,dp);


        return dp[i][sum] = (inc || exc);
    }

    bool canPartition(vector<int>& nums) {
    
    int total = 0;
        for(auto & i:nums)
        {
            total += i;
        }
        
        if(total & 1) // check odd
        {
            return 0;
        }
        int target = total /2 ;
        vector < vector <int > > dp (nums.size()+1 , vector <int> (target+1 , -1));
        return sol(nums , 0 , 0 , target , dp);
    }
};
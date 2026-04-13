class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        
        int n = nums.size();
        
        int diff = INT_MAX;
        int mini = INT_MAX;

        
        for(int i=0; i<n; i++)
        {
            if( nums[i] == target )
            {
                diff = abs(i - start);
            mini = min(diff , mini);
            }
        }

        return (mini == INT_MAX) ? 0 : mini;
    }
};
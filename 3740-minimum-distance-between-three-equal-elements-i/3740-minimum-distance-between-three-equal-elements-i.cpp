class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        
        int n = nums.size();

        if(n <3) return -1;
        int ans = INT_MAX;
        int mini  = INT_MAX;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                for(int k=j+1; k<n; k++)
                {
                if( (i != j && j != k && i != k) 
                        && 
                            (nums[i] == nums[j] && nums[i] == nums[k]))
                    {
                        
                        mini = abs(i - j) + abs(j - k) + abs(k - i);
                        cout<< mini;
                        break;
                    }
                }
                ans = min( ans , mini);
            }
        }

        
        return (ans == INT_MAX) ? -1 :ans;
    }
};
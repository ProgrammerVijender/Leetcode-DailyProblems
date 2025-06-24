class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        
        vector<int> ans;
        int n = nums.size();

        for(int i=0; i<n; i++)
        {
            if(nums[i] == key)
            {
                int start;
                int end;

                start = max(i - k ,0) ;
                end = min(i+k ,n-1) ;

                if(!ans.empty())
                {
                    int s = ans.size()-1;

                    if(ans[s] >= start )
                    {
                        start = ans[s] +1;
                    }
                }

                for(int j=start; j<= end; j++)
                {
                    ans.push_back(j);
                }
        
            }
        }

        return ans;
    }
};
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map <int,int> freq;

        for(int i=0; i<nums.size(); i++)
        {
            for(int j=i+1; j<nums.size(); j++)
            {
                freq[nums[i] * nums[j]]++;
            }
        }

        
        int ans =0;
        for(auto& n:freq)
        {
            int count = n.second;
             ans += 8 * ( (count * (count - 1) ) / 2);
        }
        
        
        return ans;
    }
};